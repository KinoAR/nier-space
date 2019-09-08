open Reprocessing;
open Entity;
open Reducers;
open Game;

let setup = (env) => {
  Env.size(~width=800, ~height=600, env);
  {score: 0, lives: 3, player:Player.player((100, 100)), enemies: [], gameScene: Title, title: "Nier Space"};
}



let draw = ({score, title, lives, player, enemies, gameScene} as state, env) => {
 switch(gameScene) {
    | Title => {
      let titleState = SceneTitle.make(~props={title:title}, env);
      combineGameWithTitle(state, titleState);
      } 
    | Battle => {
      let battleState = SceneBattle.make(~props={player, enemies, lives, score}, env);
      combineGameWithBattle(state, battleState);
    }
        | GameOver => state
    | HighScore => state
  };

};

run(~setup, ~draw, ());
