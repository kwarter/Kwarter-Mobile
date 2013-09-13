//
//  KWRewardCatalogue.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 3/1/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWReward;

/**
 * The model representing a reward catalogue for the application.
 *
 * @since 1.0.0
 */
@interface KWRewardCatalogue : NSManagedObject

/**
 * The identifier for this tag menu item
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * An NSOrderedSet of KWReward objects associated with this catalogue.
 */
@property (nonatomic, strong) NSOrderedSet *rewardOrderedSet;

@end

@interface KWRewardCatalogue (CoreDataGeneratedAccessors)

- (void)insertObject:(KWReward *)value inRewardOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromRewardOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertRewardOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeRewardOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInRewardOrderedSetAtIndex:(NSUInteger)idx withObject:(KWReward *)value;
- (void)replaceRewardOrderedSetAtIndexes:(NSIndexSet *)indexes withRewardOrderedSet:(NSArray *)values;
- (void)addRewardOrderedSetObject:(KWReward *)value;
- (void)removeRewardOrderedSetObject:(KWReward *)value;
- (void)addRewardOrderedSet:(NSOrderedSet *)values;
- (void)removeRewardOrderedSet:(NSOrderedSet *)values;

@end
