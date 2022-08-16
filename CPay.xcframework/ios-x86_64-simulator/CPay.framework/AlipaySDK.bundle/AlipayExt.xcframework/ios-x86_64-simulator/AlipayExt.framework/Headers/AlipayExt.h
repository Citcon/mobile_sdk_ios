//
//  AlipayExt.h
//  AlipayExt
//
//  Created by long.zhao on 2/21/22.
//

#import <Foundation/Foundation.h>

//! Project version number for AlipayExt.
FOUNDATION_EXPORT double AlipayExtVersionNumber;

//! Project version string for AlipayExt.
FOUNDATION_EXPORT const unsigned char AlipayExtVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AlipayExt/PublicHeader.h>

typedef void(^CompletionBlock)(NSDictionary *resultDic);

@interface AlipayExt : NSObject

+ (void)payOrder:(NSString *)orderStr
      fromScheme:(NSString *)schemeStr
        callback:(CompletionBlock)completionBlock;

+ (void)handleUrl:(NSURL *)url
          options:(NSDictionary<NSString *, id> *)options
         callback:(CompletionBlock)completionBlock;

@end
