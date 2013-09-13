//
//  KWQuestionTemplate.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 22/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "KWGameTemplate.h"

@class KWQuestionTemplateChoice;

/**
 * The model representing a badge template for an event.
 *
 * @since 1.0.0
 */
@interface KWQuestionTemplate : KWGameTemplate

/**
 * The title for this question.
 */
@property (nonatomic, strong) NSString *questionTitle;

/**
 * The set of KWQuestionTemplateChoice available for this template.
 */
@property (nonatomic, strong) NSOrderedSet *questionTemplateChoiceOrderedSet;

/**
 * The artwork to use for the question.
 */
@property (nonatomic, strong) NSString *artworkURLString;

/**
 * The text to use when sharing the congratulations announcement.
 */
@property (nonatomic, strong) NSString *sharingCongratsText;

/**
 * This determines if the question end time is relative to the event start.
 */
@property (nonatomic, strong) NSNumber *hasRelativeCountdown;

@end

@interface KWQuestionTemplate (CoreDataGeneratedAccessors)

- (void)insertObject:(KWQuestionTemplateChoice *)value inQuestionTemplateChoiceOrderedSetAtIndex:(NSUInteger)idx;
- (void)removeObjectFromQuestionTemplateChoiceOrderedSetAtIndex:(NSUInteger)idx;
- (void)insertQuestionTemplateChoiceOrderedSet:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeQuestionTemplateChoiceOrderedSetAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInQuestionTemplateChoiceOrderedSetAtIndex:(NSUInteger)idx withObject:(KWQuestionTemplateChoice *)value;
- (void)replaceQuestionTemplateChoiceOrderedSetAtIndexes:(NSIndexSet *)indexes withQuestionTemplateChoiceOrderedSet:(NSArray *)values;
- (void)addQuestionTemplateChoiceOrderedSetObject:(KWQuestionTemplateChoice *)value;
- (void)removeQuestionTemplateChoiceOrderedSetObject:(KWQuestionTemplateChoice *)value;
- (void)addQuestionTemplateChoiceOrderedSet:(NSOrderedSet *)values;
- (void)removeQuestionTemplateChoiceOrderedSet:(NSOrderedSet *)values;

@end
