//
//  KwarterMacros.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 1/31/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIScreen.h>
#import "KWEnvironment.h"

#ifndef KWARTER_MACROS_H
#define KWARTER_MACROS_H

#define KWLogDebugERTC(fmt, ...) _KWLogDebug(KWEnvironmentKeyDebugERTC, fmt, ##__VA_ARGS__);
#define KWLogDebugMappers(fmt, ...) _KWLogDebug(KWEnvironmentKeyDebugMappers, (@"%s:%03d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define KWLogDebugVerbose(fmt, ...) _KWLogDebug(KWEnvironmentKeyDebugVerbose, (@"%s:%03d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

/**
 * A convenient macro for checking whether the device is a long-form iPhone 4" model.
 */
#define IS_IPHONE_4_INCH ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [[UIScreen mainScreen] bounds].size.height == 568.0f)

/**
 * A convinient method to specify the value you vant as pixel instead of points.
 */
static inline CGFloat KWPixelValue(CGFloat pixel) {
    return pixel / [[UIScreen mainScreen] scale];
}

/**
 * Used by macros for loging with different debug modes as keys.
 */
static inline void _KWLogDebug(NSString *key, NSString *format, ...) {
    NSDictionary *settings = [KWEnvironment sharedEnvironment].settings;
    if ([[settings objectForKey:key] boolValue]) {
        
        va_list args, args_copy;
        va_start(args, format);
        va_copy(args_copy, args);
        va_end(args);
        
        NSString *va_args = [[NSString alloc] initWithFormat:format arguments:args_copy];
        NSLog(@"%@", va_args);
        va_end(args_copy);
    }
}

#endif
