//
//  KWReminderManager.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 2/8/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWevent.h"

/**
 * The key used within userInfo when posting the notification.
 */
extern NSString *const eventIdentifier;

/**
 * This manager provides convenience methods for managing user-facing
 * reminders related to events.
 *
 * @since 1.0
 */
@interface KWReminderManager : NSObject

/**
 * Sets a reminder for a particular KWEvent. The starting date
 * is used as the trigger time for the reminder. It will place the
 * KWEvent's.
 *
 * @param event the KWEvent for which the reminder is related to
 * @param message message to display
 * @param soundName the name of a sound file to play when reminding the user
 */
+ (void)scheduleReminderForEvent:(KWEvent *)event alertMessage:(NSString *)message soundName:(NSString *)soundName;

/**
 * Cancels an existing reminder and prevents it from firing.
 *
 * @param event The KWEvent for which the reminder is related to.
 */
+ (void)cancelReminderForEvent:(KWEvent *)event;

/**
 * @param event The KWEvent to check for an existing reminder.
 * @return YES if a reminder has already been set for the given KWEvent.
 */
+ (BOOL)isReminderScheduledForEvent:(KWEvent *)event;

@end
