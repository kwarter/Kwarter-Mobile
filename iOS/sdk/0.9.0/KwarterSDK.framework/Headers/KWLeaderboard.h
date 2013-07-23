//
//  KWLeaderboard.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/14/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <CoreData/CoreData.h>

@class KWLeaderboardUser, KWEvent;

/**
 * The model representing a leaderboard.
 *
 * @since 1.0.0
 */
@interface KWLeaderboard : NSManagedObject

/**
 * The identifier for this leaderboard.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The ordered set of users that are part of this leaderboard.
 */
@property (nonatomic, strong) NSOrderedSet *leaderboardUserOrderedSet;

/**
 * The event associated with this leaderboard, global leaderboards have no events.
 */
@property (nonatomic, strong) KWEvent *event;

@end

@interface KWLeaderboard (CoreDataGeneratedAccessors)

- (void)addLeaderboardUserOrderedSetObject:(KWLeaderboardUser *)value;
- (void)removeLeaderboardUserOrderedSetObject:(KWLeaderboardUser *)value;
- (void)addLeaderboardUserOrderedSet:(NSOrderedSet *)values;
- (void)removeLeaderboardUserOrderedSet:(NSOrderedSet *)values;

@end