//
//  MJCSegmentInterface.h
//  MJCSegmentInterface
//
//  Created by mjc on 16/10/7.
//  Copyright © 2016年 MJC. All rights reserved.
//  有啥问题加我QQ: 292251588 一起交流,我是菜菜..求大神指教

#import <UIKit/UIKit.h>
#import "UIView+MJCClassExtension.h"
#import "MJCCommonTools.h"
#import "MJCSegmentStylesTools.h"

@class MJCTabItem;

@class MJCSegmentInterface;
@protocol MJCSegmentDelegate <NSObject>
@required
@optional
/** 选中点击item会调用的代理方法 */
- (void)mjc_ClickEventWithItem:(UIButton *)tabItem childsController:(UIViewController *)childsController segmentInterface:(MJCSegmentInterface *)segmentInterface;
/** 取消选中点击item状态会调用的代理方法 */
- (void)mjc_cancelClickEventWithItem:(UIButton *)tabItem childsController:(UIViewController *)childsController segmentInterface:(MJCSegmentInterface *)segmentInterface;
/** 手拽滑动结束之后调用的代理方法 */
- (void)mjc_scrollDidEndDeceleratingWithItem:(UIButton *)tabItem childsController:(UIViewController *)childsController indexPage:(NSInteger)indexPage segmentInterface:(MJCSegmentInterface *)segmentInterface;
/** 获取到所有item的代理方法(可在item上面添加新的控件) */
- (void)mjc_tabitemDataWithTabitemArray:(NSArray<UIButton*>*)tabItemArray childsVCAarray:(NSArray<UIViewController*>*)childsVCAarray segmentInterface:(MJCSegmentInterface *)segmentInterface;

@end

@interface MJCSegmentInterface : UIView

-(void)jc_reviseSegmentInterfaceTitleArr:(NSArray *)titlesArr childsViewControllerArr:(NSArray *)childsViewControllerArr;

/** 代理方法 */
@property (nonatomic,weak)id<MJCSegmentDelegate> delegate;

#pragma mark -- 通用设置
/** 默认选中的item */
@property (nonatomic,assign) NSInteger selectedSegmentIndex;
/** 是否有穿透效果 */
@property (nonatomic,assign) BOOL isPenetrationEffect;

#pragma mark -- 添加方法和创建方法

/** 实例化此控件的方法 */
+(instancetype)initWithFrame:(CGRect)frame interFaceStyleTools:(MJCSegmentStylesTools *)tools;

/** 添加标题栏与添加控制器的方法(添加控制器按照控制器添加的先后顺序与按钮对应的 */
-(void)intoTitlesArray:(NSArray *)titlesArray intoChildControllerArray:(NSArray *)childControllerArray hostController:(UIViewController *)hostController;
/** 添加控制器界面的方法 */
-(void)intoChildControllerArray:(NSArray*)childControllerArray;
/** 添加标题栏的方法 */
-(void)intoTitlesArray:(NSArray*)titlesArray hostController:(UIViewController*)hostController;

/** <#  注释  #> */
@property (nonatomic,strong) MJCSegmentStylesTools *tools;

@end
