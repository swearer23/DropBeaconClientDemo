//
//  RootViewController.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-16.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DropBeaconManager.h"

@interface RootViewController : UITableViewController <DropBeaconManagerDelegate>
@property (nonatomic,retain) UIView *poiView;
@end
