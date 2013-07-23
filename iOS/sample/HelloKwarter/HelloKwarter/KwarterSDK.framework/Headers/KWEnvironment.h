//
//  KWEnvironment.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 16/11/12.
//  Copyright (c) 2012 Ludovic Landry. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Represent the Live environment configuration mode.
 */
extern NSString *const KWEnvironmentLive;

/**
 * Represent the Beta environment configuration mode.
 */
extern NSString *const KWEnvironmentBeta;

/**
 * Key constant used in the environment configuration to set the api hostname. It's value
 * is a string representig the URL.
 */
extern NSString *const KWEnvironmentKeyApiHostname;

/**
 * Key constant used in the environment configuration to enable the log debugging in the 
 * mappers. It's value is a boolean to enable or disable the logs.
 */
extern NSString *const KWEnvironmentKeyDebugMappers;

/**
 * Key constant used in the environment configuration to enable the log debugging in the event
 * real time controller. It's value is a boolean to enable or disable the logs.
 */
extern NSString *const KWEnvironmentKeyDebugERTC;

/**
 * Key constant used in the environment configuration to enable the log debugging in verbose.
 * mode. It's value is a boolean to enable or disable the logs.
 */
extern NSString *const KWEnvironmentKeyDebugVerbose;

/**
 * A KWEnvironment represents the runtime environment
 * of your application. The Kwarter SDK provides two default modes:
 *
 * - `KWEnvironmentLive` for live deployement.
 * - `KWEnvironmentBeta` for testing.
 *
 * These environments provide, among other things, the network
 * base address for API requests.
 *
 * You can also create your own custom environment is you have a dedicated platform
 * for your application. An environment configuration is a plist file with all the 
 * specific keys inside a bundle.
 *
 * The default environment configuration is the bundle `DefaultEnvironments.bundle` which 
 * includes Live.plist and Beta.plist respectively `KWEnvironmentLive` and `KWEnvironmentBeta`.
 *
 * To create your own environment create a `Environments.bundle` containing the differents
 * configuration inside plist files and set the `currentEnvironment` using this plist file name.
 * You can also reuse and override the defaults valuse for `KWEnvironmentLive` and `KWEnvironmentBeta`.
 *
 * The keys available as configuration in the plist file are the following:
 *
 * - `api.hostname` which contains the base URL for the differents API calls as http://my-server.com
 * represented by the constant `KWEnvironmentKeyApiHostname` as a String value.
 * - `debug.mappers` is a Boolean value to activate the debug logs for all the mapping internal mechanism.
 * - `debug.ertc` is a Boolean value to activate the debug logs for the KWEventRealTimeControllerDelegate calls.
 * - `debug.verbose` is a Boolean value to activate more debug logs.
 *
 * @since 1.0.0
 */
@interface KWEnvironment : NSObject

/**
 * The current environment, either KWEnvironmentLive, KWEnvironmentBeta or your own environment key.
 *
 * To create your own environment create a `Environments.bundle` containing the differents
 * configuration inside plist files and set the `currentEnvironment` using this plist file name.
 * You can also reuse and override the defaults valuse for `KWEnvironmentLive` and `KWEnvironmentBeta`.
 *
 * The keys available as configuration for the plist file are:
 *
 * - `api.hostname` which contains the base URL for the differents API calls as http://my-server.com
 * represented by the constant `KWEnvironmentKeyApiHostname` as a String value.
 * - `debug.mappers` is a Boolean value to activate the debug logs for all the mapping internal mechanism.
 * - `debug.ertc` is a Boolean value to activate the debug logs for the KWEventRealTimeControllerDelegate calls.
 * - `debug.verbose` is a Boolean value to activate more debug logs.
 */
@property (nonatomic, strong) NSString *currentEnvironment;

/**
 * Recover a shared instance of KWEnvironment.
 */
+ (KWEnvironment *)sharedEnvironment;

/**
 * A dictionary recovered from the corresponding settings found in the environment plist.
 */
- (NSDictionary *)settings;

@end
