//
//  DPK_NW_Application.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/24.
//  Copyright © 2018 GT. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "GTTCPSocket.h"
#import "MyUserModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface DPK_NW_Application : NSObject<DPKTCPSocketSink>{
    NSMutableArray* m_roomSocketArray;   //房间socket保存数组
}
@property(nonatomic, assign)BOOL isLogon;   //是否已经登录?
@property(nonatomic, strong)MyUserModel * localUserModel;   //用户本地数据
//@property(nonatomic, strong)ClientConfigParam* clientConfigParam; //客户端配置数据
//@property(nonatomic, strong)TempQueryVCBSvrInfo* tmpQueryVCBSvrInfo;  //临时查询服务器结果信息
//@property(nonatomic, strong)TempCreateRoomInfo * tempCreateRoomInfo; //临时创建房间数据
//@property(nonatomic, strong)TempJoinRoomInfo * tempJoinRoomInfo;     //临时加入房间信息

@property(nonatomic, strong)NSMutableArray* giftList;   //礼物配置
@property(nonatomic, strong)NSMutableArray* giftGroup; //礼物配置
+(DPK_NW_Application*) sharedInstance;

+(NSString *)md5:(NSString *)str;
@end

NS_ASSUME_NONNULL_END
