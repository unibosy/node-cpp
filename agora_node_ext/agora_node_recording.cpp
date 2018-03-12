#include <node.h>
#include <v8.h>
#include "agora_node_recording.h"
#include "node_log.h"
#include <string>
#include <iostream>
using namespace std;
using std::string;
//using namespace v8;

#define NODE_UID_TYPE 

DEFINE_CLASS(NodeRecordingSdk);

void NodeRecordingSdk::Init(Local<Object>& module) {
    Isolate *isolate = module->GetIsolate();
    BEGIN_PROPERTY_DEFINE(NodeRecordingSdk, createInstance, 2)//NodeRecordingSdk count of member var
        PROPERTY_METHOD_DEFINE(joinChannel)
    EN_PROPERTY_DEFINE()
    module->Set(String::NewFromUtf8(isolate, "NodeRecordingSdk"), tpl->GetFunction());
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
    m_agorasdk = new AgoraSdk();
    LOG_LEAVE;
}

NAPI_API_DEFINE(NodeRecordingSdk, joinChannel) {
    LOG_ENTER;
    cout<<"coming.........."<<endl;
    
    agora::recording::RecordingConfig config;

    NodeString key, name, chan_info, applitDir, appid;   
    uid_t uid;
    NodeRecordingSdk* pRecording = NULL;
    napi_get_native_this(args, pRecording);
    CHECK_NATIVE_THIS(pRecording);
    napi_status status = napi_get_value_nodestring_(args[0], key);
    CHECK_NAPI_STATUS(status);
    status = napi_get_value_nodestring_(args[1], name);
    CHECK_NAPI_STATUS(status);
    
    status = napi_get_value_nodestring_(args[2], applitDir);
    CHECK_NAPI_STATUS(status);
    
    status = napi_get_value_nodestring_(args[3], appid);
    CHECK_NAPI_STATUS(status);
    
    status = NodeUid::getUidFromNodeValue(args[4], uid);
    CHECK_NAPI_STATUS(status);
    string str_appid = (string)appid;
    string str_key = (string)key;
    string str_name = (string)name;
    //todo
    int result = pRecording->m_agorasdk->createChannel(str_appid, str_key, str_name, uid, config);
    //napi_set_int_result(args, result);
    do {
    }while(false);
    LOG_LEAVE;
}
