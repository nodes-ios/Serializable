//
//  AlamofireExtension.swift
//  Serializable
//
//  Created by Kasper Welner on 08/03/16.
//  Copyright © 2016 Nodes. All rights reserved.
//

import Foundation
import Alamofire

public struct Parser {
    public static let APICallSucceededNotification = "APICallSucceededNotification"
    public struct Error {
        
        public let error:NSError?
        public let response:NSHTTPURLResponse?
        public let rawResponse:String
        public let request:NSURLRequest?
    }
}

/* Unfortunately, this has to be in global scope since Swift currently (v2.2) does not support nested generic types */
public enum ApiResult<T> {
    case Success(data:T)
    case Error(error:Parser.Error)
}

public extension Alamofire.Response {
    func serializableParserError() -> Parser.Error {
        switch self.result {
        case .Failure(let error):
            let rawResponse:String
            if let data = self.data {
                rawResponse = NSString(data: data, encoding: NSUTF8StringEncoding) as? String ?? ""
            } else {
                rawResponse = ""
            }
            let unwrappedError = error as NSError ?? NSError(domain: "Serializable.Parser", code: 2048, userInfo: [ NSLocalizedDescriptionKey : "Parsing block failed!"])
            return Parser.Error.init(error: unwrappedError, response: self.response, rawResponse: rawResponse, request: self.request)
        default:
            return Parser.Error.init(error: nil, response: nil, rawResponse: "", request: nil)
        }
    }
}

public extension Parser {
    
    internal static func parse<T,S>(response response:Response<S, NSError>, completionHandler: (ApiResult<T>) -> Void, parsingHandler: (( data: AnyObject? ) -> T?)?) {
        switch response.result {
        case let Result.Success(value):
            if let parsedObject: T = parsingHandler?( data: value as? AnyObject ) {
                NSNotificationCenter.defaultCenter().postNotificationName(APICallSucceededNotification, object: nil)
                completionHandler(ApiResult.Success(data: parsedObject));
            } else {
                completionHandler(ApiResult.Error(error:response.serializableParserError()))
            }
            
        case Result.Failure:
            completionHandler(ApiResult.Error(error:response.serializableParserError()))
            break;
        }
    }
    
    internal static func parse<T:Serializable,S>(response response:Response<S, NSError>, completionHandler: ApiResult<T> -> Void) {
        parse(response:response, completionHandler: completionHandler, parsingHandler: {
            ( data: AnyObject? ) -> T? in
            
            if let sourceDictionary = data as? [String : AnyObject] {
                
                let unwrappedDictionary = unwrappedSource(sourceDictionary, type:T.self) as? [String : AnyObject] ?? sourceDictionary
                
                return T(dictionary: unwrappedDictionary) as T?
            }
            
            return nil
        })
    }
    
    internal static func parse<T:Serializable,S>(response response:Response<S, NSError>, completionHandler: ApiResult<[T]> -> Void) {
        Parser.parse(response:response, completionHandler: completionHandler, parsingHandler: {
            ( data: AnyObject? ) -> [T]? in
            
            var finalArray:AnyObject? = data
            
            if let dataDict = data as? NSDictionary {
                if let unwrappedArray = unwrappedSource(dataDict, type:T.self) as? [AnyObject] {
                    finalArray = unwrappedArray
                }
            }
            
            if let sourceArray = finalArray as? [AnyObject] {
                
                var returnArray:[T] = []
                for dict in sourceArray {
                    returnArray.append(T(dictionary: dict as? [String : AnyObject]))
                }
                return returnArray
            }
            return nil
        })
    }
    
    internal static func parse<S>(response response:Response<S, NSError>, completionHandler: ApiResult<Void> -> Void) {
        switch response.result {
        case Result.Success:
            NSNotificationCenter.defaultCenter().postNotificationName(APICallSucceededNotification, object: nil)
            completionHandler(ApiResult.Success(data: ()))
            
        case Result.Failure:
            completionHandler(ApiResult.Error(error:response.serializableParserError()))
            break;
        }
    }
    
    internal static func unwrappedSource(sourceDictionary: NSDictionary, type:Any) -> AnyObject {
        // Seriously, Swift? This is how you have to do this? All I want is the class of the generic type as a string
        let mirrorString = Mirror(reflecting: type).description
        var typeString:String = ""
        if let dotStartIndex = mirrorString.rangeOfString("for ")?.endIndex {
            typeString = mirrorString.substringFromIndex(dotStartIndex)
            if let nextDotStartIndex = typeString.rangeOfString(".")?.startIndex {
                typeString = typeString.substringToIndex(nextDotStartIndex)
            }
        }
        
        if let nestedObject: AnyObject = sourceDictionary[typeString] {
            return nestedObject
        }
        if let nestedObject: AnyObject = sourceDictionary["data"] {
            return nestedObject
        }
        
        return sourceDictionary
    }
}


//MARK: - Wrapper methods

public extension Alamofire.Request
{
    /**
     Adds a handler that attempts to parse the result of the request into type **T** using **parsingHandler**
     
     - parameter completionHandler:A closure that is invoked when the request is finished and *parsingHandler* has been executed
     - parameter parsingHandler:A closure takes the JSON data as input and outputs the parsed data of type **T**
     
     - returns: The request
     */
    
    public func response<T>(completionHandler: (ApiResult<T>) -> Void, parsingHandler: (( data: AnyObject? ) -> T?)?) -> Self {
        return validate().responseJSON(completionHandler: { (response) -> Void in
            Parser.parse(response: response, completionHandler: completionHandler, parsingHandler: parsingHandler)
        })
    }
    
    /**
     Adds a handler that attempts to parse the result of the request into a **Serializable**
     
     - parameter completionHandler:A closure that is invoked when the request is finished
     
     - returns: The request
     */
    
    public func responseSerializable<T:Serializable>(completionHandler: ApiResult<T> -> Void) -> Self {
        return validate().responseJSON(completionHandler: { (response) -> Void in
            Parser.parse(response: response, completionHandler: completionHandler)
        })
    }
    
    /**
     Adds a handler that attempts to parse the result of the request into an array of **Serializable**
     
     - parameter completionHandler:A closure that is invoked when the request is finished
     
     - returns: The request
     */
    
    public func responseSerializable<T:Serializable>(completionHandler: ApiResult<[T]> -> Void) -> Self {
        return validate().responseJSON(completionHandler: { (response) -> Void in
            Parser.parse(response: response, completionHandler: completionHandler)
        })
    }
    
    /**
     Adds a handler that ignores the response data of the request, invoking the completion handler with 
     a ApiResult without associated success data.
     
     - parameter completionHandler:A closure that is invoked when the request is finished
     
     - returns: The request
     */
    
    public func response(completionHandler: ApiResult<Void> -> Void) -> Self {
        return validate().responseVoid(completionHandler)
    }
    
    private func responseVoid(completionHandler: ApiResult<Void> -> Void) -> Self {
        return validate().response(completionHandler: { (request, response, data, error) -> Void in
            
            if error == nil {
                completionHandler(ApiResult.Success(data: ()))
            } else {
                
                let error = error ?? NSError(domain: "Serializable.Parser", code: -1, userInfo: nil)
                
                let rawResponse:String
                if let data = data {
                    rawResponse = NSString(data: data, encoding: NSUTF8StringEncoding) as? String ?? ""
                } else {
                    rawResponse = "-"
                }
                
                completionHandler(ApiResult.Error(error:Parser.Error.init(error: error, response: response, rawResponse: rawResponse, request: request))
                )
            }
        })
    }
}