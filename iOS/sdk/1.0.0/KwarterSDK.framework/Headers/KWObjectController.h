//
//  KWObjectController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 01/12/12.
//  Copyright (c) 2012 Kwarter, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 * This enum represents the means by which the KWObjectController
 * can fetch data.
 */
typedef enum {
    
    /**
     * Local fetch, pull from local cache.
     */
	KWObjectControllerFetchLocally   = 1 << 0,
    
    /**
     * Remote fetch, pull from the Kwarter platform server.
     */
    KWObjectControllerFetchRemotely  = 1 << 1,
    
    /**
     * Both, combine local and remote fetches.
     */
    KWObjectControllerFetchLocallyAndRemotely = KWObjectControllerFetchLocally | KWObjectControllerFetchRemotely,
    
} KWObjectControllerFetchMode;

typedef void (^KWObjectControllerCompletionBlock)(KWObjectControllerFetchMode fetchMode, id result, NSError *error);

/**
 * The KWObjectController is a base class designed to manage
 * the synchronization of data between the Kwarter platform
 * and the device.
 *
 * By extending this class, you may pull and cache results
 * from the Kwarter platform for a particular model type.
 *
 * This base class enables periodic updating and management of
 * the most recently retrieved data.
 *
 * @since 1.0.0
 */
@interface KWObjectController : NSObject

/**
 * The cached data that this KWObjectController is managing. All
 * fetches are saved as reference to this property.
 */
@property (nonatomic, strong, readonly) id content;

/**
 * The NSManagedObjectContext used to save any updates to core
 * data.
 */
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;

/**
 * If `YES`, the KWObjectController will save after each successful
 * recovery of its content.
 */
@property (nonatomic, assign) BOOL automaticallySavesManagedObjectContextOnSuccess;

/**
 * If `YES`, the KWObjectController is currently in the process
 * of pulling data from the Kwarter platform.
 */
@property (nonatomic, readonly, getter = isSyncing) BOOL syncing;

/**
 * If `YES`, this KWObjectController will fetch the data periodically
 * using the periodicUpdateFetchMode.
 */
@property (nonatomic, assign) BOOL updatesPeriodically;

/**
 * The periodic update time (seconds).
 */
@property (nonatomic, assign) NSTimeInterval periodicUpdatesTimeInterval;

/**
 * Fetch the object(s) managed by this KWObjectController with the given mode.
 *
 * @param fetchMode The KWObjectControllerFetchMode to use when fetching.
 */
- (void)fetchObjectWithMode:(KWObjectControllerFetchMode)fetchMode;

/**
 * Fetch the object(s) managed by this KWObjectController with the given mode.
 *
 * @param fetchMode The KWObjectControllerFetchMode to use when fetching.
 * @param block Will receive the result of the fetch.
 */
- (void)fetchObjectWithMode:(KWObjectControllerFetchMode)fetchMode completionBlock:(KWObjectControllerCompletionBlock)block;

/**
 * Sub-classes should override.
 *
 * The extending class should fetch the requested object(s) from the
 * database.
 *
 * @param block The KWObjectControllerCompletionBlock to receive the result.
 */
- (void)fetchObjectLocallyWithCompletionBlock:(KWObjectControllerCompletionBlock)block;

/**
 * Sub-classes should override.
 *
 * The extending class should fetch the requested object(s) from the
 * Kwarter platform.
 *
 * @param block The KWObjectControllerCompletionBlock to receive the result.
 */
- (void)fetchObjectRemotelyWithCompletionBlock:(KWObjectControllerCompletionBlock)block;

/**
 * Sub-classes should override.
 *
 * @return `YES` if the object(s) can be fetched locally
 */
- (BOOL)canFetchObjectLocally;

/**
 * Sub-classes should override as well as call super.
 *
 * @return `YES` if the object(s) can be fetched remotely.
 */
- (BOOL)canFetchObjectRemotely;

@end
