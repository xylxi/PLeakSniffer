//
//  NSObject+PLeakTrack.h
//  PIXY
//
//  Created by gao feng on 16/7/2.
//  Copyright © 2016年 instanza. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PObjectProxy.h"

@interface NSObject (PLeakTrack) <PObjectProxyKVODelegate>

// 每个对象观察属性的层级(5级)
- (void)watchAllRetainedProperties:(int)level;

@end
