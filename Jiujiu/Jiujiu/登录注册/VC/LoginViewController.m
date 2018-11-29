//
//  LoginViewController.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/11/29.
//  Copyright © 2018 GT. All rights reserved.
//

#import "LoginViewController.h"

@interface LoginViewController ()
@property (weak, nonatomic) IBOutlet UITextField *textFieldUserId;
@property (weak, nonatomic) IBOutlet UITextField *textFieldPwd;
@property (weak, nonatomic) IBOutlet UIButton *btnRemember;
@property (weak, nonatomic) IBOutlet UIButton *btnLogin;
@property (weak, nonatomic) IBOutlet UIButton *btnRegister;

@end

@implementation LoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

#pragma mark Action

/**
 记住密码

 @param sender <#sender description#>
 */
- (IBAction)btnRememberClicked:(UIButton *)sender {
}

/**
 忘记密码

 @param sender <#sender description#>
 */
- (IBAction)btnForgetClicked:(UIButton *)sender {
}

/**
 登录

 @param sender <#sender description#>
 */
- (IBAction)btnLoginClicked:(UIButton *)sender {
}

/**
 注册

 @param sender <#sender description#>
 */
- (IBAction)btnRegisterClicked:(UIButton *)sender {
}

/**
 登录即同意用户协议

 @param sender <#sender description#>
 */
- (IBAction)btnProtocolClicked:(UIButton *)sender {
}

/**
 微信登录

 @param sender <#sender description#>
 */
- (IBAction)btnWechatClicked:(UIButton *)sender {
}

/**
 QQ登录

 @param sender <#sender description#>
 */
- (IBAction)btnQQClicked:(UIButton *)sender {
}
@end
