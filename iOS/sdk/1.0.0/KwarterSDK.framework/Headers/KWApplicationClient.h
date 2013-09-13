//
//  KWApplicationClient.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 3/12/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWApplication.h"

extern NSString *const KWApplicationDidUpdateNotificationName;

typedef void (^KWApplicationClientCompletionBlock)(id result, NSError *error);

/**
 * Client for API calls relative to the application (`KWApplication` objects).
 *
 * @since 1.0.0
 */
@interface KWApplicationClient : NSObject

/**
 * Returns the current app description asynchronously.
 * Will launch the notification `KWApplicationDidUpdateNotificationName` when the app updates.
 * @param block The block that will be called when the client will complete the request.
 */
- (void)getCurrentApplicationCompletion:(KWApplicationClientCompletionBlock)block;

/**
 * Returns the app that has the current client `identifier` if it's present locally, else nil.
 */
+ (KWApplication *)currentApplication;

/**
 * Returns the app executable name from the `CFBundleExecutable` property without the `-Beta`.
 */
+ (NSString *)executableName;

/**
 * Returns the app display name from the `CFBundleDisplayName` property.
 */
+ (NSString *)displayName;

@end
