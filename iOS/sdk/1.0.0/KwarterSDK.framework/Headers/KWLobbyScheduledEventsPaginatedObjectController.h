//
//  KWLobbyScheduledEventsPaginatedObjectController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 10/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWPaginatedObjectController.h"

/**
 * This object controller is responsible for recovering scheduled
 * app-wide events, KWEvent models.
 *
 * @since 1.0.0
 */
@interface KWLobbyScheduledEventsPaginatedObjectController : KWPaginatedObjectController

/**
 * Tag used to filter the loby live event with.
 */
@property (nonatomic, strong, readonly) NSString *filterTag;

/**
 * Init the object controller with the given tag.
 * @param filterTag The tag to filter the loby live event with.
 */
- (id)initWithTag:(NSString *)filterTag;

@end
