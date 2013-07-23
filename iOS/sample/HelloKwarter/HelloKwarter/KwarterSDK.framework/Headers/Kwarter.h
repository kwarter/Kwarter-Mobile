//
//  Kwarter.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 2/10/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This is the primary point of access for the Kwarter SDK. This
 * class is responsible for initializing all required components.
 *
 * @since 1.0.0
 */
@interface Kwarter : NSObject

/**
 * A Boolean value that indicates whether or not Kwarter servers are currently reachable.
 */
@property (nonatomic, assign, readonly, getter=isServerReachable) BOOL serverReachable;

/**
 * Starts the SDK, this method should be called at the beginning of the application:didFinishLaunchingWithOptions:.
 * The default enviroment is KWEnvironmentLive, it can be changed via the KWEnvironment class.
 *
 * By defalut the SDK start on the live environment, you can also specify and alternative environment.
 * @see KWEnvironment
 *
 * @param clientId The client identifier.
 */
+ (void)startWithClientId:(NSString *)clientId;

@end
