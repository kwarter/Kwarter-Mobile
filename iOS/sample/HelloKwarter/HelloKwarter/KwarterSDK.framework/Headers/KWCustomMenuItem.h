//
//  KWCustomMenuItem.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 2/5/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class represents a single custom menu item which can be
 * associated with a KWEvent or a KWApplication. They are typically
 * presented as additional points of navigation to the user.
 *
 * @since 1.0.0
 */
@interface KWCustomMenuItem : NSObject <NSCoding>

/**
 * The artwork associated for this menu item's icon when not selected.
 */
@property (strong, nonatomic) NSString *artworkURLString;

/**
 * The artwork associated for this menu item's icon when selected.
 */
@property (strong, nonatomic) NSString *artworkOnURLString;

/**
 * The title of the menu item.
 */
@property (strong, nonatomic) NSString *title;

/**
 * The URL which this menu item redirects users to.
 */
@property (strong, nonatomic) NSURL *url;

@end
