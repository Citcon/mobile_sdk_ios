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

// API run environment
typedef NS_ENUM(NSInteger, CPayMode){
    CPayModePROD = 0,     // default, Production Mode
    CPayModeUAT,          // UAT Mode
    CPayModeDEV,          // Develop Mode
    CPayModeQA,           // QA Mode
};

// API Path Type Enum
typedef NS_ENUM(NSInteger, CPayRequestMode){
    CPayRequestModePayApp = 0,     // default, Pay app
    CPayRequestModeInquire,        // order inquire
};

#define weakify(var) \
  __weak __typeof__(var) var ## _weak = var; \

#define strongify(var) \
  __strong __typeof__(var) var = var ## _weak; \

#endif /* CPayCommon_h */
