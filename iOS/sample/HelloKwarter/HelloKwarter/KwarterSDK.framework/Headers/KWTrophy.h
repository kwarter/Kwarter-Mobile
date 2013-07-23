//
//  KWTrophy.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 2/7/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWUser, KWGameTemplate;

/**
 * The model representing a caught badge.
 *
 * @since 1.0.0
 */
@interface KWTrophy : NSManagedObject

/**
 * The identifier for this trophy.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The artwork to show for this trophy.
 */
@property (nonatomic, strong) NSString *artworkURLString;

/**
 * How many times has this trophy been caught.
 */
@property (nonatomic, strong) NSNumber *trophyCount;

/**
 * The game type for this trophy.
 */
@property (nonatomic, strong) NSString *gameType;

/**
 * The user this trophy belongs to.
 */
@property (nonatomic, strong) KWUser *user;

/**
 * The template that describes this trophy.
 */
@property (nonatomic, strong) KWGameTemplate *gameTemplate;

/**
 * The last time this trophy was updated.
 */
@property (nonatomic, strong) NSDate *updateDate;

@end
