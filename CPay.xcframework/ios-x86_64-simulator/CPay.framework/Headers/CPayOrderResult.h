//
//  CPayOrderResult.h
//  CPay
//
//  Created by long.zhao on 3/27/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CPayOrder;

@interface CPayOrderResult : NSObject

@property (nonatomic, retain, readonly) NSString *message;
@property (nonatomic, retain, readonly) NSString *result;
@property (nonatomic, assign, readonly) NSInteger resultStatus;
@property (nonatomic, retain, readonly) CPayOrder *order;

@end

NS_ASSUME_NONNULL_END
