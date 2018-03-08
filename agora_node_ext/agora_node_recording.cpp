#include <node.h>
#include <v8.h>

#include "agora_node_recording.h"
#include "node_log.h"

#include <string>
using std::string;

using namespace v8;


void NodeRecordingSdk::Init(Local<Object>& module) {
    Isolate *isolate = module->GetIsolate();
    BEGIN_PROPERTY_DEFINE(NodeRtcEngine, createInstance, 5)
        PROPERTY_METHOD_DEFINE(joinChannel)
    EN_PROPERTY_DEFINE()
}
//The function is used as class constructor in JS layer

void NodeRecordingSdk::createInstance(const FunctionCallbackInfo<Value>& args) {
    LOG_ENTER;
    Isolate *isolate = args.GetIsolate();
    //Called from new
    if (args.IsConstructCall()) {
        NodeRecordingSdk* recording = new NodeRecordingSdk(isolate);
        recording->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }else {
        Local<Function> cons = Local<Function>::New(isolate, constructor);
        Local<Context> context = isolate->GetCurrentContext();
        Local<Object> instance = cons->NewInstance(context).ToLocalChecked();
        args.GetReturnValue().Set(instance);
    }
    LOG_LEAVE;
}
NodeRecordingSdk::NodeRecordingSdk(Isolate *isolate)
   : m_isolate(isolate) {
    LOG_ENTER;
    //m_eventHandler = new NodeEventHandler(this);
    LOG_LEAVE;
}
/*
int joinChannel(const FunctionCallbackInfo<Value>& args) {
    // 使用 HandleScope 来管理生命周期
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    // 判断参数格式和格式
    if (args.Length() < 2 || !args[0]->IsString()) {
       isolate->ThrowException(Exception::TypeError(
                   String::NewFromUtf8(isolate, "Wrong arguments")));
       return -1;
    }
    // callback, 使用Cast方法来转换
    Local<Function> callback = Local<Function>::Cast(args[1]);
    Local<Value> argv[1] = {
    // 拼接String
    String::Concat(Local<String>::Cast(args[0]), String::NewFromUtf8(isolate, " world"))};
    // 调用回调, 参数: 当前上下文，参数个数，参数列表
    callback->Call(isolate->GetCurrentContext()->Global(), 1, argv);

}

void leaveChannel(const FunctionCallbackInfo<Value>& args) {

}


// 相当于在 exports 对象中添加 { hello: hello }
void init(Handle<Object> exports) {
    NODE_SET_METHOD(exports, "hello", hello);
}

*/

NAPI_API_DEFINE(NodeRecordingSdk, joinChannel) {
    LOG_ENTER;
    NodeString key, name, chan_info;
    //napi_status status = napi_get_value_nodestring_(args[0], key);
    //CHECK_NAPI_STATUS(status);
    do {
    }while(false);



    LOG_LEAVE;
}