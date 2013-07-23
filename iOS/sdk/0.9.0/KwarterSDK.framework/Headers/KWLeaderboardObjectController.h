//
//  KWLeaderboardObjectController.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/14/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWObjectController.h"

/**
 * KWObjectController is responsible for recovering leaderboard
 * data. This class can be used to access the global app-wide
 * leaderboard or one associated with a particular event.
 *
 * @since 1.0.0
 */
@interface KWLeaderboardObjectController : KWObjectController

/**
 * Initialize with identifier.
 *
 * @param identifier The leaderboard identifier.
 * @return an instance of KWLeaderboardObjectController which will recover
 * leaderboard data for the given leaderboard identifier
 */
- (id)initWithLeaderboardIdentifier:(NSString *)identifier;

@end
