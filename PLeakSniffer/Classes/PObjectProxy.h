//
//  PObjectProxy.h
//  PLeakSniffer
//
//  Created by gao feng on 16/7/1.
//  Copyright © 2016年 music4kid. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PObjectProxyKVODelegate <NSObject>

- (void)didObserveNewValue:(id)value;

@end

@interface PObjectProxy : NSObject

- (void)prepareProxy:(NSObject*)target;
// 当前监控的对象
@property (nonatomic, weak) NSObject*                 weakTarget;
// 当前监控的对象是weakHost的属性
@property (nonatomic, weak) NSObject*                 weakHost;
// 如果是UIView的话，找到最终的响应者??
@property (nonatomic, weak) NSObject*                 weakResponder;

@property (nonatomic, weak) id<PObjectProxyKVODelegate>                 kvoDelegate;

- (void)observeObject:(id)obj withKeyPath:(NSString*)path withDelegate:(id<PObjectProxyKVODelegate>)delegate;

@end
