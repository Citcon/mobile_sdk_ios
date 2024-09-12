//
//  CPayOrder.h
//  CPay
//
//  Created by long.zhao on 3/27/22.
//

#import <Foundation/Foundation.h>
#import "CPayDefines.h"

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

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
@property (nonatomic, copy) NSString *consumerStreet;
@property (nonatomic, copy) NSString *consumerCity;
@property (nonatomic, copy) NSString *consumerZip;
@property (nonatomic, copy) NSString *consumerCountry;

@property (nonatomic, copy) NSString *taxableAmount;
@property (nonatomic, copy) NSString *taxExemptAmount;
@property (nonatomic, copy) NSString *totalTaxAmount;
@property (nonatomic, copy) NSString *productType;
@property (nonatomic, copy) NSString *desc; // goods
@property (nonatomic, copy) NSString *sku;

@property (nonatomic, copy) NSString *installmentId;
@property (nonatomic, copy) NSString *installmentNumber;
@property (nonatomic, copy) NSString *installmentQuantity;

@property (nonatomic, copy) NSString *cardIssuer;
@property (nonatomic, copy) NSString *totalDiscountCode;
@property (nonatomic, copy) NSString *cashReceiptType;

@property (nonatomic, strong) UIViewController *controller;
@property (nonatomic, assign) CPayUnionMode unionPayMode;

@property (nonatomic, retain, readwrite) NSString *transactionId;

@property (nonatomic, copy) NSString *source;
@property (nonatomic, copy) NSString *note;
@property (nonatomic, assign) BOOL autoCapture;





@end

NS_ASSUME_NONNULL_END
