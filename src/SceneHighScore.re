open Reprocessing;

let make = (~props, env) => {
  Draw.text(~body="High Scores", ~pos=(100, 100), env);
  Draw.text(~body="Score: ", ~pos=(100, 120), env);
};
