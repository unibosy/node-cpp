#include <node.h>
#include <node_object_wrap.h>
#include "node_log.h"
#include "node_napi_api.h"
#include "node_uid.h"

#include <../agorasdk/AgoraSdk.h>

using namespace agora;
using agora::base::opt_parser;
using v8::Isolate;

#define unsigned int uid_t


//Used to declare native interface to nodejs
#define NAPI_API(m) \
    static void (m)(const FunctionCallbackInfo<Value>& args)

//Used to define native interface which is exposed to nodejs
#define NAPI_API_DEFINE(cls, method) \
    void cls::method(const FunctionCallbackInfo<Value>& args)

//class NodeEventHandler;

//class NodeRecordingSdk is the wrapper for AgoraSdk, and is exposed to nodejs as the native interface.

class NodeRecordingSdk : public node::ObjectWrap {
public:
    //Constructor
    static void createInstance(const FunctionCallbackInfo<Value>& args);
    // Helper function, used to declare all supported native interface that are exposed to nodejs.
    static void Init(Local<Object>& module);
    //Wrapper for RtcEngine functions
    NAPI_API(joinChannel);
    //NAPI_API(leaveChannel);
//private:
   NodeRecordingSdk(Isolate *isolate);
   ~NodeRecordingSdk(){}
private:
    DECLARE_CLASS;
    AgoraSdk* m_agorasdk;
    Isolate* m_isolate;
};


/**
 * Helper MACRO to check whether the last API call return success.
 */
 #define CHECK_NAPI_STATUS(status) \
    if(status != napi_ok) { \
        LOG_ERROR("Error :%s, :%d\n", __FUNCTION__, __LINE__); \
    }


//Use to extract native this pointer from JS object
#define napi_get_native_this(args, native) \ 
    native = ObjectWrap::Unwrap<NodeRecordingSdk>(args.Holder());

//Helper MACRO to check whether the extracted native this is valid.
#define CHECK_NATIVE_THIS(recording) \
        if(!recording || !recording->m_agorasdk) { \
            LOG_ERROR("m_agorasdk is null.\n");\
        }

