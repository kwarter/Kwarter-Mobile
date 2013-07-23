//
//  KWQuestion+SubmitAnswer.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/28/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWQuestion.h"

#define MAX_ANSWER_RETRY_COUNT 5

/**
 * This category is a convenience for submitting the user's
 * answer to this question to Kwarter.
 *
 * @since 1.0.0
 */
@interface KWQuestion (SubmitAnswer)

/**
 * Sends the user's selected choice to Kwarter. This method will
 * attempt to send the request MAX_ANSWER_RETRY_COUNT times before
 * giving up at which point if it does, will reset the user's selection
 * to nil and save the object.
 */
- (void)sendAnswer;

@end
