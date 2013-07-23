//
//  KWUserHistoryPaginatedObjectController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 2/15/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWPaginatedObjectController.h"
#import "KWUser.h"

/**
 * The KWUserHistoryPaginatedObjectController manages recovering the
 * user's event history.
 *
 * @warning When fetching, can return InvalidOffsetError
 * @since 1.0.0
 */
@interface KWUserHistoryPaginatedObjectController : KWPaginatedObjectController

/**
 * Initialize the controller for a particular user
 *
 * @param user The user whose history should be recovered.
 */
- (id)initWithUser:(KWUser *)user;

@end
