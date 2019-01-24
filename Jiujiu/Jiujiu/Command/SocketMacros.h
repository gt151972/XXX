//
//  SocketMacros.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/14.
//  Copyright © 2018 GT. All rights reserved.
//

#ifndef SocketMacros_h
#define SocketMacros_h

#include "BaseSocket.h"

#define MXP_SUBCMD_LOGIN_VERSION_REQUEST 1061 //版本请求
#define MXP_SUBCMD_LOGIN_VERSION_RESPONSE 1062 //版本回包

#define MXP_SUBCMD_LOGIN_LOGIN_REQUEST 1003 //账号登陆请求
#define MXP_SUBCMD_LOGIN_LOGIN_RESPONSE 1004 //账号登陆回报

#define MXP_SUBCMD_LOGIN_LOGIN_REQUEST_M 1007//密码登录请求
#define MXP_SUBCMD_LOGIN_LOGIN_RESPONSE_M 1008//密码登录回包

#define MXP_SUBCMD_LOGIN_LOGIN_HEART_REQUEST 1018//心跳包
#define MXP_SUBCMD_LOGIN_LOGIN_HEART_RESPONSE 1019//心跳回包

#define MXP_SUBCMD_LOGIN_USER_PACKET_RESPONSE 1021//我的包裹回包

#define MXP_SUBCMD_LOGIN_IP_PORT_REQUEST 1032//元素相应的ip和port请求
#define MXP_SUBCMD_LOGIN_IP_PORT_RESPONSE 1033//元素相应的ip和port回包

#define MXP_SUBCMD_LOGIN_MY_COLLECTION_REQUEST 1038//获取/添加/删除我的收藏请求
#define MXP_SUBCMD_LOGIN_MY_COLLECTION_RESPONSE 1039//获取/添加/删除我的收藏回包

#define MXP_SUBCMD_LOGIN_USER_LOVE_ROOM_IP_NOTICE 1041//用户常用房间IP回包

#define MXP_SUBCMD_LOGIN_USER_BOLCKING_RADIO_NOTICE 1043//用户被冻结

#define MXP_SUBCMD_LOGIN_USER_BAN_RADIO_NOTICE 1045//用户被封停
#define MXP_SUBCMD_LOGIN_ROOM_NETWORK_CHANGE 1055//房间网关被修改,1033

#define MXP_SUBCMD_LOGIN_REPEAT_LOGON_NOTICE 1058//重复登录(被顶号)

#define MXP_SUBCMD_LOGIN_UPDATE_ROOM_BINDING_PACKAGE 1060//更新房间绑定包裹(只有该房间能用的包裹),1021
#define MXP_SUBCMD_LOGIN_LOGOUT_NOTICE 1017//退出登陆相关

#define MXP_SUBCMD_LOGIN_LOGON_ERRORRE_NOTICE 1999//错误信息

#define MXP_SOBCMD_ROOM_QUIT_ROOM_REQUEST 5001//退出房间请求
#define MXP_SUBCMD_ROOM_QIIT_ROOM_RESPONSE 5002//退出房间回包

#define MXP_SUBCMD_ROOM_JION_ROOM_REQUEST 5003//加入房间请求
#define MXP_SUBCMD_ROOM_JION_ROOM_RESPONSE 5004//加入房间回包
#define MXP_SUBCMD_ROOM_JION_ROOM_REQUEST_AGAIN 5062//重连加入房间请求
#define MXP_SUBCMD_ROOM_JION_ROOM_RESPONSE_AGAIN 5063//重连加入房间请求

#define MXP_SUBCMD_ROOM_GET_INFO_NOTICE 5006//房间配置信息
#define MXP_SUBCMD_ROOM_GET_CONFIG_NOTICE 5073//后台修改房间属性

#define MXP_SUBCMD_ROOM_GET_ROOM_USER_REQUEST 5009//房间用户请求
#define MXP_SUBCMD_ROOM_GET_ROOM_USER_RESPONSE 5010//房间用户回包

#define MXP_SUBCMD_ROOM_ROOM_USER_HEART_REQUEST 5044//房间心跳包
#define MXP_SUBCMD_ROOM_ROOM_USER_HEART_RESPONSE 5045//房间心跳回包

#define MXP_SUBCMD_ROOM_CHAT_REQUEST 5015//聊天
#define MXP_SUBCMD_ROOM_CHAT_RESPONSE_OR_RADIO 5016//聊天回包广播

#define MXP_SUBCMD_ROOM_GIFT_REQUEST 5017//正常刷礼物请求
#define MXP_SUBCMD_ROOM_GIFT_RADIO 5018//正常刷礼物广播

#define MXP_SUBCMD_ROOM_LUCKY_WINNING_RADIO 5019//幸运礼物中奖广播

#define MXP_SUBCMD_ROOM_ON_MIC_RADIO 5022//上下麦操作广播

#define MXP_SUBCMD_ROOM_COMMON_PRIVILEGE_RESPONSE 5034//房间通用权限回包

#define MXP_SUBCMD_ROOM_UPDATE_ROOM_USER_INFO_RADIO 5035//更新房间用户信息广播

#define MXP_SUBCMD_ROOM_STATE_MODIFY_RESPONSE 5038 //房间状态更改请求(隐身/在线)

#define MXP_SUBCMD_ROOM_MESSAGE_CAST_REQUEST 5039 //喇叭请求
#define MXP_SUBCMD_ROOM_MESSAGE_CAST_RESPONSE 5040 //喇叭回包

#define MXP_SUBCMD_ROOM_UPDATE_USER_SETTING_RADIO 5041//更新用户设置广播

#define MXP_SUBCMD_ROOM_OTO_MIC_RESPONSE 5047//用户一对一麦回复

#define MXP_SUBCMD_ROOM_USER_MONEY_CHANDE_RESPONSE 5057//用户金币变化

#define MXP_SUBCMD_ROOM_USER_CIDEO_CHANGE_RESPONSE 5059//视频状态变化包

#define MXP_SUBCMD_ROOM_GIFT_RUN_WAY_RADIO 5064//礼物上跑道广播

#define MXP_SUBCMD_ROOM_DELAY_GIFT_RADIO 5065//特殊礼物延迟发广播

#define MXP_SUBCMD_ROOM_USER_BLOCKING_BROAD_CAST 5068//封用户喇叭

#define MXP_SUBCMD_ROOM_QUIT_ROOM_RADIO 5069 //挤出房间广播

#define MXP_SUBCMD_ROOM_GROUP_GIFT_RESPONSE 5085//礼物群刷回包(礼物赠送通知)

#define MXP_SUBCMD_ROOM_GROUP_GIFT_RESPONSE_EX 5087 //礼物群刷回包(用户金币变化通知)

#define MXP_SUBCMD_ROOM_BOMB_OUT_ROOM_RESPONSE 5094 //炸出房间通知包

#define MXP_SUBCMD_ROOM_UNION_MIC_RESPONSE 5102 //合麦申请包回包

#define MXP_SUBCMD_ROOM_USER_LEVEL_MODIFY_RESPONSE 5108 //用户刷量达标升级回包

#define MXP_SUBCMD_ROOM_SOCKET_SURVIVAL_REQUEST 5099//确认用户socket存活询问请求包 收到发5100

#define MXP_SUBCMD_ROOM_SVR_REEOE 5999//错误包
#endif /* SocketMacros_h */

//登录
/**
 版本请求
 */
typedef struct tag_MpType_VersionRequest
{
    unsigned int    nVersion ;    //目前自己用的版本(客户端)
}VersionRequest_t;


/**
 版本回包
 */
typedef struct tag_VersionResponse
{
    short int    nFlag ;        //1表示客户端，2表示斗地主
    unsigned int version[2];        //最新版本号(客户端、斗地主)
    char        nettype;            //其他线路 其他 0，电信 1，联通 2，移动 3，BGP 4，电信vip 101，联通vip 102，移动vip 103，BGPvip 104
}VersionResponse_t;

/**
 账号登录
 */
typedef struct tag_LogonRequest
{
    unsigned short logintype;        //登陆方式0=账号登陆; 1=数字id登陆;2=游客登录; 3=无身份登录(一起动就发);10=账号登陆(手机); 11=数字id登陆(手机)
    char caccount[32];            //用户账号或用户ID
    char  cip[32];
    char cmac[32];                //用户MAC地址
    char cdisknum[32];            //硬盘序号
    char ccpunum[32];                //手机码，仅15位
    int  unionid;                    //联盟ID
    int  channelid;                //渠道ID
}LogonRequest;

//1004回包:
/**
 账号登录回包
 */
typedef struct tag_LogonResponse
{
    long long userid;
    char caccount[32];
}LogonResponse;

//1007发包:
/**
 密码登录请求
 */
typedef struct tag_LogonRequestM
{
    char szPassword[33];//密码 加密方式口述
}LogonRequestM;

//1008回包:
//表示登录成功
/**
 登陆成功回包
 */
typedef struct tag_LogonResponseM
{
    long long        userid;                        //用户ID
    long long       umoney;                        //虚拟币
    long long       uscore;                        //积分
    int                nlevel;                        //用户等级
    int                nhonorlevel;                //用户荣誉等级
    int                nsingerlevel;                //歌手等级
    char            headurl[128];                //头像ID
    char            usersex;                    //性别（0－女，1－男，2－未知）
    char            unickname[32];                //昵称
    char            cidiograph[256];            //个性签名
    char            locallogon;                    //(没用，强制为0)0:本地登陆，1：异地登陆(手机)，2：异地登陆(邮箱)，3：异地登陆(密保)
    int             lockmachine;                //是否锁定本机
    int                nDiscard;            //废弃
    char            nMoneystatus;                //无用
    char            nGuestChat;                    //0：禁止游客和我聊天；1：允许游客和我聊天
    char            cguid[33];                    //令牌
    int                nlevelversion;                //等级版本号
    int                nlevelnum;                    //等级数量
    long long        nGiftPriceSum;                //周一到现在的礼物总刷量
    char            content[0];                    //密保问题结构
}LogonResponseM;

//=================客户端登录重连======================
typedef struct tag_UserReconnectRequest
{
    long long   nUserID;                                        //用户ID
}UserReconnectRequest_t;

typedef struct tag_UserReconnectRadio
{
    long long   nUserID;                                        //用户ID
    char        nResult  ;                                        //1表示成功
}UserReconnectRadio_t;


//1018发包:
//心跳包,登录成功之后发
/**
 心跳包
 */
typedef struct tag_LogonHeartRequest
{
    long long    nuserid ;    //用户ID
}LogonHeartRequest_t;

//1019回包:
//心跳回包
typedef struct tag_LogonHeartResponse
{
    long long    nuserid ;    //用户ID
}LogonHeartResponse_t;


//1021回包:
//我的包裹
typedef struct tag_UserPacketResponse
{
    long long nuserid;                //用户ID
    int        ntype;                    //道具类型:1虚拟型，2实物型
    int        nid;                    //道具ID
    int        nnum;                    //道具数量
    char    picurl[32];                //图片资源地址
    char    giftname[32];            //道具名字
}UserPacketResponse_t;


//1032发包:
//获取元素相应的ip和port
typedef struct tag_IpPortRequest
{
    int nickid;
    char linetype;        //线路类型 1=电信 2=网通   7=其他 默认=1
}IpPortRequest;

//1033回包:
//获取元素相应的ip和port反馈
#define IP_COUNT 8
typedef struct tag_IpPortResponse
{
    int nickid;
    char linetype[IP_COUNT];    //线路类型 1=电信 2=网通   7=其他 默认=1
    char ip[IP_COUNT][20];
    unsigned short port[IP_COUNT];
}IpPortResponse;


//1038发包:
//获取/添加/删除我的收藏
typedef struct tag_MycollectionRequest
{
    long long  userid;    //用户ID
    char  mycfalg;        //0:获取; //1:增加;  //2:删除; //3多个内容查询
    int   nickid;        //房间ID
}MycollectionRequest;

//1039回包:
//获取我的收藏反馈
typedef struct tag_MycollectionResponse
{
    long long  nType;        //操作类型:0:获取; //1:增加;  //2:删除; //3多个内容查询
    int  nickid[20];        //成功的房间ID
    char openflag;        //操作是否成功 0:失败;1:成功;
    
//    tag_MycollectionResponse()
//    {
//        nType =0;
//        openflag = 0;
//    }
}MycollectionResponse;


//1041回包:
//用户常用房间IP回包
typedef struct tag_UserLoveRoomIPResponse
{
    long long        userid;                        //用户ID
    char            content[0];                    //房间IP信息 变长
}UserLoveRoomIPResponse_t;


//1043回包:
//=================用户被冻结=========================
typedef struct tag_UserBolckingRadio
{
    long long   nUserID;                        //用户ID
    int            nRoomID;                        //房间ID
    char        szReason[32];    //原因
}UserBolckingRadio_t;

//1045回包:
//=================用户被封停=========================
typedef struct tag_UserBanRadio
{
    long long   nUserID;                        //用户ID
    int            nRoomID;                        //房间ID
    char        szReason[32];        //原因
}UserBanRadio_t;

//1055回包:
//(房间网关被修改)
//结构同1033

//1058回包:
//========重复登录(被顶号)===============
typedef struct tag_RepeatLogon_Request
{
    long long nUserID ;
}RepeatLogon_Request;

//1060回包:
//更新房间绑定包裹(只有该房间能用的包裹)
//结构同1021

//1017发包:
//======退出登陆相关============
typedef struct tag_LogoutRequest
{
    long long    nuserid ;    //退出用户ID
}LogoutRequest_t;

//1999回包:
//错误信息

/**
 错误信息
 -2000 密码错误
 -1007 账号不存在或者密码错误
 -2002 您的账号已在别处登录
 -1009 登录异常
 -1111 登录失效,请重新登录
 -1002 账号不存在或者密码错误
 */
typedef struct tag_LogonErrorre
{
    int        errorid;                            //错误id.
    char       errmsg[128];                        //具体错误
//    tag_LogonErrorre() {
//        errorid = 0;
//        memset(errmsg,0,sizeof(char)*128);
//    }
}LogonErrorre;



//5001发包:
//退出房间
typedef struct tag_quitroomRequest
{
    int                nickid;        //房间ID
    long long        userid;
    unsigned short    logintype;      //登陆方式 0=账号登陆 1=数字id登陆 2=游客登录 3=无身份登录
    char                micflag;        //无用
    int                etctime;        //无用
}quitroomRequest;

//5002回包:
typedef struct tag_quitroomRadio
{
    int    nickid;
    long long    userid;
}quitroomRadio;

//5003发包:
//加入房间

//5062发包:
//重连加入房间
typedef struct tag_joinRoomRequest
{
    int    nickid;                    //房间ID
    int serverid;                    //无用
    long long userid;                //用户ID
    unsigned short logintype;        //登陆方式 0=账号登陆 1=数字id登陆 2=游客登录 3=无身份登录，5web游客登陆，10=账号登陆(手机); 11=数字id登陆(手机)
    int  roomstatus;        //房间状态
    char cip[32];                    //用户IP
    char roompwd[33];                //房间密码md5
    char cmac[32];                //用户MAC地址(电脑)，手机序列号(手机)
}joinRoomRequest;

//5004回包:

//5063回包:
typedef struct tag_joinRoomRadio
{
    int                nickid;
    int                serverid;
    long long        userid;
    char            headpicurl[32];
    char            unickname[32];
    int                usersex;
    char            cidiograph[128];
    int                ncur_level;                    //当前保级进度
    int                level;                        //消费等级或者官方等级(两个等级只能取一个)
    int                roomlevel;                    //0表示无此等级;房间等级；身份标识：1：室主，2：副室主，3：管理员,4临管
    int                singerlevel;                //0表示无此等级；歌手等级；
    int                honorlevel;                    //荣誉等级
    int                ndiscount;                    //发喇叭折扣率(以百分比形式体现)
    long long        umoney;
    int                sealid;                        //印章ID
    int        roomstatus ;                //房间状态
    unsigned int    nAttendNum;                    //关注人数
    unsigned int    nFansNum;                    //粉丝数量
    int                nTrumpet;                        //1：喇叭通知，0：不需要
    char            nJoinRoomAudio;                            //1：进房间声音提示，0：不需要
    char            nforbbitchat;                //禁言
    int                nCarId;                        //座驾ID
    char            szDiscard[20];                //废弃
    char            szDiscard2[32];                //废弃
    char            szActivityStart[20];        //活动星，单人的最多20个
    unsigned int    timer;                        //通知客户端随机种子.用于安全。
    char            m_nBlockBroadCast;            //0: 锁喇叭 1 正常
    char            m_nUserType ;                //用户类型：0表示正常用户，1表示机器人
    long long        nScore;                        //用户积分
    long long        nGiftPriceSum ;                //用户刷量
}joinRoomRadio;

//5006回包:
//房间配置信息

//5073回包:
//后台修改房间属性
typedef struct tag_getconfigResponse
{
    int        nickid;
    char        szroomname[32];            //房间名字
    char        ispubmic;                //是否允许公麦（0：禁止，1：允许）
    char        isprimic;                //是否允许私麦（0：禁止，1：允许）
    char        issecmic;                //无用
    int        speaktime;                //发言时间间隔（单位：秒）
    int        colorbartime;                //彩条发送时间间隔（单位：秒）
    int        forbidPubMsg ;            //0:禁止公聊，1：允许公聊
    int        forbidUserIOMsg;        //0：屏蔽进出消息，1：允许进出消息
    int        joinroomRule;            //房间进入规则：0 ：允许任何人；1：只允许房间管理员进(临管退出后将不再是房间管理员，所以不能进)
    int        nworldcastvalue;        //世界喇叭价格
    int        nbigcastvalue;            //大喇叭价格
    int        nsmallcastvalue;        //小喇叭价格
    int        nlockmic1;                //锁一号麦，1表示锁，0表示不锁
    int        nlockmic2;                //锁二号麦，1表示锁，0表示不锁
    int        nlockmic3;                //锁三号麦，1表示锁，0表示不锁
    char    videoserverinfo[256];    //媒体服务器列表(ip1:port1;ip2:port2..)
    int        nbarversion;            //表情、彩条版本号
    int        ngiftversion;            //礼物、盖章版本号
    int        ngiftnum;                //礼物数量
    int        nbarnum;                //彩条数量
    char    nVideoType;                //视频类型
    char    szVideoCnf[64];            //视频属性
}getconfigResponse;

//5009发包:
typedef struct tag_getRoomuserRequest
{
    int    nickid;
}getRoomuserRequest;

//5010回包:
//房间用户
typedef struct tag_getRoomuserResponse
{
    int                nickid;                    //房间号
    long long        userid;                    //用户ID
    char            headpicurl[32];            //头像路径
    char            unickname[32];            //用户昵称
    int              usersex;                //性别
    char            cidiograph[128];        //个人签名
    int                level;                    //用户等级
    int                ncur_level;                //当前保级状态
    int                roomlevel;                //0表示无此等级;房间等级；身份标识：1：室主，2：副室主，3：管理员,4临管
    int              singerlevel;            //0表示无此等级；歌手等级；
    int                honorlevel;                //荣誉等级
    int                sequence;                //麦序号 0表示没排麦，1排头位。
    char            pubmic;                    //是否在公麦（0：不是，1：是）
    char            primic;                    //是否在私麦（0：不是，1：是）
    char            unionmic;                    //是否在合麦（-1: -2: -3: -4: -5: -6 按顺序从左到右，从上到下）
    char            ndiscard;                            //废弃
    int                sealid;                    //印章ID，0表示没有。
    int                colorbarnum;            //彩条数，0表示没有。
    int        roomstatus ;            //房间状态
    int                nsequemictime;            //无用
    unsigned int    nAttendNum;                //关注人数
    unsigned int    nFans;                    //粉丝人数
    char            nforbbidchat;            //1：禁言，0:不禁言
    char            n_videostatus ;            //视频状态：0播放，1暂停
    char            n_audiostatus ;            //音频状态：0播放，1暂停
    int                nCarId;                    //座驾ID
    char            szDiscard[20];            //废弃
    char            szDiscard2[32];            //废弃
    char            szActivityStart[20];        //活动星，单人的最多20个
    char            m_nUserType;            //用户类型：0表示正常用户，1表示机器人
    long long        nGiftPriceSum;            //用户本周刷量
}getRoomuserResponse;

//5044发包:
//=========房间心跳包==============
typedef struct tag_RoomUserHeartRequest
{
    long long    nuserid ;    //用户ID
    int            nroomid ;    //房间ID
}RoomUserHeartRequest_t;

//5045回包:
typedef struct tag_RoomUserHeartResponse
{
    long long    nuserid ;    //用户ID
    int            nroomid ;    //房间ID
}RoomUserHeartResponse_t;

//5015发包:
typedef struct tag_chatRequest
{
    int    nickid;                        //本房间ID
    long long    init_userid;        //发起方用户ID
    long long    recei_userid;        //接收方ID；0表示大家
    char        chatmode;            //聊天方式;0:公聊 1:私聊 2:临时公告 4:自动回复 5:欢迎词(6:房间管理悄悄 7:房间管理公聊；8:房间艺人悄悄 9:房间艺人公聊 10:房间所有人悄悄 11:房间所有人公聊 12:游客和注册号悄悄 13:游客和注册号公聊)
    char        content[0];            //聊天内容
}chatRequest;

//5016回包:
typedef struct tag_chatResponseOrRadio
{
    int    nickid;                        //本房间ID
    long long    init_userid;        //发起方用户ID
    long long    recei_userid;        //接收方ID；0表示大家
    char        chatmode;            //聊天方式;0：公聊；1：私聊； 2：临时公告  3：广播  4:私聊自动回复，5欢迎词
    char        content[0];            //聊天内容
}chatResponseOrRadio;

//5017发包:
//正常刷礼物请求
typedef struct tag_giftRequest
{
    int            nickid;                                //本房间ID
    long long    init_userid;                        //发起方用户ID
    long long    recei_userid;                        //接收方ID；0表示大家
    int            giftid;                                //礼物ID
    int            giftnum;                            //礼物数量
    int            nDiscard;                            //废弃
    char        classtype;                            //礼物种类，可划分幸运礼物，奢侈礼物等印章无分类，全部为“默认”(2表示幸运礼物，3表示奢侈道具，4表示印章,5表示点歌包场,6点歌包场回包，7为平分 8群发 9 魔法道具 -1余额不足)
    int            ntype;                                //消费类型：0表示金币型，1表示道具类型，2表示红包,3表示点歌包场，4表示绑定烟花
    char        szMessage[64];        //赠送信息
}giftRequest;

//5018回包:
//正常刷礼物回包
typedef struct tag_giftRadio
{
    int            nickid;                            //本房间ID
    long long    init_userid;                    //发起方用户ID
    long long    init_money;                        //发起方剩下的币
    int            giftid;                            //礼物ID
    int            giftnum;                        //礼物数量
    long long    recei_userid;                    //接收方ID；0表示大家。
    long long    recei_money;                    //接收者剩下的币
    long long    recei_score;                    //接收者剩下的积分
    char            classtype;                        //礼物种类，可划分幸运礼物，奢侈礼物等印章无分类，全部为“默认”,6表示点歌包场回包
    char            szMessage[64];    //赠送信息
    char            szTime[32];                        //赠送礼物时间
    long long    nGiftPriceSum;                //客户端：刷礼物总量(从上次级别变动开始)，服务端：本次刷礼物人变动值
}giftRadio;

//5019回包:
//幸运礼物中奖
#define WIN_LIST_NUM 30
typedef struct tag_luckywinningRadio
{
    int    nickid;                                    //本房间ID
    long long    init_userid;                    //发起方用户ID
    long long    init_money;                        //发起方剩下的币
    int    giftid;                                    //礼物ID
    int winnum_ten;                                //10倍中的数量
    int winnum_fifty;                            //50倍中的数量
    int winnum_fivehundred;                        //500倍中的数量
    int win_list[WIN_LIST_NUM] ;                //中奖序列
    int winnum_onethou;                            //1000倍中的S数量
}luckywinningRadio;

//5022回包:
//上下麦操作
typedef struct tag_onmicRadio
{
    int    nickid;                        //本房间ID
    long long init_userid;            //发起方用户ID
    long long to_userid;            //被操作用户ID 无操作对象则为0
    char    micflag;                    //1:是公麦，2是私麦，3是排麦序,7合麦
    char    onmic;                    //1:上麦，2是下麦
    char    micindex;                //上公麦时，从左到右为1,2,3;其它麦时为0
    int        onmicsequetime;            //排麦时间
}onmicRadio;

//5034回包:
//房间通用权限回复
typedef struct tag_RoomCommonPrivilegeResponse {
    int result;                //操作结果
    int privilegeId;        //权限ID
    long long opUserid;        //操作者id
    long long opUserid2;    //对象id
    char errmsg[128];        //操作结果
}roomCommonPrivilegeResponse;
//===========一对一权限==================
//踢出房间
#define PRIVILEGE_KICK_USER                1
//踢出房间并拉入黑名单
#define PRIVILEGE_BLACK_LIST            2
//抱人上/下公麦
#define PRIVILEGE_MAKE_PUB_MIC            3
//邀请/取消私麦
#define PRIVILEGE_MAKE_PRI_MIC            4
//任命/解除房间临时管理员
#define PRIVILEGE_MAKE_TMP_MGR            5
//任命/解除房间管理员
#define PRIVILEGE_MAKE_MANAGER            6
//任命/解除副室主
#define PRIVILEGE_MAKE_ASS_OWNER        7
//禁止/解除禁止和我聊天
#define PRIVILEGE_CHAT_WHIT_ME            8
//禁言/解除禁言
#define PRIVILEGE_SHUTUP                9
//全站封IP、硬盘
#define PRIVILEGE_BLOCKED_IP            10
//查看用户IP
#define PRIVILEGE_LOOKUP_IP                11
//踢出房间并封IP一小时
#define PRIVILEGE_KICK_AND_BLOCKED        12
//禁止/解除任命房间主持
#define PRIVILEGE_MAKE_SINGER            13

//5035回包:
//更新房间用户信息广播
typedef struct tag_updateRoomUserInfoRadio
{
    int    nickid;
    long long userid;
    char headpicurl[32];
    char unickname[32];
    int usersex;
    char cidiograph[128];
    int level;
    int roomlevel;                    //0表示无此等级;房间等级；身份标识：1：室主，2：副室主，3：管理员,4临管
    int singerlevel;                //0表示无此等级；歌手等级；
    long long umoney;
    int sealid;                        //印章ID
    char m_nUserType;                //用户类型：0表示正常用户，1表示机器人
}updateRoomUserInfoRadio;
//房间用户信息
typedef struct tag_roomUserInfo
{
    long long userid;
    char headpicurl[32];
    char unickname[32];
    int usersex;
    char cidiograph[128];
    int level;
    int roomlevel;                    //0表示无此等级;房间等级；身份标识：1：室主，2：副室主，3：管理员,4临管
    int singerlevel;                //0表示无此等级；歌手等级；
    long long umoney;
    int sealid;                        //印章ID
    char m_nUserType;                //用户类型：0表示正常用户，1表示机器人
}roomUserInfo;

//5038回包:
//房间状态更改请求(隐身/在线)
typedef struct tag_roomStatusModifyResponse
{
    bool bResult;            //操作结果
    int roomid ;            //房间ID
    long long    userid;        //用户ID
    char headpicurl[32];
    char unickname[32];
    int usersex;
    char cidiograph[128];
    int level;
    int roomlevel;                    //0表示无此等级;房间等级；身份标识：1：室主，2：副室主，3：管理员,4临管
    int singerlevel;                //0表示无此等级；歌手等级；
    long long umoney;
    int sealid;                        //印章ID
    char m_nUserType;                //用户类型：0表示正常用户，1表示机器人ye
    char  szComment[32] ;    //备注
}roomStatusModifyResponse;

//5039发包:
//喇叭
#define ROOM_MESSAGE_CAST_CONTENT_LENGTH 700
typedef struct tag_RoomMessageCastRequest
{
    long long        userid ;                    //发起人用户ID
    int                nlevel ;                    //发起人等级
    int                nroomid;                    //发起人所在房间
    int                ntype;                        //喇叭类型 1:世界喇叭；2大喇叭；3小喇叭；4道具型世界喇叭；5道具型大喇叭；6道具型小喇叭;8幸运道具中奖喇叭，9.9999广播信息 10奢侈礼物广播信息,11 大烟花喇叭，12用户进房间喇叭通知
    char            szMessage[ROOM_MESSAGE_CAST_CONTENT_LENGTH];                //内容
}RoomMessageCastRequest_t;

//5040回包:
//喇叭回包
typedef struct tag_RoomMessageCastResponse
{
    int                nFlag ;                                    //0：需要更新货币，1，不需要更新货币
    int                nRoomid ;                                //房间ID
    long long        nUserid ;                                //发喇叭人ID
    long long       nMoney;                                    //发喇叭人剩余的金币
    int                nlevel ;                                    //发送人等级
    char            unickname[32];                                //发喇叭人昵称
    int                ntype;                                    //喇叭类型 1:世界喇叭；2大喇叭；3小喇叭；4道具型世界喇叭；5道具型大喇叭；6道具型小喇叭;7 小烟花喇叭 8幸运道具中奖喇叭，9.9999广播信息 10奢侈礼物广播信息 11 大烟花喇叭，12用户进房间喇叭通知
    char            szMessage[ROOM_MESSAGE_CAST_CONTENT_LENGTH];        //内容
}RoomMessageCastResponse_t;

//5041回包:
//更新用户设置广播
typedef struct tag_udateUserSettingRadio
{
    long long    userid ;    //用户ID
    int    nlevel ;    //消费等级
    char    usersex;    //性别（0－女，1－男，2－未知）
    char    brithday[32];    //生日
    char    unickname[32];    //昵称
    char    cidiograph[128];    //个性签名
    char    headpicurl[32];    //头像路径
    char    szDiscard[20];    //无用
    int    nSingerLevel ;    //艺人等级
    int    nSingerRoomID;    //艺人等级房间
}udateUserSettingRadio;

//5047回包:
//用户一对一麦回复
typedef struct tag_RoomOTOMicResponse
{
    int            ntype;        //2：报私麦请求;3：联合麦请求
    int            nresult;        //结果 0不同意 1同意
    long long   nsrcuserid;    //发起用户ID
    long long    ndesuserid;    //用户ID
    int            nroomid ;    //房间ID
}RoomOTOMicResponse_t;

//5057回包:
//用户金币变化
typedef struct tag_RoomUserMoneychangeResponse
{
    int            nroomid;            //房间ID
    long long    nuserid;            //用户ID
    long long    nmoney;                //用户金币
    long long    recei_score;        //用户积分
}RoomUserMoneychangeResponse_t;

//5059回包:
//视频状态变化包
typedef struct tag_RoomUserVideochangeResponse
{
    int            nroomid;            //房间ID
    long long    nuserid;            //用户ID
    char        nstatus;            //1：播放，2暂停
}RoomUserVideochangeResponse_t;

//5064回包:
//=================礼物上跑道==========================
typedef struct tag_RoomGiftRunWayRadio
{
    int            nickid;                            //本房间ID
    long long    nsrcuserid;                        //发起方用户ID
    long long    ndesuserid;                        //接收方ID；0表示大家。
    char        szsrcnick[32];                    //发起方昵称
    char        szdesnick[32];                    //接收方昵称
    int            init_level;                        //发送方消费等级
    int            recei_level ;                    //接收者消费等级
    int            giftid;                            //礼物ID
    int            giftnum;                        //礼物数量
    char        szTime[32];                        //时间
    char        bSrcHide;                        //发送人是否隐藏
    char        bDesHide;                        //接收人是否隐藏
    char        szMessage[64];    //赠送信息
}RoomGiftRunWayRadio_t;

//5065回包:
//=================特殊礼物延迟发======================
typedef struct tag_DelayGiftRadio
{
    int            nickid;                            //房间ID
    long long    init_userid;                    //发起方用户ID
    int            nLevel;                            //发起方等级
    int            giftid;                            //礼物ID
    int            giftnum;                        //礼物数量
    long long    recei_userid;                    //接收方ID；0表示大家。
    long long    recei_money;                    //接收者剩下的币
    long long    recei_score;                    //接收者剩下的积分
    char        classtype;                        //礼物种类，可划分幸运礼物，奢侈礼物等印章无分类，全部为“默认”,6表示点歌包场回包
    char        szMessage[64];    //赠送信息
    char        szsrcnick[32];                    //发起方昵称
}DelayGiftRadio_t;

//5068回包:
//=================封用户喇叭=========================
typedef struct tag_UserBlockingBroadCast
{
    long long   nUserID;                                        //用户ID
    int            nRoomID;                                        //房间ID
    char        nType  ;                                        //0表示被封，1表示解封
    char        szReason[32];        //原因
}UserBlockingBroadCast_t;

////5069回包:
////挤出房间
//typedef struct tag_quitroomRadio
//{
//    int    nickid;
//    long long    userid;
//}quitroomRadio;

//5085回包:
//礼物群刷回包(礼物赠送通知)
typedef struct tag_GroupGiftResponse
{
    int            nRoomID;        //本房间ID
    long long    nSrcUserid;        //发起方用户ID
    int            nGiftId;        //礼物ID
    int            nGiftNum;        //礼物数量(每个用户)
    char        nClassType;        //礼物种类，可划分幸运礼物，奢侈礼物等印章无分类，全部为“默认”(2表示幸运礼物，3表示奢侈道具，4表示印章,5表示点歌包场,6点歌包场回包，7为平分 8群发 9 魔法道具 -1余额不足)
    char        szDes[0];        //接收人队列
}GroupGiftResponse_t;

//5087回包:
//礼物群刷回包(用户金币变化通知)
typedef struct tag_GroupGiftResponseEx
{
    int            nRoomID;            //本房间ID
    long long    nUserId;            //用户ID
    long long    nMoney;                //用户剩下的币
    long long    nScore;                //接收者剩下的积分
    long long    nRecei_AddMoney;    //接受者本次增加的金钱
}GroupGiftResponseEx_t;

//5094回包:
//炸出房间通知包
typedef struct tag_BombOutRoomResponse
{
    long long    nSrcUserID;            //发起者
    long long   nDesUserID;            //接收者ID
}BombOutRoomResponse_t;

//5102回包:
//合麦申请包回包
typedef struct tag_UnionMicResponse
{
    int            nRoomid ;        //房间ID
    long long    nSrcUserid ;        //操作方ID
    long long    nDesUserid ;        //被操作方ID
    int            nMicOper;        //动作: 1 上麦，2 下麦
    int            nMicIndex;        //麦的位置，1,2,3麦 从上向下
}UnionMicResponse_t;

//5108回包:
//用户刷量达标升级回包
typedef struct tag_UserLevelModifyResponse
{
    long long    nUserID;    //用户ID
    char    noper;    //1:刷量到了，升级
    int    nLevel;    //升级后的等级
    char    nRet;    //0:升级成功；-1:升级失败；-2:等级超过710
    long long    nGiftPriceSum;    //升级失败表示真实刷量，升级成功代表新的刷量
}UserLevelModifyResponse_t;

//5099回包:
//确认用户socket存活询问请求包 收到发5100

//5999回包:
//错误包
typedef struct tag_roomsvrError
{
    int        errorid;        //错误id.
    char       errmsg[128];    //具体错误
}roomsvrError;
//-1000 房间需要密码
//-1111 -2223 -1002 退出房间
//-5114 房间人数已满,请稍后再试 退出房间
