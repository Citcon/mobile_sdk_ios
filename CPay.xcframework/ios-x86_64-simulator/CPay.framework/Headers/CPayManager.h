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
+ (void)setupTokenKey:(NSString *_Nonnull)token;

// setup your running Environment, CPayModePROD = 0, CPayModeUAT = 1, CPayModeDEV = 2
+ (void)setupMode:(CPayMode)mode;

/**
 * Call this function in -application: openURL:
 *
 * (iOS 9+): - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
 * and in (iOS 8/7/6): - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(id)annotation
 */
+ (BOOL)processOpenUrl:(UIApplication *_Nonnull)application
                   url:(NSURL *_Nonnull)url
       standbyCallback:(CPayOrderResultBlock _Nonnull)callback;

/**
 * Call this function in -application: continueUserActivity:
 */
+ (BOOL)processUserActivity:(nonnull NSUserActivity *)userActivity;

/**
 * Create an order request with detail parameters
 *
 * @param referenceId       set a reference id string
 * @param subject           set the order subject string
 * @param body              set the order body string
 * @param amount            set the order amount, 100 means 1 USD if the currency is USD
 * @param currency          set the order currency, eg. USD, CNY, JPY.
 * @param vendor            set the order's payment method, eg. wechatpay, alipay
 * @param ipnUrl            notify url string
 * @param callbackUrl       callback by server when the payment finished
 * @param allowDuplicate    allow dumplicate the order
 * @param scheme            your app scheme, set in your App's info.plist, eg. cpaysdk, required in Alipay
 * @param completion        completion callback, check the 'CPayOrderResultBlock' for details
 * @param controller        root viewcontroller, required in UnionPay(upop)
 */
+ (void)requestOrder:(NSString *_Nonnull)referenceId
             subject:(NSString *_Nonnull)subject
                body:(NSString *_Nonnull)body
              amount:(NSString *_Nonnull)amount
            currency:(NSString *_Nonnull)currency
              vendor:(NSString *_Nonnull)vendor
              ipnUrl:(NSString *_Nonnull)ipnUrl
         callbackUrl:(NSString *_Nonnull)callbackUrl
      allowDuplicate:(BOOL)allowDuplicate
              scheme:(NSString*_Nonnull)scheme
  rootViewController:(UIViewController*_Nonnull)controller
          completion:(CPayOrderResultBlock _Nullable )completion;

/**
 * Create an order request with detail parameters (new ADD "ext" field)
 *
 * @param referenceId           set a reference id string
 * @param subject                    set the order subject string
 * @param body                           set the order body string
 * @param amount                      set the order amount, 100 means 1 USD if the currency is USD
 * @param currency                  set the order currency, eg. USD, CNY, JPY.
 * @param vendor                      set the order's payment method, eg. wechatpay, alipay
 * @param ipnUrl                      notify url string
 * @param callbackUrl           callback by server when the payment finished
 * @param allowDuplicate    allow dumplicate the order
 * @param ext                             extra string, eg. "{\"reference2\":\"123456789\"\,\"reference3\":\"xxxx\"}"
 * @param scheme                      your app scheme, set in your App's info.plist, eg. cpaysdk, required in Alipay
 * @param completion             completion callback, check the 'CPayOrderResultBlock' for details
 * @param controller             root viewcontroller, required in UnionPay(upop)
 */
+ (void)requestOrder:(NSString *_Nonnull)referenceId
             subject:(NSString *_Nonnull)subject
                body:(NSString *_Nonnull)body
              amount:(NSString *_Nonnull)amount
            currency:(NSString *_Nonnull)currency
              vendor:(NSString *_Nonnull)vendor
              ipnUrl:(NSString *_Nonnull)ipnUrl
         callbackUrl:(NSString *_Nonnull)callbackUrl
      allowDuplicate:(BOOL)allowDuplicate
                ext:(NSString *_Nonnull)ext
              scheme:(NSString*_Nonnull)scheme
  rootViewController:(UIViewController*_Nonnull)controller
          completion:(CPayOrderResultBlock _Nullable )completion;

/**
 * Create an order request with the order object
 *
 * @param order         order object
 * @param completion    completion callback, check the 'CPayOrderResultBlock' for details
 */
+ (void)requestOrder:(CPayOrder *_Nonnull)order
          completion:(CPayOrderResultBlock _Nonnull )completion;

/**
 * Check the order payment result, normally, you don't need to call this function, just by observing the "kOrderPaymentFinishedNotification"
 *
 * @param order         order object
 * @param transactionId transaction id
 * @param method        eg. real
 * @param completion    completion callback, check the 'CPayCheckResultBlock' for details
 */
+ (void)inquireResult:(NSString *_Nonnull)transactionId
                order:(CPayOrder*_Nonnull)order
               method:(NSString *_Nonnull)method
           completion:(CPayCheckResultBlock _Nonnull )completion;

/**
 * Check the order payment result by reference. Make sure your reference id is unique.
 *
 * @param referenceId       reference id of the order
 * @param currency              currency of the order
 * @param method                  eg. real
 * @param vendor                  vendor
 * @param completion         completion callback, check the 'CPayCheckResultBlock' for details
 */
+ (void)inquireResultByRef:(NSString *_Nullable)referenceId
                  currency:(NSString *_Nullable)currency
                    method:(NSString *_Nullable)method
                    vendor:(NSString *_Nullable)vendor
                completion:(CPayCheckResultBlock _Nullable )completion;

/**
 * Check if WeChat application is installed
 *
 * @param wxAppId       Wechat app ID
 * @param universalLink  Apple Universal Link
 */
+ (BOOL)isWechatInstalled:(NSString *_Nonnull)wxAppId
            universalLink:(NSString*_Nonnull)universalLink;


/**
*   Check if the Alipay CN application is installed
*/
+ (BOOL)isAlipayInstalled;

/**
*   Check if the Alipay HK application is installed
*/
+ (BOOL)isAlipayHKInstalled;

/**
*   Check if the Kakao Pay application is installed
*/
+ (BOOL)isKakaoPayInstalled;

/**
*   Check if the UnionPay(aka. upop)  application is installed
*/
+ (BOOL)isUnionPayInstalled;

/**
*   Check if the Gcash  application is installed
*/
+ (BOOL)isGcashInstalled;

/**
 * Get the SDK version
 */
+ (NSString* _Nonnull)getVersion;

@end
