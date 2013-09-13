//
//  KWEventRealTimeController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 21/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KWEventRealTimeControllerDelegate.h"
#import "KWQuestionTemplateChoice.h"
#import "KWQuestion.h"
#import "KWBadge.h"
#import "KWEvent.h"

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
 * The timeline is the event's list of games. These can be Questions or Badges. The easiest way 
 * to manage the event's state and the incoming games is to use the EventRealTimeController. It 
 * will do the automatic fetching, keep track of expiring questions and also update the user's 
 * score. The main communications point is the interface/protocol that the controller exposes. 
 * You can also configure the controller by specifying which game mechanics you want to enable, if 
 * you don't want to use badges you can turn that feature off with the mechanics flag in the 
 * constructor.
 *
 * @since 1.0.0
 */
@interface KWEventRealTimeController : NSObject

/**
 * The number of unanswered questions in the currently checked-in event.
 */
@property (nonatomic, assign, readonly) NSInteger unansweredQuestionCount;

/**
 * The current user leadearboard rank in the currently checked-in event.
 */
@property (nonatomic, assign, readonly) NSNumber *leaderboardRankForCurrentUser;

/**
 * The current user points in the currently checked-in event.
 */
@property (nonatomic, assign, readonly) NSNumber *pointsForCurrentUser;

/**
 * The current user credits in the currently checked-in event.
 */
@property (nonatomic, assign, readonly) NSNumber *creditsForCurrentUser;

/**
 * The current user question ratio in the currently checked-in event.
 */
@property (nonatomic, assign, readonly) NSNumber *questionRatioForCurrentUser;

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
 * Remove a KWEventRealTimeControllerDelegate to the collection
 * of delegates listening to this KWEventRealTimeController.
 * @param delegate The delegate class to remove.
 */
- (void)removeDelegate:(id<KWEventRealTimeControllerDelegate>)delegate;

/**
 * Removes all references to any KWEventRealTimeControllerDelegate listening to this
 * KWEventRealTimeController.
 */
- (void)removeAllDelegates;

/**
 * Call this method when the user has started participating in the event. This method must be called in order to
 * begin updates. The user have to be authenticated to use this, or the eventRealTimeControllerDidFailToCheckin:
 * will be called on the delegate.
 */
- (void)checkin;

/**
 * Call this method when a user no longer wishes to participate in the
 * event.
 */
- (void)checkout;

/**
 * @return the current KWEvent that has been checked into
 */
- (KWEvent *)currentCheckedInEvent;

/**
 * Notify the KWEventRealTimeController that a previously received KWBadge
 * has been caught by the user.
 * @param badge The badge that have been caught.
 */
- (void)catchBadge:(KWBadge *)badge;

/**
 * Notify the KWEventRealTimeController that a previously received KWQuestion
 * has been answered by the user.
 * @param question The question to answer.
 * @param choice The user choice for this question.
 */
- (void)answerQuestion:(KWQuestion *)question withChoice:(KWQuestionTemplateChoice *)choice;

@end

/**
 * The event real time controller shared instance gives you an easy access to the 
 * KWEventRealTimeController instance for an event.
 *
 * @since 1.0.0
 */
@interface KWEventRealTimeController (SharedInstance)

/**
 * Register an event realtime controller to the shared instance.
 * @param eventRealTimeController The event real time controller to register.
 */
+ (void)registerEventRealTimeController:(KWEventRealTimeController *)eventRealTimeController;

/**
 * Unregister an event realtime controller from the shared instance.
 * @param eventRealTimeController The event real time controller to register.
 */
+ (void)unregisterEventRealTimeController:(KWEventRealTimeController *)eventRealTimeController;

/**
 * Access the shared instance to get the event real time controller associated with an event.
 * @param event The event used to retrieve the event real time controller. The event cannot be nil or an exception
 * will be raised.
 * @param shouldCreate A boolean that indicates if the function should create the event realtime for this event
 * if it's nil. If creation is enabled, the event real time controller created will enable all the game mechanics 
 * using KWEventRealTimeControllerGameMechanicAll. If creation is not enabled, if the event real time controller 
 * is nil, nil will be returned.
 * @return The event real time controller associated with the event.
 */
+ (KWEventRealTimeController *)eventRealTimeControllerForEvent:(KWEvent *)event createIfNil:(BOOL)shouldCreate;

@end
