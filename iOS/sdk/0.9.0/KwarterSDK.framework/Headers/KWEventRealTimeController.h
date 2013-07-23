//
//  KWEventRealTimeController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 21/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWEventRealTimeControllerDelegate.h"
#import "KWEvent.h"
#import "KWBadge.h"

/**
 * These mechanics are what the KWEventRealTimeController currently
 * manages for each event, you can limit the updates that its delegates
 * receive by initializing it with a subset of these mechanics.
 *
 * @since 1.0.0
 */
typedef enum {
	KWEventRealTimeControllerGameMechanicBadges         = 1 << 0,
	KWEventRealTimeControllerGameMechanicQuestions      = 1 << 1,
    KWEventRealTimeControllerGameMechanicAll            =
        KWEventRealTimeControllerGameMechanicBadges |
        KWEventRealTimeControllerGameMechanicQuestions
} KWEventRealTimeControllerGameMechanic;

/**
 * The KWEventRealTimeController manages relating updates about
 * its event to all interested parties. It manages handling the
 * state of games and leaderboard associated with the event.
 *
 * @since 1.0.0
 */
@interface KWEventRealTimeController : NSObject

/**
 * Initialize the KWEventRealTimeController with a KWEvent and KWEventRealTimeControllerGameMechanic.
 *
 * @param event - the event to pull game data for
 * @param gameMechanics - the mechanics you wish to enable
 */
- (id)initWithEvent:(KWEvent *)event andGameMechanics:(KWEventRealTimeControllerGameMechanic)gameMechanics;

/**
 * Append a KWEventRealTimeControllerDelegate to the collection
 * of delegates listening to this KWEventRealTimeController.
 * @param delegate The delegate class to add.
 */
- (void)addDelegate:(id<KWEventRealTimeControllerDelegate>)delegate;

/**
 * Removes all references to any KWEventRealTimeControllerDelegate listening to this
 * KWEventRealTimeController.
 */
- (void)removeAllDelegates;

/**
 * Call this method when the user has started participating in the event.
 * This method must be called in order to begin updates.
 */
- (void)checkin;

/**
 * Call this method when a user no longer wishes to participate in the
 * event.
 */
- (void)checkout;

/**
 * Notify this KWEventRealTimeController that a previously received KWBadge
 * has been caught by the user.
 * @param badge The badge that have been caught.
 */
- (void)didCatchBadge:(KWBadge *)badge;

/**
 * @return the current KWEvent that has been checked into
 */
- (KWEvent *)currentCheckedInEvent;

/**
 * @return the number of unanswered questions in the currently
 * checked-into event.
 */
- (int)getUnansweredQuestionCount;

@end
