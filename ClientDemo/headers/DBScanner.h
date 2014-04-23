//
//  DBScanner.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-14.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocationManagerDelegate.h>

@class DBScanner;

@protocol DBScannerDelegate <NSObject>

@required
- (void)scanner:(DBScanner *) scanner didRangedDBBeaconRegion : (NSArray *) regionList;
- (void)scanner:(DBScanner *) scanner didDiscoverBeaconRegionInBackground : (id) region;
- (void)scanner:(DBScanner *) scanner didDiscoverBeaconRegionInForeground : (id) region;
- (void)scanner:(DBScanner *) scanner didDiscoverBeaconRegionWhenTerminated : (id) region;
@end

@interface DBScanner : NSObject <CLLocationManagerDelegate>
@property id<DBScannerDelegate> delegate;
- (void)startScan;
@end
