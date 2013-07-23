//
//  KWUserTrophiesPaginatedObjectController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 2/14/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWPaginatedObjectController.h"
#import "KWUser.h"

/**
 * This ObjectController manages recovering a user's Trophy
 * collection.
 *
 * @since 1.0
 */
@interface KWUserTrophiesPaginatedObjectController : KWPaginatedObjectController

/**
 * @param user A KWUser to fetch Trophy objects for.
 * @return a KWUserTrophiesPaginatedObjectController initialized with the given KWUser.
 */
- (id)initWithUser:(KWUser *)user;

@end
