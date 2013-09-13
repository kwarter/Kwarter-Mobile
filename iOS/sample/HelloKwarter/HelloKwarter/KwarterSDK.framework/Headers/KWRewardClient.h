//
//  KWRewardClient.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/15/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWRewardCatalogue.h"

extern NSString *const applicationCatalogueIdentifier;

typedef void (^KWRewardsClientCompletionBlock)(id result, NSError *error);
typedef void (^KWRewardsClientRedeemCompletionBlock)(BOOL result, NSError *error);

/**
 * Client for API calls relative to the KWReward objects.
 *
 * @since 1.0.0
 */
@interface KWRewardClient : NSObject

/**
 * The Application reward catalogue, it is the common reward catalogue. If it has not been created before, recovering
 * it from this property will do so.
 */
+ (KWRewardCatalogue *)applicationCatalogue;

/**
 * Returns all the rewards available for the current application.
 * @param block The block to receive the results.
 */
- (void)getRewardsWithCompletion:(KWRewardsClientCompletionBlock)block;

/**
 * Returns the rewards paginated for the current application.
 * @param offset The index from which to start.
 * @param limit The limit is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the results.
 */
- (void)getRewardsWithOffset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWRewardsClientCompletionBlock)block;

/**
 * Return the reward for the specified identifier.
 * @param rewardIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getRewardWithIdentifier:(NSString *)rewardIdentifier completion:(KWRewardsClientCompletionBlock)block;

/**
 * Returns a boolean, asserting that the redeem succeded or failed.
 * User have to be authenticated to be able to update, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param rewardIdentifier The reward identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param email The email is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)redeemRewardWithIdentifier:(NSString *)rewardIdentifier email:(NSString *)email completion:(KWRewardsClientRedeemCompletionBlock)block;

@end
