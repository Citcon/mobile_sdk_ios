//
//  CPayOrder.h
//  AlixPayDemo
//
//  Created by 方彬 on 11/2/13.
//
//

#import <Foundation/Foundation.h>
#import "CPayDefines.h"
@import UIKit;

@interface CPayOrder : NSObject

@property (nonatomic, copy) NSString *referenceId;
@property (nonatomic, copy) NSString *amount;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *vendor;
@property (nonatomic, copy) NSString *subject;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSString *ipnUrl;
@property (nonatomic, copy) NSString *scheme;
@property (nonatomic, copy) NSString *universalLink;
@property (nonatomic, copy) NSString *callbackUrl;
@property (nonatomic, copy) NSString *callbackFail;
@property (nonatomic, copy) NSString *cancelUrl;
@property (nonatomic, assign) BOOL allowDuplicate;
@property (nonatomic, copy) NSString *transCurrency;
@property (nonatomic, copy) NSString *extra;
@property (nonatomic, assign) BOOL isAccelerateCNPay;

@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *consumerReference;

@property (nonatomic, copy) NSString *taxableAmount;
@property (nonatomic, copy) NSString *taxExemptAmount;
@property (nonatomic, copy) NSString *totalTaxAmount;

@property (nonatomic, strong) UIViewController *controller;

@property (nonatomic, retain, readwrite) NSString *transactionId;

@property (nonatomic, assign) PayType payType;

- (void)completedOrder:(CPayOrderResult *)result;

@end
