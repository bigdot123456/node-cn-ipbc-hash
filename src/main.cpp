#include <cmath>
#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>
#include <string>
#include <algorithm>
#include "crypto/crypto.h"
#include "Common/Base58.h"

#include <nan.h>

using namespace node;
using namespace v8;

#define THROW_ERROR_EXCEPTION(x) Nan::ThrowError(x)

NAN_METHOD(cn_slowhash_variant_nimp) {
    if (info.Length() < 2)
        THROW_ERROR_EXCEPTION("You must provide 2 arguments.");

    Local<Object> a_input = info[0]->ToObject();
    uint32_t a_variant = info[1]->Uint32Value();

    if (!Buffer::HasInstance(a_input))
        THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

    char* input = Buffer::Data(a_input);
    Crypto::Hash output;
    size_t input_len = Buffer::Length(a_input);

    if (a_variant > 0 && input_len < 43) THROW_ERROR_EXCEPTION("Variants need more than 43 bytes input.");

    static thread_local Crypto::cn_context context;
    Crypto::cn_slow_hash(context, input, input_len, output, a_variant);

    v8::Local<Object> returnValue = Nan::CopyBuffer((char*)&output, 32).ToLocalChecked();
    info.GetReturnValue().Set(
        returnValue
    );
}

NAN_MODULE_INIT(init) {
    Crypto::CN_INIT();
    Nan::Set(target, Nan::New("cn_slowhash_variant").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(cn_slowhash_variant_nimp)).ToLocalChecked());
}

NODE_MODULE(cryptonote, init)
