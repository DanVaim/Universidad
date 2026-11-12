"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.replaceInvalidSongUrl = exports.startServer = void 0;
const picocolors_1 = __importDefault(require("picocolors"));
function startServer({ app, PORT }) {
    app.listen(PORT, () => {
        console.log(picocolors_1.default.bgBlack(picocolors_1.default.green(`SERVER RUNNING ON PORT ${PORT}`)));
    });
    return;
}
exports.startServer = startServer;
const DEFAULT_SONG_URL = "https://p.scdn.co/mp3-preview/174b7bd06c6ddb87d25acec6afc731c6edc9db62";
function replaceInvalidSongUrl(url) {
    if (url.includes("open") || url.includes("spotify")) {
        return DEFAULT_SONG_URL;
    }
    return url;
}
exports.replaceInvalidSongUrl = replaceInvalidSongUrl;
