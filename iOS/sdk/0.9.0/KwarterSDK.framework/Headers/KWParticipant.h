//
//  KWParticipant.h
//  KwarterSDK
//
//  Created by Ludo on 27/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWEvent, KWGame;

/**
 * The model representing a user in a leaderboard.
 *
 * @since 1.0.0
 */
@interface KWParticipant : NSManagedObject

/**
 * The abbreviated version of the participant name.
 */
@property (nonatomic, strong) NSString *abbreviation;

/**
 * The short name version of the participant name.
 */
@property (nonatomic, strong) NSString *shortname;

/**
 * The identifier for this participant.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The full name of the participant.
 */
@property (nonatomic, strong) NSString *name;

/**
 * The artwork for this participant, depending on the app you may or may not have the right to use it.
 */
@property (nonatomic, strong) NSString *participantArtworkURLString;

/**
 * The set of events that this participant belongs to.
 */
@property (nonatomic, strong) NSSet *eventSet;

/**
 * The set of games that this participant belongs to.
 */
@property (nonatomic, strong) NSSet *gameSet;

/**
 * Helper method for when you need a specific length name to show for this participant.
 * @param maxLength The maximum length that the name can take.
 */
- (NSString *)nameWithLengthSmallerThan:(NSUInteger)maxLength;

@end

@interface KWParticipant (CoreDataGeneratedAccessors)

- (void)addEventSetObject:(KWEvent *)value;
- (void)removeEventSetObject:(KWEvent *)value;
- (void)addEventSet:(NSSet *)values;
- (void)removeEventSet:(NSSet *)values;

- (void)addGameSetObject:(KWGame *)value;
- (void)removeGameSetObject:(KWGame *)value;
- (void)addGameSet:(NSSet *)values;
- (void)removeGameSet:(NSSet *)values;

@end
