//
//  KWRewardObjectController.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/15/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWObjectController.h"
#import "KWReward.h"

/**
 * The KWRewardObjectController is an object controller responsible for
 * recovering a specific KWReward.
 *
 * @since 1.0.0
 */
@interface KWRewardObjectController : KWObjectController

/**
 * Initialized with a specific reward.
 *
 * @param reward The reward whose details we wish to recover.
 */
- (id)initWithReward:(KWReward *)reward;

@end
