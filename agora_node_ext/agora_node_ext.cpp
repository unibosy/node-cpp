#include "agora_node_ext.h"
#include "agora_node_recording.h"
using v8::Object;

/**
 * Initialize NODEJS ADDON
 */
void InitExt(Local<Object> module)
{
	LOG_ENTER;
    NodeRecordingSdk::Init(module);
    LOG_LEAVE;
}

/**
 * NODEJS registration
 */
NAPI_MODULE(NODE_GYP_MODULE_NAME, InitExt)
