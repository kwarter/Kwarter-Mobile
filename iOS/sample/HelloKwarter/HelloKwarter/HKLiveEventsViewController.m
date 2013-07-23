//
//  HKLiveEventsViewController.m
//  HelloKwarter
//
//  Created by Ludovic Landry on 7/17/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "HKLiveEventsViewController.h"

@interface HKLiveEventsViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) IBOutlet UITableView *tableView;
@property (nonatomic, strong) KWLobbyLiveEventsPaginatedObjectController *lobbyLiveEventsPaginatedObjectController;
@end

@implementation HKLiveEventsViewController

@synthesize lobbyLiveEventsPaginatedObjectController;

- (id)init {
    self = [super init];
    if (self) {
        self.title = NSLocalizedString(@"Live Events", nil);
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
	
    self.lobbyLiveEventsPaginatedObjectController.updatesPeriodically = YES;
    [self.lobbyLiveEventsPaginatedObjectController fetchFirstPageWithMode:KWObjectControllerFetchLocallyAndRemotely completionBlock:^(KWObjectControllerFetchMode fetchMode, id result, NSError *error) {
        
        // If everithing went fine
        if (!error) {
            [self.tableView reloadData];
            
        // If we got an error when fetching
        } else {
            [self displayError:error];
        }
    }];
}

- (KWLobbyLiveEventsPaginatedObjectController *)lobbyLiveEventsPaginatedObjectController {
    if (!lobbyLiveEventsPaginatedObjectController) {
        lobbyLiveEventsPaginatedObjectController = [[KWLobbyLiveEventsPaginatedObjectController alloc] init];
    }
    return lobbyLiveEventsPaginatedObjectController;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.lobbyLiveEventsPaginatedObjectController.content count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }
    
    // Get the event from the object controller and configure the cell
    KWEvent *event = [self.lobbyLiveEventsPaginatedObjectController.content objectAtIndex:indexPath.row];
    KWParticipant *firstTeam = [event.participantOrderedSet objectAtIndex:0];
    KWParticipant *secondTeam = [event.participantOrderedSet objectAtIndex:1];
    cell.textLabel.text = [NSString stringWithFormat:@"%@ vs %@", firstTeam.shortname, secondTeam.shortname];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (void)displayError:(NSError *)error {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error"
                                                    message:[error domain]
                                                   delegate:nil
                                          cancelButtonTitle:@"Ok"
                                          otherButtonTitles:nil];
    [alert show];
}

@end
