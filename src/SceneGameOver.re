open Reprocessing;

type sceneGameOverPropsT = {
  score: int,
  highScore: int
};

let make =(~props, env) => {
  let {score} = props;
  Draw.text(~body="Game Over", ~pos=(100, 80), env);
  Draw.text(~body="Score: " ++ string_of_int(score), ~pos=(100, 100), env);
  {...props, highScore: score};
};
