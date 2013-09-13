//
//  NSMutableArray+WeakReferences.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 21/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This category provides methods for instantiating
 * NSMutableArray with weakly referenced items within it.
 *
 * @since 1.0.0
 */
@interface NSMutableArray (WeakReferences)

/**
 * Calls mutableArrayUsingWeakReferencesWithCapacity:capacity with
 * capacity 0.
 *
 * @return A reference to an NSMutableArray of weak references
 * with initial capacity of 0.
 */
+ (id)mutableArrayUsingWeakReferences;

/**
 * @param capacity The initial capacity of the NSMutableArray.
 * @return A new NSMutableArray using weak references with the provided
 * capacity.
 */
+ (id)mutableArrayUsingWeakReferencesWithCapacity:(NSUInteger)capacity;

@end
