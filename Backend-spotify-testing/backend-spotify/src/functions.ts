import { StartServerProps } from "./types";
import picocolors from "picocolors";

export function startServer({ app, PORT }: StartServerProps) {
  app.listen(PORT, () => {
    console.log(
      picocolors.bgBlack(picocolors.green(`SERVER RUNNING ON PORT ${PORT}`))
    );
  });

  return;
}

const DEFAULT_SONG_URL = "https://p.scdn.co/mp3-preview/174b7bd06c6ddb87d25acec6afc731c6edc9db62";

export function replaceInvalidSongUrl(url: string): string {
  if (url.includes("open") || url.includes("spotify")) {
    return DEFAULT_SONG_URL;
  }
  return url;
}
