//
//  KWLoginManager.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 03/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWUser.h"

/**
 * Notification name for when a KWUser successfully logs in.
 */
extern NSString *const KWUserDidLoginNotificationName;

/**
 * Notification name for when a KWUser begins to logout, published at the beginning of logout.
 */
extern NSString *const KWUserWillLogoutNotificationName;

/** 
 * Notification name for when a KWUser successfully logs out, published at the end of logout.
 */
extern NSString *const KWUserDidLogoutNotificationName;

/**
 * The KWLoginManager is a convenient class for centralizing
 * the login/logout logic. It also maintains a reference to the
 * currently authenticated KWUser.
 *
 * @since 1.0.0
 */
@interface KWLoginManager : NSObject

/**
 * The currently authenticated user, or nil if not logged in
 */
@property (nonatomic, strong) KWUser *user;

/**
 * @return the singleton instance of the KWLoginController
 */
+ (KWLoginManager *)sharedLogin;

/**
 * This method will attempt to login the KWUser with the given username
 * and password. It is not recommended to store KWUser credentials 
 * on the device.
 *
 * Upon successful login, the KWCredentialManager will retain the KWUser 
 * identifier and access token.
 *
 * @param username The username to use for login.
 * @param password The password to use for login.
 * @param block The block to use for the result.
 */
- (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
               completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * This method will attempt to login the KWUser with the given facebook token.
 * 
 * Different use cases:
 *      - The KWUser is already connected with Kwarter, this will attach their
 *        Kwarter account to facebook
 *      - The KWUser is not connected:
 *          - This facebook user does not have an account on the Kwarter 
 *            platform, a new account will be created
 *          - They already have an account; this account will be returned.
 *
 * Upon successful login, the KWCredentialManager will retain the user identifier
 * and access token.
 * 
 * @param facebookToken The facebook token to use for login. This parameter 
 * is mandatory. If the parameter is missing, the completion block will be called 
 * with the error `KWClientErrorMissingParameterError`.
 * @param block The block used to return the KWUser.
 */
- (void)loginWithFacebookToken:(NSString *)facebookToken
                    completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Login with a partner user. This function takes in parameter the partner user identifier and it's required fields to create
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
- (void)loginWithPartnerUserIdentifier:(NSString *)identifier
                             firstName:(NSString *)firstName
                              lastName:(NSString *)lastName
                              birthday:(NSDate *)birthday
                               options:(NSDictionary *)options
                            completion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Call this method after the initial authentication in order to
 * recover the cached KWUser.
 * @param block The block used to return the KWUser.
 */
- (void)loginWithSavedCredentialsCompletion:(void(^)(KWUser *user, NSError *error))block;

/**
 * Boolean that indicates if the user can be connected with the login info 
 * curently saved on the device.
 * @return `YES` if the KWCredentialManager can connect, otherwise `NO`.
 */
- (BOOL)canConnect;

/**
 * Boolean that indicates if the KWUser is connected.
 * @return `YES` if the KWUser object is loaded, otherwise `NO`.
 */
- (BOOL)isConnected;

/**
 * Log the KWUser out, broadcasts both KWUserWillLogoutNotificationName and
 * KWUserDidLogoutNotificationName notifications.
 */
- (void)logout;

@end
