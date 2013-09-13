//
//  KWApplication.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 3/12/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWTagMenuLeaderboardItem, KWTagMenuLobbyItem;

/**
 * The model representing an application, contains useful configuration options.
 *
 * @since 1.0.0
 */
@interface KWApplication : NSManagedObject

/**
 * The application identifier.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The application name.
 */
@property (nonatomic, strong) NSString *name;

/**
 * The applications latest version.
 */
@property (nonatomic, strong) NSString *lastVersion;

/**
 * This tells if the application is allowed to show the team logos.
 */
@property (nonatomic, strong) NSNumber *allowTeamArtwork;

/**
 * The application supported languages.
 */
@property (nonatomic, strong) NSArray *languages;

/**
 * The banner to use for congrats.
 */
@property (nonatomic, strong) NSString *bannerCongratsUrlString;

/**
 * The banner to use for the lobby.
 */
@property (nonatomic, strong) NSString *bannerLobbyUrlString;

/**
 * The banner to use for the room view.
 */
@property (nonatomic, strong) NSString *bannerRoomUrlString;

/**
 * The application menu items, added to each event this app can see.
 */
@property (nonatomic, strong) NSArray *menuItems;

/**
 * An ordered set of tags by which the lobby should be filterable by.
 */
@property (nonatomic, strong) NSOrderedSet *tagMenuLobbyItemOrderedSet;

/**
 * An ordered set of tags by which the global leaderboard should be filterable by.
 */
@property (nonatomic, strong) NSOrderedSet *tagMenuLeaderboardItemOrderedSet;

/**
 * A set of gameTemplates that are enabled for the application
 */
@property (nonatomic, strong) NSSet *gameTemplateSet;

@end

@interface KWApplication (CoreDataGeneratedAccessors)

- (void)insertObject:(KWTagMenuLeaderboardItem *)value inTagMenuLeaderboardItemOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromTagMenuLeaderboardItemOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertTagMenuLeaderboardItemOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeTagMenuLeaderboardItemOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInTagMenuLeaderboardItemOrderedSetAtIndex:(NSUInteger)idx withObject:(KWTagMenuLeaderboardItem *)value;
- (void)replaceTagMenuLeaderboardItemOrderedSetAtIndexes:(NSIndexSet *)indexes withTagMenuLeaderboardItemOrderedSet:(NSArray *)values;
- (void)addTagMenuLeaderboardItemOrderedSetObject:(KWTagMenuLeaderboardItem *)value;
- (void)removeTagMenuLeaderboardItemOrderedSetObject:(KWTagMenuLeaderboardItem *)value;
- (void)addTagMenuLeaderboardItemOrderedSet:(NSOrderedSet *)values;
- (void)removeTagMenuLeaderboardItemOrderedSet:(NSOrderedSet *)values;

- (void)insertObject:(KWTagMenuLobbyItem *)value inTagMenuLobbyItemOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromTagMenuLobbyItemOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertTagMenuLobbyItemOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeTagMenuLobbyItemOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInTagMenuLobbyItemOrderedSetAtIndex:(NSUInteger)idx withObject:(KWTagMenuLobbyItem *)value;
- (void)replaceTagMenuLobbyItemOrderedSetAtIndexes:(NSIndexSet *)indexes withTagMenuLobbyItemOrderedSet:(NSArray *)values;
- (void)addTagMenuLobbyItemOrderedSetObject:(KWTagMenuLobbyItem *)value;
- (void)removeTagMenuLobbyItemOrderedSetObject:(KWTagMenuLobbyItem *)value;
- (void)addTagMenuLobbyItemOrderedSet:(NSOrderedSet *)values;
- (void)removeTagMenuLobbyItemOrderedSet:(NSOrderedSet *)values;

@end
