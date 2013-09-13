//
//  KWEventRealTimeControllerDelegate.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 21/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KWEventRealTimeController;
@class KWLeaderboardObjectController;
@class KWAchievement;
@class KWUserLevel;
@class KWQuestion;
@class KWBadge;
@class KWEvent;

/**
 * Delegates of a KWEventRealTimeController must adopt the KWEventRealTimeControllerDelegate protocol. All the delegate methods are optionals and allow to track updates on the event, new games received and user updates as well as perform other actions.
 *
 * @since 1.0.0
 */
@protocol KWEventRealTimeControllerDelegate <NSObject>

@optional

/**
 * @name Event Updates
 */

/**
 * Notifies the delegate that the event definition finished loading. The event definition starts loading when the [KWEventRealTimeController checkin] method in KWEventRealTimeController is called.
 *
 * @param controller The controller you are associated with.
 */
- (void)eventRealTimeControllerDidLoadEventDefinition:(KWEventRealTimeController *)controller;

/**
 * Notifies the delegate that the period did update for the current event.
 *
 * @param controller The controller you are associated with.
 * @param event The event which had it's period updated.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didUpdatePeriodForEvent:(KWEvent *)event;

/**
 * Notifies the delegate that the score did update for the current event.
 *
 * @param controller The controller you are associated with.
 */
- (void)eventRealTimeControllerDidUpdateScore:(KWEventRealTimeController *)controller;

/**
 * @name Event Check-in
 */

/**
 * Notifies the delegate that the checkin succeed. After the [KWEventRealTimeController checkin] method in KWEventRealTimeController has been called.
 *
 * @param controller The controller you are associated with.
 */
- (void)eventRealTimeControllerDidCheckin:(KWEventRealTimeController *)controller;

/**
 * Notifies the delegate that the checkin failed. After the [KWEventRealTimeController checkin] method in KWEventRealTimeController has been called.
 *
 * @param controller The controller you are associated with.
 */
- (void)eventRealTimeControllerDidFailToCheckin:(KWEventRealTimeController *)controller;

/**
 * @name Timeline Updates and Games
 */

/**
 * Notifies the delegate that we received open and closed games in the timeline.
 * Called only once, after the [KWEventRealTimeController checkin] method in KWEventRealTimeController has beenc called.
 *
 * @param controller The controller you are associated with.
 * @param openGamesList A list of open games.
 * @param closedGamesList A list of closed games.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didReceiveTimelineWithOpenGames:(NSArray *)openGamesList closedGames:(NSArray *)closedGamesList;

/**
 * Notifies the delegate that the timeline has received a new badge.
 *
 * @param controller The controller you are associated with.
 * @param badge The badge which was just received.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didReceiveBadge:(KWBadge *)badge;

/**
 * Notifies the delegate that the timeline received a new question.
 *
 * @param controller The controller you are associated with.
 * @param question The question which was just received.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didReceiveQuestion:(KWQuestion *)question;

/**
 * Notifies the delegate that a question in the timeline has expired.
 *
 * @param controller The controller you are associated with.
 * @param question The question which has expired.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didExpireQuestion:(KWQuestion *)question;

/**
 * Notifies the delegate that the timeline received a response for a question.
 *
 * @param controller The controller you are associated with.
 * @param question the question which now has a correct answer.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didReceiveResponseForQuestion:(KWQuestion *)question;

/**
 * Notifies the delegate that the user just collected a badge.
 *
 * @param controller The controller you are associated with.
 * @param badge A badge which has been collected by the user.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didCollectBadge:(KWBadge *)badge;

/**
 * Notifies the delegate that the user just answered a question.
 *
 * @param controller The controller you are associated with.
 * @param question A question which has been answered by the user.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didAnswerQuestion:(KWQuestion *)question;

/**
 * Notifies the delegate that the user's question ratio has changed.
 *
 * @param controller The controller you are associated with.
 * @param ratio The percentage of correctly answered questions has been updated.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didUpdateQuestionRatioForCurrentUser:(NSNumber *)ratio;

/**
 * @name User Scores and Achievements
 */

/**
 * Notifies the delegate that the points acquired by the user during this event have changed.
 *
 * @param controller The controller you are associated with.
 * @param points The user's point value accrued during this event.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didUpdatePointsForCurrentUser:(NSNumber *)points;

/**
 * Notifies the delegate that the credits acquired by the user during this event have changed.
 *
 * @param controller The controller you are associated with.
 * @param credits The user's credit value accrued during this event.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didUpdateCreditsForCurrentUser:(NSNumber *)credits;

/**
 * Notifies the delegate that the user's rank in the event leaderboard has changed.
 *
 * @param controller The controller you are associated with.
 * @param rank The user's new rank in the event leaderboard.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didUpdateLeaderboardRankForCurrentUser:(NSNumber *)rank;

/**
 * Notifies the delegate that the user received a victory in the current event.
 *
 * @param controller The controller you are associated with.
 * @param event The `KWEvent` associated with this KWEventRealTimeController that the user has won.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didReceiveEventVictoryForCurrentUser:(KWEvent *)event;

/**
 * Notifies the delegate that the user has reached the next level.
 *
 * @param controller The controller you are associated with.
 * @param level The new level which the user has reached.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didLevelUpForCurrentUser:(KWUserLevel *)level;

/**
 * Notifies the delegate that the user unlocked an achievement
 *
 * @param controller The controller you are associated with.
 * @param achievement The achievement that the user unlocked.
 */
- (void)eventRealTimeController:(KWEventRealTimeController *)controller didUnlockAchievementForCurrentUser:(KWAchievement *)achievement;

@end
