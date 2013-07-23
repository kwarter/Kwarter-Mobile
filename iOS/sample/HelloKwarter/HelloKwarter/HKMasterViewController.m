//
//  HKMasterViewController.m
//  HelloKwarter
//
//  Created by Ludovic Landry on 7/18/13.
//  Copyright (c) 2013 Kwarter, inc. All rights reserved.
//

#import "HKMasterViewController.h"
#import "HKLiveEventsViewController.h"

@implementation HKMasterViewController

- (id)init {
    self = [super init];
    if (self) {
        self.title = NSLocalizedString(@"HelloKwarter", nil);
    }
    return self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table View

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}

// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }

    cell.textLabel.text = @"Live Events";
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    HKLiveEventsViewController *liveEventsViewController = [[HKLiveEventsViewController alloc] init];
    [self.navigationController pushViewController:liveEventsViewController animated:YES];
}

@end
