//
//  SearchView.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/12/18.
//  Copyright © 2018 GT. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SearchView : UIView
@property (nonatomic,strong)UISearchBar *searchBar;

@property (nonatomic,strong)UIButton *cancleButton;

@property (nonatomic,strong)UIButton *searchButton;

@property (nonatomic,copy)void (^cancleBlock)();
@property (nonatomic,copy)void (^hideBlock)();
- (void) popToView;
- (void) hide;

@end

NS_ASSUME_NONNULL_END
