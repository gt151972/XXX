//
//  DPK_NW_Application.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/24.
//  Copyright © 2018 GT. All rights reserved.
//

#import "DPK_NW_Application.h"
#define typeCount 6

static DPK_NW_Application* DPKApp_ShareObj =nil;
@interface DPK_NW_Application()
@property (nonatomic, strong)NSMutableArray *array;
@end
@implementation DPK_NW_Application
+(DPK_NW_Application*) sharedInstance
{
    //NSLog(@"DPK_NW_Application:sharedInstance");
    @synchronized(self) {
        if(DPKApp_ShareObj ==nil) {
            DPKApp_ShareObj =[[self alloc] init];
        }
    }
    return DPKApp_ShareObj;
}

+(id)allocWithZone:(NSZone *)zone
{
    NSLog(@"DPK_NW_Application:allocWithZone");
    @synchronized(self) {
        if(DPKApp_ShareObj ==nil) {
            DPKApp_ShareObj =[super allocWithZone:zone];
            DPKApp_ShareObj.localUserModel = [[MyUserModel alloc]init];
            DPKApp_ShareObj->m_roomSocketArray = [NSMutableArray array];
            //DPKApp_ShareObj.giftConf =[NSMutableArray array];
            //DPKApp_ShareObj.defaultServerAddr = DEFAULT_SERVER_ADDRESS;
            //DPKApp_ShareObj.defaultServerPort = DEFAULT_SERVER_PORT;
            return DPKApp_ShareObj;
        }
    }
    return nil;
}

@end
