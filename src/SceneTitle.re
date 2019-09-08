open Reprocessing;


type sceneTitleProps = {
  title:string,
};

let make = (~props, env) => {
  Draw.background(Constants.white, env);
  Draw.text(~body=props.title, ~pos=(150, 70), env);
  props;
};
