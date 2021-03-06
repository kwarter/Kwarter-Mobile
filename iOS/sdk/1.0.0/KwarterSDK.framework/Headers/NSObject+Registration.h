//
//  NSObject+Registration.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 30/11/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A category which makes use of the class_conformsToProtocol macro
 * to recover an NSArray of all Class objects found within the project
 * that conform to the a Protocol.
 *
 * @since 1.0.0
 */
@interface NSObject (Registration)

/**
 * @param protocol The Protocol to check for conformity to.
 * @return An array containing all of the Classes conforming
 * to the provided Protocol.
 */
+ (NSArray *)classesConformingTo:(Protocol *)protocol;

@end
