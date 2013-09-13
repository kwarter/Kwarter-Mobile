//
//  KWLeaderboardClient.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/14/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWLeaderboard.h"
#import "KWUser.h"

/**
 * Client for API calls relative to the leaderboards.
 *
 * @since 1.0.0
 */
@interface KWLeaderboardClient : NSObject

/**
 * Return the leaderboard for the specified identifier.
 * @param leaderboardIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the KWLeaderboard.
 */
- (void)getLeaderboardWithIdentifier:(NSString *)leaderboardIdentifier
                          completion:(void(^)(KWLeaderboard *leaderboard, NSError *error))block;

/**
 * Return the leaderboard users arround the user specified for the specified identifier.
 * @param leaderboardIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param userIdentifier The user identifier that will be used as reference to get the leaderboard users around.
 * @param before The number of KWLeaderboardUser that will be returned preceding the user.
 * @param after The number of KWLeaderboardUser that will be returned following the user.
 * @param block The block to receive the array of KWLeaderboardUser.
 */
- (void)getRankingsInLeaderboard:(NSString *)leaderboardIdentifier
                         forUser:(NSString *)userIdentifier
                       numBefore:(NSUInteger)before
                        numAfter:(NSUInteger)after
                      completion:(void(^)(NSArray *leaderboardUsers, NSError *error))block;

/**
 * Return the user rank in the specified leaderboard.
 * @param leaderboardIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param userIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the rank number.
 */
- (void)getRankInLeaderboard:(NSString *)leaderboardIdentifier
                     forUser:(NSString *)userIdentifier
                  completion:(void(^)(NSNumber *rankNumber, NSError *error))block;

/**
 * Add the current connected user to a new leaderboard. The user needs to be authenticated to be able to use this endpoint.
 * @param leaderboardIdentifier The leaderboard identifier to add the user to. This parameter is mandatory.
 * @param block The block to receive the result.
 */
- (void)addCurrentUserToLeaderboard:(NSString *)leaderboardIdentifier
                         completion:(void(^)(BOOL succeed, NSError *error))block;

@end
