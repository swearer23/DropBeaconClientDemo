//
//  DBBasicSetting.h
//  DropBeaconSDK
//
//  Created by niexin on 4/23/14.
//  Copyright (c) 2014 杨 世伟. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DBBasicSetting : NSObject

@property(nonatomic,assign) int notificationTimeInterVal;
@property(nonatomic,assign) int popTimeInterval;
@property(nonatomic,assign) int beaconListUpdateInterval;
@property(nonatomic,assign) int beaconPOIUpdateInterval;

@property(nonatomic,retain,readonly) NSString *sdkVersionNumber;

+(instancetype)sharedManager;
@end
