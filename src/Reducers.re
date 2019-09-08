type titleStateT = SceneTitle.sceneTitleProps;
type battleStateT = SceneBattle.sceneBattleProps;
type gameOverStateT = SceneGameOver.sceneGameOverPropsT;
type gameStateT = Game.gameStateT;

let combineGameWithTitle = (gameState:gameStateT, titleState:titleStateT) => {
  {...gameState,
    title: titleState.title
  };
};
let combineGameWithBattle = (gameState:gameStateT, battleState:battleStateT) => {
  {...gameState, 
    player: battleState.player,
    enemies: battleState.enemies,
    score: battleState.score,
    lives: battleState.lives
  };
};

let combineGameWithGameOver = (gameState:gameStateT, gameOverState:gameOverStateT) => {
 {...gameState, score: gameOverState.score, highScore: gameOverState.highScore}
};

