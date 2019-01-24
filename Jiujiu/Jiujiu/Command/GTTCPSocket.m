//
//  GTTCPSocket.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/18.
//  Copyright © 2018 GT. All rights reserved.
//

#import "GTTCPSocket.h"
#import "BaseSocket.h"
@implementation GTTCPSocket
-(id)init
{
    if((self=[super init])) {
        _asyncSocket=nil;
        _socketSink =nil;
        _messageEventSink=nil;
        _isConnecting =0;
        _isConnected =0;
        m_nRecvSize =0;
    }
    return self;
}

-(void)SetSocketSink:(id)delegate
{
    _socketSink = delegate;
}

- (void)SetMessageEventSink:(id)delegate
{
    _messageEventSink =delegate;
}

- (id)GetMessageEventSink
{
    return _messageEventSink;
}

- (BOOL)ConnectServer:(NSString*)ipAddr ServerPort:(int)port
{
    BOOL bRet;
    if(_asyncSocket ==nil) {
        _asyncSocket=[[GCDAsyncSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
    }
    if(_isConnected ==1) {
        NSLog(@"服务器已经处于连接中.");
        return YES;
    }
    if(_isConnected == 1) {
        NSLog(@"服务器已经连接成功.");
        return YES;
    }
    NSError* error=nil;
    bRet = [_asyncSocket connectToHost:ipAddr onPort:port withTimeout:5 error:&error];
    NSLog(@"%@", error);
    if(!bRet)
        return NO;
    
    _isConnecting =1;
    return YES;
}

- (void)CloseSocket:(int)reason_code
{
    if(_asyncSocket != nil) {
        [_asyncSocket disconnect];
    }
    _isConnecting = 0;
    _isConnected = 0;
    m_nRecvSize =0;
}

-(void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port
{
    NSLog(@"DPKTCPSocket INFO_didConnectToHost");
    _isConnected =1;
    _isConnecting = 0;
    //开始接受数据
    [sock readDataWithTimeout:-1 tag:0];
    
    if(_socketSink) {
        [_socketSink OnEventTCPSocketLink:self error:0];
    }
}

-(void)socket:(GCDAsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag
{
    //NSLog(@"+++++++ DPKTCPSocket INFO_didReadData");
    int nRecvLen =[data length];
    if(nRecvLen >0) {
        if(m_nRecvSize <0) {
            //NSLog(@"+++++++++ DPKTCPSocket INFO_didReadData [3]");
        }
        
        char* pWriteData =m_szRecvBuf + m_nRecvSize;
        [data getBytes:pWriteData length:nRecvLen];
        m_nRecvSize += nRecvLen;
        
        char* p= m_szRecvBuf;
        while( m_nRecvSize >4) {
            int msglen =*((int*)p);
            if(msglen <0 || msglen > SOCKET_TCP_BUFFER_SIZE) {
                m_nRecvSize =0;
                //[sock disconnect];
                return;
            }
            else if(m_nRecvSize < msglen)
                break;
            else {
                //NSLog(@"++++++++ DPKTCPSocket INFO_didReadData [1]");
                if([self HandleData:p DataLen:msglen] == -1)
                {
                    //NSLog(@"+++++++ DPKTCPSocket INFO_didReadData [2]");
                    return;
                }
                //NSLog(@"+++++++ prepare: m_nRecvSize=%d, msglen=%d", m_nRecvSize, msglen);
                m_nRecvSize -= msglen;
                p += msglen;
            }
        }
        if(m_nRecvSize >= SOCKET_TCP_BUFFER_SIZE) {
            m_nRecvSize = 0;
            //[sock disconnect];
            return;
        }
        if( p!= m_szRecvBuf && m_nRecvSize >0)
        {
            memmove(m_szRecvBuf, p, m_nRecvSize);
        }
    }
    else if(nRecvLen <0) {
        //NSLog(@"+++++++ DPKTCPSocket INFO_didReadData [4]");
    }
    
    //继续接受数据
    [sock readDataWithTimeout:-1 tag:0];
    
}

-(void)socket:(GCDAsyncSocket* )sock didWriteDataWithTag:(long)tag
{
    //NSLog(@"发送数据的tag");
}

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)err
{
    NSLog(@"DPKTCPSocket INFO_socketDidDisconnect, error:%@", err);
    if(_isConnecting ==1) {
        _isConnecting = 0;
        if(_socketSink != nil) {
            [_socketSink OnEventTCPSocketLink:self error:err.code];
        }
    }
    //
    if(_isConnected ==1) {
        _isConnected = 0;
        if(_socketSink != nil ) {
            [_socketSink OnEventTCPSocketShut:self reason:err.code];
        }
    }
}


- (int)SendData:(int)cmd
{
    NSArray*array = NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask,YES);
    NSString*cachePath = array[0];
    NSString*filePathName = [cachePath stringByAppendingPathComponent:@"SocketVerify.plist"];
    NSArray*dataArray = [NSArray arrayWithContentsOfFile:filePathName];
    char szBuffer[256];
    HBNetHead_t* header = (HBNetHead_t*)szBuffer;
    header->version = 1;
    header->cmd1 = cmd;
    header->cmd2 = cmd;
    header->cmd3 = cmd;
    header->timer = [dataArray[0] intValue];
    header->luserid = [dataArray[1] intValue];
    header->build_id = 3;
    header->number = 0;
    header->cguid = [dataArray[2] intValue];
    header->length = sizeof(HBNetHead_t);
    if(_isConnected == 1 && _asyncSocket != nil)
    {
        NSData* nsData =[[NSData alloc]initWithBytes:szBuffer length:header->length];
        [_asyncSocket writeData:nsData withTimeout:0 tag:0];
        return 0;
    }
    return -1;
}

- (int)SendData:(int)cmd
           Data:(const char*)pdata
        DataLen:(int)data_len
{
    NSArray*array = NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask,YES);
    NSString*cachePath = array[0];
    NSString*filePathName = [cachePath stringByAppendingPathComponent:@"SocketVerify.plist"];
    NSArray*dataArray = [NSArray arrayWithContentsOfFile:filePathName];
    char szBuffer[SOCKET_TCP_BUFFER_SIZE];
    HBNetHead_t* header =(HBNetHead_t*)szBuffer;
    header->version = 1;
    header->cmd1 = cmd;
    header->cmd2 = cmd;
    header->cmd3 = cmd;
    header->timer = [dataArray[0] intValue];
    header->luserid = [dataArray[1] intValue];
    header->build_id = 3;
    header->number = 0;
    memcpy(header->cguid, dataArray[2] , data_len);
    header->length = sizeof(HBNetHead_t) + data_len;
    if(_isConnected == 1&& _asyncSocket != nil)
    {
        NSData* nsData =[[NSData alloc]initWithBytes:szBuffer length:header->length];
        [_asyncSocket writeData:nsData withTimeout:0 tag:0];
        return 0;
    }
    return -1;
}


- (int)HandleData:(const char*)pdata DataLen:(int)data_len
{
    //NSLog(@"HandleData");
    HBNetHead_t* header = (HBNetHead_t *)pdata;
    if(header->length != data_len || data_len < sizeof(HBNetHead_t))
    {
        NSLog(@"收到不一样的数据，应该要临时保存的!header->length=%d, data_len=%d", header->length, data_len);
        return -1;
    }
//    if(header->mainCmd == MXP_MAINCMD_COMMON && header->subCmd == MXP_SUBCMD_COMMON_SERVERPING)
//    {
//        [self SendData:MXP_MAINCMD_COMMON SubCommand:MXP_SUBCMD_COMMON_CLIENTPING];
//        return 0;
//    }
    //other message process
    if(_socketSink) {
        NSLog(@"处理消息数据: mainCmd=%d,dataLen=%d time = %d, luserid = %lld, cguid = %s", header->cmd1, data_len,header->timer,header->luserid,header->cguid);
        [_socketSink OnEventTCPSocketRead:self
                                     cmd1:header->cmd1
                                     cmd2:header->cmd2
                                     cmd3:header->cmd3
                                    timer:header->timer
                                  luserid:header->luserid
                                    cguid:header->cguid
                                   length:header->length - sizeof(HBNetHead_t)];
    }
    return 0;
    
}

//#pragma mark 发送数据方法
//获取空闲服务器请求(主播端)
-(int)SendQueryRoomServerReq:(int)userId
{
    HBCMD_VideoChat_Query_VCBServer_Req_t req;
    memset(&req, 0, sizeof(req));
    req.userId = userId;
    if(_isConnected == 1) {
        int nret = [self SendData:MXP_MAINCMD_VIDEOCHAT SubCommand:MXP_SUBCMD_VIDEOCHAT_QUERY_VCBSERVER_REQ Data:(char*)&req DataLen:sizeof(HBCMD_VideoChat_Query_VCBServer_Req_t)];
        return 0;
    }
    else if(_isConnecting == 1) {
        return -1;
    }
    return -2;
}

@end
