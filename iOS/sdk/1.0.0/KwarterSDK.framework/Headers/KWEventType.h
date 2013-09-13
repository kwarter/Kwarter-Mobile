//
//  KWEventType.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/31/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <CoreData/CoreData.h>

@class KWEvent, KWEventPeriod;

/**
 * The model representing an event type.
 *
 * @since 1.0.0
 */
@interface KWEventType : NSManagedObject

/**
 * The identifier for this event type.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The name for this event type.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The set of ordered event periods that belong to this type.
 */
@property (nonatomic, strong) NSOrderedSet *periodOrderedSet;

/**
 * The set of events that this type belongs to.
 */
@property (nonatomic, strong) NSSet *eventSet;

@end

@interface KWEventType (CoreDataGeneratedAccessors)

- (void)addEventSetObject:(KWEvent *)value;
- (void)removeEventSetObject:(KWEvent *)value;
- (void)addEventSet:(NSSet *)values;
- (void)removeEventSet:(NSSet *)values;

- (void)addPeriodOrderedSetObject:(KWEventPeriod *)value;
- (void)removePeriodOrderedSetObject:(KWEventPeriod *)value;
- (void)addPeriodOrderedSet:(NSOrderedSet *)values;
- (void)removePeriodOrderedSet:(NSOrderedSet *)values;

@end
