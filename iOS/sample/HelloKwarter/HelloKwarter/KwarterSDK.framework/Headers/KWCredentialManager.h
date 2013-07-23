//
//  KWCredentialManager.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 25/11/12.
//  Copyright (c) 2012 Ludovic Landry. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * The KWCredentialManager maintains and retains the currently
 * authorized user's unique identifier and auth token.
 *
 * @since 1.0.0
 */
@interface KWCredentialManager : NSObject

/**
 * The currently authenticated user's access token.
 */
@property (nonatomic, strong) NSString *authToken;

/**
 * The currently authenticated user's unique identifier.
 */
@property (nonatomic, strong) NSString *userIdentifier;

/**
 * Recovers the shared singleton instance of the KWCredentialManager.
 */
+ (KWCredentialManager *)sharedManager;

/**
 * Returns `YES` if the current user has a valid auth token.
 */
- (BOOL)isLoggedIn;

/**
 * Clears away all cached information regarding the user's
 * authorization and idenitifier.
 */
- (void)clearSavedCredentials;

@end
