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

extern NSString *const KWUserClientParameterRegisterFirstName;
extern NSString *const KWUserClientParameterRegisterLastName;
extern NSString *const KWUserClientParameterRegisterPassword;
extern NSString *const KWUserClientParameterRegisterEmail;
extern NSString *const KWUserClientParameterRegisterGender;
extern NSString *const KWUserClientParameterRegisterBirthday;
extern NSString *const KWUserClientParameterRegisterLocale;
extern NSString *const KWUserClientParameterRegisterPhoto;
extern NSString *const KWUserClientParameterRegisterCover;
extern NSString *const KWUserClientParameterRegisterMailingList;

typedef enum {
	KWUserFetchModeBasic,
	KWUserFetchModeProfile,
    KWUserFetchModeEdit,
    KWUserFetchModeScoreOnly
} KWUserFetchMode;

typedef void (^KWUserClientCompletionBlock)(id result, NSError *error);
typedef void (^KWUserClientBooleanCompletionBlock)(BOOL success, NSError *error);

/**
 * Client for API calls relative to the KWUser objects.
 *
 * @since 1.0
 */
@interface KWUserClient : NSObject

/**
 * Create an account on the kwarter platform with the user infos specified, then returns the user.
 * @param userInfo is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the user.
 */
- (void)signUpWithUserInfo:(NSDictionary *)userInfo completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Update the user infos and returns the Basic user updated.
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
- (void)resetPasswordWithEmail:(NSString *)email completion:(KWUserClientBooleanCompletionBlock)block;

/**
 * Get a session with a username and password.
 * @param username is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param password is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
               completion:(KWUserClientCompletionBlock)block;

/**
 * Get a session with a facebook token. If it's the first time conecting with this facebook account, a
 * kwarter account will be created.
 * @param token is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)loginWithFacebookToken:(NSString *)token completion:(KWUserClientCompletionBlock)block;

/**
 * Disconnect the facebook account from the current authenticated user
 * User have to he authenticated to be able to disconnect, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)disconnectFromFacebookCompletion:(KWUserClientCompletionBlock)block;

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
