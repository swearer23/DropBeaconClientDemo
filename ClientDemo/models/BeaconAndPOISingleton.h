//
//  BeaconAndPOISingleton.h
//  DropBeaconSDK
//
//  Created by niexin on 3/22/14.
//  Copyright (c) 2014 edaoyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BeaconAndPOISingleton : NSObject

@property(nonatomic,retain)NSMutableArray *scandBeaconArray;
@property(nonatomic,retain)NSMutableArray *canPopPOIArray;

+(instancetype)sharedManager;

@end
