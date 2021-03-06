//
//  GTDataRequest.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/6.
//  Copyright © 2018 GT. All rights reserved.
//

#import "GTDataRequest.h"

@implementation GTDataRequest
+ (GTDataRequest *)shareInstance {
    static GTDataRequest *tools = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        tools = [[self alloc] init];
    });
    return tools;
}
-(void)postData: (NSString *)cmd data: (NSDictionary *)data{
    // 获得请求管理者
    AFHTTPSessionManager *session = [AFHTTPSessionManager manager];
    // 设置请求格式
    session.requestSerializer = [AFJSONRequestSerializer serializer];
    NSMutableDictionary* parameters = [NSMutableDictionary dictionaryWithDictionary:data];
    [parameters setValue:cmd forKey:@"cmd"];
    NSLog(@"parameters == %@",parameters);
    NSString* strAPIUrl = URL_PATH;
    [session.requestSerializer requestWithMethod:@"POST" URLString:strAPIUrl parameters:parameters error:nil];
    [session POST:strAPIUrl parameters:parameters progress:^(NSProgress * _Nonnull uploadProgress) {
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        NSLog(@"Success: %@", responseObject);
        NSLog(@"task: %@",task);
        NSMutableDictionary *appDic =(NSMutableDictionary*)responseObject;
        if ([appDic[@"code"] intValue] == 0) {
            [self requestCallBack:appDic];
            NSLog(@"%@",appDic[@"msg"]);
        }else{
            [self requestCallBack:appDic];
            NSLog(@"%@",appDic[@"msg"]);
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        NSLog(@"error: %@", error);
    }];
}

/**
 *  数据回调
 *
 *  @param webData 字节数据
 */
-(void)requestCallBack:(NSMutableDictionary *)dict
{
    if (_delegate) {
        [self DalDataCallBack:dict :currResult];
    }
}
/**
 *  解析返回的数据
 *
 *  @param data   字节流
 *  @param result 当前执行的命令
 */
-(void)DalDataCallBack:(NSMutableDictionary *)dict :(NSString *)result{
    NSError *error = nil;
    if (_delegate) {
        if (error)
        {
            if (_delegate) {
                [_delegate responseDataWithCmd:result data:dict];
            }
        }
        else{
            if (_delegate) {
                //                NSLog(@"dict == %@",dict);
                [_delegate responseDataWithCmd:result data:dict];
            }
        }
    }
}

- (void)baseInfo{
    currResult = CMD_BASE;
//    LocalUserModel *model = [DPK_NW_Application sharedInstance].localUserModel;
//    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:[NSString stringWithFormat:@"%d",model.userID], @"uid", nil];
//    //    NSLog(@"dic == %@",dict);
//    [self postData:currResult data:dict];
}
@end
