//
//  KWBadge.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 22/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "KWGame.h"
#import "KWBadgeTemplate.h"

/**
 * The model representing a badge game triggered for an event.
 *
 * @since 1.0.0
 */
@interface KWBadge : KWGame

/**
 * This is a boolean to let us know if the badge has been caught.
 */
@property (strong, nonatomic) NSNumber *hasBeenCaught;

/**
 * The template that represents this badge.
 */
@property (strong, nonatomic, readonly) KWBadgeTemplate *badgeTemplate;

@end
