//
//  KWGameClient.h
//  KwarterSDK
//
//  Created by Stoyan Gaydarov on 1/25/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWQuestion.h"
#import "KWEvent.h"
#import "KWBadge.h"

typedef void (^KWTimelineClientCompletionBlock)(NSArray *games, NSError *error);
typedef void (^KWGameClientGenericCompletionBlock)(id result, NSError *error);
typedef void (^KWGameClientCompletionBlock)(BOOL succeed, NSError *error);

/**
 * Client for API calls related to recovering game data.
 *
 * @since 1.0.0
 */
@interface KWGameClient : NSObject

/**
 * Pull the games for the given event. Only returns the games targeted for the current app, except if the current user is a Game Master, in which case all games are returned. 
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getGamesForEvent:(KWEvent *)event completion:(KWTimelineClientCompletionBlock)block;

/**
 * Pull the new games for the event after the given game. Only returns the games targeted for the current app, except if the current user is a Game Master, in which case all games are returned. 
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param game The game is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getGamesForEvent:(KWEvent *)event sinceGame:(KWGame *)game completion:(KWTimelineClientCompletionBlock)block;

/**
 * Pull the new games for the event after the given game identifier. Only returns the games targeted for the current app, except if the current user is a Game Master, in which case all games are returned. 
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param gameIdentifier The game identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getGamesForEvent:(KWEvent *)event sinceGameWithIdentifier:(NSString *)gameIdentifier completion:(KWTimelineClientCompletionBlock)block;

/**
 * Tell the server which choice the user made, the user must have been authenticated to be able to update,
 * if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param question The question is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError` or `KWClientErrorInvalidParameterError`if invalid.
 * @param choiceIdentifier The choice identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)answerQuestion:(KWQuestion *)question withChoiceIdentifier:(NSString *)choiceIdentifier completion:(KWGameClientCompletionBlock)block;

/**
 * Tell the server that the user caught a badge, the user must have been authenticated to be able to update,
 * if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param badge The badge is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError` or `KWClientErrorInvalidParameterError`if invalid.
 * @param block The block to receive the results.
 */
- (void)catchBadge:(KWBadge *)badge completion:(KWGameClientCompletionBlock)block;

/**
 * Grab the game information for the given game object.
 * @param game The game is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError` or `KWClientErrorInvalidParameterError`if invalid.
 * @param block The block to receive the results.
 */
- (void)getInfoForGame:(KWGame *)game completion:(KWGameClientCompletionBlock)block;

/**
 * Check if the current user has replied to the games passed in, all the games have to be part of the same event.
 * the user must have been authenticated to be able to update, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param games The game list is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError` or `KWClientErrorInvalidParameterError`if invalid.
 * @param event The event is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getCheckForGames:(NSArray *)games withEvent:(KWEvent *)event completion:(KWGameClientGenericCompletionBlock)block;

/**
 * Check if the current user has replied to the games passed in, all the games have to be part of the same event.
 * the user must have been authenticated to be able to update, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param games The game list is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError` or `KWClientErrorInvalidParameterError`if invalid.
 * @param eventIdentifier The event identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getCheckForGames:(NSArray *)games withEventIdentifier:(NSString *)eventIdentifier completion:(KWGameClientGenericCompletionBlock)block;

/**
 * Check the status of the games passed in, all the games have to be part of the same event.
 * @param games is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError` or `KWClientErrorInvalidParameterError`if invalid.
 * @param block The block to receive the results.
 */
- (void)getStatusForGames:(NSArray *)games completion:(KWGameClientGenericCompletionBlock)block;

/**
 * Pull the game template for the given game identifier.
 * @param identifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block to receive the results.
 */
- (void)getGameTemplateWithIdentifier:(NSString *)identifier completion:(KWGameClientGenericCompletionBlock)block;

@end
