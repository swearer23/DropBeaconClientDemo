//
//  DBAuthentication.h
//  DropBeaconSDK
//
//  Created by 杨 世伟 on 14-3-18.
//  Copyright (c) 2014年 edaoyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DBAuthentication : NSObject
@property NSString *authToken;
@property NSString *authSecret;
@property NSString *requestToken;
- (DBAuthentication *) initWithAuthToken:(NSString *) authToken andAuthSecret:(NSString *) authSecret;
- (BOOL)generateRequestToken;
- (void)refresh;
@end
