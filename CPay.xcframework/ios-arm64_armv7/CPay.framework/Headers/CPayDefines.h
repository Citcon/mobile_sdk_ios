//
//  CPayCommon.h
//  CPay
//
//  Created by Siwei Y. on 6/5/17.
//  Copyright © 2017 Dinolab. All rights reserved.
//

#ifndef CPayCommon_h
#define CPayCommon_h

@class CPayOrderResult;
@class CPayCheckResult;

typedef void (^CPayOrderResultBlock) (CPayOrderResult * result);
typedef void (^CPayCheckResultBlock) (CPayCheckResult * result);

#define kCPayErrorDomain    @"com.cpay.error"

//paymenet result
static NSString * const kFailed = @"fail";
static NSString * const kSuccess = @"success";
static NSString * const kCancel = @"cancel";

// payment notification
static NSString * const kOrderPaymentFinishedNotification = @"CPAY_INQUIRE_ORDER";
static NSUInteger const kOrderPaymentCancelledByUserCode = 6001;
static NSUInteger const kOrderPaymentFailedCode = 6002;
static NSUInteger const kOrderPaymentSuccessCode = 0;
static NSUInteger const kOrderPaymentErrorCode = 1001;

// payment callback url scheme
static NSString * const kAlipayScheme = @"safepay";
static NSString * const kWechatPayScheme = @"pay";
static NSString * const kUnionPayScheme = @"uppayresult";

// wallet app scheme
static NSString * const kAlipayCNScheme = @"alipays://";
static NSString * const kKaKaoScheme = @"kakaokompassauth://";
static NSString * const kAlipayHKScheme = @"alipayhk://";
static NSString * const kGcashScheme = @"gcash://";


// API run environment
typedef NS_ENUM(NSInteger, CPayMode){
    CPayModePROD = 0,     // default, Production Mode
    CPayModeUAT,          // UAT Mode
    CPayModeDEV           // Develop Mode
};

// API Path Type Enum
typedef NS_ENUM(NSInteger, CPayRequestMode){
    CPayRequestModePayApp = 0,     // default, Pay app
    CPayRequestModeInquire,        // order inquire
};

typedef NS_ENUM(NSInteger, PayType) {
    PayTypeAlipay,       // Alipay CN
    PayTypeWechatSDK,    // Wechat Pay
    PayTypeWechatH5,     // Wechat H5
    PayTypeAlipayHK,     // Alipay HK
    PayTypeKakao,        // Kakao Pay
    PayTypeUnion,        // Union Pay
    PayTypeDana,         // Dana Pay
    PayTypeGcash,        // Gcash Pay
    PayTypeTruemoney,    // Truemoney Pay
    PayTypeJkopay,       // Jkopay
    PayTypeEasypaisa,    // Easypaisa
    PayTypeBkash,        // Bkash
    PayTypeCC,           // CC Pay
    PayTypeTouchnGo,     // Touch'N Go
    PayTypeUnknown       // Unknown Payment Method
};

// payment vendors
static NSString * const kWechatPay = @"wechatpay";
static NSString * const kWechatPayH5 = @"wechatpay_h5";
static NSString * const kAlipay = @"alipay";
static NSString * const kAlipayHK = @"alipay_hk";
static NSString * const kUpop = @"upop";
static NSString * const kCC = @"cc";
static NSString * const kKakaoPay = @"kakaopay";
static NSString * const kGcash = @"gcash";
static NSString * const kDana = @"dana";
static NSString * const kTruemoney = @"truemoney";
static NSString * const kBkash = @"bkash";
static NSString * const kEasypaisa = @"easypaisa";
static NSString * const kJkopay = @"jkopay";
static NSString * const kTouchnGo = @"touchngo";

// fields
static NSString * const kAmount = @"amount";
static NSString * const kTransAmount = @"trans_amount";
static NSString * const kCurrency = @"currency";
static NSString * const kTransCurrency = @"trans_currency";
static NSString * const kResultField = @"reason";

// union pay test mark
static NSString * const kUnionProd = @"00";
static NSString * const kUnionDev = @"01";


// Default API
static NSString * const kDevUSDDomainPrefix = @"https://dev.citconpay.com/";        // Development Mode for USD
static NSString * const kUATUSDDomainPrefix = @"https://uat.citconpay.com/";        // UAT Mode for USD
static NSString * const kProdUSDDomainPrefix = @"https://citconpay.com/";           // Production Mode for USD

// CNY
static NSString * const kDevCNYDomainPrefix = @"https://dev.citconpay.cn/";         // Development Mode for CNY
static NSString * const kUATCNYDomainPrefix = @"https://uat.citconpay.cn/";         // UAT Mode for CNY
static NSString * const kProdCNYDomainPrefix = @"https://citconpay.cn/";            // Production Mode for CNY

// AMS & UNIONPAY
static NSString * const kDevAMSDomainPrefix = @"https://dev.citconpay.com/";        // Development Mode for AMS(eg. gcash, dana, alipay_hk, kaokaopay, upop)
static NSString * const kUATAMSDomainPrefix = @"https://uat.citconpay.com/";        // UAT Mode for AMS
static NSString * const kProdAMSDomainPrefix = @"https://citconpay.com/";           // Production Mode for AMS


// URL path
static NSString * const kPayPath = @"payment/pay_app";
static NSString * const kInquirePath = @"payment/inquire";

// URL path for AMS & UPOP
static NSString * const kAMSPayPath = @"payment/pay_app";
static NSString * const kAMSInquirePath = @"payment/inquire";

// Environment
static NSString * tokenKey = @"";
static NSInteger runMode = 0;
static NSString * currencyRMB = @"CNY";
static NSString * currencyUSD = @"USD";

#define GetPayType(vendor) \
({\
    PayType pt = PayTypeUnknown; \
    if([vendor isEqualToString: kWechatPay]) \
        pt = PayTypeWechatSDK; \
    else if([vendor isEqualToString: kWechatPayH5]) \
        pt = PayTypeWechatH5; \
    else if([vendor isEqualToString: kAlipayHK]) \
        pt = PayTypeAlipayHK; \
    else if([vendor isEqualToString: kDana]) \
        pt = PayTypeDana; \
    else if([vendor isEqualToString: kKakaoPay]) \
        pt = PayTypeKakao; \
    else if([vendor isEqualToString: kGcash]) \
        pt = PayTypeGcash; \
    else if([vendor isEqualToString: kUpop]) \
        pt = PayTypeUnion; \
    else if([vendor isEqualToString: kTruemoney]) \
        pt = PayTypeTruemoney; \
    else if([vendor isEqualToString: kEasypaisa]) \
        pt = PayTypeEasypaisa; \
    else if([vendor isEqualToString: kCC]) \
        pt = PayTypeCC; \
    else if([vendor isEqualToString: kBkash]) \
        pt = PayTypeBkash; \
    else if([vendor isEqualToString: kJkopay]) \
        pt = PayTypeJkopay; \
    else if([vendor isEqualToString: kAlipay]) \
        pt = PayTypeAlipay; \
    (pt); \
})\

#define weakify(var) \
  __weak __typeof__(var) var ## _weak = var; \

#define strongify(var) \
  __strong __typeof__(var) var = var ## _weak; \

#endif /* CPayCommon_h */
