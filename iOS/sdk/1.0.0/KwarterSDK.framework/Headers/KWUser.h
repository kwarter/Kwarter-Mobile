//
//  KWUser.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 28/11/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <CoreData/CoreData.h>
#import "KWUserLevel.h"

@class KWEvent, KWTrophy, KWLeaderboardUser;

/**
 * Constant string representing Males.
 */
extern NSString *const KWUserGenderMale;

/**
 * Constant string representing Females.
 */
extern NSString *const KWUserGenderFemale;

/**
 * Constant string representing unknown/unspecified gender.
 */
extern NSString *const KWUserGenderUnknown;

/**
 * This model represents a Kwarter platform user.
 *
 * @since 1.0.0
 */
@interface KWUser : NSManagedObject

/**
 * The identifier for this user.
 */
@property (nonatomic, strong) NSString *identifier;
/**
 * The user's first name.
 */
@property (nonatomic, strong) NSString *firstName;

/**
 * The user's last name.
 */
@property (nonatomic, strong) NSString *lastName;

/**
 * The URL representing this user's avatar image.
 */
@property (nonatomic, strong) NSString *avatarArtworkURLString;

/**
 * The URL representing this user's cover art image.
 */
@property (nonatomic, strong) NSString *coverArtworkURLString;

/**
 * This user's birth date.
 */
@property (nonatomic, strong) NSDate *birthDate;

/**
 * The date at which this user registered their Kwarter account.
 */
@property (nonatomic, strong) NSDate *sinceDate;

/**
 * Gender, value can be KWUserGenderFemale, KWUserGenderMale or KWUserGenderUnknown.
 */
@property (nonatomic, strong) NSString *gender;

/**
 * If true, this user will receive email from Kwarter.
 */
@property (nonatomic, strong) NSNumber *isInMailingList;

/**
 * The user's email address.
 */
@property (nonatomic, strong) NSString *email;

/**
 * This user's prefered locale.
 */
@property (nonatomic, strong) NSString *locale;

/**
 * The number of Credits this user has accrued since the account creation.
 */
@property (nonatomic, strong) NSNumber *credits;

/**
 * The number of Points this user has accrued since the account creation.
 */
@property (nonatomic, strong) NSNumber *points;

/**
 * A set of KWLeaderboardUser objects in which this KWUser is linked.
 */
@property (nonatomic, strong) NSSet *leaderboardUserSet;

/**
 * A set of KWEvent objects representing events this KWUser has participated in.
 */
@property (nonatomic, strong) NSSet *eventHistorySet;

/**
 * A sorted array of KWEvent objects representing events this KWUser has participated in (by date).
 */
@property (nonatomic, strong, readonly) NSArray *sortedEventsHistory;

/**
 * A set of KWTrophy objects this user has earned.
 */
@property (nonatomic, strong) NSSet *trophySet;

/**
 * A sorted array of KWTrophy objects this user has earned (by date).
 */
@property (nonatomic, strong, readonly) NSArray *sortedTrophies;

/**
 * Returns the user with the given identifier.
 * @return The user corresponding to the identifier, nil if user is not found.
 * @param identifier The unique user identifier.
 */
+ (KWUser *)userWithIdentifier:(NSString *)identifier;

/**
 * The fullname of the user.
 * @return The fullname of the user (concat first and last name).
 */
- (NSString *)fullName;

/**
 * The user short name.
 * @return The shortname (concat first name with last name first letter).
 */
- (NSString *)shortName;

/**
 * The age of this user.
 * @return The age of this user, in years.
 */
- (NSUInteger)age;

/**
 * The user level representation.
 * @return A KWUserLevel object representing this user's level.
 */
- (KWUserLevel *)userLevel;

/**
 * @return `YES` if this user is the user authenticated on this device.
 */
- (BOOL)isCurrentUser;

@end

@interface KWUser (CoreDataAccessors)

- (void)addLeaderboardUserSetObject:(KWLeaderboardUser *)value;
- (void)removeLeaderboardUserSetObject:(KWLeaderboardUser *)value;
- (void)addLeaderboardUserSet:(NSSet *)values;
- (void)removeLeaderboardUserSet:(NSSet *)values;

- (void)addEventHistorySetObject:(KWEvent *)value;
- (void)removeEventHistorySetObject:(KWEvent *)value;
- (void)addEventHistorySet:(NSSet *)values;
- (void)removeEventHistorySet:(NSSet *)values;

- (void)addTrophySetObject:(KWTrophy *)value;
- (void)removeTrophySetObject:(KWTrophy *)value;
- (void)addTrophySet:(NSSet *)values;
- (void)removeTrophySet:(NSSet *)values;

@end