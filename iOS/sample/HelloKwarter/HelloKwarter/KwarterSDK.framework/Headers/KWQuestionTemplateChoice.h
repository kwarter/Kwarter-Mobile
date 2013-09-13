//
//  KWQuestionTemplateChoice.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 6/6/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWQuestionTemplate;

/**
 * Represents a choice for a particular KWQuestionTemplate.
 *
 * @since 1.0.0
 */
@interface KWQuestionTemplateChoice : NSManagedObject

/**
 * Unique identifier for this KWQuestionTemplateChoice.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The number of Credits the user will earn for this choice.
 */
@property (nonatomic, strong) NSNumber *credits;

/**
 * The title of this choice.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The number of Points the user will earn for this choice.
 */
@property (nonatomic, strong) NSNumber *points;

/**
 * The template that this KWQuestionTemplateChoice associates with.
 */
@property (nonatomic, strong) KWQuestionTemplate *questionTemplate;

@end
