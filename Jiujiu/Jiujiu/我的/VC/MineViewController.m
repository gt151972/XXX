//
//  MineViewController.m
//  Jiujiu
//
//  Created by 高婷婷 on 2018/11/28.
//  Copyright © 2018 GT. All rights reserved.
//

#import "MineViewController.h"

@interface MineViewController ()<UITableViewDelegate, UITableViewDataSource>{
    NSArray *arrayTitle;
    NSArray *arrayImg;
}
@property (weak, nonatomic) IBOutlet UIButton *btnHead;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@end

@implementation MineViewController
- (instancetype)init{
    arrayTitle = @[@"我的收益", @"客服中心", @"安全中心", @"设置"];
    arrayImg = @[@"mine_tb_earnings", @"mine_tb_service", @"mine_tb_safe", @"mine_tb_setting"];
    return self;
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self.navigationController.navigationBar setHidden:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

#pragma mark tableView
-(UITableView *)tableView{
    if (_tableView == nil) {
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.backgroundColor = CLEARCOLOR;
        _tableView.separatorColor = BG_COLOR;
    }
    return _tableView;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *CellWithIdentifier = @"MineTableView";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellWithIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:CellWithIdentifier];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
//    UIView *viewLine = [[UIView alloc] initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, 1)];
//    viewLine.backgroundColor = BG_COLOR;
//    [cell.contentView addSubview:viewLine];
    if (indexPath.row == 0) {
        
    }else if (indexPath.row == 1){
    }else{
        cell.imageView.image = [UIImage imageNamed:[arrayImg objectAtIndex:indexPath.row - 2]];
        cell.textLabel.text = [arrayTitle objectAtIndex:indexPath.row - 2];
        cell.textLabel.font = [UIFont systemFontOfSize:16];
        cell.textLabel.textColor = TEXT_MAIN_COLOR;
    }
    
    cell.accessoryType = UITableViewCellStyleValue1;
    return cell;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return arrayTitle.count+2;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 44;
}
#pragma mark ACTION

/**
 切换账号

 @param sender <#sender description#>
 */
- (IBAction)btnCutAccountClicked:(id)sender {
}

/**
 个人资料

 @param sender <#sender description#>
 */
- (IBAction)btnHeadClicked:(id)sender {
}
@end
