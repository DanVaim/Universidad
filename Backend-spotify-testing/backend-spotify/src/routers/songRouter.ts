import { Router } from "express";
import SongsController from "../controllers/songsController";
import { SongModel } from "../typegoose/models";

const songRouter = Router();

songRouter.get("/top", SongsController.getTopSongs);
songRouter.get("/getById/:idSong", SongsController.getSongById);
songRouter.get("/genres", SongsController.getGenres);
songRouter.get("/getByGenre/:genre", SongsController.getSongsByGenre2);

songRouter.get("/updateAllOpen", async (_req, res) => {
  try {
    const result = await SongModel.updateMany(
      { urlSong: { $regex: "spotify|open", $options: "i" } },
      {
        urlSong:
          "https://p.scdn.co/mp3-preview/174b7bd06c6ddb87d25acec6afc731c6edc9db62",
      }
    );
    res.status(200).send({ message: "URLs updated successfully", result });
  } catch (error) {
    res.status(500).send({ message: "Error updating URLs", error });
  }
});

songRouter.get("/:songName", SongsController.getSongByName);


songRouter.post("/add", SongsController.addSong);

songRouter.delete("/delete/:id", SongsController.deleteSong);

export default songRouter;
