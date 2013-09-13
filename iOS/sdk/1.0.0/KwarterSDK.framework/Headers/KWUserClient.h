//
//  KWUserClient.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 06/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import "KWUser.h"

extern NSString *const KWUserClientErrorDomain;
extern NSString *const KWUserClientUserNotFoundKey;
extern NSInteger const KWUserClientUserNotFoundError;

extern NSString *const KWUserClientParameterPartnerIdentifier;
extern NSString *const KWUserClientParameterFirstName;
extern NSString *const KWUserClientParameterLastName;
extern NSString *const KWUserClientParameterPassword;
extern NSString *const KWUserClientParameterEmail;
extern NSString *const KWUserClientParameterGender;
extern NSString *const KWUserClientParameterBirthday;
extern NSString *const KWUserClientParameterLocale;
extern NSString *const KWUserClientParameterPhoto;
extern NSString *const KWUserClientParameterCover;
extern NSString *const KWUserClientParameterMailingList;
extern NSString *const KWUserClientParameterNonce;

typedef enum {
	KWUserFetchModeBasic,
	KWUserFetchModeProfile,
    KWUserFetchModeEdit,
    KWUserFetchModeScoreOnly
} KWUserFetchMode;

typedef void (^KWUserClientCompletionBlock)(id result, NSError *error);

/**
 * KWUserClient is a network client for fetching KWUser objects.
 * It can be used to create a user account, reset password, login or retrieve
 * related KWUser information.
 *
 * @since 1.0.0
 */
@interface KWUserClient : NSObject

/**
 * Create an account on the kwarter platform with the user infos specified, then returns the user.
 *
 * This required at least the following parameters in the userInfo dictionary:
 *
 * - KWUserClientParameterFirstName with a value as NSString
 * - KWUserClientParameterLastName with a value as NSString
 * - KWUserClientParameterPassword with a value as NSString
 * - KWUserClientParameterBirthday with a value as NSDate
 * - KWUserClientParameterEmail with a value as NSString
 * - KWUserClientParameterMailingList with a value as NSNumber
 *
 * The optionals parameters are:
 *
 * - KWUserClientParameterGender with a value as NSString
 * - KWUserClientParameterLocale with a value as NSString
 * - KWUserClientParameterPhoto with a value as UIImage
 * - KWUserClientParameterCover with a value as UIImage
 *
 * @param userInfo The user info is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the new user.
 */
- (void)signUpWithUserInfo:(NSDictionary *)userInfo completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Update the user infos and returns the Basic user updated. The keys that can be updated in the user info dictionary are:
 * - KWUserClientParameterPhoto with a value as UIImage
 * - KWUserClientParameterCover with a value as UIImage
 * User have to he authenticated to be able to update, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param userInfo is mandatory, if missing the completion block will be called with the error `KWClientErrorNeedsAuthenticationError`.
 * @param block The block to receive the results.
 */
- (void)updateUserWithUserInfo:(NSDictionary *)userInfo completion:(KWUserClientCompletionBlock)block;

/**
 * Ask to reset password. Send an email to reset the password associated with the account.
 * The email have to be the one used with the account.
 * The email is not case sensitive, if not found, returns error `KWUserClientErrorDomain` with code `KWUserClientUserNotFoundError`.
 * @param email is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)resetPasswordWithEmail:(NSString *)email completion:(void(^)(BOOL success, NSError *error))block;

/**
 * Get a session with a username and password.
 * @param username The user name is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param password The password is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the user.
 */
- (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
               completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Get a session with a facebook token. If it's the first time conecting with this facebook account, a
 * kwarter account will be created.
 * @param token is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the user.
 */
- (void)loginWithFacebookToken:(NSString *)token completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Disconnect the facebook account from the current authenticated user
 * User have to he authenticated to be able to disconnect, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)disconnectFromFacebookCompletion:(KWUserClientCompletionBlock)block;

/**
 * Associate a partner user with a Kwarter user. This function takes in parameter the partner user identifier and it's required fields to create
 * the KWUser if required, the optional fields can be passed in the option fields. To be able to use this method the KwarterSDK have to be started
 * with a secret, if missing the completion block will be called with the error `KWClientErrorNeedsSecretError`.
 *
 * The optionals parameters that can be passed in the option dictionary are:
 *
 * - KWUserClientParameterGender with a value as NSString
 * - KWUserClientParameterLocale with a value as NSString
 *
 * @param identifier The partner user identifier. This is not and will not become the KWUser identifier. This parameter is mandatory, if missing the
 * completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param firstName The first name for the user the be associated. This parameter is mandatory, if missing the completion block will be called with 
 * the error `KWClientErrorMissingParameterError`.
 * @param lastName The last name for the user the be associated. This parameter is mandatory, if missing the completion block will be called with
 * the error `KWClientErrorMissingParameterError`.
 * @param birthday The birthday for the user the be associated. This parameter is mandatory, if missing the completion block will be called with
 * the error `KWClientErrorMissingParameterError`.
 * @param options A dictionary that contains the optional parameters. Can be KWUserClientParameterGender or/and KWUserClientParameterLocale.
 * @param block The block to receive the new user.
 */
- (void)associatePartnerUserWithIdentifier:(NSString *)identifier
                                 firstName:(NSString *)firstName
                                  lastName:(NSString *)lastName
                                  birthday:(NSDate *)birthday
                                   options:(NSDictionary *)options
                                completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Get the user using the session token.
 * User have to he authenticated to be able to use it, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getUserAuthenticatedCompletion:(KWUserClientCompletionBlock)block;

/**
 * Returns the user with the specified identifier using different modes:
 *
 * - Basic: Returns the user description for this user identifier (firstName, lastName and artworks)
 * - Profile: Returns the user for profile display (basic user description + birthDate and points)
 * - Edit: Returns the user for profile edition (basic user description + email, birthDate, genre and isInMailingList)
 * - Scores only: Returns the only the points and credits for the user
 *
 * @param userIdentifier The user identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param userFetchMode The user fetch mode used to retrieve the user, can be KWUserFetchModeBasic, KWUserFetchModeProfile, KWUserFetchModeEdit or KWUserFetchModeScoreOnly.
 * @param block The block to receive the results.
 */
- (void)getUserWithIdentifier:(NSString *)userIdentifier
                         mode:(KWUserFetchMode)userFetchMode
                   completion:(KWUserClientCompletionBlock)block;

/**
 * Returns the event history for the user. To get all the events with pagination, use `getHistoryForUser:offset:limit:completion:`.
 * @param user is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getHistoryForUser:(KWUser *)user completion:(KWUserClientCompletionBlock)block;

/**
 * Returns the event history for the user paginated.
 * @param user is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param sinceEventIdentifier is not mandatory. If nil, that will start at the beginning with the most recent event.
 * @param count is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the results.
 */
- (void)getHistoryForUser:(KWUser *)user since:(NSString *)sinceEventIdentifier count:(NSUInteger)count completion:(KWUserClientCompletionBlock)block;

/**
 * Returns user caught trophies. To get all the badges with pagination, use `getCaughtTrophiesForUser:offset:limit:completion:`.
 * @param user is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getCaughtTrophiesForUser:(KWUser *)user completion:(KWUserClientCompletionBlock)block;

/**
 * Returns user caught trophies paginated.
 * @param user The user is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param limit The limit is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param offset The offset is optional
 * @param block The block to receive the results.
 */
- (void)getCaughtTrophiesForUser:(KWUser *)user offset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWUserClientCompletionBlock)block;

@end
