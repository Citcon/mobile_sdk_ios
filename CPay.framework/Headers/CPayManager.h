//
//  CPayManager.h
//  CPay
//
//  Created by Siwei Y. on 6/5/17.
//  Copyright © 2017 Dinolab. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CPayDefines.h"

@class CPayOrder;

@interface CPayManager : NSObject

// setup your merchant token from CITCON, and setup your Wechat app id (open.weixin.qq.com) in the info.plist, eg. wxeb0650d489d69e14
+ (void)setupTokenKey:(NSString *)token;

// setup your running Environment, CPayModePROD = 0, CPayModeUAT = 1, CPayModeDEV = 2
+ (void)setupMode:(CPayMode)mode;

/**
 * Call this function in -application: openURL:
 *
 * (iOS 9+): - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
 * and in (iOS 8/7/6): - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation
 */
+ (BOOL)processOpenUrl:(UIApplication *)application url:(NSURL *)url standbyCallback:(CPayOrderResultBlock)callback;

/**
 * Call this function in -application: continueUserActivity:
 */
+ (BOOL)processUserActivity:(nonnull NSUserActivity *)userActivity;

/**
 * Create an order request with detail parameters
 *
 * @param referenceId       Set a reference id string
 * @param subject           Set the order subject string
 * @param body              Set the order body string
 * @param amount            set the order amount, 100 means 1 USD if the currency is USD
 * @param currency          set the order currency, eg. USD, CNY, JPY.
 * @param vendor            set the order's payment method, eg. wechatpay, alipay
 * @param ipnUrl            notify url string
 * @param callbackUrl       callback by server when the payment finished
 * @param allowDuplicate    allow dumplicate the order
 * @param scheme            you app scheme, set in your App's info.plist, eg. cpaysdk, required in Alipay
 * @param completion        completion callback, check the 'CPayOrderResultBlock' for details
 */
+ (void)requestOrder:(NSString *)referenceId subject:(NSString *)subject body:(NSString *)body amount:(NSString *)amount currency:(NSString *)currency vendor:(NSString *)vendor ipnUrl:(NSString *)ipnUrl callbackUrl:(NSString *)callbackUrl allowDuplicate:(BOOL)allowDuplicate scheme:(NSString*)scheme completion:(CPayOrderResultBlock)completion;

/**
 * Create an order request with the order object
 *
 * @param order         order object
 * @param completion    completion callback, check the 'CPayOrderResultBlock' for details
 */
+ (void)requestOrder:(CPayOrder *)order completion:(CPayOrderResultBlock)completion;

/**
 * Check the order payment result, normally, you don't need to call this function, just by observing the "kOrderPaymentFinishedNotification"
 *
 * @param order         order object
 * @param transactionId transaction id
 * @param method        eg. real
 * @param completion    completion callback, check the 'CPayCheckResultBlock' for details
 */
+ (void)inquireResult:(NSString *)transactionId order:(CPayOrder*)order method:(NSString *)method completion:(CPayCheckResultBlock)completion;

/**
 * Check if WeChat application is installed
 *
 * @param wxAppId       Wechat app ID
 * @param universalLink  Apple Universal Link
 */
+ (BOOL)isWechatInstalled:(NSString *)wxAppId universalLink:(NSString*)universalLink;

/**
 * Get SDK version
 */
+ (NSString*)getVersion;

@end
