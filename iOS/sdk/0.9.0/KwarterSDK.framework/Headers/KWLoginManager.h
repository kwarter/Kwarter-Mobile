//
//  KWLoginManager.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 03/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWUser.h"

typedef void (^KWLoginManagerCompletionBlock)(BOOL succeed, NSError *error);

/**
 * Notification name for when a user successfully logs in.
 */
extern NSString *const KWUserDidLoginNotificationName;

/**
 * Notification name for when a user begins to logout, published at the beginning of logout.
 */
extern NSString *const KWUserWillLogoutNotificationName;

/** 
 * Notification name for when a user successfully logs out, published at the end of logout.
 */
extern NSString *const KWUserDidLogoutNotificationName;

/**
 * The KWLoginManager is a convenient class for centralizing
 * the login/logout logic. It also maintains a reference to the
 * currently authenticated user.
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
 * This method will attempt to login the user with the given username
 * and password. You do not and it is not recommended to store the user's
 * credentials on the device.
 *
 * Upon successful login, the KWCredentialManager will retain the user ID
 * and access token.
 *
 * @param username the username to use for login
 * @param password the password to use for login
 * @param block the block to use for the result
 */
- (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
               completion:(KWLoginManagerCompletionBlock)block;

/**
 * This method will attempt to login the user with the given facebook token.
 * 
 * Different use cases:
 *      - The user is already connected with Kwarter, this will attach his 
 *        kwarter account to facebook
 *      - The user is not connected:
 *          - This facebook user does not have an account on the Kwarter 
 *            platform, a new account will be created
 *          - He already has an account this account will be returned.
 *
 * Upon successful login, the KWCredentialManager will retain the user ID and access token.
 * 
 * @param facebookToken The facebook token to use for login. This parameter 
 * is mandatory, if missing the completion block will be called with the 
 * error `KWClientErrorMissingParameterError`.
 * @param block the block to use for the result
 */
- (void)loginWithFacebookToken:(NSString *)facebookToken
                    completion:(KWLoginManagerCompletionBlock)block;

/**
 * Call this method after the initial authentication in order to
 * recover the cached KWUser.
 * @param block the block to use for the result
 */
- (void)loginWithSavedCredentialsCompletion:(KWLoginManagerCompletionBlock)block;

/**
 * @return `YES` if the KWCredentialManager has a cached user ID and
 * access token.
 */
- (BOOL)canConnect;

/**
 * Tells if the user is connected (if the user object is loaded).
 */
- (BOOL)isConnected;

/**
 * Log the user out, broadcasts both KWUserWillLogoutNotificationName and
 * KWUserDidLogoutNotificationName notifications.
 */
- (void)logout;

@end
