//
//  BeaconAndPOISingleton.m
//  DropBeaconSDK
//
//  Created by niexin on 3/22/14.
//  Copyright (c) 2014 edaoyou. All rights reserved.
//

#import "BeaconAndPOISingleton.h"

@implementation BeaconAndPOISingleton

@synthesize scandBeaconArray;
@synthesize canPopPOIArray;


+(instancetype)sharedManager
{
    static BeaconAndPOISingleton *sharedManager = nil;
    static dispatch_once_t once_token;
    dispatch_once(&once_token,^{
        sharedManager = [[self alloc] init];
    });
    return sharedManager;
}

-(id)init
{
    if (self = [super init]) {
        scandBeaconArray = [NSMutableArray arrayWithCapacity:0];
        canPopPOIArray = [NSMutableArray arrayWithCapacity:0];
    }
    return self;
}




@end
