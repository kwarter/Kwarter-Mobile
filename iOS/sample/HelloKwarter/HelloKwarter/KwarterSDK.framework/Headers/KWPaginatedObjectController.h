//
//  KWPaginatedObjectController.h
//  KwarterSDK
//
//  Created by Ludovic Landry on 4/18/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "KWObjectController.h"

/**
 * The KWPaginatedObjectController is a special base extension
 * of the KWObjectController that is designed to recover a list of
 * objects. It can recover them page by page in order to reduce
 * the computation and request size on the Kwarter platform.
 *
 * @since 1.0.0
 */
@interface KWPaginatedObjectController : KWObjectController

/**
 * The content is always an array of items so we have
 * redefined the content property.
 */
@property (nonatomic, strong, readonly) NSArray *content;

/**
 * If `YES`, this KWPaginatedObjectController will delete
 * old items from CoreData when they are no longer found on
 * the Kwarter platform.
 *
 * @default `NO`
 */
@property (nonatomic, assign) BOOL shouldClearOldContent;

/**
 * This represents the number of items which will be recovered
 * per page.
 *
 * @default `10`
 */
@property (nonatomic, assign, readonly) NSUInteger pageSize;

/**
 * `YES` if and only if the KWPaginatedObjectController has recovered
 * all items from the Kwarter platform.
 */
@property (nonatomic, assign, readonly) BOOL isFullyLoaded;

/**
 * Initializes the KWPaginatedObjectController with a pageSize
 * of `10`
 */
- (id)init;

/**
 * Initializes the KWPaginatedObjectController with the given page size.
 * @param pageSize the number of objects to recover with each page
 */
- (id)initWithPageSize:(NSUInteger)pageSize;

/**
 * Fetch the first page of items.
 * @param fetchMode The mode with which to fetch it.
 * @param block The block to receive the result.
 */
- (void)fetchFirstPageWithMode:(KWObjectControllerFetchMode)fetchMode completionBlock:(KWObjectControllerCompletionBlock)block;

/**
 * This method will fetch the next page with mode KWObjectControllerFetchRemotely.
 * @param block The block to receive the results.
 */
- (void)fetchNextPage:(KWObjectControllerCompletionBlock)block;

/**
 * Sub-classes should override.
 *
 * @param offset The index from which to start.
 * @param limit The number of items to retrieve.
 * @param block The block to receive results.
 */
- (void)fetchObjectRemotelyWithOffset:(NSUInteger)offset limit:(NSUInteger)limit completionBlock:(KWObjectControllerCompletionBlock)block;

@end
