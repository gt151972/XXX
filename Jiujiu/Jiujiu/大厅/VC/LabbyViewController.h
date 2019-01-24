//
//  LabbyViewController.h
//  Jiujiu
//
//  Created by 高婷婷 on 2018/11/28.
//  Copyright © 2018 GT. All rights reserved.
//

#import "BaseViewController.h"
#import "TopTitleView.h"
#import "SearchView.h"
NS_ASSUME_NONNULL_BEGIN

@interface LabbyViewController : BaseViewController
@property (nonatomic,strong)TopTitleView *titleView;
@property (nonatomic, strong)SearchView *searchView;
@property (nonatomic,strong)UIScrollView *homeScrollView;
@end

NS_ASSUME_NONNULL_END
