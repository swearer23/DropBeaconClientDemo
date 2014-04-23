//
//  EnclosedDBBeaconRegion.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-22.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EnclosedDBBeaconRegion : NSObject
@property (nonatomic , readonly) NSString * pmmid;
@property NSInteger duration;
@property NSTimeInterval foundTimestamp;
@property (nonatomic)BOOL isInValidRange;
@property (nonatomic, readonly) NSString * name;
@property (nonatomic, readonly) NSString * description;
@property (nonatomic, readonly) NSInteger prepopDuration;
@property (nonatomic, readonly) NSNumber * preDefineDistance;
@property (nonatomic, readonly) double distance;
- (instancetype) initWithDBBeaconRegion : (id) dbBeaconRegion;
@end
