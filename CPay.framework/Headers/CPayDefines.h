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

// payment notification
static NSString * const kOrderPaymentFinishedNotification = @"CPAY_INQUIRE_ORDER";
static NSUInteger const kOrderPaymentCancelledByUserCode = 6001;

// API run environment
typedef NS_ENUM(NSInteger, CPayMode){
    CPayModePROD = 0,     // default, Production Mode
    CPayModeUAT,          // UAT Mode
    CPayModeDEV           // Develop Mode
};

#endif /* CPayCommon_h */
