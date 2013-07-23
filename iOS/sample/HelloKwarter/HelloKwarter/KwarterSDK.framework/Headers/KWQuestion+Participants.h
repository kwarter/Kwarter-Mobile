//
//  KWQuestion+Participants.h
//  KwarterMobile
//
//  Created by Stoyan Gaydarov on 2/4/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWQuestion.h"

/**
 * This category provides convenient methods for replacing
 * {{participant_*}} tags within strings found in this question's
 * KWQuestionTemplate with the appropriate participant name.
 *
 * @since 1.0.0
 */
@interface KWQuestion (Participants)

/**
 * A method for replacing the {{participant_*}} tag
 * within a given string with the question's event participants.
 *
 * @param inString The string to replace participants in.
 * @return The inString with it's {{participant_*}} tags replaced.
 */
- (NSString *)replaceParticipants:(NSString *)inString;

/**
 * Convenience for calling [KWQuestion replaceParticipants:] with
 * the title of the user's choice of this KWQuestion.
 *
 * @return The user's selected choice title with it's {{participant_*}} tags replaced.
 */
- (NSString *)replaceUserChoice;

/**
 * Convenience for calling [KWQuestion replaceParticipants:] with
 * the title of the correct choice of this KWQuestion.
 *
 * @return The correct choice title with it's {{participant_*}} tags replaced.
 */
- (NSString *)replaceCorrectChoice;

/**
 * A static method for replacing the {{participant_*}} tag
 * within a given string with event's participants.
 *
 * @param inString The string to replace participants in.
 * @param event The event to use when replacing participants.
 * @return The inString with it's {{participant_*}} tags replaced.
 */
+ (NSString *)replaceParticipants:(NSString *)inString withEvent:(KWEvent *)event;

@end
