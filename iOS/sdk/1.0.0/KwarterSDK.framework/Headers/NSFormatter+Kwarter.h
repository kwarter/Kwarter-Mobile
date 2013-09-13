//
//  NSFormatter+Kwarter.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 5/22/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This a helper class for convenient access
 * to common NSFormatter variants used throughout
 * the application.
 *
 * @since 1.0.0
 */
@interface NSFormatter (Kwarter)

/**
 * A formatter which returns a short date and no time.
 * @return The date formater with short style.
 */
+ (NSDateFormatter *)formatterDateShortStyle;

/**
 * Formats without a date and uses a medium time style.
 * @return The date formater with medium style.
 */
+ (NSDateFormatter *)formatterTimeMediumStyle;

/**
 * Formats a decimal number limiting it to a single decimal place.
 * @return The number formater with decimal style.
 */
+ (NSNumberFormatter *)formatterNumberDecimalStyle;

@end
