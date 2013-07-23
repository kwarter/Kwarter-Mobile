//
//  KWAnalyticsWorker.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 2/6/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWAnalytics.h"

/**
 * This is the protocol which your class must adhere to
 * in order to be dynamically added to KWAnalytics. Each
 * instance of KWAnalyticsWorker found in your project will be
 * added to KWAnalytics.
 *
 * Not all methods are required.
 *
 * @since 1.0.0
 */
@protocol KWAnalyticsWorker <NSObject>

/** @name Required Methods */

@required

/**
 * This gives the KWAnalyticsWorker an opportunity to
 * initialize the underlying analytics library among other
 * variables.
 */
- (void)startSession;

/**
 * Return YES if this KWAnalyticsWorker is prepared to start.
 * Returning NO will result in being excluded from the array
 * of KWAnalyticsWorker instances inside of KWAnalytics.
 *
 * @return YES if the worker is prepared to start the session, NO otherwise
 */
- (BOOL)canStartSession;

/** @name Optional Methods */

@optional

/**
 * Log a page view.
 * 
 * @param pageName The name of the page being viewed.
 * @param infos Additional information provided by the client.
 */
- (void)logPageView:(NSString *)pageName infos:(NSDictionary *)infos;

/**
 * Log an event.
 *
 * @param eventName The name of the event.
 * @param actionName The name of an action performed with this event.
 * @param infos Additional information provided by the client.
 */
- (void)logEvent:(NSString *)eventName action:(NSString *)actionName infos:(NSDictionary *)infos;

/**
 * Log an event with error.
 *
 * @param eventName The name of the event.
 * @param actionResult The name of an action performed with this event.
 * @param actionError An error which occurred with this event.
 * @param infos Additional information provided by the client.
 */
- (void)logEvent:(NSString *)eventName result:(NSString *)actionResult error:(NSError *)actionError infos:(NSDictionary *)infos;

/**
 * Log an error.
 *
 * @param errorId An error identifier.
 * @param message A message describing the error.
 * @param exception The exception which produced the error.
 */
- (void)logError:(NSString *)errorId message:(NSString *)message exception:(NSException *)exception;

/**
 * Corresponding to UIApplication:application:didEnterForeground.
 */
- (void)onApplicationEnterForeground;

/**
 * Corresponding to UIApplication:application:didResignActive.
 */
- (void)onApplicationResignActive;

/**
 * Corresponding to UIApplication:application:didTerminate.
 */
- (void)onApplicationTerminate;

/**
 * Gives the KWAnalyticsWorker an opportunity to associate with the currently
 * logged in user.
 *
 * @param userIdentifier The user's unique Kwarter identifier.
 */
- (void)setUserIdentifier:(NSString *)userIdentifier;

/**
 * Gives the KWAnalyticsWorker an opportunity to relay the user's age.
 *
 * @param age The user's provided age.
 */
- (void)setUserAge:(NSUInteger)age;

/**
 * Gives the KWAnalyticsWorker an opportunity to relay the user's gender.
 *
 * @param gender value can be KWUserGenderMale, KWUserGenderFemale or KWUserGenderUnknown
 * found in KWUser.
 */
- (void)setUserGender:(NSString *)gender;

@end
