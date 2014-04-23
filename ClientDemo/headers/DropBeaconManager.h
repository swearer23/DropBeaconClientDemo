//
//  DropBeaconManager.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-14.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DBAuthentication.h"
#import "DBScanner.h"
#import "DBDisplayManager.h"

@protocol DropBeaconManagerDelegate <NSObject>
@required
- (void)didDiscoverInfoToShow:(DBPoi *)poi;
- (void)didDiscoverRegionInBackground:(DBPoi *)poi;
- (void)didDiscoverRegionWhenTerminated;
- (void)didRangedDBBeaconRegions : (NSArray *) dbBeaconRegionList;
- (void)onAuthenticationSuccess;
- (void)onAuthenticationFailed;
@end

@interface DropBeaconManager : NSObject <DBScannerDelegate , DBDisplayManagerDelegate>
@property (nonatomic , strong) id<DropBeaconManagerDelegate> delegate;
@property (nonatomic , strong)DBAuthentication * dbAuthentication;
+ (DropBeaconManager *)sharedManager;
+ (BOOL) isDeviceSupported;
- (void) startScan;
- (void) setAuthenticationToken : (NSString *)authToken andSecret : (NSString *)authSecret;
- (void) verifyAuthenticationInfo;
- (UIView *)showPOIViewWithpoi:(DBPoi *)poi View:(UIView *)view AndFrame:(CGRect)frame;
- (void) fireNotificationWhenDiscoveredRegionInBackground : (DBPoi *) poi;
- (void) fireNotificationWhenDiscoveredRegionInTermination : (NSString *) notificationBody;
@end