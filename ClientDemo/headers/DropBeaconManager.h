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
@class DBBasicSetting;
@class DropBeaconManager;

@protocol DropBeaconManagerDelegate <NSObject>
@optional
/* 蓝牙状态或定位状态发生变化*/
- (void)updateScannerStatus:(DropBeaconManager *)dropBeaconManager;
/* 正在读取POI信息*/
- (void)loadingPOIData;
/* 读取POI信息成功*/
- (void)loadingPOIDataOK;
/* 读取POI信息失败*/
- (void)loadingPOIDataFailed;
/* 正在为POI准备WebView数据*/
- (void)beginPreparePOIWebViewForPOI:(DBPoi *)poi;

@required
/* 扫描发现beacon*/
- (void)didDiscoverInfoToShow:(DBPoi *)poi ;
/* 应用在退到后台时，扫描到beacon*/
- (void)didDiscoverRegionInBackground:(DBPoi *)poi;
/* 应用未开启时扫描发现beacon*/
- (void)didDiscoverRegionWhenTerminated;
/* 扫描到的beacon列表*/
- (void)didRangedDBBeaconRegions : (NSArray *) dbBeaconRegionList;
- (void)didExitDBBeaconRegions : (NSArray *) dbBeaconRegionList;
/* 生成requesttoken成功回调方法*/
- (void)onAuthenticationSuccess;
/* 生成requesttoken失败回调方法*/
- (void)onAuthenticationFailed;

@end

@interface DropBeaconManager : NSObject <DBScannerDelegate , DBDisplayManagerDelegate>
@property (nonatomic , strong) id<DropBeaconManagerDelegate> delegate;
@property (nonatomic , strong)DBAuthentication * dbAuthentication;
@property (nonatomic , strong)DBBasicSetting *dbBasicSetting;


+ (DropBeaconManager *)sharedManager;
+ (BOOL) isLocationServiceEnabled;
+ (BOOL) isDeviceSupported;
+ (BOOL) isBLEEnabled;
- (void) startScan;
- (void) setAuthenticationToken : (NSString *)authToken andSecret : (NSString *)authSecret;
- (void) verifyAuthenticationInfo;
- (UIView *)showPOIViewWithpoi:(DBPoi *)poi View:(UIView *)view AndFrame:(CGRect)frame;
- (void) fireNotificationWhenDiscoveredRegionInBackground : (DBPoi *) poi;
- (void) fireNotificationWhenDiscoveredRegionInTermination : (NSString *) notificationBody;

@end