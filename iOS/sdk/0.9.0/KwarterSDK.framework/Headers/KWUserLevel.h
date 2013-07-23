//
//  KWUserLevel.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 17/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * The KWUserLevel represents a KWUser's experience on the
 * Kwarter platform. 
 *
 * A KWUserLevel has a Level, a Grade and a Progress. The highest
 * magnitude value is the Grade. Each Grade is 5 Levels and the
 * Progress is how many levels the user has gained of the 5 required
 * in order to gain the next Grade.
 *
 * @since 1.0.0
 */
@interface KWUserLevel : NSObject

/**
 * The global user level, earning more Points increases the user's level.
 */
@property (nonatomic, readonly) NSInteger level;

/**
 * The grade is updated when the progress is complete, after progressing 5 times you update to a new grade.
 */
@property (nonatomic, readonly) NSInteger grade;

/**
 * Progress of the user inside its current grade.
 */
@property (nonatomic, readonly) NSInteger progress;

/**
 * Return a new instance of user level object representing the given level number.
 * @param level The level as integer used to create the KWUserLevel instance.
 * @return A new instance of KWUserLevel representing the given level number.
 */
+ (KWUserLevel *)userLevelWithLevel:(NSInteger)level;

/**
 * Return a new instance of user level object representing the given grade and progress.
 * @param grade The grade as integer used to create the KWUserLevel instance.
 * @param progress The progress as integer used to create the KWUserLevel instance.
 * @return A new instance of KWUserLevel representing the given grade and progress.
 */
+ (KWUserLevel *)userLevelWithGrade:(NSInteger)grade andProgress:(NSInteger)progress;

/**
 * Return a new instance of user level object representing the user points acquired.
 * @param points The points as integer used to create the KWUserLevel instance.
 * @return A new instance of KWUserLevel from the number of points acquired
 * by the user.
 */
+ (KWUserLevel *)userLevelFromUserPoints:(NSInteger)points;

/**
 * @return A ready-to-display title for this KWUserLevel.
 */
- (NSString *)levelTitle;

/**
 * @return a message to display to the user when congratulating them
 * on acheiving this KwUserLevel
 */
- (NSString *)levelUpMessage;

@end
