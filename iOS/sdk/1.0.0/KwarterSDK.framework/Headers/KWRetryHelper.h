//
//  KWRetryHelper.h
//  KwarterSDK
//
//  Created by Stan Idesis on 5/9/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KWRetryHelper;

/**
 * This is used for when the retry helper needs to actually make the network calls.
 */
typedef void (^KWRetryBlock)(KWRetryHelper *helper, BOOL maximumAttemptsExceeded);

/**
 * KWRetryHelper is used for managing retries for API calls.
 *
 * @since 1.0.0
 */
@interface KWRetryHelper : NSObject

/**
 * Initializes the KWRetryHelper with a default retry count of 5.
 *
 * @param block the block which will be retried
 * @return initialized KWRetryHelper
 */
- (id)initWithBlock:(KWRetryBlock)block;

/**
 * Initialize with a KWRetryBlock and a maximum retry count.
 *
 * @param block the block which will be retried
 * @param maxRetries the maximum number of repeated attempts
 */
- (id)initWithBlock:(KWRetryBlock)block andRetryCount:(NSInteger)maxRetries;

/** 
 * Call this method to start executing the block.
 */
- (void)start;

/**
 * Let the helper know whether or not the latest attempt succeeded.
 * @param didSucceed The lastest attempt result.
 */
- (void)latestAttempt:(BOOL)didSucceed;

@end
