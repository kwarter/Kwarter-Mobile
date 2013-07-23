//
//  KWQuestion.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/22/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <CoreData/CoreData.h>
#import "KWGame.h"

@class KWQuestionTemplate;

/**
 * The model representing a question game triggered for an event.
 *
 * @since 1.0.0
 */
@interface KWQuestion : KWGame

/**
 * The correct choice id selected by an event master.
 */
@property (nonatomic, strong) NSString *correctChoiceId;

/**
 * The user selected choice id.
 */
@property (nonatomic, strong) NSString *userSelectedChoiceId;

/**
 * The dictionary holding the information about the number of answers for each choice.
 */
@property (nonatomic, strong) NSDictionary *answerCounts;

/**
 * The template that represents this question.
 */
@property (nonatomic, strong, readonly) KWQuestionTemplate *questionTemplate;

/**
 * The user selected choice value title.
 */
@property (nonatomic, readonly) NSString *userSelectedChoice;

/**
 * The correct choice value title.
 */
@property (nonatomic, readonly) NSString *correctChoice;

@end
