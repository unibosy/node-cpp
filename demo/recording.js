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

    joinChannel(key, name, chan_info, uid, appliteDir, appid) {
        console.log("hhhhhhh");
        return this.recording.joinChannel(key, name, appliteDir, appid, uid);
    }

    leaveChannel() {
        return this.recording.leaveChannel();
    }

};
let rec = new Recording();
rec.joinChannel(null, "myrobot", null, 99999,  "./", "0c0b4b61adf94de1befd7cdd78a50444");

rec.leaveChannel();


module.exports = Recording;
