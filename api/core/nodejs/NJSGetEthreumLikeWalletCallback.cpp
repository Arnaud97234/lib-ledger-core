// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ethereum_like_wallet.djinni

#include "NJSGetEthreumLikeWalletCallback.hpp"

using namespace v8;
using namespace node;
using namespace std;

void NJSGetEthreumLikeWalletCallback::onSuccess(const std::shared_ptr<EthereumLikeWallet> & wallet, bool isCreated)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0_wrap = NJSEthereumLikeWallet::wrap(wallet);
    auto arg_0 = Nan::ObjectWrap::Unwrap<NJSEthereumLikeWallet>(arg_0_wrap)->handle();

    auto arg_1 = Nan::New<Boolean>(isCreated);
    Handle<Value> args[2] = {arg_0,arg_1};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGetEthreumLikeWalletCallback::onSuccess fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("onSuccess").ToLocalChecked()).ToLocalChecked();
    auto handle = this->handle();
    auto result_onSuccess = Nan::CallAsFunction(calling_funtion->ToObject(),handle,2,args);
    if(result_onSuccess.IsEmpty())
    {
        Nan::ThrowError("NJSGetEthreumLikeWalletCallback::onSuccess call failed");
    }
}

void NJSGetEthreumLikeWalletCallback::onError(const Error & error)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<Object>();
    auto arg_0_1 = Nan::New<Integer>((int)error.code);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("code").ToLocalChecked(), arg_0_1);
    auto arg_0_2 = Nan::New<String>(error.message).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("message").ToLocalChecked(), arg_0_2);

    Handle<Value> args[1] = {arg_0};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGetEthreumLikeWalletCallback::onError fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("onError").ToLocalChecked()).ToLocalChecked();
    auto handle = this->handle();
    auto result_onError = Nan::CallAsFunction(calling_funtion->ToObject(),handle,1,args);
    if(result_onError.IsEmpty())
    {
        Nan::ThrowError("NJSGetEthreumLikeWalletCallback::onError call failed");
    }
}

NAN_METHOD(NJSGetEthreumLikeWalletCallback::addRef) {

    NJSGetEthreumLikeWalletCallback *obj = Nan::ObjectWrap::Unwrap<NJSGetEthreumLikeWalletCallback>(info.This());
    obj->Ref();
}

NAN_METHOD(NJSGetEthreumLikeWalletCallback::removeRef) {

    NJSGetEthreumLikeWalletCallback *obj = Nan::ObjectWrap::Unwrap<NJSGetEthreumLikeWalletCallback>(info.This());
    obj->Unref();
}

NAN_METHOD(NJSGetEthreumLikeWalletCallback::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSGetEthreumLikeWalletCallback function can only be called as constructor (use New)");
    }

    auto resolver = v8::Promise::Resolver::New(Nan::GetCurrentContext()).ToLocalChecked();
    NJSGetEthreumLikeWalletCallback *node_instance = new NJSGetEthreumLikeWalletCallback(resolver);

    if(node_instance)
    {
        //Wrap and return node instance
        node_instance->Wrap(info.This());
        node_instance->Ref();
        info.GetReturnValue().Set(info.This());
    }
}

void NJSGetEthreumLikeWalletCallback::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSGetEthreumLikeWalletCallback::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSGetEthreumLikeWalletCallback").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"addRef", addRef);
    Nan::SetPrototypeMethod(func_template,"removeRef", removeRef);

    //Add template to target
    target->Set(Nan::New<String>("NJSGetEthreumLikeWalletCallback").ToLocalChecked(), func_template->GetFunction());
}
