//
//  CPayOrderResult.h
//  CPay
//
//  Created by Siwei Y. on 6/5/17.
//  Copyright © 2017 Dinolab. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CPayOrder;

@interface CPayOrderResult : NSObject

@property (nonatomic, retain, readonly) NSString *message;
@property (nonatomic, retain, readonly) NSString *result;
@property (nonatomic, assign, readonly) NSInteger  resultStatus;
@property (nonatomic, retain, readonly) CPayOrder *order;

+ (CPayOrderResult *)orderResultWithResult:(id)result order:(CPayOrder *)order;

@end
