//
//  KWTagMenuItem.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 5/22/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWApplication, KWEvent, KWLeaderboardUser;

/**
 * The model representing a tag menu item.
 *
 * @since 1.0.0
 */
@interface KWTagMenuItem : NSManagedObject

/**
 * The identifier for this tag menu item
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The tag value.
 */
@property (nonatomic, strong) NSString *tag;

/**
 * The menu item title human-readable.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The application where this tag can be used.
 */
@property (nonatomic, strong) KWApplication *application;

/**
 * The set of events using this tag.
 */
@property (nonatomic, strong) NSSet *eventSet;

/**
 * The set og leaderboardUser using this tag.
 */
@property (nonatomic, strong) NSSet *leaderboardUserSet;

@end

@interface KWTagMenuItem (CoreDataGeneratedAccessors)

- (void)addEventSetObject:(KWEvent *)value;
- (void)removeEventSetObject:(KWEvent *)value;
- (void)addEventSet:(NSSet *)values;
- (void)removeEventSet:(NSSet *)values;

- (void)addLeaderboardUserSetObject:(KWLeaderboardUser *)value;
- (void)removeLeaderboardUserSetObject:(KWLeaderboardUser *)value;
- (void)addLeaderboardUserSet:(NSSet *)values;
- (void)removeLeaderboardUserSet:(NSSet *)values;

@end
