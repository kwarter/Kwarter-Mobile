//
//  KWEventMaster.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 2/8/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <CoreData/CoreData.h>

/**
 * The model representing an event master user
 *
 * @since 1.0.0
 */
@interface KWEventMaster : NSManagedObject

/**
 * The identifier for this event master.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The first name. Always capitalized.
 */
@property (nonatomic, strong) NSString *firstName;

/**
 * The last name. Always capitalized.
 */
@property (nonatomic, strong) NSString *lastName;

/**
 * The avatar artwork for this event master.
 */
@property (nonatomic, strong) NSString *avatarArtworkURLString;

/**
 * The cover artwork for this event master.
 */
@property (nonatomic, strong) NSString *coverArtworkURLString;

/**
 * @return The full name for this event master.
 */
- (NSString *)fullName;

/**
 * @return The shortname, first name followed by the last initial.
 */
- (NSString *)shortName;

@end
