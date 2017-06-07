//
//  PLeakSniffer.h
//  PLeakSniffer
//
//  Created by gao feng on 16/7/1.
//  Copyright © 2016年 music4kid. All rights reserved.
//

#import <Foundation/Foundation.h>

#define PLeakLog(format, ...) NSLog(format, ##__VA_ARGS__)

#define Notif_PLeakSniffer_Ping @"Notif_PLeakSniffer_Ping"
#define Notif_PLeakSniffer_Pong @"Notif_PLeakSniffer_Pong"

@protocol PLeakSnifferCitizen <NSObject>

+ (void)prepareForSniffer;

- (BOOL)markAlive;

- (BOOL)isAlive;

@end

@interface PLeakSniffer : NSObject

+ (instancetype)sharedInstance;
/**
 *  控制监控
 *  1. hook UINavigationController
 *  2. hook UIViewController
 *  3. hook UIView
 *  4. 开始不断发广播，通知监听折POjectProxy检查对象是否存在泄漏
 */
- (void)installLeakSniffer;
/**
 *  1. 不需要监控的类集合
 */
- (void)addIgnoreList:(NSArray*)ignoreList;
/**
 *  是否用AlertView提示
 */
- (void)alertLeaks; //use UIAlertView to notify leaks

@end
