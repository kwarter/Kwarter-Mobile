//
//  KWUserObjectController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 10/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import "KWObjectController.h"
#import "KWUserClient.h"
#import "KWUser.h"

/**
 * Manages fetching data related to a given user.
 *
 * Info: if the userFetchMode is set to KWUserFetchModeProfile, `getUserAuthenticatedCompletion:` will be use for the authenticated user and `getUserWithIdentifier:mode:completion:` with the mode profile will be used for the others.
 *
 * @since 1.0.0
 */
@interface KWUserObjectController : KWObjectController

/**
 * Defines the fetch mode used if `useCurrentUserEndpoint` is false 
 * and it's not the current user. Default is KWUserFetchModeBasic.
 */
@property (nonatomic, readonly, assign) KWUserFetchMode userFetchMode;

/**
 * @param user the KWUser to fetch data for
 * @return an initialized KWUserObjectController
 */
- (id)initWithUser:(KWUser *)user;

/**
 * @param user the KWUser to fetch data for
 * @param userFetchMode the KWUserFetchMode
 * @return an initialized KWUserObjectController
 */
- (id)initWithUser:(KWUser *)user mode:(KWUserFetchMode)userFetchMode;

/**
 * @param userFetchMode the KWUserFetchMode to fetch data with
 * @return an initialized KWUserObjectController with the currently authenticated KWUser
 */
- (id)initWithMode:(KWUserFetchMode)userFetchMode;

@end
