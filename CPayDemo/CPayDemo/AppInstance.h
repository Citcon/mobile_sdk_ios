//
//  AppInstance.h
//  CPayDemo
//
//  Created by long.zhao on 3/31/22.
//

#import <Foundation/Foundation.h>
#import <CPay/CPay.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppInstance : NSObject

+ (NSArray *)currencies;
+ (NSArray *)vendors;
+ (CPayMode)modeby:(NSString *)mode;
+ (NSArray *)countries;
+ (NSArray *)envs;

@end

NS_ASSUME_NONNULL_END
