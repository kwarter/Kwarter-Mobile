//
//  KWLobbyClient.h
//  KwarterSDK
//
//  Created by Ludo on 26/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import "KWLobby.h"

typedef void (^KWLobbyClientCompletionBlock)(id result, NSError *error);

/**
 * Client for API calls relative to the lobby items.
 *
 * @since 1.0
 */
@interface KWLobbyClient : NSObject

/**
 * The Application lobby, it is the common lobby. If it has not been created before, recovering
 * it from this property will do so.
 */
+ (KWLobby *)applicationLobby;

/**
 * Returns custom items in the lobby. To get all the items with pagination, use `getLobbyCustomItemsWithOffset:limit:completion:`.
 * @param block The block to receive the result.
 */
- (void)getLobbyCustomItemsWithCompletion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns custom items in the lobby paginated.
 * @param offset The index from which to start.
 * @param limit If the limit is invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the result.
 */
- (void)getLobbyCustomItemsWithOffset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns live events in the lobby. To get all the events with pagination, use `getLobbyLiveEventsWithOffset:limit:completion:`.
 * @param block The block to receive the result.
 */
- (void)getLobbyLiveEventsWithCompletion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns live events in the lobby paginated.
 * @param offset The index from which to start.
 * @param limit is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the result.
 */
- (void)getLobbyLiveEventsWithOffset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns live events in the lobby paginated, filtered by tag.
 * @param filterTag is not mandatory, used to filter the events.
 * @param offset The index from which to start.
 * @param limit is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the result.
 */
- (void)getLobbyLiveEventsWithFilterTag:(NSString *)filterTag offset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns scheduled events in the lobby. To get all the events with pagination, use `getLobbyScheduledEventsWithOffset:limit:completion:`.
 * @param block The block to receive the result.
 */
- (void)getLobbyScheduledEventsWithCompletion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns scheduled events in the lobby paginated.
 * @param offset The index from which to start.
 * @param limit is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the result.
 */
- (void)getLobbyScheduledEventsWithOffset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWLobbyClientCompletionBlock)block;

/**
 * Returns scheduled events in the lobby paginated.
 * @param filterTag is not mandatory, used to filter the events.
 * @param offset The index from which to start.
 * @param limit is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the result.
 */
- (void)getLobbyScheduledEventsWithFilterTag:(NSString *)filterTag offset:(NSUInteger)offset limit:(NSUInteger)limit completion:(KWLobbyClientCompletionBlock)block;

@end
