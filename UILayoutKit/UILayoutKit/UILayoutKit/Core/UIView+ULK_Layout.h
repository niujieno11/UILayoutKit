//
//  UIView+ULK.h
//  UILayoutKit
//
//  Created by Tom Quist on 22.07.12.
//  Copyright (c) 2012 Tom Quist. All rights reserved.
//
//  Modified by towik on 19.07.16.
//  Copyright (c) 2016 towik. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ULKLayoutParams.h"

/**
 * This is used by the layout-inflater to pass an action target to a UIControl
 */
FOUNDATION_EXPORT NSString *const ULKViewAttributeActionTarget;

typedef NS_ENUM(NSInteger, ULKLayoutMeasureSpecMode) {
    ULKLayoutMeasureSpecModeUnspecified,
    ULKLayoutMeasureSpecModeExactly,
    ULKLayoutMeasureSpecModeAtMost
};

typedef struct ULKLayoutMeasureSpec {
    CGFloat size;
    ULKLayoutMeasureSpecMode mode;
} ULKLayoutMeasureSpec;

ULKLayoutMeasureSpec ULKLayoutMeasureSpecMake(CGFloat size, ULKLayoutMeasureSpecMode mode);

typedef NS_OPTIONS(NSInteger, ULKLayoutMeasuredState) {
    ULKLayoutMeasuredStateNone = 0x0,
    ULKLayoutMeasuredStateTooSmall = 0x1
};

typedef struct ULKLayoutMeasuredDimension {
    CGFloat size;
    ULKLayoutMeasuredState state;
} ULKLayoutMeasuredDimension;

typedef struct ULKLayoutMeasuredSize {
    ULKLayoutMeasuredDimension width;
    ULKLayoutMeasuredDimension height;
} ULKLayoutMeasuredSize;

typedef struct ULKLayoutMeasuredWidthHeightState {
    ULKLayoutMeasuredState widthState;
    ULKLayoutMeasuredState heightState;
} ULKLayoutMeasuredWidthHeightState;

typedef NS_OPTIONS(NSInteger, ULKViewVisibility) {
    ULKViewVisibilityVisible = 0x00000000,
    ULKViewVisibilityInvisible = 0x00000004,
    ULKViewVisibilityGone = 0x00000008
};

ULKViewVisibility ULKViewVisibilityFromString(NSString *visibilityString);

ULKLayoutMeasuredSize ULKLayoutMeasuredSizeMake(ULKLayoutMeasuredDimension width, ULKLayoutMeasuredDimension height);

BOOL ULKBOOLFromString(NSString *boolString);

@interface UIView (ULK_Layout)

@property (nonatomic, assign) CGSize ulk_minSize;
@property (nonatomic, readonly) CGSize ulk_measuredSize;
@property (nonatomic, readonly) BOOL ulk_hadMeasured;
@property (nonatomic, readonly) ULKLayoutMeasuredWidthHeightState ulk_measuredState;
@property (nonatomic, readonly) CGFloat ulk_baseline;
@property (nonatomic, assign) NSString *ulk_identifier;
@property (nonatomic, assign) ULKViewVisibility ulk_visibility;

- (void)ulk_onMeasureWithWidthMeasureSpec:(ULKLayoutMeasureSpec)widthMeasureSpec heightMeasureSpec:(ULKLayoutMeasureSpec)heightMeasureSpec;
- (void)ulk_measureWithWidthMeasureSpec:(ULKLayoutMeasureSpec)widthMeasureSpec heightMeasureSpec:(ULKLayoutMeasureSpec)heightMeasureSpec;
- (void)ulk_onLayoutWithFrame:(CGRect)frame didFrameChange:(BOOL)changed;
- (BOOL)ulk_setFrame:(CGRect)frame;
- (void)ulk_layoutWithFrame:(CGRect)frame;

- (void)ulk_setMeasuredDimensionSize:(ULKLayoutMeasuredSize)size;
- (void)ulk_clearMeasuredDimensionSize;

- (void)ulk_requestLayout;
- (void)ulk_onFinishInflate;
- (UIView *)ulk_findViewById:(NSString *)identifier;

+ (ULKLayoutMeasuredWidthHeightState)ulk_combineMeasuredStatesCurrentState:(ULKLayoutMeasuredWidthHeightState)curState newState:(ULKLayoutMeasuredWidthHeightState)newState;
+ (ULKLayoutMeasuredDimension)ulk_resolveSizeAndStateForSize:(CGFloat)size measureSpec:(ULKLayoutMeasureSpec)measureSpec childMeasureState:(ULKLayoutMeasuredState)childMeasuredState;
+ (CGFloat)ulk_resolveSizeForSize:(CGFloat)size measureSpec:(ULKLayoutMeasureSpec)measureSpec;


- (ULKLayoutParams *)ulk_generateDefaultLayoutParams;
- (ULKLayoutParams *)ulk_generateLayoutParamsFromLayoutParams:(ULKLayoutParams *)lp;
- (ULKLayoutParams *)ulk_generateLayoutParamsFromAttributes:(NSDictionary *)attrs;
- (BOOL)ulk_checkLayoutParams:(ULKLayoutParams *)layoutParams;
- (ULKLayoutMeasureSpec)ulk_childMeasureSpecWithMeasureSpec:(ULKLayoutMeasureSpec)spec padding:(CGFloat)padding childDimension:(CGFloat)childDimension;

- (void)ulk_measureChildWithMargins:(UIView *)child parentWidthMeasureSpec:(ULKLayoutMeasureSpec)parentWidthMeasureSpec widthUsed:(CGFloat)widthUsed parentHeightMeasureSpec:(ULKLayoutMeasureSpec)parentHeightMeasureSpec heightUsed:(CGFloat)heightUsed;
-(void)ulk_measureChild:(UIView *)child withParentWidthMeasureSpec:(ULKLayoutMeasureSpec)parentWidthMeasureSpec parentHeightMeasureSpec:(ULKLayoutMeasureSpec)parentHeightMeasureSpec;
- (UIView *)ulk_findViewTraversal:(NSString *)identifier;

@property (nonatomic, readonly) BOOL ulk_isViewGroup;

@end
