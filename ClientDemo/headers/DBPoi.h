//
//  DBPoi.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-4-15.
//  Copyright (c) 2014年 杨 世伟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * DropBeaconPOI: 表示与DropBeacon关联的信息。
 * 一个DropBeacon会关联一个或一个以上的DropBeaconPOI
 */
@interface DBPoi : NSObject<NSCoding,NSCopying>

+ (instancetype)poiWithData:(NSDictionary *)data;

+ (NSArray *)getPOIsInCacheByPMMID:(NSString *)pmmid;

+ (void)setPOIs:(NSArray *)pois inCacheByPMMID:(NSString *)pmmid;

- (void) setPmmid : (NSString *) pmmid;

@property (nonatomic, readonly) NSString * identifier;

@property (nonatomic, readonly) NSString * pmmid;

@property (nonatomic, readonly) NSString * name;

@property (nonatomic, readonly) NSString * description;

@property (nonatomic, readonly) NSArray * images;

@property (nonatomic, readonly) NSString * url;

@property (nonatomic, readonly) NSString * logo;

@property (nonatomic, readonly) NSString * type;

@property (nonatomic, readonly) NSDictionary * extendInfo;

@property (nonatomic, readonly) NSInteger prepopDuration;

@property (nonatomic, readonly) NSNumber *preDefineDistance;



@end

