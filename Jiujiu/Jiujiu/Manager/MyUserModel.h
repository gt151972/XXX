//
//  MyUserModel.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/17.
//  Copyright © 2018 GT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MyUserModel : NSObject
@property(nonatomic, assign) int userid; //用户ID
@property(nonatomic, assign) int nlevel;    //用户等级
@property(nonatomic, assign) int nhonorlevel; //用户荣誉等级
@property(nonatomic, assign) int nsingerlevel; //歌手等级
@property(nonatomic, assign) int64_t uscore;    //积分
@property(nonatomic, assign) int64_t umoney;    //虚拟币
@property(nonatomic, strong) NSString* unickname;//昵称
@property(nonatomic, strong) NSString* headurl; //头像ID
@property(nonatomic, strong) NSString* usersex; //性别（0－女，1－男，2－未知
@property(nonatomic, strong) NSString* cidiograph;//签名
@property(nonatomic, strong) NSString* locallogon;//是否被关注
@property(nonatomic, assign) int lockmachine; //是否锁定本机
@property(nonatomic, assign) int nDiscard;    //废弃
@property(nonatomic, assign) int nlevelversion;    //等级版本号
@property(nonatomic, assign) int nlevelnum; //等级数量
@property(nonatomic, assign) int nGiftPriceSum; //周一到现在的礼物总刷量
@property(nonatomic, strong) NSString* nMoneystatus; //无用
@property(nonatomic, strong) NSString* nGuestChat; //0：禁止游客和我聊天；1：允许游客和我聊天
@property(nonatomic, strong) NSString* cguid;//令牌
@property(nonatomic, strong) NSString* content;//密保问题结构
@end

NS_ASSUME_NONNULL_END
