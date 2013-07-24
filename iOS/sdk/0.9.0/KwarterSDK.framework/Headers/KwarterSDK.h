//
//  KwarterSDK.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 02/11/12.
//  Copyright (c) 2012 Kwarter. All rights reserved.
//

// Umbrella header

// Configuration & Tools
#import <KwarterSDK/Kwarter.h>
#import <KwarterSDK/KwarterMacros.h>
#import <KwarterSDK/KWEnvironment.h>

// Analytics
#import <KwarterSDK/KWAnalytics.h>
#import <KwarterSDK/KWAnalyticsWorker.h>

// Controllers + SDK Logic
#import <KwarterSDK/KWDocumentManager.h>
#import <KwarterSDK/KWEventRealTimeController.h>
#import <KwarterSDK/KWEventRealTimeControllerDelegate.h>
#import <KwarterSDK/KWLoginManager.h>
#import <KwarterSDK/KWReminderManager.h>

// Data Controllers
#import <KwarterSDK/KWObjectController.h>
#import <KwarterSDK/KWUserObjectController.h>
#import <KwarterSDK/KWLeaderboardObjectController.h>
#import <KwarterSDK/KWRewardObjectController.h>
#import <KwarterSDK/KWPaginatedObjectController.h>
#import <KwarterSDK/KWLobbyCustomItemsPaginatedObjectController.h>
#import <KwarterSDK/KWLobbyLiveEventsPaginatedObjectController.h>
#import <KwarterSDK/KWLobbyScheduledEventsPaginatedObjectController.h>
#import <KwarterSDK/KWRewardsPaginatedObjectController.h>
#import <KwarterSDK/KWUserTrophiesPaginatedObjectController.h>
#import <KwarterSDK/KWUserHistoryPaginatedObjectController.h>

// API Clients
#import <KwarterSDK/KWAchievementClient.h>
#import <KwarterSDK/KWApplicationClient.h>
#import <KwarterSDK/KWEventClient.h>
#import <KwarterSDK/KWEventMasterClient.h>
#import <KwarterSDK/KWGameClient.h>
#import <KwarterSDK/KWLeaderboardClient.h>
#import <KwarterSDK/KWLobbyClient.h>
#import <KwarterSDK/KWRewardClient.h>
#import <KwarterSDK/KWUserClient.h>

// Models
#import <KwarterSDK/KWAchievement.h>
#import <KwarterSDK/KWApplication.h>
#import <KwarterSDK/KWBadge.h>
#import <KwarterSDK/KWBadgeTemplate.h>
#import <KwarterSDK/KWCustomLobbyItem.h>
#import <KwarterSDK/KWCustomMenuItem.h>
#import <KwarterSDK/KWEvent.h>
#import <KwarterSDK/KWEventMaster.h>
#import <KwarterSDK/KWEventPeriod.h>
#import <KwarterSDK/KWEventType.h>
#import <KwarterSDK/KWGame.h>
#import <KwarterSDK/KWGameTemplate.h>
#import <KwarterSDK/KWGameTemplateSubtype.h>
#import <KwarterSDK/KWLeaderboard.h>
#import <KwarterSDK/KWLeaderboardUser.h>
#import <KWarterSDK/KWLobby.h>
#import <KwarterSDK/KWParticipant.h>
#import <KwarterSDK/KWQuestion.h>
#import <KwarterSDK/KWQuestionTemplate.h>
#import <KwarterSDK/KWQuestionTemplateChoice.h>
#import <KwarterSDK/KWReward.h>
#import <KwarterSDK/KWRewardCatalogue.h>
#import <KwarterSDK/KWTagMenuItem.h>
#import <KwarterSDK/KWTrophy.h>
#import <KwarterSDK/KWUser.h>
#import <KwarterSDK/KWUserLevel.h>

// UI
#import <KwarterSDK/KWIllustratedLabel.h>

// Categories
#import <KwarterSDK/NSArray+KWQuestion.h>
#import <KwarterSDK/NSDictionary+URLQueryString.h>
#import <KwarterSDK/NSObject+Registration.h>
#import <KwarterSDK/NSFormatter+Kwarter.h>
#import <KwarterSDK/NSString+URLEncoding.h>
#import <KwarterSDK/KWBadge+SubmitCatch.h>
#import <KwarterSDK/KWQuestion+Participants.h>
#import <KwarterSDK/KWQuestion+SubmitAnswer.h>
