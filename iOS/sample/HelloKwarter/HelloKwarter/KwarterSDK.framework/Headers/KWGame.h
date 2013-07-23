//
//  KWGame.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 22/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWEvent, KWGameTemplate, KWParticipant;

/**
 * The model representing an instance of a game that was triggered for an event.
 *
 * @since 1.0.0
 */
@interface KWGame : NSManagedObject

/**
 * The identifier for this game.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The time at which this game was triggered.
 */
@property (nonatomic, strong) NSDate *triggerTime;

/**
 * The event this game belongs to.
 */
@property (nonatomic, strong) KWEvent *event;

/**
 * The template that represents this game.
 */
@property (nonatomic, strong) KWGameTemplate *gameTemplate;

/**
 * The participant that is associated with this game, if any.
 */
@property (nonatomic, strong) KWParticipant *participant;

/**
 * The end time for this game.
 */
@property (nonatomic, readonly) NSDate *endTime;

/**
 * True if the end time is in the past.
 */
@property (nonatomic, readonly) BOOL hasExpired;

/**
 * True if this game should be considered open.
 */
@property (nonatomic, readonly) BOOL isOpen;

@end
