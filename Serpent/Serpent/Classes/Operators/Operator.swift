//
//  Operator.swift
//  Serializable
//
//  Created by Chris Combs on 16/02/16.
//  Copyright © 2016 Nodes. All rights reserved.
//

import Foundation


// MARK: - Custom Operators -

precedencegroup SerializablePrecedence {
	associativity: left
}

infix operator <== : SerializablePrecedence

// For Encodable
public func <==<T>(left: (dict: NSMutableDictionary, key: String), right: T?) {
    left.dict.setValue(right, forKey: left.key)
}

public func <==<T: Encodable>(left: (dict: NSMutableDictionary, key: String), right: T?) {
    left.dict.setValue(right?.encodableRepresentation(), forKey: left.key)
}

public func <==<T: StringInitializable>(left: (dict: NSMutableDictionary, key: String), right: T?) {
    left.dict.setValue(right?.stringRepresentation(), forKey: left.key)
}

public func <==<T>(left: (dict: NSMutableDictionary, key: String), right: T?) where T:Sequence, T.Iterator.Element: Encodable {
	left.dict.setValue(right?.encodableRepresentation(), forKey: left.key)
}

public func <==<T: RawRepresentable>(left: (dict: NSMutableDictionary, key: String), right: T?) {
	left.dict.setValue(right?.encodableRepresentation(), forKey: left.key)
}

// For Decodable

// Primitive
public func <==<T, S>(left: inout T?, right: (instance: S, dict: NSDictionary?, key: String)) where S: Decodable {
    let value: T? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

public func <==<T, S>(left: inout T, right: (instance: S, dict: NSDictionary?, key: String)) where S: Decodable {
    let value: T? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

// Serializable
public func <==<T, S>(left: inout T?, right: (instance: S, dict: NSDictionary?, key: String)) where T: Decodable, S: Decodable {
    let value: T? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

public func <==<T, S>(left: inout T, right: (instance: S, dict: NSDictionary?, key: String)) where T: Decodable, S: Decodable {
    let value: T? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

// Enum
public func <==<T, S>(left: inout T?, right: (instance: S, dict: NSDictionary?, key: String)) where T: RawRepresentable, S: Decodable {
    let value: T? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

public func <==<T, S>(left: inout T, right: (instance: S, dict: NSDictionary?, key: String)) where T: RawRepresentable, S: Decodable {
    let value: T? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

public func <==<T, S>(left: inout [T]?, right: (instance: S, dict: NSDictionary?, key: String)) where T: RawRepresentable, S: Decodable {
    let value: [T]? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

public func <==<T, S>(left: inout [T], right: (instance: S, dict: NSDictionary?, key: String)) where T: RawRepresentable, S: Decodable {
    let value: [T]? = right.instance.mapped(right.dict, key: right.key)
    left = value ?? left
}

// [Serializable]
public func <==<T, S>(left: inout T?, right: (instance: S, dict: NSDictionary?, key: String)) where T:Sequence, T.Iterator.Element: Decodable, S: Decodable {
	let value: T? = right.instance.mapped(right.dict, key: right.key)
	left = value ?? left
}

public func <==<T, S>(left: inout T, right: (instance: S, dict: NSDictionary?, key: String)) where T:Sequence, T.Iterator.Element: Decodable, S: Decodable {
	let value: T? = right.instance.mapped(right.dict, key: right.key)
	left = value ?? left
}

// StringInitializable

public func <==<T, S>(left: inout T?, right: (instance: S, dict: NSDictionary?, key: String)) where T: StringInitializable, S: Decodable {
	let value: T? = right.instance.mapped(right.dict, key: right.key)
	left = value ?? left
}

public func <==<T, S>(left: inout T, right: (instance: S, dict: NSDictionary?, key: String)) where T: StringInitializable, S: Decodable {
	let value: T? = right.instance.mapped(right.dict, key: right.key)
	left = value ?? left
}

// HexInitializable

public func <==<T, S>(left: inout T?, right: (instance: S, dict: NSDictionary?, key: String)) where T: HexInitializable, S: Decodable {
	let value: T? = right.instance.mapped(right.dict, key: right.key)
	left = value ?? left
}

public func <==<T, S>(left: inout T, right: (instance: S, dict: NSDictionary?, key: String)) where T: HexInitializable, S: Decodable {
	let value: T? = right.instance.mapped(right.dict, key: right.key)
	left = value ?? left
}
