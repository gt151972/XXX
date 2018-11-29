//
//  BaseViewController.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/11/28.
//  Copyright © 2018 GT. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


//左右导航按钮回调
typedef void(^PassAction)(UIButton *button);
//刷新按钮回调
typedef void(^RefreshAction)();
//传值回调
typedef void(^PassStr)(NSString *);
@interface BaseViewController : UIViewController
@property (copy, nonatomic) PassAction leftItemAction;
@property (copy, nonatomic) PassAction rightItemAction;
@property (copy, nonatomic) RefreshAction refreshAction;
@property (copy, nonatomic) PassStr passStr;

- (void)setNavigationBarTitle:(NSString *)title;

/**
  *  设置navigation背景透明
  */
- (void)setNavigationBackGroudDiaphanous;

/**
  *  设置navigation背景不透明
  */
- (void)setNavigationBackGroudOpaque;

#pragma mark ===== leftBarButton
/**
  *  设置navigation左按钮（图片）
  *
  *  @param image     normal图片
  *  @param highImage 高亮图片
  */
- (void)setNavigationBarLeftItemimage:(NSString *)image highImage:(NSString *)highImage;

/**
  *  设置navigation左按钮（文字）
  *
  *  @param title 按钮文字
  */
- (void)setNavigationBarLeftItemButttonTitle:(NSString *)title;

/**
  *  设置navigation左按钮（图片 + 文字）
  *
  *  @param title 文字
  *  @param image 图片
  */
- (void)setNavigationBarLeftItemButtonTitle:(NSString *)title image:(NSString *)image;

#pragma mark ===== rightBarButton

/**
  *  设置navigation右按钮
  *
  *  @param image     正常图片
  *  @param highImage 高亮图片
  */
- (void)setNavigationBarRightItemimage:(NSString *)image highImage:(NSString *)highImage;

/**
  *  设置navigation右按钮（文字）
  *
  *  @param title 按钮文字
  */
- (void)setNavigationBarRightItemButttonTitle:(NSString *)title;

/**
  *  设置navigation右按钮（图片 + 文字）
  *
  *  @param title 文字
  *  @param image 图片
  */
- (void)setNavigationBarRightItemButtonTitle:(NSString *)title image:(NSString *)image;

@end

NS_ASSUME_NONNULL_END
