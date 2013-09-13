//
//  KWGameTemplate.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 22/01/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWEvent, KWGame, KWGameTemplateSubtype;

/**
 * The model representing the details of a game as a template.
 *
 * @since 1.0.0
 */
@interface KWGameTemplate : NSManagedObject

/**
 * The identifier for this game template.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The title of the game.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The description of the template.
 */
@property (nonatomic, strong) NSString *templateDescription;

/**
 * The event that this tempalte is associated with.
 */
@property (nonatomic, strong) KWEvent *event;

/**
 * The set of game instances based on this template.
 */
@property (nonatomic, strong) NSSet *gameSet;

/**
 * The amount of time in seconds that this game stays active for.
 */
@property (nonatomic, strong) NSNumber *countdown;

/**
 * The subtype for this tempalte, used for sorting.
 */
@property (nonatomic, strong) KWGameTemplateSubtype *subtype;

/**
 * True if this template requires a participant to be triggered, false otherwise.
 */
@property (nonatomic, strong) NSNumber *needsTeam;

/**
 * The text to use when this game shared before being completed.
 */
@property (nonatomic, strong) NSString *sharingText;

/**
 * The text to use when this game is succesfully completed.
 */
@property (nonatomic, strong) NSString *congratsText;

/**
 * The ids of the apps the GameTemplate is targeted for
 */
@property (nonatomic, strong) NSSet *applicationSet;

/**
 * YES if the gameTemplate's applicationSet contains the current app
 */
@property (nonatomic, assign, readonly) BOOL isAvailableInCurrentApplication;



/**
 * @return YES if all the fields have been loaded, or if we only have a partial description of template.
 */
- (BOOL)hasAllFieldsLoaded;

@end

@interface KWGameTemplate (CoreDataGeneratedAccessors)

- (void)addGameSetObject:(KWGame *)value;
- (void)removeGameSetObject:(KWGame *)value;
- (void)addGameSet:(NSSet *)values;
- (void)removeGameSet:(NSSet *)values;

@end
