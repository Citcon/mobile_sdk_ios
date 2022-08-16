//
//  AppInstance.m
//  CPayDemo
//
//  Created by long.zhao on 3/31/22.
//

#import "AppInstance.h"

@implementation AppInstance

+ (NSArray *)currencies {
    return @[
        @"USD", @"CNY", @"HKD", @"IDR", @"PHP", @"KRW", @"GBP", @"EUR", @"SGD",
        @"AUD", @"TWD", @"CAD", @"JPY", @"NZD"
    ];
}

+ (NSArray *)countries {
    return @[
        @"US", @"KR", @"JP", @"CN", @"HK", @"CA", @"NZ", @"AU"
    ];
}

+ (NSArray *)vendors {
    return @[
        @"wechatpay", @"wechatpay_h5", @"alipay", @"upop", @"alipay_hk", @"kakaopay",
        @"gcash", @"dana", @"truemoney", @"bkash", @"easypaisa", @"cc", @"jkopay",
        @"card", @"payco", @"naverpay", @"banktransfer", @"linepay", @"paypay",
        @"rakutenpay", @"toss", @"lpay", @"lgpay", @"samsungpay"
    ];
}

+ (NSArray *)envs {
    return @[
        @"DEV", @"QA", @"PROD", @"UAT"
    ];
}

+ (CPayMode)modeby:(NSString *)mode {
    NSDictionary *modes = @{
        @"DEV": @(CPayModeDEV),
        @"QA": @(CPayModeQA),
        @"UAT": @(CPayModeUAT),
        @"PROD": @(CPayModePROD)
    };
    return [modes objectForKey:mode] ? [modes[mode] intValue] : CPayModePROD;
}

@end
