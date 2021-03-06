// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from emitter.djinni

#import "RCTCoreLGEvent.h"


@implementation RCTCoreLGEvent
//Export module
RCT_EXPORT_MODULE(RCTCoreLGEvent)

-(instancetype)init
{
    self = [super init];
    //Init Objc implementation
    if(self)
    {
        self.objcImpl = [[LGEvent alloc] init];
    }
    return self;
}

/**
 *Get event code (for more details, please refer to EventCode enum)
 *@return EventCode enum entry
 */
RCT_REMAP_METHOD(getCode,getCodeWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :@([self.objcImpl getCode])};if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGEvent::getCode", nil);
    }
}

/**
 *Get payload of event
 *@return DynamicObject object
 */
RCT_REMAP_METHOD(getPayload,getPayloadWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getPayload]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGEvent::getPayload", nil);
    }
}

/**
 *Know if event is sticky one
 *@return bool
 */
RCT_REMAP_METHOD(isSticky,isStickyWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :@([self.objcImpl isSticky])};if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGEvent::isSticky", nil);
    }
}

/**
 *If event is sticky, return sticky tag
 *@return 32 bits integer
 */
RCT_REMAP_METHOD(getStickyTag,getStickyTagWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :@([self.objcImpl getStickyTag])};if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGEvent::getStickyTag", nil);
    }
}

/**
 *Create a new instance of Event class
 *@param code, EventCode enum entry
 *@param payload, DynamicObject object
 *@return Event instance
 */
RCT_REMAP_METHOD(newInstance,newInstance:(LGEventCode)code
                                 payload:(nullable LGDynamicObject *)payload withResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[LGEvent newInstance:code payload:payload]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGEvent::newInstance", nil);
    }
}
@end
