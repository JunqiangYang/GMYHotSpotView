//
//  GMYHotSpotView.h
//  GMYHotSpotView
//
//  Created by 郭妙友 on 15/7/19.
//  Copyright (c) 2015年 miaoyou.gmy. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol GMYHotSpotViewLayout;
@protocol GMYHotSpot;
typedef void(^HotspotClickHandle)(NSInteger index,NSString *title);
/**
 *  HotSpotView 状态
 */
typedef NS_ENUM(NSUInteger, HotspotState) {
    /**
     *  正常状态
     */
    HotspotStateNormal = 0,
    /**
     *  编辑状态
     */
    HotspotStateEditing,
};

@interface GMYHotSpotView : UIView
/**
 *  忽略长按手势
 */
@property (nonatomic, assign) BOOL igonreLongPress;
/**
 *  按钮 标题文字的大小
 */
@property (nonatomic, assign) CGFloat fontSize;
/**
 *  按钮的宽度
 */
@property (nonatomic, assign) CGFloat buttonWidth;
/**
 *  按钮的高度
 */
@property (nonatomic, assign) CGFloat buttonHeight;
/**
 *  按钮两行之间的距离
 */
@property (nonatomic, assign) CGFloat minimumLineSpacing;
/**
 *  按钮之间的距离
 */
@property (nonatomic, assign) CGFloat minimumInteritemSpacing;
/**
 *  按钮背景颜色
 */
@property (nonatomic, strong) UIColor *buttonBackgroundColor;
/**
 *  按钮标题文字颜色
 */
@property (nonatomic, strong) UIColor *buttonTitleColor;
/**
 *  按钮标题到边框的距离
 */
@property (nonatomic, assign) CGFloat titleSpace;
/**
 *  支持最大热点行数
 */
@property (nonatomic, assign) NSInteger maxLines;
/**
 *  热点 点击回调
 */
@property (nonatomic, copy) HotspotClickHandle clickHandle;
/**
 *  热点数据源
 */
@property (nonatomic, strong, readonly) NSMutableArray *hotspots;
/**
 *  初始化方法
 *
 *  @param frame  视图位置,大小
 *  @param layout 布局方式
 *
 *  @return GMYHotSpotView 视图实例
 */
- (instancetype)initWithFrame:(CGRect)frame hotspotViewLayout:(id<GMYHotSpotViewLayout>)layout; //the designated initializer
/**
 *  更新热点视图
 *
 *  @param hotspots    热点数据 实现 GMYHotSpot 协议
 *  @param clickHandle 点击热点回调
 */
- (void)updateHotSpotWithArray:(NSArray<id<GMYHotSpot>> *)hotspots ClickHandle:(HotspotClickHandle)clickHandle;
/**
 *  根据 hotspots 计算视图高度
 *
 *  @param hotspots 热点数据
 *
 *  @return 视图高度
 */
- (CGFloat)calcluateViewHeightWithHotspots:(NSArray<id<GMYHotSpot>> *)hotspots;
@end

