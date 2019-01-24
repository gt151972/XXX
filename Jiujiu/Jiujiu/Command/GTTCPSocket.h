//
//  GTTCPSocket.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/18.
//  Copyright © 2018 GT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GCDAsyncSocket.h>
#import "SocketMacros.h"

#define SOCKET_TCP_BUFFER_SIZE   16384
#define SOCKET_TCP_BUFFER_MAXSIZE SOCKET_TCP_BUFFER_SIZE *10
NS_ASSUME_NONNULL_BEGIN

@class GTTCPSocket;
@protocol DPKTCPSocketSink
- (void)OnEventTCPSocketLink:(DPKTCPSocket*)sock error:(int) error_code;
- (void)OnEventTCPSocketShut:(DPKTCPSocket*)sock reason:(int)reason_code;
- (void)OnEventTCPSocketRead:(DPKTCPSocket*)sock
                        cmd1:(int)cmd1
                        cmd2:(int)cmd2
                        cmd3:(int)cmd3
                        timer:(int)timer
                      luserid:(long long)luserid
                      cguid:(char *)cguid
                     length:(int)length;
@end //GTTCPSocketSink
@protocol DPKRoomMessageSink

@required
- (void) OnDPKEventTCPSocketLink:(int)error_code;
- (void) OnDPKEventTCPSocketShut:(int)reason_code;


/**
 版本号回包

 @param nFlag 1表示客户端，2表示斗地主
 @param version 最新版本号(客户端、斗地主)
 @param nettype 其他线路 其他 0，电信 1，联通 2，移动 3，BGP 4，电信vip 101，联通vip 102，移动vip 103，BGPvip 104
 */
-(void)OnNetMsg_versionResp:(int)nFlag
                    version:(int)version
                    nettype:(NSString *)nettype;

/**
 登录回包1

 @param userid <#userid description#>
 @param caccount <#caccount description#>
 */
-(void)OnNetMsg_loginResp:(int)userid
                 caccount:(NSString *)caccount;

/**
 登录回包

 @param userid 用户ID
 @param umoney 虚拟币
 @param uscore 积分
 @param nlevel 用户等级
 @param nhonorlevel 用户荣誉等级
 @param nsinglevel 歌手等级
 @param headurl 头像ID
 @param usersex usersex description性别（0－女，1－男，2－未知）
 @param unickname 昵称
 @param cidiograph 个性签名
 @param locallogon (没用，强制为0)0:本地登陆，1：异地登陆(手机)，2：异地登陆(邮箱)，3：异地登陆
 @param lockmachine 是否锁定本机
 @param nDiscard 废弃
 @param nMoneystatus 无用
 @param nGuestChat 0：禁止游客和我聊天；1：允许游客和我聊天
 @param cguid 令牌
 @param nlevelversion 等级版本号
 @param nlevelnum 等级数量
 @param nGiftPriceSum 周一到现在的礼物总刷量
 @param content 密保问题结构
 */
-(void)OnNetMsg_loginRespM:(int)userid
                    umoney:(int)umoney
                    uscore:(int)uscore
                    nlevel:(int)nlevel
               nhonorlevel:(int)nhonorlevel
              nsingerlevel:(int)nsinglevel
                   headurl:(NSString *)headurl
                   usersex:(NSString *)usersex
                 unickname:(NSString *)unickname
                cidiograph:(NSString *)cidiograph
                locallogon:(NSString *)locallogon
               lockmachine:(int)lockmachine
                  nDiscard:(int)nDiscard
               nMoneystaus:(NSString *)nMoneystatus
                nGuestChat:(NSString *)nGuestChat
                     cguid:(NSString *)cguid
             nlevelversion:(int)nlevelversion
                 nlevelnum:(int)nlevelnum
             nGiftPriceSum:(int)nGiftPriceSum
                   content:(NSString *)content;


/**
 心跳回包

 @param nuserid 用户ID
 */
-(void)OnNetMsg_LogonHeardResp:(int)nuserid;

/**
 我的包裹

 @param nuserid 用户ID
 @param ntype 道具类型:1虚拟型，2实物型
 @param nid 道具ID
 @param nnum 道具数量
 @param picurl 图片资源地址
 @param giftname 道具名字
 */
-(void)OnNetMsg_userPacketResp:(int)nuserid
                         ntype:(int)ntype
                           nid:(int)nid
                          nnum:(int)nnum
                        picurl:(NSString *)picurl
                      giftname:(NSString *)giftname

/**
 获取元素相应的ip和port反馈

 @param nickid 线路类型 1=电信 2=网通   7=其他 默认=1
 @param linetype <#linetype description#>
 @param ip <#ip description#>
 @param port <#port description#>
 */
-(void)ipPortResp:(int)nickid
         linetype:(NSString *)linetype
               ip:(NSString *)ip
             port:(int)port;

/**
 获取我的收藏反馈

 @param nType <#nType description#>
 @param nickid <#nickid description#>
 @param openflag <#openflag description#>
 */
-(void)MycollectionResp:(int)nType
                 nickid:(int)nickid
               openflag:(NSString *)openflag;


/**
 用户常用房间IP回包

 @param userid 用户ID
 @param content 房间IP信息 变长
 */
-(void)userLoveRoomIpResp:(int)userid
                  content:(NSString *)content;


/**
 用户被冻结

 @param nUserID 用户ID
 @param nRoomID 房间ID
 @param szReason 原因
 */
-(void)UserBolckingRadio:(int)nUserID
                 nRoomID:(int)nRoomID
                szReason:(NSString *)szReason;

/**
 用户被封停

 @param nUserID 用户ID
 @param nRoomID 房间ID
 @param szReason 原因
 */
-(void)userBanRadio:(int)nUserID
            nRoomID:(int)nRoomID
           szReason:(NSString *)szReason;

/**
 重复登录(被顶号)

 @param nUserID 用户ID
 */
-(void)RepeatLogonRequest:(int)nUserID;

/**
 退出登陆错误信息
 
 @param nuserid 退出用户ID
 @param errmsg 具体错误
 */
-(void)LogonErrorre:(int)errorid
             errmsg:(NSString *)errmsg;



/**
 退出房间

 @param nickid 房间ID
 @param userid 用户ID
 */
-(void)quitroomRadio:(int)nickid
              userid:(int)userid;

/**
 加入房间回包

 @param nickid 房间ID
 @param serverid 无用
 @param userid 用户ID
 @param headpicurl
 @param unickname
 @param usersex
 @param cidiograph <#cidiograph description#>
 @param ncurLevel 当前保级进度
 @param level 消费等级或者官方等级(两个等级只能取一个)
 @param roomlevel 0表示无此等级;房间等级；身份标识：1：室主，2：副室主，3：管理员,4临管
 @param singerlevel 0表示无此等级；歌手等级
 @param honorlevel 荣誉等级
 @param ndiscount 发喇叭折扣率(以百分比形式体现)
 @param umoney <#umoney description#>
 @param sealid 印章ID
 @param roomstatus 房间状态
 @param nAttendNum 关注人数
 @param nFansNum 粉丝数量
 @param nTrumpet 1：喇叭通知，0：不需要
 @param nJoinRoomAudio 1：进房间声音提示，0：不需要
 @param nforbbitchat 禁言
 @param nCarId 座驾ID
 @param szDiscard 废弃
 @param szDiscard2 废弃
 @param szActivityStart 动星，单人的最多20个
 @param timer 通知客户端随机种子.用于安全
 @param m_nBlockBroadCast 0: 锁喇叭 1 正常
 @param m_nUserType 用户类型：0表示正常用户，1表示机器人
 @param nScore 用户积分
 @param nGiftPriceSum 用户刷量
 */
- (void)joinRoomRadio:(int)nickid
             serverid:(int)serverid
               userid:(int)userid
           headpicurl:(NSString *)headpicurl
            unickname:(NSString *)unickname
              usersex:(int)usersex
           cidiograph:(NSString *)cidiograph
            ncurLevel:(int)ncurLevel
                level:(int)level
            roomlevel:(int)roomlevel
          singerlevel:(int)singerlevel
           honorlevel:(int)honorlevel
            ndiscount:(int)ndiscount
               umoney:(int)umoney
               sealid:(int)sealid
           roomstatus:(int)roomstatus
           nAttendNum:(int)nAttendNum
             nFansNum:(int)nFansNum
             nTrumpet:(int)nTrumpet
       nJoinRoomAudio:(NSString *)nJoinRoomAudio
         nforbbitchat:(NSString *)nforbbitchat
               nCarId:(int)nCarId
            szDiscard:(NSString *)szDiscard
           szDiscard2:(NSString *)szDiscard2
      szActivityStart:(NSString *)szActivityStart
                timer:(int)timer
    m_nBlockBroadCast:(NSString *)m_nBlockBroadCast
          m_nUserType:(NSString *)m_nUserType
               nScore:(int)nScore
        nGiftPriceSum:(int)nGiftPriceSum;

/**
 <#Description#>

 @param nickid <#nickid description#>
 @param szroomname <#szroomname description#>
 @param ispubmic <#ispubmic description#>
 @param isprimic <#isprimic description#>
 @param issecmic <#issecmic description#>
 @param speaktime <#speaktime description#>
 @param colorbartime <#colorbartime description#>
 @param forbidPubMsg <#forbidPubMsg description#>
 @param forbidUserIOMsg <#forbidUserIOMsg description#>
 @param joinroomRule <#joinroomRule description#>
 @param nworldcastvalue <#nworldcastvalue description#>
 @param nbigcastvalue <#nbigcastvalue description#>
 @param nlockmic1 <#nlockmic1 description#>
 @param nlockmic2 <#nlockmic2 description#>
 @param nlockmic3 <#nlockmic3 description#>
 @param videoserverinfo <#videoserverinfo description#>
 @param nbarversion <#nbarversion description#>
 @param ngiftversion <#ngiftversion description#>
 @param ngiftnum <#ngiftnum description#>
 @param nbarnum <#nbarnum description#>
 @param nVideoType <#nVideoType description#>
 */
-(void)getconfigResp:(int)nickid
          szroomname:(NSString *)szroomname
            ispubmic:(NSString *)ispubmic
            isprimic:(NSString *)isprimic
            issecmic:(NSString *)issecmic
           speaktime:(int)speaktime
        colorbartime:(int)colorbartime
        forbidPubMsg:(int)forbidPubMsg
     forbidUserIOMsg:(int)forbidUserIOMsg
        joinroomRule:(int)joinroomRule
     nworldcastvalue:(int)nworldcastvalue
       nbigcastvalue:(int)nbigcastvalue
           nlockmic1:(int)nlockmic1
           nlockmic2:(int)nlockmic2
           nlockmic3:(int)nlockmic3
     videoserverinfo:(NSString *)videoserverinfo
         nbarversion:(int)nbarversion
        ngiftversion:(int)ngiftversion
            ngiftnum:(int)ngiftnum
             nbarnum:(NSString *)nbarnum
          nVideoType:(NSString *)nVideoType;

-(void)getRoomuserResp:()nickid
                userid:userid
            headpicurl:headpicurl
             unickname:unickname
               usersex:usersex
            cidiograph:cidiograph
                 level:level
            ncur_level:ncur_level
             roomlevel:roomlevel
           singerlevel:singerlevel
            honorlevel:honorlevel
              sequence:sequence
                pubmic:pubmic
                primic:primic
              unionmic:unionmic
              ndiscard:ndiscard
                sealid:sealid
           colorbarnum:colorbarnum
            roomstatus:roomstatus
@end
@interface GTTCPSocket : NSObject
{
    GCDAsyncSocket* _asyncSocket;
    __weak id<DPKTCPSocketSink> _socketSink;            //socket回调接口
    __weak id<DPKRoomMessageSink> _messageEventSink;    //message回调接口
    int  m_nRecvSize;
    char m_szRecvBuf[SOCKET_TCP_BUFFER_MAXSIZE];        //接受数据缓冲
}
@property(nonatomic, assign) int roomid;               //如果使用roomid,则使用该属性
@property(nonatomic, assign) int isConnecting;         //socket正在连接标志
@property(nonatomic, assign) int isConnected;          //socket已连接标志

// --基本方法
- (BOOL)ConnectServer:(NSString*)ipAddr ServerPort:(int)port;
- (void)CloseSocket:(int)reason_code;

- (void)SetSocketSink:(id)delegate;
- (void)SetMessageEventSink:(id)delegate;
- (id)GetMessageEventSink;

//发送数据
- (int)SendData:(int)main_cmd SubCommand:(int)sub_cmd;
- (int)SendData:(int)main_cmd SubCommand:(int)sub_cmd
           Data:(const char*)pdata
        DataLen:(int)data_len;
//处理数据
- (int)HandleData:(const char*)pdata DataLen:(int)data_len;
@end

NS_ASSUME_NONNULL_END
