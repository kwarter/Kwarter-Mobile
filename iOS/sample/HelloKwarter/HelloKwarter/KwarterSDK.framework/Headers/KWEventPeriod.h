//
//  KWEventPeriod.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/31/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <CoreData/CoreData.h>

@class KWEvent, KWEventType;

/**
 * The model representing an event period.
 *
 * @since 1.0.0
 */
@interface KWEventPeriod : NSManagedObject

/**
 * The identifier for this event period.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The name for this period.
 */
@property (nonatomic, strong) NSString *name;

/**
 * The duration for this period.
 */
@property (nonatomic, strong) NSNumber *duration;

/**
 * The set of events that this period belongs to.
 */
@property (nonatomic, strong) NSSet *eventSet;

/**
 * The set of event types that this period belongs to.
 */
@property (nonatomic, strong) KWEventType *eventType;

@end

@interface KWEventPeriod (CoreDataGeneratedAccessors)

- (void)addEventSetObject:(KWEvent *)value;
- (void)removeEventSetObject:(KWEvent *)value;
- (void)addEventSet:(NSSet *)values;
- (void)removeEventSet:(NSSet *)values;

@end