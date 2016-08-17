//
//  UILabel+ULK_View.h
//  UILayoutKit
//
//  Created by Tom Quist on 22.07.12.
//  Copyright (c) 2012 Tom Quist. All rights reserved.
//
//  Modified by towik on 19.07.16.
//  Copyright (c) 2016 towik. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ULKGravity.h"

@interface UILabel (ULK_View)

@property (nonatomic, assign) ULKViewContentGravity ulk_gravity;

- (void)ulk_setText:(NSString *)text;
- (void)ulk_setFont:(UIFont *)font;
- (void)ulk_setLineBreakMode:(NSLineBreakMode)lineBreakMode;

@end