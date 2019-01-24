//
//  GTDataRequest.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/6.
//  Copyright © 2018 GT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking.h>
NS_ASSUME_NONNULL_BEGIN
@protocol GTDataRequestDelegate <NSObject>
- (void) responseDataWithCmd :(NSString *)cmd
                         data: (NSDictionary *)data;
@end
@interface GTDataRequest : NSObject{
    NSString *currResult;
}

@property (nonatomic, weak) id<GTDataRequestDelegate> delegate;

+(GTDataRequest *)shareInstance;


/**
 基础配置
 */
-(void)baseInfo;
@end

NS_ASSUME_NONNULL_END
