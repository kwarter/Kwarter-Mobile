//
//  KWEventClient.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 21/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWEvent.h"

typedef enum {
	KWEventFetchModeBasic,
	KWEventFetchModeDefinition,
    KWEventFetchModeFull
} KWEventFetchMode;

/**
 * Client for API calls relative to the KWEvent objects.
 *
 * @since 1.0
 */
@interface KWEventClient : NSObject

typedef void (^KWEventClientCompletionBlock)(id result, NSError *error);

/**
 * Check the current user into the event specified in parameter.
 * User have to he authenticated to be able to update, if not the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param eventIdentifier The event identifier whe want to checkin in. Mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param block The block executed when the checkin complete.
 */
- (void)checkinIntoEventWithIdentifier:(NSString *)eventIdentifier completion:(KWEventClientCompletionBlock)block;

/**
 * Returns the event with the specified identifier using different modes:
 *
 * - Basic: Returns the event description for this event identifier for history display (participants, scores, artwork)
 * - Definition: Returns the event cached with it's (participants, game templates)
 * - Full: Returns the full event (definition + basic + period and game type)
 *
 * @param eventIdentifier The eventIdentifier is mandatory, if missing the completion block will be called with the error `KWClientErrorMissingParameterError`.
 * @param eventFetchMode The eventIdentifier is mandatory, if invalid the completion block will be called with the error `KWClientErrorInvalidParameterError`.
 * @param block The block to receive the results.
 */
- (void)getEventWithIdentifier:(NSString *)eventIdentifier
                          mode:(KWEventFetchMode)eventFetchMode
                    completion:(KWEventClientCompletionBlock)block;

@end
