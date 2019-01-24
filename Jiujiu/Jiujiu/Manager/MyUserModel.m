//
//  MyUserModel.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/17.
//  Copyright © 2018 GT. All rights reserved.
//

#import "MyUserModel.h"

@implementation MyUserModel
-(void)reset{
    self.userid = 0;
    self.nlevel = 0;
    self.nhonorlevel = 0;
    self.nsingerlevel = 0;
    self.uscore = 0;
    self.umoney = 0;
    self.lockmachine = 0;
    self.nDiscard = 0;
    self.nlevelversion = 0;
    self.nlevelnum = 0;
    self.nGiftPriceSum = 0;
    self.unickname = @"";
    self.headurl = @"";
    self.usersex = @"";
    self.cidiograph = @"";
    self.locallogon = @"";
    self.nMoneystatus = @"";
    self.nGuestChat = @"";
    self.cguid = @"";
    self.content = @"";
}
@end
