//
//  DBScanner.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-14.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocationManagerDelegate.h>

typedef NS_ENUM(NSInteger, DBScannerStatus) {
    DBScannerStatusIsWorking = 0,
    DBScannerStatusLocationUnavailable,
    DBScannerStatusBLEUnavailable,
    DBScannerStatusOtherError
};

@class DBScanner;
@class DBPoi;

@protocol DBScannerDelegate <NSObject>

@optional

- (void)scanner:(DBScanner *) scanner updateScannerStatus:(DBScannerStatus)status;
- (void)scannerIsLoadingPOIData:(DBScanner *) scanner;
- (void)scannerLoadingPOIDataFailed:(DBScanner *) scanner;
- (void)scannerLoadingPOIDataOK:(DBScanner *) scanner;

@required
- (void)scanner:(DBScanner *) scanner didRangedDBBeaconRegion : (NSArray *) regionList;
- (void)scanner:(DBScanner *) scanner didDiscoverBeaconRegionInBackground : (id) region;
- (void)scanner:(DBScanner *) scanner didDiscoverBeaconRegionInForeground : (id) region;
- (void)scanner:(DBScanner *) scanner didDiscoverBeaconRegionWhenTerminated : (id) region;
@end

@interface DBScanner : NSObject <CLLocationManagerDelegate>
@property id<DBScannerDelegate> delegate;
+ (instancetype)sharedScanner;
- (void)startScan;
@end
