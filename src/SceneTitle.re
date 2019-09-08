open Reprocessing;


type sceneTitleProps = {
  title:string,
};

let make = (~props, env) => {
  Draw.background(Constants.white, env);
  Draw.text(~body=props.title, ~pos=(300, 70), env);
  Draw.text(~body="Press Any Button To Start", ~pos=(200, 150), env);
  Draw.text(~body="Escape To Exit", ~pos=(290, 200), env);
  props;
};
