//
//  KWAchievementClient.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 7/5/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWAchievement.h"

/**
 * Client for API calls relative to the KWAchievement objects.
 *
 * @since 1.0.0
 */
@interface KWAchievementClient : NSObject

/**
 * Pull the achievements for the given tag.
 * @param tag The tag is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the achievement list.
 */
- (void)getAchievementsForTag:(NSString *)tag completion:(void(^)(NSArray *achievements, NSError *error))block;

@end
