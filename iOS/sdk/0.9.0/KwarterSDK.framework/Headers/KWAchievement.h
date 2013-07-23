//
//  KWAchievement.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 7/5/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 * The model representing an achievement. An achievement is something that a user can earn.
 *
 * @since 1.0.0
 */
@interface KWAchievement : NSManagedObject

/**
 * The identifier for this achievement.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The title for this achievement.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The list of tags that can represent where this achievement can be won and how.
 */
@property (nonatomic, strong) NSArray *tags;

/**
 * The artwork to use for the achievement.
 */
@property (nonatomic, strong) NSString *artworkURLString;

@end
