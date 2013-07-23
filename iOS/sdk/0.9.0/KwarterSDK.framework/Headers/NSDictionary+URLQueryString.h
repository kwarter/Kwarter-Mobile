//
//  NSDictionary+URLQueryString.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 07/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This category will convert your NSDictionary into a UTF8
 * NSString for use in a URL as paramaters.
 *
 * @since 1.0.0
 */
@interface NSDictionary (URLQueryString)

/**
 * Return a UTF8 encoded string of keys and values. For example @{@"key": @"param", @"key2": @"param2"} 
 * becomes @"key=param&key2=param2".
 * @return The UTF8 encoded string of keys and values.
 */
- (NSString *)URLQueryString;

@end
