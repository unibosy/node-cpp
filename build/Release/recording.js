﻿const EventEmitter = require("events");
const agora = require("./agora_node_ext");
//require("./webgl-utils")
//require("./AgoraRender2")

class Recording  {
    constructor() {
        super();
        this.recording = new agora.NodeRecordingSdk();
        'this.streams = {};
    }

    initialize(appid, onSuccess, onFailed) {
        return this.rtcengine.initialize(appid);
    };

    joinChannel(key, name, chan_info, uid) {
        return this.rtcengine.joinChannel(key, name, chan_info, uid);
    }

    leaveChannel() {
        var localRender = this.streams["local"];
        this.streams = {};
        this.streams["local"] = localRender;
        return this.rtcengine.leaveChannel();
    }

};

module.exports = Recording;
