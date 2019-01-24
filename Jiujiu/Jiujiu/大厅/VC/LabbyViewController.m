//
//  LabbyViewController.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/11/28.
//  Copyright © 2018 GT. All rights reserved.
//

#import "LabbyViewController.h"
#import "FirstViewController.h"
#import "HistoryViewController.h"
@interface LabbyViewController ()<UIScrollViewDelegate>
@property (nonatomic, strong)NSArray *arrayTitle;
@end

@implementation LabbyViewController{
    NSMutableArray *_arr;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    _arrayTitle = [NSArray array];
//    GTAFNData *data = [[GTAFNData alloc] init];
//    data.delegate = self;
//    [data requestImageHead];
    // Do any additional setup after loading the view.
    
        self.arrayTitle = @[@"1111",@"2222",@"3333",@"4444"];
    UIImage *leftImg = [UIImage imageNamed:@"home_search"];
    leftImg = [leftImg imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithImage:leftImg style:UIBarButtonItemStylePlain target:self action:@selector(enterSearchClick)];
    
    UIImage *rightImg = [UIImage imageNamed:@"home_record"];
    rightImg = [rightImg imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithImage:rightImg style:UIBarButtonItemStylePlain target:self action:@selector(btnHistoryClicked)];
    [self.view addSubview:self.homeScrollView];
    
    [self searchView];
    [self initTitleView];

}

- (void)initChildViewControllers:(NSArray *)arrayData{
    _arr = [NSMutableArray array];
    for (int index = 0; index < _arrayTitle.count; index ++) {
        //推荐
        FirstViewController*mainVC = [[FirstViewController alloc]init];
        mainVC.tag = 500+index;
        mainVC.arrData = arrayData;
        [self addChildViewController:mainVC];
        [_arr addObject:mainVC];
    }
    for (NSInteger i=0; i<self.childViewControllers.count; i++) {
        //调成子VC中view(root_view)的位置，然后都加入到scrollView中
        UIViewController *cls = self.childViewControllers[i];
        cls.view.frame = CGRectMake(SCREEN_WIDTH*i, 0, SCREEN_WIDTH, SCREEN_HEIGHT-49 - 64);
        [self.homeScrollView addSubview:cls.view];
    }
}
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView{
    [self.titleView scrollMove:(scrollView.contentOffset.x/SCREEN_WIDTH + 50)];
}
//搜索栏
- (SearchView *)searchView{
    if (!_searchView) {
        _searchView = [[SearchView alloc]initWithFrame:self.view.bounds];
    }
    return _searchView;
}
- (void)enterSearchClick{
    [_searchView popToView];
}

- (void)btnHistoryClicked{
    HistoryViewController *historyVC = [[HistoryViewController alloc] init];
    [self.navigationController pushViewController:historyVC animated:YES];
}


#pragma  加载
- (TopTitleView *)titleView{
    if (!_titleView) {
        _titleView = [[TopTitleView alloc]initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH-88, 44)];
        NSMutableArray *array = [NSMutableArray array];
        for (int index = 0; index<_arrayTitle.count; index++) {
            [array addObject:[_arrayTitle objectAtIndex:index]];
        }
        self.titleView.titleArr = array;
        [self.titleView CreatUI];
        WEAKSELF;
        [_titleView setTitleClick:^(NSInteger tag, NSInteger lastTag) {
            CGPoint point = CGPointMake((tag - 50) * SCREEN_WIDTH ,weakSelf.homeScrollView.contentOffset.y);
            [weakSelf.homeScrollView setContentOffset:point animated:YES];
            UIButton *button1 = (UIButton *)[_titleView viewWithTag:lastTag];
            UIButton *button2 = (UIButton *)[_titleView viewWithTag:tag];
            button1.selected = NO;
            button2.selected = YES;
        }];
        //        [_titleView setBtnTitleClicked:^(NSInteger tag) {
        //            GTAFNData *data = [[GTAFNData alloc] init];
        //            data.delegate = weakSelf;
        //            NSString *key = [[weakSelf.arrayTitle objectAtIndex:(tag - 50)] objectForKey:@"key"];
        //            [data mainListData:key];
        //        }];
        
    }
    return _titleView;
}

- (UIScrollView *)homeScrollView{
    if (!_homeScrollView) {
        self.edgesForExtendedLayout = UIRectEdgeNone;
        _homeScrollView = [[UIScrollView alloc]initWithFrame:self.view.bounds]; //当前内容区域大小
        _homeScrollView.contentSize = CGSizeMake(4 * SCREEN_WIDTH, 0); //4个屏幕宽度
        _homeScrollView.contentOffset = CGPointMake(0, 0);  //一次性移动多少??
        _homeScrollView.showsHorizontalScrollIndicator = NO;
        _homeScrollView.pagingEnabled = YES;
        _homeScrollView.bounces = NO;
        _homeScrollView.delegate = self;
        _homeScrollView.userInteractionEnabled = YES;
        _homeScrollView.backgroundColor = [UIColor whiteColor];
    }
    return _homeScrollView;
}


-(void)initTitleView{
//    self.arrayTitle = @[@"1111",@"2222",@"3333",@"4444"];
    self.navigationItem.titleView = self.titleView;
    [self initChildViewControllers:self.arrayTitle];
}
@end
