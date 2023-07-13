//
//  CPayDefines.h
//  CPay
//
//  Created by long.zhao on 3/28/22.
//

#ifndef CPayDefines_h
#define CPayDefines_h

@class CPayOrderResult;
@class CPayCheckResult;

typedef void (^CPayOrderResultBlock) (CPayOrderResult * result);
typedef void (^CPayCheckResultBlock) (CPayCheckResult * result);

/// SDK runtime environment
typedef NS_ENUM(NSInteger, CPayMode) {
    CPayModePROD = 0,
    CPayModeUAT,
    CPayModeDEV,
    CPayModeQA
};

/// Payment notification
static NSString * const kOrderPaymentFinishedNotification = @"CPAY_INQUIRE_ORDER";

/// Union Pay runtime environment
typedef NS_ENUM(NSInteger, CPayUnionMode) {
    CPayUnionDevMode = 0,
    CPayUnionProdMode
};

#endif /* CPayDefines_h */
