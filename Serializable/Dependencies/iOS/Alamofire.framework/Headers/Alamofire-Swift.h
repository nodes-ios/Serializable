// Generated by Apple Swift version 3.0 (swiftlang-800.0.43.6 clang-800.0.38)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSOperationQueue;
@class NSURLSessionTask;
@class NSProgress;
@class NSError;
@class NSURLCredential;
@class NSURLSession;
@class NSHTTPURLResponse;
@class NSInputStream;
@class NSURLAuthenticationChallenge;

/**
  The task delegate is responsible for handling all delegate callbacks for the underlying task as well as
  executing all operations attached to the serial operation queue upon task completion.
*/
SWIFT_CLASS("_TtC9Alamofire12TaskDelegate")
@interface TaskDelegate : NSObject
/**
  The serial operation queue used to execute all operations after the task completes.
*/
@property (nonatomic, readonly, strong) NSOperationQueue * _Nonnull queue;
@property (nonatomic, strong) NSURLSessionTask * _Nonnull task;
@property (nonatomic, readonly, strong) NSProgress * _Nonnull progress;
@property (nonatomic, readonly, copy) NSData * _Nullable data;
@property (nonatomic, strong) NSError * _Nullable error;
@property (nonatomic, strong) NSURLCredential * _Nullable credential;
- (nonnull instancetype)initWithTask:(NSURLSessionTask * _Nonnull)task OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, copy) NSURLRequest * _Nullable (^ _Nullable taskWillPerformHTTPRedirection)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, NSHTTPURLResponse * _Nonnull, NSURLRequest * _Nonnull);
@property (nonatomic, copy) NSInputStream * _Nullable (^ _Nullable taskNeedNewBodyStream)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull);
@property (nonatomic, copy) void (^ _Nullable taskDidCompleteWithError)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, NSError * _Nullable);
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task willPerformHTTPRedirection:(NSHTTPURLResponse * _Nonnull)response newRequest:(NSURLRequest * _Nonnull)request completionHandler:(void (^ _Nonnull)(NSURLRequest * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task needNewBodyStream:(void (^ _Nonnull)(NSInputStream * _Nullable))completionHandler;
- (void)urlSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class NSURLSessionDataTask;
@class NSURLResponse;
@class NSURLSessionDownloadTask;
@class NSCachedURLResponse;

SWIFT_CLASS("_TtC9Alamofire16DataTaskDelegate")
@interface DataTaskDelegate : TaskDelegate <NSURLSessionDataDelegate>
@property (nonatomic, readonly, strong) NSURLSessionDataTask * _Nullable dataTask;
@property (nonatomic, readonly, copy) NSData * _Nullable data;
@property (nonatomic, copy) void (^ _Nullable dataProgress)(int64_t, int64_t, int64_t);
@property (nonatomic, copy) void (^ _Nullable dataStream)(NSData * _Nonnull);
- (nonnull instancetype)initWithTask:(NSURLSessionTask * _Nonnull)task OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, copy) NSURLSessionResponseDisposition (^ _Nullable dataTaskDidReceiveResponse)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSURLResponse * _Nonnull);
@property (nonatomic, copy) void (^ _Nullable dataTaskDidBecomeDownloadTask)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSURLSessionDownloadTask * _Nonnull);
@property (nonatomic, copy) void (^ _Nullable dataTaskDidReceiveData)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSData * _Nonnull);
@property (nonatomic, copy) NSCachedURLResponse * _Nullable (^ _Nullable dataTaskWillCacheResponse)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSCachedURLResponse * _Nonnull);
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveResponse:(NSURLResponse * _Nonnull)response completionHandler:(void (^ _Nonnull)(NSURLSessionResponseDisposition))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didBecomeDownloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask;
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveData:(NSData * _Nonnull)data;
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask willCacheResponse:(NSCachedURLResponse * _Nonnull)proposedResponse completionHandler:(void (^ _Nonnull)(NSCachedURLResponse * _Nullable))completionHandler;
@end


SWIFT_CLASS("_TtC9Alamofire20DownloadTaskDelegate")
@interface DownloadTaskDelegate : TaskDelegate <NSURLSessionDownloadDelegate>
@property (nonatomic, readonly, strong) NSURLSessionDownloadTask * _Nullable downloadTask;
@property (nonatomic, copy) void (^ _Nullable downloadProgress)(int64_t, int64_t, int64_t);
@property (nonatomic, copy) NSData * _Nullable resumeData;
@property (nonatomic, readonly, copy) NSData * _Nullable data;
@property (nonatomic, copy) NSURL * _Nonnull (^ _Nullable downloadTaskDidFinishDownloadingToURL)(NSURLSession * _Nonnull, NSURLSessionDownloadTask * _Nonnull, NSURL * _Nonnull);
@property (nonatomic, copy) void (^ _Nullable downloadTaskDidWriteData)(NSURLSession * _Nonnull, NSURLSessionDownloadTask * _Nonnull, int64_t, int64_t, int64_t);
@property (nonatomic, copy) void (^ _Nullable downloadTaskDidResumeAtOffset)(NSURLSession * _Nonnull, NSURLSessionDownloadTask * _Nonnull, int64_t, int64_t);
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didFinishDownloadingToURL:(NSURL * _Nonnull)location;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didWriteData:(int64_t)bytesWritten totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didResumeAtOffset:(int64_t)fileOffset expectedTotalBytes:(int64_t)expectedTotalBytes;
- (nonnull instancetype)initWithTask:(NSURLSessionTask * _Nonnull)task OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSError (SWIFT_EXTENSION(Alamofire))
- (nonnull instancetype)initWithDomain:(NSString * _Nonnull)domain code:(NSInteger)code failureReason:(NSString * _Nonnull)failureReason;
@end

@class NSURLSessionStreamTask;
@class NSOutputStream;

/**
  Responsible for handling all delegate callbacks for the underlying session.
*/
SWIFT_CLASS("_TtC9Alamofire15SessionDelegate")
@interface SessionDelegate : NSObject
/**
  Overrides default behavior for NSURLSessionDelegate method \code
  URLSession:didBecomeInvalidWithError:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable sessionDidBecomeInvalidWithError)(NSURLSession * _Nonnull, NSError * _Nullable);
/**
  Overrides all behavior for NSURLSessionDelegate method \code
  URLSession:didReceiveChallenge:completionHandler:
  \endcode and requires the caller to call the \code
  completionHandler
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable sessionDidReceiveChallengeWithCompletion)(NSURLSession * _Nonnull, NSURLAuthenticationChallenge * _Nonnull, void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable));
/**
  Overrides default behavior for NSURLSessionDelegate method \code
  URLSessionDidFinishEventsForBackgroundURLSession:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable sessionDidFinishEventsForBackgroundURLSession)(NSURLSession * _Nonnull);
/**
  Overrides default behavior for NSURLSessionTaskDelegate method \code
  URLSession:task:willPerformHTTPRedirection:newRequest:completionHandler:
  \endcode.
*/
@property (nonatomic, copy) NSURLRequest * _Nullable (^ _Nullable taskWillPerformHTTPRedirection)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, NSHTTPURLResponse * _Nonnull, NSURLRequest * _Nonnull);
/**
  Overrides all behavior for NSURLSessionTaskDelegate method \code
  URLSession:task:willPerformHTTPRedirection:newRequest:completionHandler:
  \endcode and
  requires the caller to call the \code
  completionHandler
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable taskWillPerformHTTPRedirectionWithCompletion)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, NSHTTPURLResponse * _Nonnull, NSURLRequest * _Nonnull, void (^ _Nonnull)(NSURLRequest * _Nullable));
/**
  Overrides all behavior for NSURLSessionTaskDelegate method \code
  URLSession:task:didReceiveChallenge:completionHandler:
  \endcode and
  requires the caller to call the \code
  completionHandler
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable taskDidReceiveChallengeWithCompletion)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, NSURLAuthenticationChallenge * _Nonnull, void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable));
/**
  Overrides default behavior for NSURLSessionTaskDelegate method \code
  URLSession:session:task:needNewBodyStream:
  \endcode.
*/
@property (nonatomic, copy) NSInputStream * _Nullable (^ _Nullable taskNeedNewBodyStream)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull);
/**
  Overrides all behavior for NSURLSessionTaskDelegate method \code
  URLSession:session:task:needNewBodyStream:
  \endcode and
  requires the caller to call the \code
  completionHandler
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable taskNeedNewBodyStreamWithCompletion)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, void (^ _Nonnull)(NSInputStream * _Nullable));
/**
  Overrides default behavior for NSURLSessionTaskDelegate method \code
  URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable taskDidSendBodyData)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, int64_t, int64_t, int64_t);
/**
  Overrides default behavior for NSURLSessionTaskDelegate method \code
  URLSession:task:didCompleteWithError:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable taskDidComplete)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, NSError * _Nullable);
/**
  Overrides default behavior for NSURLSessionDataDelegate method \code
  URLSession:dataTask:didReceiveResponse:completionHandler:
  \endcode.
*/
@property (nonatomic, copy) NSURLSessionResponseDisposition (^ _Nullable dataTaskDidReceiveResponse)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSURLResponse * _Nonnull);
/**
  Overrides all behavior for NSURLSessionDataDelegate method \code
  URLSession:dataTask:didReceiveResponse:completionHandler:
  \endcode and
  requires caller to call the \code
  completionHandler
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable dataTaskDidReceiveResponseWithCompletion)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSURLResponse * _Nonnull, void (^ _Nonnull)(NSURLSessionResponseDisposition));
/**
  Overrides default behavior for NSURLSessionDataDelegate method \code
  URLSession:dataTask:didBecomeDownloadTask:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable dataTaskDidBecomeDownloadTask)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSURLSessionDownloadTask * _Nonnull);
/**
  Overrides default behavior for NSURLSessionDataDelegate method \code
  URLSession:dataTask:didReceiveData:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable dataTaskDidReceiveData)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSData * _Nonnull);
/**
  Overrides default behavior for NSURLSessionDataDelegate method \code
  URLSession:dataTask:willCacheResponse:completionHandler:
  \endcode.
*/
@property (nonatomic, copy) NSCachedURLResponse * _Nullable (^ _Nullable dataTaskWillCacheResponse)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSCachedURLResponse * _Nonnull);
/**
  Overrides all behavior for NSURLSessionDataDelegate method \code
  URLSession:dataTask:willCacheResponse:completionHandler:
  \endcode and
  requires caller to call the \code
  completionHandler
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable dataTaskWillCacheResponseWithCompletion)(NSURLSession * _Nonnull, NSURLSessionDataTask * _Nonnull, NSCachedURLResponse * _Nonnull, void (^ _Nonnull)(NSCachedURLResponse * _Nullable));
/**
  Overrides default behavior for NSURLSessionDownloadDelegate method \code
  URLSession:downloadTask:didFinishDownloadingToURL:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable downloadTaskDidFinishDownloadingToURL)(NSURLSession * _Nonnull, NSURLSessionDownloadTask * _Nonnull, NSURL * _Nonnull);
/**
  Overrides default behavior for NSURLSessionDownloadDelegate method \code
  URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable downloadTaskDidWriteData)(NSURLSession * _Nonnull, NSURLSessionDownloadTask * _Nonnull, int64_t, int64_t, int64_t);
/**
  Overrides default behavior for NSURLSessionDownloadDelegate method \code
  URLSession:downloadTask:didResumeAtOffset:expectedTotalBytes:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable downloadTaskDidResumeAtOffset)(NSURLSession * _Nonnull, NSURLSessionDownloadTask * _Nonnull, int64_t, int64_t);
/**
  Overrides default behavior for NSURLSessionStreamDelegate method \code
  URLSession:readClosedForStreamTask:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable streamTaskReadClosed)(NSURLSession * _Nonnull, NSURLSessionStreamTask * _Nonnull);
/**
  Overrides default behavior for NSURLSessionStreamDelegate method \code
  URLSession:writeClosedForStreamTask:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable streamTaskWriteClosed)(NSURLSession * _Nonnull, NSURLSessionStreamTask * _Nonnull);
/**
  Overrides default behavior for NSURLSessionStreamDelegate method \code
  URLSession:betterRouteDiscoveredForStreamTask:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable streamTaskBetterRouteDiscovered)(NSURLSession * _Nonnull, NSURLSessionStreamTask * _Nonnull);
/**
  Overrides default behavior for NSURLSessionStreamDelegate method \code
  URLSession:streamTask:didBecomeInputStream:outputStream:
  \endcode.
*/
@property (nonatomic, copy) void (^ _Nullable streamTaskDidBecomeInputStream)(NSURLSession * _Nonnull, NSURLSessionStreamTask * _Nonnull, NSInputStream * _Nonnull, NSOutputStream * _Nonnull);
/**
  Initializes the \code
  SessionDelegate
  \endcode instance.

  returns:
  The new \code
  SessionDelegate
  \endcode instance.
*/
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
/**
  Returns a \code
  Bool
  \endcode indicating whether the \code
  SessionDelegate
  \endcode implements or inherits a method that can respond
  to a specified message.
  \param selector A selector that identifies a message.


  returns:
  \code
  true
  \endcode if the receiver implements or inherits a method that can respond to selector, otherwise \code
  false
  \endcode.
*/
- (BOOL)respondsToSelector:(SEL _Nonnull)selector;
@end


@interface SessionDelegate (SWIFT_EXTENSION(Alamofire)) <NSURLSessionDownloadDelegate>
/**
  Tells the delegate that a download task has finished downloading.
  \param session The session containing the download task that finished.

  \param downloadTask The download task that finished.

  \param location A file URL for the temporary file. Because the file is temporary, you must either
  open the file for reading or move it to a permanent location in your app’s sandbox
  container directory before returning from this delegate method.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didFinishDownloadingToURL:(NSURL * _Nonnull)location;
/**
  Periodically informs the delegate about the download’s progress.
  \param session The session containing the download task.

  \param downloadTask The download task.

  \param bytesWritten The number of bytes transferred since the last time this delegate
  method was called.

  \param totalBytesWritten The total number of bytes transferred so far.

  \param totalBytesExpectedToWrite The expected length of the file, as provided by the Content-Length
  header. If this header was not provided, the value is
  \code
  NSURLSessionTransferSizeUnknown
  \endcode.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didWriteData:(int64_t)bytesWritten totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
/**
  Tells the delegate that the download task has resumed downloading.
  \param session The session containing the download task that finished.

  \param downloadTask The download task that resumed. See explanation in the discussion.

  \param fileOffset If the file’s cache policy or last modified date prevents reuse of the
  existing content, then this value is zero. Otherwise, this value is an
  integer representing the number of bytes on disk that do not need to be
  retrieved again.

  \param expectedTotalBytes The expected length of the file, as provided by the Content-Length header.
  If this header was not provided, the value is NSURLSessionTransferSizeUnknown.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session downloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask didResumeAtOffset:(int64_t)fileOffset expectedTotalBytes:(int64_t)expectedTotalBytes;
@end


@interface SessionDelegate (SWIFT_EXTENSION(Alamofire)) <NSURLSessionDelegate>
/**
  Tells the delegate that the session has been invalidated.
  \param session The session object that was invalidated.

  \param error The error that caused invalidation, or nil if the invalidation was explicit.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session didBecomeInvalidWithError:(NSError * _Nullable)error;
/**
  Requests credentials from the delegate in response to a session-level authentication request from the
  remote server.
  \param session The session containing the task that requested authentication.

  \param challenge An object that contains the request for authentication.

  \param completionHandler A handler that your delegate method must call providing the disposition
  and credential.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
/**
  Tells the delegate that all messages enqueued for a session have been delivered.
  \param session The session that no longer has any outstanding requests.

*/
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession * _Nonnull)session;
@end


@interface SessionDelegate (SWIFT_EXTENSION(Alamofire)) <NSURLSessionStreamDelegate>
/**
  Tells the delegate that the read side of the connection has been closed.
  \param session The session.

  \param streamTask The stream task.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session readClosedForStreamTask:(NSURLSessionStreamTask * _Nonnull)streamTask;
/**
  Tells the delegate that the write side of the connection has been closed.
  \param session The session.

  \param streamTask The stream task.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session writeClosedForStreamTask:(NSURLSessionStreamTask * _Nonnull)streamTask;
/**
  Tells the delegate that the system has determined that a better route to the host is available.
  \param session The session.

  \param streamTask The stream task.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session betterRouteDiscoveredForStreamTask:(NSURLSessionStreamTask * _Nonnull)streamTask;
/**
  Tells the delegate that the stream task has been completed and provides the unopened stream objects.
  \param session The session.

  \param streamTask The stream task.

  \param inputStream The new input stream.

  \param outputStream The new output stream.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session streamTask:(NSURLSessionStreamTask * _Nonnull)streamTask didBecomeInputStream:(NSInputStream * _Nonnull)inputStream outputStream:(NSOutputStream * _Nonnull)outputStream;
@end


@interface SessionDelegate (SWIFT_EXTENSION(Alamofire)) <NSURLSessionDataDelegate>
/**
  Tells the delegate that the data task received the initial reply (headers) from the server.
  \param session The session containing the data task that received an initial reply.

  \param dataTask The data task that received an initial reply.

  \param response A URL response object populated with headers.

  \param completionHandler A completion handler that your code calls to continue the transfer, passing a
  constant to indicate whether the transfer should continue as a data task or
  should become a download task.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveResponse:(NSURLResponse * _Nonnull)response completionHandler:(void (^ _Nonnull)(NSURLSessionResponseDisposition))completionHandler;
/**
  Tells the delegate that the data task was changed to a download task.
  \param session The session containing the task that was replaced by a download task.

  \param dataTask The data task that was replaced by a download task.

  \param downloadTask The new download task that replaced the data task.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didBecomeDownloadTask:(NSURLSessionDownloadTask * _Nonnull)downloadTask;
/**
  Tells the delegate that the data task has received some of the expected data.
  \param session The session containing the data task that provided data.

  \param dataTask The data task that provided data.

  \param data A data object containing the transferred data.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveData:(NSData * _Nonnull)data;
/**
  Asks the delegate whether the data (or upload) task should store the response in the cache.
  \param session The session containing the data (or upload) task.

  \param dataTask The data (or upload) task.

  \param proposedResponse The default caching behavior. This behavior is determined based on the current
  caching policy and the values of certain received headers, such as the Pragma
  and Cache-Control headers.

  \param completionHandler A block that your handler must call, providing either the original proposed
  response, a modified version of that response, or NULL to prevent caching the
  response. If your delegate implements this method, it must call this completion
  handler; otherwise, your app leaks memory.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask willCacheResponse:(NSCachedURLResponse * _Nonnull)proposedResponse completionHandler:(void (^ _Nonnull)(NSCachedURLResponse * _Nullable))completionHandler;
@end


@interface SessionDelegate (SWIFT_EXTENSION(Alamofire)) <NSURLSessionTaskDelegate>
/**
  Tells the delegate that the remote server requested an HTTP redirect.
  \param session The session containing the task whose request resulted in a redirect.

  \param task The task whose request resulted in a redirect.

  \param response An object containing the server’s response to the original request.

  \param request A URL request object filled out with the new location.

  \param completionHandler A closure that your handler should call with either the value of the request
  parameter, a modified URL request object, or NULL to refuse the redirect and
  return the body of the redirect response.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task willPerformHTTPRedirection:(NSHTTPURLResponse * _Nonnull)response newRequest:(NSURLRequest * _Nonnull)request completionHandler:(void (^ _Nonnull)(NSURLRequest * _Nullable))completionHandler;
/**
  Requests credentials from the delegate in response to an authentication request from the remote server.
  \param session The session containing the task whose request requires authentication.

  \param task The task whose request requires authentication.

  \param challenge An object that contains the request for authentication.

  \param completionHandler A handler that your delegate method must call providing the disposition
  and credential.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
/**
  Tells the delegate when a task requires a new request body stream to send to the remote server.
  \param session The session containing the task that needs a new body stream.

  \param task The task that needs a new body stream.

  \param completionHandler A completion handler that your delegate method should call with the new body stream.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task needNewBodyStream:(void (^ _Nonnull)(NSInputStream * _Nullable))completionHandler;
/**
  Periodically informs the delegate of the progress of sending body content to the server.
  \param session The session containing the data task.

  \param task The data task.

  \param bytesSent The number of bytes sent since the last time this delegate method was called.

  \param totalBytesSent The total number of bytes sent so far.

  \param totalBytesExpectedToSend The expected length of the body data.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
/**
  Tells the delegate that the task finished transferring data.
  \param session The session containing the task whose request finished transferring data.

  \param task The task whose request finished transferring data.

  \param error If an error occurred, an error object indicating how the transfer failed, otherwise nil.

*/
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;
@end



@interface NSURLSession (SWIFT_EXTENSION(Alamofire))
@end

@class NSURLSessionUploadTask;

SWIFT_CLASS("_TtC9Alamofire18UploadTaskDelegate")
@interface UploadTaskDelegate : DataTaskDelegate
@property (nonatomic, readonly, strong) NSURLSessionUploadTask * _Nullable uploadTask;
@property (nonatomic, copy) void (^ _Null_unspecified uploadProgress)(int64_t, int64_t, int64_t);
@property (nonatomic, copy) void (^ _Nullable taskDidSendBodyData)(NSURLSession * _Nonnull, NSURLSessionTask * _Nonnull, int64_t, int64_t, int64_t);
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (nonnull instancetype)initWithTask:(NSURLSessionTask * _Nonnull)task OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop
