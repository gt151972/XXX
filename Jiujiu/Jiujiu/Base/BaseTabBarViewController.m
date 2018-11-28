//
//  BaseTabBarViewController.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/11/28.
//  Copyright © 2018 GT. All rights reserved.
//

#import "BaseTabBarViewController.h"
#import "MainViewController.h"
#import "LabbyViewController.h"
#import "ActivityViewController.h"
#import "RankViewController.h"
#import "MineViewController.h"
#import "LikeViewController.h"
@interface BaseTabBarViewController ()

@end

@implementation BaseTabBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIView *backView=[[UIView alloc]initWithFrame:self.view.frame];
    backView.backgroundColor=[UIColor whiteColor];
    [self.tabBar insertSubview:backView atIndex:0];
    self.tabBar.opaque=YES;
    
    self.tabBar.tintColor=[UIColor blackColor];
    [self initChildViewControllers];
    
    //隐藏tabBar上的线
    [[UITabBar appearance] setShadowImage:[UIImage new]];
    [[UITabBar appearance] setBackgroundImage:[[UIImage alloc]init]];
}
- (void)initChildViewControllers{
    //大厅
    LabbyViewController *labbyVC = [[LabbyViewController alloc]init];
    MainViewController *labbyNav = [[MainViewController alloc]initWithRootViewController:labbyVC];
    [self addChildViewController:labbyNav image:@"tabbar_labby_normal" selectedImage:@"tabbar_labby_select" title:@"大厅"];
    
    //喜欢
    LikeViewController *likeVC = [[LikeViewController alloc] init];
    MainViewController *likeNav = [[MainViewController alloc] initWithRootViewController:likeVC];
    [self addChildViewController:likeNav image:@"tabbar_like_normal" selectedImage:@"tabbar_like_select" title:@"喜欢"];
    
    //活动
    ActivityViewController *activityVC = [[ActivityViewController alloc] init];
    MainViewController *activityNav = [[MainViewController alloc] initWithRootViewController:activityVC];
    [self addChildViewController:activityNav image:@"tabbar_activity_normal" selectedImage:@"tabbar_activity_select" title:@"活动"];
    
    //排行
    RankViewController *rankVC = [[RankViewController alloc] init];
    MainViewController *rankNav = [[MainViewController alloc] initWithRootViewController:rankVC];
    [self addChildViewController:rankNav image:@"tabbar_rank_normal" selectedImage:@"tabbar_rank_select" title:@"排行"];
    
    //我的
    MineViewController *mineVC = [[MineViewController alloc] init];
    MainViewController *mineNav = [[MainViewController alloc] initWithRootViewController:mineVC];
    [self addChildViewController:mineNav image:@"tabbar_mine_normal" selectedImage:@"tabbar_mine_select" title:@"我的"];
}

- (void)addChildViewController:(UIViewController *)nav image:(NSString *)image selectedImage:(NSString *)selectedImage title: (NSString *)title{
    
    UIViewController *childViewController = nav.childViewControllers.firstObject;
    //tabBarItem图片,显示原图，否则变形
    UIImage *normal = [[UIImage imageNamed:image] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    childViewController.tabBarItem.image = normal;
    childViewController.tabBarItem.selectedImage = [[UIImage imageNamed:selectedImage]imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    childViewController.title = title;
    NSMutableDictionary *textAttribute = [NSMutableDictionary dictionary];
    textAttribute[NSForegroundColorAttributeName] = [UIColor colorWithRed:24/255.0 green:24/255.0 blue:24/255.0 alpha:1.0];
    textAttribute[NSFontAttributeName] = [UIFont systemFontOfSize:11];
    [childViewController.tabBarItem setTitleTextAttributes:textAttribute forState:UIControlStateNormal];
    [childViewController.tabBarItem setTitleTextAttributes:@{NSForegroundColorAttributeName:[UIColor colorWithRed:24/255.0 green:24/255.0 blue:24/255.0 alpha:1.0]} forState:UIControlStateSelected];
    [self addChildViewController:nav];
}

- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item{
    NSInteger index = [self.tabBar.items indexOfObject:item];
    [self animatedWithindex:index];
}

- (void)animatedWithindex:(NSInteger )index{
    NSMutableArray *tabArr = [NSMutableArray array];
    for (UIView *tabBarButton in self.tabBar.subviews) {
        if ([tabBarButton isKindOfClass:NSClassFromString(@"UITabBarButton")]) {
            [tabArr addObject:tabBarButton];
        }
    }
    CABasicAnimation *base = [CABasicAnimation animationWithKeyPath:@"transform.scale"];
    base.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut];
    base.duration = 0.1;
    base.repeatCount = 1;
    base.autoreverses = YES;
    base.fromValue = [NSNumber numberWithFloat:0.8];
    base.toValue = [NSNumber numberWithFloat:1.2];
    [[tabArr[index] layer] addAnimation:base forKey:@"Base"];
    
}

//- (void)setupImagePicker:(UIImagePickerControllerSourceType)sourceType{
//    if (sourceType != UIImagePickerControllerSourceTypeCamera) {
//        return;
//    }
//    self.imagePickerController.sourceType = sourceType;
//    [[UIApplication sharedApplication]setStatusBarHidden:YES];
//}

//-(void)doLogon {
//    AppDelegate* appDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
//    [appDelegate doLogon];
//
//}


@end
