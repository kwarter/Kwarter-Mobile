//
//  KWLobby.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 3/4/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWCustomLobbyItem, KWEvent;

extern NSString *const applicationLobbyIdentifier;

/**
 * The model representing a lobby. A lobby consists of
 * custom items, live events and scheduled events.
 *
 * @since 1.0.0
 */
@interface KWLobby : NSManagedObject

/**
 * The identifier for this lobby.
 */
@property (nonatomic, retain) NSString * identifier;

/**
 * An NSOrderedSet of KWEvent objects currently live and playable.
 */
@property (nonatomic, retain) NSOrderedSet *liveEventOrderedSet;

/**
 * An NSOrderedSet of KWEvent objects which represent scheduled events.
 */
@property (nonatomic, retain) NSOrderedSet *scheduledEventOrderedSet;

/**
 * An NSOrderedSet of KWCustomLobbyItem objects associated with this KWLobby.
 */
@property (nonatomic, retain) NSOrderedSet *customItemOrderedSet;

@end

@interface KWLobby (CoreDataGeneratedAccessors)

- (void)insertObject:(KWEvent *)value inLiveEventOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromLiveEventOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertLiveEventOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeLiveEventOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInLiveEventOrderedSetAtIndex:(NSUInteger)idx withObject:(KWEvent *)value;
- (void)replaceLiveEventOrderedSetAtIndexes:(NSIndexSet *)indexes withLiveEventOrderedSet:(NSArray *)values;
- (void)addLiveEventOrderedSetObject:(KWEvent *)value;
- (void)removeLiveEventOrderedSetObject:(KWEvent *)value;
- (void)addLiveEventOrderedSet:(NSOrderedSet *)values;
- (void)removeLiveEventOrderedSet:(NSOrderedSet *)values;

- (void)insertObject:(KWEvent *)value inScheduledEventOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromScheduledEventOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertScheduledEventOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeScheduledEventOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInScheduledEventOrderedSetAtIndex:(NSUInteger)idx withObject:(KWEvent *)value;
- (void)replaceScheduledEventOrderedSetAtIndexes:(NSIndexSet *)indexes withScheduledEventOrderedSet:(NSArray *)values;
- (void)addScheduledEventOrderedSetObject:(KWEvent *)value;
- (void)removeScheduledEventOrderedSetObject:(KWEvent *)value;
- (void)addScheduledEventOrderedSet:(NSOrderedSet *)values;
- (void)removeScheduledEventOrderedSet:(NSOrderedSet *)values;

- (void)insertObject:(KWCustomLobbyItem *)value inCustomItemOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromCustomItemOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertCustomItemOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeCustomItemOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInCustomItemOrderedSetAtIndex:(NSUInteger)idx withObject:(KWCustomLobbyItem *)value;
- (void)replaceCustomItemOrderedSetAtIndexes:(NSIndexSet *)indexes withCustomItemOrderedSet:(NSArray *)values;
- (void)addCustomItemOrderedSetObject:(KWCustomLobbyItem *)value;
- (void)removeCustomItemOrderedSetObject:(KWCustomLobbyItem *)value;
- (void)addCustomItemOrderedSet:(NSOrderedSet *)values;
- (void)removeCustomItemOrderedSet:(NSOrderedSet *)values;

@end
