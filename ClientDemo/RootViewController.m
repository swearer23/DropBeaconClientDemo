//
//  RootViewController.m
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-16.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import "RootViewController.h"
#import "DropBeaconManager.h"
#import "DBPoi.h"
#import "EnclosedDBBeaconRegion.h"

@interface RootViewController ()

@end

@implementation RootViewController
{
    DropBeaconManager * _dbManager;
    NSArray * _enclosedDBBeaconRegionList;
}

- (void)onAuthenticationFailed
{
    
}

- (void)onAuthenticationSuccess
{
    if ([DropBeaconManager isDeviceSupported]) {
        NSLog(@"---------authentication success----------------");
        [_dbManager startScan];
    }
}

- (void)didDiscoverInfoToShow:(DBPoi *)poi
{
    [self.poiView removeFromSuperview];
    UIView *backView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 320, 480)];
    self.poiView = [_dbManager showPOIViewWithpoi:poi View:backView AndFrame:CGRectMake(0, 100, 320, 380)];
    [self.view addSubview:self.poiView];
    
    
    //保存可显示的poi
    //BeaconAndPOISingleton *sharedSingleton = [BeaconAndPOISingleton sharedManager];
    //[sharedSingleton.canPopPOIArray addObject:poi];
    
}

- (void)didDiscoverRegionInBackground:(DBPoi *)poi
{
    [_dbManager fireNotificationWhenDiscoveredRegionInBackground:poi];
}

- (void)didDiscoverRegionWhenTerminated
{
    [_dbManager fireNotificationWhenDiscoveredRegionInTermination:@"hello world 你好世界"];
}

- (void)didRangedDBBeaconRegions:(NSArray *)dbBeaconRegionList
{
    _enclosedDBBeaconRegionList = dbBeaconRegionList;
    [self.tableView reloadData];
}

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    _dbManager = [DropBeaconManager sharedManager];
    _dbManager.delegate = self;
    
    [_dbManager setAuthenticationToken:@"{{your auth token here}}" andSecret:@"{{your auth secret here}}"];
    
    [_dbManager verifyAuthenticationInfo];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return [_enclosedDBBeaconRegionList count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil)
	{
		cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier];
		cell.selectionStyle = UITableViewStylePlain;
	}
    
    EnclosedDBBeaconRegion * dbBeaconRegion = [_enclosedDBBeaconRegionList objectAtIndex:indexPath.row];
    cell.textLabel.text = dbBeaconRegion.name;
    cell.detailTextLabel.text = [NSString stringWithFormat:@"距离: %f, 预设范围: %@, 是否进入: %@",dbBeaconRegion.distance , dbBeaconRegion.preDefineDistance , dbBeaconRegion.isInValidRange ? @"yes" : @"no"];
    return cell;
}


/*
 // Override to support conditional editing of the table view.
 - (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
 {
 // Return NO if you do not want the specified item to be editable.
 return YES;
 }
 */

/*
 // Override to support editing the table view.
 - (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
 {
 if (editingStyle == UITableViewCellEditingStyleDelete) {
 // Delete the row from the data source
 [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
 } else if (editingStyle == UITableViewCellEditingStyleInsert) {
 // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
 }
 }
 */

/*
 // Override to support rearranging the table view.
 - (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
 {
 }
 */

/*
 // Override to support conditional rearranging of the table view.
 - (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
 {
 // Return NO if you do not want the item to be re-orderable.
 return YES;
 }
 */

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
 {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

@end
