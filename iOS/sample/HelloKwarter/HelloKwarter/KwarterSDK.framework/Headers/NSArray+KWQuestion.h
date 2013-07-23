//
//  NSArray+KWQuestion.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 2/8/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This category provides convenient methods for sorting
 * an NSArray consisting of KWQuestions.
 *
 * @since 1.0.0
 */
@interface NSArray (KWQuestion)

/**
 * @return A sorted array for use in the timeline. It sorts by status
 * and then by end time. [{OPEN+UNANSWERED},{OPEN+ANSWERED},{CLOSED}].
 */
- (NSArray *)sortedQuestionArrayForTimeline;

/**
 * @return A sorted NSArray descending by expiration time, from soonest to
 * latest.
 */
- (NSArray *)sortedQuestionArrayForQueuing;

@end
