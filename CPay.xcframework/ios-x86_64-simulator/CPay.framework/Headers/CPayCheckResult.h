//
//  CPayCheckResult.h
//  CPay
//
//  Created by long.zhao on 3/27/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CPayCheckResult : NSObject

@property (nonatomic, retain, readonly) NSString *transactionId;
@property (nonatomic, retain, readonly) NSString *referenceId;
@property (nonatomic, retain, readonly) NSString *type;
@property (nonatomic, retain, readonly) NSString *amount;
@property (nonatomic, retain, readonly) NSString *currency;
@property (nonatomic, retain, readonly) NSString *time;
@property (nonatomic, retain, readonly) NSString *status;
@property (nonatomic, retain, readonly) NSString *refund_status;
@property (nonatomic, retain, readonly) NSString *refunded_amount;
@property (nonatomic, retain, readonly) NSString *note;
@property (nonatomic, assign, readonly) NSInteger code;
@property (nonatomic, retain, readonly) NSString *message;

@end

NS_ASSUME_NONNULL_END
