//
//  NSString+URLEncoding.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 30/11/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This category provides a convenient method for encoding
 * an NSString into an escaped string for use in a URL.
 *
 * @since 1.0.0
 */
@interface NSString (URLEncoding)

/**
 * @param encoding The encoding to use when escaping special
 * character in this string.
 * @return An encoded string based on the provided encoding.
 */
- (NSString *)urlEncodeUsingEncoding:(NSStringEncoding)encoding;

@end
