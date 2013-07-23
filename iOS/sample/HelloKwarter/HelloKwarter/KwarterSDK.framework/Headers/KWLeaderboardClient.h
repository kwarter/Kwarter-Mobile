//
//  KWLeaderboardClient.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/14/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

typedef void (^KWLeaderboardClientCompletionBlock)(id result, NSError *error);

/**
 * Client for API calls relative to the leaderboards.
 *
 * @since 1.0
 */
@interface KWLeaderboardClient : NSObject

/**
 * Return the leaderboard for the specified identifier.
 * @param leaderboardIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getLeaderboardWithIdentifier:(NSString *)leaderboardIdentifier completion:(KWLeaderboardClientCompletionBlock)block;

/**
 * Return the user rank in the specified leaderboard.
 * @param leaderboardIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param userIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getRankInLeaderboard:(NSString *)leaderboardIdentifier forUser:(NSString *)userIdentifier completion:(void(^)(NSNumber *rankNumber, NSError *error))block;

/**
 * Add the current connected user to a new leaderboard. The user needs to be authenticated to be able to use this endpoint.
 * @param leaderboardIdentifier The leaderboard identifier to add the user to. This parameter is mandatory.
 * @param block The block to receive the results.
 */
- (void)addCurrentUserToLeaderboard:(NSString *)leaderboardIdentifier completion:(void(^)(BOOL succeed, NSError *error))block;

@end
