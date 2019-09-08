open Reprocessing;
open Entity;

type sceneBattleProps =  {
  player: Entity.entityT,
  enemies: list(Entity.entityT),
  score: int,
  lives: int,
};

let moveCharacter = (env, dispatcher) => {
  if(Env.key(Right, env)) {
    dispatcher(AddMoveTo(1, 0));
  } else if(Env.key(Left, env)) {
    dispatcher(AddMoveTo(-1, 0));
  }
  else if(Env.key(Down, env)) {
    dispatcher(AddMoveTo(0, 1));
  }
  else if(Env.key(Up, env)) {
    dispatcher(AddMoveTo(0, -1));
  } else {
    dispatcher(AddMoveTo(0, 0));
  };

};


let make = (~props, env) => {
  let {score, enemies, player, lives } = props; 
  Draw.background(Utils.color(~r=255, ~g=217, ~b=229, ~a=255), env);

  let player = moveCharacter(env, dispatcher(player, _));
  /* Draw Characters And Entitiies*/ 
  drawEntity(player.position, player.type_, env);
  List.iteri((index, enemy) => drawEntity(enemy.position, enemy.type_, env), enemies);
  Draw.text(~body="Score: " ++ string_of_int(score), ~pos=(200, 100), env);
  let (x, y) = player.position;
  Draw.text(~body="Player Position: " ++ string_of_int(x), ~pos=(0, 120), env);
  {player, enemies, score, lives}; 
};
