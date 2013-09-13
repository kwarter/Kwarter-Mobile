//
//  KWReward.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 3/1/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWRewardCatalogue;

/**
 * The model representing a reward for the application.
 *
 * @since 1.0.0
 */
@interface KWReward : NSManagedObject

/**
 * The artwork to use in the details view.
 */
@property (nonatomic, retain) NSString *backgroundArtworkURLString;

/**
 * The cost in credits to redeem this reward.
 */
@property (nonatomic, retain) NSNumber *cost;

/**
 * The artwork to use in the background of the details view.
 */
@property (nonatomic, retain) NSString *detailArtworkURLString;

/**
 * A boolean representing if this reward have an inventory. If not, the inventoryCount doe not matter.
 */
@property (nonatomic, retain) NSNumber *hasInventory;

/**
 * The identifier for this reward item.
 */
@property (nonatomic, retain) NSString *identifier;

/**
 * The index for this reward in the catalog.
 */
@property (nonatomic, retain) NSNumber *index;

/**
 * The count of how gloabl many redemtions are left for this reward.
 */
@property (nonatomic, retain) NSNumber *inventoryCount;

/**
 * Legal text that should be shown to the user.
 */
@property (nonatomic, retain) NSString *legal;

/**
 * The artwork to use when showing this reward in the catalog.
 */
@property (nonatomic, retain) NSString *listArtworkURLString;

/**
 * The description of this reward.
 */
@property (nonatomic, retain) NSString *rewardDescription;

/**
 * The title of this reward.
 */
@property (nonatomic, retain) NSString *title;

/**
 * The catalog this reward belongs to.
 */
@property (nonatomic, retain) KWRewardCatalogue *rewardCatalogue;

@end
