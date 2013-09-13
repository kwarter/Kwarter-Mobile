//
//  KWEvent.h
//  KwarterSDK
//
//  Created by Ludo on 27/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "KWLobby.h"

/**
 * A constant state string representing scheduled events.
 */
extern NSString *const KWEventStateScheduled;

/**
 * A constant state string representing live events.
 */
extern NSString *const KWEventStateLive;

/**
 * A constant state string representing events that have ended.
 */
extern NSString *const KWEventStateCompleted;

@class KWEventMaster, KWEventPeriod, KWEventType, KWGame, KWGameTemplate, KWLobby, KWParticipant, KWTagMenuItem, KWUser, KWLeaderboard;

/**
 * This model represents an event on the Kwarter platform.
 *
 * @since 1.0.0
 */
@interface KWEvent : NSManagedObject

/**
 * A human-readable description of this event.
 */
@property (nonatomic, strong) NSString *eventDescription;

/**
 * True if this event should be represented by the participant's logos or their names.
 */
@property (nonatomic, strong) NSNumber *hasArtworkTitle;

/**
 * The title of the event.
 */
@property (nonatomic, strong) NSString *title;

/**
 * Representing the location this event is taking place.
 */
@property (nonatomic, strong) NSString *locale;

/**
 * When this event began or will begin.
 */
@property (nonatomic, strong) NSDate *startDate;

/**
 * When this event will end.
 */
@property (nonatomic, strong) NSDate *endDate;

/**
 * The state of the event, different values are:
 * KWEventStateScheduled, KWEventStateLive or KWEventStateCompleted
 */
@property (nonatomic, strong) NSString *state;

/**
 * The number of Points awarded to the winning user of this event.
 */
@property (nonatomic, strong) NSNumber *victoryPoints;

/**
 * The number of Credits awarded to the winning user of this event.
 */
@property (nonatomic, strong) NSNumber *victoryCredits;

/**
 * The identifier for this event.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * A set of KWEventMaster objects linking this KWEvent to the KWUser that controls it.
 */
@property (nonatomic, strong) NSSet *eventMasterSet;

/**
 * An NSOrderedSet containing the KWParticipant objects representing the participants of this event.
 */
@property (nonatomic, strong) NSOrderedSet *participantOrderedSet;

/**
 * All the KWGame objects that have been played during this event.
 */
@property (nonatomic, strong) NSSet *gameSet;

/**
 * The set of allowable KWGameTemplate objects capable of being played during this event.
 */
@property (nonatomic, strong) NSSet *gameTemplateSet;

/**
 * A set mapping KWParticipant identifiers to their respective scores.
 */
@property (nonatomic, strong) NSDictionary *scores;

/**
 * Artwork representing the KWEvent for displaying to the user.
 */
@property (nonatomic, strong) NSString *eventArtworkURLString;

/**
 * A message shown only to the event masters.
 */
@property (nonatomic, strong) NSString *eventmastersInstructions;

/**
 * The live KWLobby that this event belongs to if it's state is KWEventStateLive.
 */
@property (nonatomic, strong) KWLobby *lobbyLive;

/**
 * The scheduled KWLobby that this event belongs to if it's state is KWEventStateScheduled.
 */
@property (nonatomic, strong) KWLobby *lobbyScheduled;

/**
 * The type of event this is.
 */
@property (nonatomic, strong) KWEventType *eventType;

/**
 * Which period this event is currently in.
 */
@property (nonatomic, strong) KWEventPeriod *period;

/**
 * A set of KWUser objects that have this KWEvent in their history.
 */
@property (nonatomic, strong) NSSet *userHistorySet;

/**
 * A set of tags to use with the menu.
 */
@property (nonatomic, strong) NSSet *tagMenuItemSet;

/**
 * An array of KWCustomMenuItem objects associated with this event.
 */
@property (nonatomic, strong) NSArray *menuItems;

/**
 * A URL which, if not nil, may be used to redirect the user to when they check-in to this event.
 */
@property (nonatomic, strong) NSString *url;

/**
 * A human-readable string representing the network that is broadcasting the event.
 */
@property (nonatomic, strong) NSString *network;

/**
 * Represents the number of Points the currently authenticated KWUser has accrued during this event.
 */
@property (nonatomic, strong) NSNumber *userPoints;

/**
 * Represents the number of Credits the currently authenticated KWUser has accrued during this event.
 */
@property (nonatomic, strong) NSNumber *userCredits;

/**
 * Set of leaderboards associated with this event. There is a default leadeboard that have the same identifier
 * as the event and optionally other leaderboards for tournaments.
 */
@property (nonatomic, retain) NSSet *leaderboardSet;

/**
 * @return `YES` if this event's state is KWEventStateLive.
 */
- (BOOL)isLive;

/**
 * @return `YES` if this event's state is KWEventStateScheduled.
 */
- (BOOL)isScheduled;

/**
 * @return a human-readable string for detailing when the event begins, i.e. "In 1 hour", "Tomorrow", etc.
 */
- (NSString *)relativeStartDate;

/**
 * Convinient method to know if the basic fields have been loaded, or if we only have a partial description of this event.
 * Can be used to display the event with the artwork, teams, and scores.
 */
- (BOOL)hasAllBasicFieldsLoaded;

/**
 * Convinient method to know if the full definition have been loaded, or if we only have a partial description of this event.
 * Can be used access all the games templates that this event have.
 */
- (BOOL)hasAllDefinitionFieldsLoaded;

@end

@interface KWEvent (CoreDataGeneratedAccessors)

- (void)addEventMasterSetObject:(KWEventMaster *)value;
- (void)removeEventMasterSetObject:(KWEventMaster *)value;
- (void)addEventMasterSet:(NSSet *)values;
- (void)removeEventMasterSet:(NSSet *)values;

- (void)insertObject:(KWParticipant *)value inparticipantOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromparticipantOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertparticipantOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeparticipantOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInparticipantOrderedSetAtIndex:(NSUInteger)idx withObject:(KWParticipant *)value;
- (void)replaceparticipantOrderedSetAtIndexes:(NSIndexSet *)indexes withparticipantOrderedSet:(NSArray *)values;
- (void)addparticipantOrderedSetObject:(KWParticipant *)value;
- (void)removeparticipantOrderedSetObject:(KWParticipant *)value;
- (void)addparticipantOrderedSet:(NSOrderedSet *)values;
- (void)removeparticipantOrderedSet:(NSOrderedSet *)values;

- (void)addGameSetObject:(KWGame *)value;
- (void)removeGameSetObject:(KWGame *)value;
- (void)addGameSet:(NSSet *)values;
- (void)removeGameSet:(NSSet *)values;

- (void)addGameTemplateSetObject:(KWGameTemplate *)value;
- (void)removeGameTemplateSetObject:(KWGameTemplate *)value;
- (void)addGameTemplateSet:(NSSet *)values;
- (void)removeGameTemplateSet:(NSSet *)values;

- (void)addUserHistorySetObject:(KWUser *)value;
- (void)removeUserHistorySetObject:(KWUser *)value;
- (void)addUserHistorySet:(NSSet *)values;
- (void)removeUserHistorySet:(NSSet *)values;

- (void)addTagMenuItemSetObject:(KWTagMenuItem *)value;
- (void)removeTagMenuItemSetObject:(KWTagMenuItem *)value;
- (void)addTagMenuItemSet:(NSSet *)values;
- (void)removeTagMenuItemSet:(NSSet *)values;

- (void)addLeaderboardSetObject:(KWLeaderboard *)value;
- (void)removeLeaderboardSetObject:(KWLeaderboard *)value;
- (void)addLeaderboardSet:(NSSet *)values;
- (void)removeLeaderboardSet:(NSSet *)values;

@end
