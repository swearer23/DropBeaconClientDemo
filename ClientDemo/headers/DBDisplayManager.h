//
//  DBDisplayBeaconInfo.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-3-19.
//  Copyright (c) 2014年 edaoyou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DBPoi.h"

@class DBDisplayManager;

@protocol DBDisplayManagerDelegate <NSObject>
- (void)dbDisplayManager:(DBDisplayManager *)displayManager displayDidPrepared:(DBPoi *)poi;
@end

@interface DBDisplayManager : NSObject <UIWebViewDelegate>
@property id<DBDisplayManagerDelegate> delegate;
- (DBDisplayManager *)initWithDBPoi:(DBPoi *) poi;
- (void)loadPoiView;
@end