//
//  KWCustomLobbyItem.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 1/30/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "KWLobby.h"

/**
 * The model representing a custom item to be shown in the lobby.
 *
 * @since 1.0.0
 */
@interface KWCustomLobbyItem : NSManagedObject

/**
 * The identifier for this item.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The URL to redirect to once selected.
 * This can start with kwarter:// in the case that
 * we want to redirect to the reward list or a specific reward.
 */
@property (nonatomic, strong) NSString *itemURLString;

/**
 * The title to use for this lobby item.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The index in the lobby for this custom item.
 */
@property (nonatomic, strong) NSNumber *index;

/**
 * The artwork to use when showing this item.
 */
@property (nonatomic, strong) NSString *itemArtworkURLString;

/**
 * The lobby this item belongs to.
 */
@property (nonatomic, strong) KWLobby *lobby;

/**
 * True if this menu item has an artwork title.
 */
@property (nonatomic, strong) NSNumber *hasArtworkTitle;

@end
