//
//  KWBadgeTemplate.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 22/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "KWGameTemplate.h"

/**
 * The model representing a badge template for an event.
 *
 * @since 1.0.0
 */
@interface KWBadgeTemplate : KWGameTemplate

/**
 * The number of points awarded for catching this badge.
 */
@property (nonatomic, strong) NSNumber *points;

/**
 * The number of credits awarded for catching this badge.
 */
@property (nonatomic, strong) NSNumber *credits;

/**
 * The artwork for the badge itself.
 */
@property (nonatomic, strong) NSString *pinArtworkURLString;

/**
 * The artwork for the banner to use once the badge has been caught.
 */
@property (nonatomic, strong) NSString *backgroundArtworkURLString;

@end
