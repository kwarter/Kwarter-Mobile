//
//  KWGameTemplateSubtype.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 4/24/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class KWGameTemplate;

/**
 * The model representing the subtype for a game template.
 *
 * @since 1.0.0
 */
@interface KWGameTemplateSubtype : NSManagedObject

/**
 * The title for this subtype.
 */
@property (nonatomic, strong) NSString *title;

/**
 * The identifier for this subtype.
 */
@property (nonatomic, strong) NSString *identifier;

/**
 * The set of game templates that belong to this sub type.
 */
@property (nonatomic, strong) NSSet *gameTemplateSet;

@end

@interface KWGameTemplateSubtype (CoreDataGeneratedAccessors)

- (void)addGameTemplateSetObject:(KWGameTemplate *)value;
- (void)removeGameTemplateSetObject:(KWGameTemplate *)value;
- (void)addGameTemplateSet:(NSSet *)values;
- (void)removeGameTemplateSet:(NSSet *)values;

@end
