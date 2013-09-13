//
//  KWIllustratedLabel.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 26/11/12.
//  Copyright (c) 2012 Kwarter. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

/**
 * These are the options for KWIllustratedLabelType
 *
 * @since 1.0.0
 */
typedef enum {
	KWIllustratedLabelTypePoints = 0,
	KWIllustratedLabelTypeCredits
} KWIllustratedLabelType;

/**
 * These are the options for KWIllustratedLabelResizingMode
 *
 * @since 1.0.0
 */
typedef enum {
	KWIllustratedLabelResizingModeFixedLeft = 0,
    KWIllustratedLabelResizingModeFixedCenter,
	KWIllustratedLabelResizingModeFixedRight
} KWIllustratedLabelResizingMode;

/**
 * These are the options for KWIllustratedLabelSize
 *
 * @since 1.0.0
 */
typedef enum {
    KWIllustratedLabelSizeSmall = 0,    // height is 24
	KWIllustratedLabelSizeNormal,       // height is 30
	KWIllustratedLabelSizeLarge         // height is 38
} KWIllustratedLabelSize;

/**
 * These are the options for KWIllustratedLabelShadowType
 *
 * @since 1.0.0
 */
typedef enum {
    KWIllustratedLabelShadowTypeNone = 0,
	KWIllustratedLabelShadowTypeBlack,
	KWIllustratedLabelShadowTypeWhite,
} KWIllustratedLabelShadowType;

/**
 * This is a helper UILabel for displaying the points or credits of a user.
 *
 * @since 1.0.0
 */
@interface KWIllustratedLabel : UILabel

/**
 * The type for this label, default is KWIllustratedLabelTypePoints.
 */
@property (nonatomic, assign) KWIllustratedLabelType type;

/**
 * The shadow type to use for this label, default is KWIllustratedLabelShadowTypeNone.
 */
@property (nonatomic, assign) KWIllustratedLabelShadowType shadowType;

/**
 * The resizing mode to use for this label, default is KWIllustratedLabelResizingModeFixedRight.
 */
@property (nonatomic, assign) KWIllustratedLabelResizingMode resizingMode;

/**
 * The size to use for this label, default is KWIllustratedLabelSizeNormal.
 */
@property (nonatomic, assign) KWIllustratedLabelSize size;

/**
 * The minWidth to use for this label, default is 48.
 */
@property (nonatomic, assign) CGFloat minWidth;

/**
 * The maxWidth to use for this label, default is 108.
 */
@property (nonatomic, assign) CGFloat maxWidth;

/**
 * Swith to an alternative representation for the score representation.
 * By default, the points have a lightning bolt icon and the credits have a money bag with
 * a Kwarter logo on it. The values are the boolean number representations @YES and @NO.
 * This property is compatible with `UIAppearance` proxy and can also be customized only for
 * a specific `KWIllustratedLabelType`.
 *
 * The alternative icon are the following:
 *
 * - For the points, a star instead of the lightning bolt
 * - For the Credits a bag without the Kwarter logo
 */
@property (nonatomic, strong) NSNumber *useAlternativeIcon UI_APPEARANCE_SELECTOR;

/**
 * Defines the label icon appearance for a specific `KWIllustratedLabelType`.
 * @param useAlternativeIcon The number representing a boolean that indicates if we are using the alternative icon.
 * @param illustratedLabelType The type of illustrated label that we want to set the alternative representation for.
 */
- (void)setUseAlternativeIcon:(NSNumber *)useAlternativeIcon forLabelType:(KWIllustratedLabelType)illustratedLabelType UI_APPEARANCE_SELECTOR;

/**
 * Returns a boolean that indicates if the label icon appearance is specific for a given `KWIllustratedLabelType`.
 * @param illustratedLabelType The type of illustrated label that we want to get the alternative representation from.
 * @return A number representing a boolean indicating if the label use the alternative representation or not.
 */
- (NSNumber *)useAlternativeIconForLabelType:(KWIllustratedLabelType)illustratedLabelType UI_APPEARANCE_SELECTOR;

/**
 * Set the label's text based on the provided number.
 * @param score The score to set in he label.
 */
- (void)setTextFromScore:(NSNumber *)score;

/**
 * Set the label's text based on the provided number, and prefix it with a '+'.
 * @param score The score to set in he label.
 */
- (void)setTextFromScoreWithPlusSign:(NSNumber *)score;

@end
