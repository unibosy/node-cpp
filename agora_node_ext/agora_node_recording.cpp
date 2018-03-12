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
        PROPERTY_METHOD_DEFINE(leaveChannel)
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
    cout<<"joinChannel..."<<endl;
    
    agora::recording::RecordingConfig config;
    config.appliteDir = "./";

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
    string str_key = "";
    string str_name = (string)name;
    //todo

    int result = pRecording->m_agorasdk->createChannel(str_appid, "", str_name, uid, config);
    cout<<"pRecording->m_agorasdk->createChannel return result:"<<result<<endl;
    while (true) {
        usleep(1000*10);
    }
    //napi_set_int_result(args, result);
    do {
    }while(false);
    LOG_LEAVE;
}

NAPI_API_DEFINE(NodeRecordingSdk, leaveChannel) {
    LOG_ENTER;
    cout<<"leaveChannel..."<<endl;
    do {
        NodeRecordingSdk* pRecording = NULL;
        napi_get_native_this(args, pRecording);
        CHECK_NATIVE_THIS(pRecording);
        /*std::shared_ptr<agora::rtc::NodeVideoStreamChannel> chan;
        for (auto& channel : pEngine->m_channels) {
            if (channel->getUid() == 0) {
                chan = channel;
                break;
            }
        }
        pEngine->m_channels.clear();
        pEngine->m_channels.push_back(chan);*/
        int result = pRecording->m_agorasdk->leaveChannel();
        //args.GetReturnValue().Set(Integer::New(args.GetIsolate(), result));
    } while (false);
    LOG_LEAVE;

}
