//
//  BaseSocket.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/14.
//  Copyright © 2018 GT. All rights reserved.
//

#ifndef BaseSocket_h
#define BaseSocket_h

#include "yc_dataType.h"
#include "yc_define.h"

#define MAX_HB_MESSAGE_SIZE   16*1024

#define MXP_MAINCMD_COMMON              100       //Œ’ ÷

#define MXP_SUBCMD_COMMON_CLIENT_HELLO           1   //ClientHello
#define MXP_SUBCMD_COMMON_SERVERPING             2   //ServerPing
#define MXP_SUBCMD_COMMON_CLIENTPING             3   //ClientPing

#pragma pack(1)

//69 位
typedef struct _tag_HBNetHead {
    int length;//整个包的长度 头长度加信息体长度
    int version = 1;
    int cmd3;
    int cmd1;//命令标志
    int cmd2;
    int timer;//安全校验 登录成功之后(1008回包)之后的每个包都带上
    unsigned short build_id=3;
    long long luserid=0;//用户id 登录成功之后(1008回包)之后的每个包都带上
    char cguid[0];//33位长度   回话id 登录成功之后(1008回包)之后的每个包都带上
    unsigned short number=0;
}HBNetHead_t;

typedef struct _tag_HBCMD_COMMON_ClientHello
{
    int32 a;
    int32 b;
    int32 c;
    int32 d;
}HBCMD_COMMON_ClientHello_t;

typedef struct _tag_HBCMD_COMMON_ServerPing
{
    
}HBCMD_COMMON_ServerPing_t;

typedef struct  _tag_HBCMD_COMMON_ClientPing
{
    
}HBCMD_COMMON_ClientPing_t;

#pragma pack()
#endif /* BaseSocket_h */
