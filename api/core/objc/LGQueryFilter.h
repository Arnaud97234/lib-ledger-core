// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#import "LGOperationType.h"
#import "LGTrustLevel.h"
#import <Foundation/Foundation.h>
@class LGAmount;
@class LGQueryFilter;


@interface LGQueryFilter : NSObject

+ (nullable LGQueryFilter *)accountEq:(nonnull NSString *)accountUid;

+ (nullable LGQueryFilter *)accountNeq:(nonnull NSString *)accountUid;

+ (nullable LGQueryFilter *)dateLte:(nonnull NSDate *)time;

+ (nullable LGQueryFilter *)dateLt:(nonnull NSDate *)time;

+ (nullable LGQueryFilter *)dateGt:(nonnull NSDate *)time;

+ (nullable LGQueryFilter *)dateGte:(nonnull NSDate *)time;

+ (nullable LGQueryFilter *)dateEq:(nonnull NSDate *)time;

+ (nullable LGQueryFilter *)dateNeq:(nonnull NSDate *)time;

+ (nullable LGQueryFilter *)containsRecipient:(nonnull NSString *)recipientAddress;

+ (nullable LGQueryFilter *)containsSender:(nonnull NSString *)senderAddress;

+ (nullable LGQueryFilter *)currencyEq:(nonnull NSString *)currencyName;

+ (nullable LGQueryFilter *)operationUidEq:(nonnull NSString *)operationUid;

+ (nullable LGQueryFilter *)operationUidNeq:(nonnull NSString *)operationUid;

+ (nullable LGQueryFilter *)trustEq:(LGTrustLevel)trust;

+ (nullable LGQueryFilter *)trustNeq:(LGTrustLevel)trust;

+ (nullable LGQueryFilter *)feesEq:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)feesNeq:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)feesGte:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)feesGt:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)feesLte:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)feesLt:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)amountEq:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)amountNeq:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)amountGte:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)amountGt:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)amountLte:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)amountLt:(nullable LGAmount *)amount;

+ (nullable LGQueryFilter *)blockHeightEq:(int64_t)blockHeight;

+ (nullable LGQueryFilter *)blockHeightNeq:(int64_t)blockHeight;

+ (nullable LGQueryFilter *)blockHeightGte:(int64_t)blockHeight;

+ (nullable LGQueryFilter *)blockHeightGt:(int64_t)blockHeight;

+ (nullable LGQueryFilter *)blockHeightLte:(int64_t)blockHeight;

+ (nullable LGQueryFilter *)blockHeightLt:(int64_t)blockHeight;

+ (nullable LGQueryFilter *)blockHeightIsNull;

+ (nullable LGQueryFilter *)operationTypeEq:(LGOperationType)operationType;

+ (nullable LGQueryFilter *)operationTypeNeq:(LGOperationType)operationType;

- (nullable LGQueryFilter *)opAnd:(nullable LGQueryFilter *)filter;

- (nullable LGQueryFilter *)opOr:(nullable LGQueryFilter *)filter;

- (nullable LGQueryFilter *)opAndNot:(nullable LGQueryFilter *)filter;

- (nullable LGQueryFilter *)opOrNot:(nullable LGQueryFilter *)filter;

@end
