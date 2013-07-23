//
//  KWAnalytics.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 03/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * KWAnalytics behaves as an arbiter between app-level event logging
 * and the analytics libraries which actually perform the logging.
 *
 * Provide one or more classes which adhere to the KWAnalyticsWorker
 * protocol in your project and they will be instantiated and employed
 * by KWAnalytics automatically.
 *
 * @since 1.0.0
 */
@interface KWAnalytics : NSObject

/**
 * Singleton to access the KWAnalytics default instance.
 *
 * @return The shared instance of KWAnalytics.
 */
+ (KWAnalytics *)defaultInstance;

/**
 * This method allocates and initializes each KWAnalyticsWorker, it must
 * be called before logging events or page views.
 *
 * Note: Don't call this more than once.
 */
- (void)startSession;

/**
 * Logs a single page view, this can be anything you qualify as a page.
 * either a full screen ViewController or a modal or any interface
 * worth logging a view for.
 *
 * @param pageName The name which represents this page.
 * @param infos Additional information.
 */
- (void)logPageView:(NSString *)pageName infos:(NSDictionary *)infos;

/**
 * Log an event which may have a name, action and additional info. An event
 * should be more than a page visit, use #logPageView for that purpose.
 *
 * @param eventName The name of the event.
 * @param actionName The name of the action.
 * @param infos Additional information.
 */
- (void)logEvent:(NSString *)eventName action:(NSString *)actionName infos:(NSDictionary *)infos;

/**
 * This method logs similarly to the previous, however, it also provides
 * the capacity to log an NSError.
 *
 * @param eventName The name of the event.
 * @param actionResult The name of the action result.
 * @param actionError An error to log with this event.
 * @param infos Additional information.
 */
- (void)logEvent:(NSString *)eventName result:(NSString *)actionResult error:(NSError *)actionError infos:(NSDictionary *)infos;

@end
