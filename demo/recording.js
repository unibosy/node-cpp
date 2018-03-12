const EventEmitter = require("events");
const agora = require("./agorasdk");
//require("./webgl-utils")
//require("./AgoraRender2")

console.log("hhhhhhh");
class Recording  {
    constructor() {
        //super();
        console.log(agora);
        this.recording = new agora.NodeRecordingSdk();
        //'this.streams = {};
    }

    initialize(appid, onSuccess, onFailed) {
        //return this.rtcengine.initialize(appid);
    };

    joinChannel(key, name, chan_info, uid, appliteDir) {
        console.log("hhhhhhh");
        return this.recording.joinChannel(key, name, chan_info, uidi, appliteDir);
    }

    leaveChannel() {
        /*var localRender = this.streams["local"];
        this.streams = {};
        this.streams["local"] = localRender;
        return this.rtcengine.leaveChannel();*/
    }

};
let rec = new Recording();
rec.joinChannel();
module.exports = Recording;
