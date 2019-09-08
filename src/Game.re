
type gameSceneT =
| Title
| Battle
| GameOver
| HighScore;

type gameStateT = {
  score: int,
  lives: int,
  title: string,
  player: Entity.entityT,
  enemies: list(Entity.entityT),
  gameScene: gameSceneT
};

