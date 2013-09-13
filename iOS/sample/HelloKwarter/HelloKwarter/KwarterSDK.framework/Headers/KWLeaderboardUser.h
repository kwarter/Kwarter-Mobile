//
//  KWLeaderboardUser.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 5/23/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWTagMenuItem, KWUser;

/**
 * The model representing a user in a leaderboard.
 *
 * @since 1.0.0
 */
@interface KWLeaderboardUser : NSManagedObject

/**
 * The identifier for this leaderboard user.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The user represented by this KWLeaderboardUser.
 */
@property (nonatomic, strong) KWUser *user;

/**
 * The number of points that this user has for the given leaderboard.
 */
@property (nonatomic, strong) NSNumber *points;

/**
 * The rank that this user has for the given leaderboard.
 */
@property (nonatomic, strong) NSNumber *rank;

/**
 * A set of tags this KWLeaderboardUser can be filtered by.
 */
@property (nonatomic, strong) NSSet *tagMenuItemSet;

@end

@interface KWLeaderboardUser (CoreDataGeneratedAccessors)

- (void)addTagMenuItemSetObject:(KWTagMenuItem *)value;
- (void)removeTagMenuItemSetObject:(KWTagMenuItem *)value;
- (void)addTagMenuItemSet:(NSSet *)values;
- (void)removeTagMenuItemSet:(NSSet *)values;

@end
