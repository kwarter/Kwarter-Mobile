//
//  KWBadge+SubmitCatch.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 2/14/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWBadge.h"

#define MAX_CATCH_RETRY_COUNT 5

/**
 * This category provides a convenience for sending an API
 * request to Kwarter acknowledging that the user has caught
 * this badge.
 *
 * @since 1.0.0
 */
@interface KWBadge (SubmitCatch)

/**
 * Tells the platform that the user has caught this badge. This method
 * will attempt to send the request MAX_CATCH_RETRY_COUNT times and if
 * it fails, will set this KWBadge's caught status to NO.
 */
- (void)sendCatch;

@end
