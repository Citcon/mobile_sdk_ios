//
//  CPayCheckResult.h
//  CPay
//
//  Created by Siwei Y. on 6/5/17.
//  Copyright © 2017 Dinolab. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CPayCheckResult : NSObject

@property (nonatomic, retain, readonly) NSString * transactionId;
@property (nonatomic, retain, readonly) NSString * referenceId;
@property (nonatomic, retain, readonly) NSString * type;
@property (nonatomic, retain, readonly) NSString * amount;
@property (nonatomic, retain, readonly) NSString * currency;
@property (nonatomic, retain, readonly) NSString * time;
@property (nonatomic, retain, readonly) NSString * status;
@property (nonatomic, retain, readonly) NSString * refund_status;
@property (nonatomic, retain, readonly) NSString * refunded_amount;
@property (nonatomic, retain, readonly) NSString * note;

@end
