//
//  KWEventMasterClient.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/29/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWEvent.h"
#import "KWQuestion.h"
#import "KWParticipant.h"
#import "KWQuestionTemplate.h"

/**
 * Client for API calls related to event master functions.
 *
 * @since 1.0
 */
@interface KWEventMasterClient : NSObject

typedef void (^KWEventMasterClientCompletionBlock)(BOOL result, NSError *error);

/**
 * Set the score for the given event.
 *
 * @param scores The scores are mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param period The period is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param state The state is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)setScore:(NSDictionary *)scores andPeriod:(NSString *)period andState:(NSString *)state forEvent:(KWEvent *)event completion:(KWEventMasterClientCompletionBlock)block;

/**
 * Create a new game based on the given template id. If the template requires a participant then there will be an error given to the callback.
 *
 * @param gameTemplate The game template is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)triggerNewGame:(KWGameTemplate *)gameTemplate forEvent:(KWEvent *)event completion:(KWEventMasterClientCompletionBlock)block;

/**
 * Create a new game based on the given template id and the chosen participant. If the template requires a participant.
 * and no participant has been passed in then there will be an error given to the callback.
 *
 * @param gameTemplate The game template is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param participant The participant is optional. A game can just be triggered or can be triggered for a specific participant. If there is no participant, prefer to use triggerNewGame:forEvent:completion:
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)triggerNewGame:(KWGameTemplate *)gameTemplate withParticipant:(KWParticipant *)participant forEvent:(KWEvent *)event completion:(KWEventMasterClientCompletionBlock)block;

/**
 * Tell the server what the correct answer for the given question is.
 *
 * @param question The question is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param choiceIdentifier The choice identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)setResultForQuestion:(KWQuestion *)question withChoiceIdentifier:(NSString *)choiceIdentifier completion:(KWEventMasterClientCompletionBlock)block;

/**
 * Tell the server your suggestion for a new question/badge.
 * @param text is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)suggest:(NSString *)text forEvent:(KWEvent *)event completion:(KWEventMasterClientCompletionBlock)block;

@end
