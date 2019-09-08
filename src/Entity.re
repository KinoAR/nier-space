open Reprocessing;

type entityTypeT = 
| Player
| SquareShip
| CircleShip
| TriangleShip;

type statusT = 
| Alive
| Dead;

type entityT = {
  health: int,
  atk: int,
  def: int,
  position: (int, int),
  type_: entityTypeT,
  status: statusT
};

type action =
| AddHealth(int)
| AddDef(int)
| AddAtk(int)
| CollideWith(entityTypeT)
| AddMoveTo(int, int)
| NoStateChange;


let make = (~health, ~atk, ~def, ~pos, ~type_) => {
  {health, atk, def, position:pos, type_, status: Alive}
};

let makeWithDispatcher = (~health, ~atk, ~def, ~pos, ~type_, ~reducer: (entityT, action) => entityT) => {
  let newEntity = make(~health, ~atk, ~def, ~pos, ~type_); 
  let dispatcher = reducer;
  
  (newEntity, dispatcher)
};

let drawEntity = (position, type_, env) => {
  let (x, y) = position;
  switch(type_) {
    | SquareShip => Draw.rect(~pos=position, ~width=32, ~height=32, env)
    | Player => Draw.triangle(~p1=(x, 32 + y), ~p2=(32 + x, y), ~p3=(x, y), env)
    | CircleShip => Draw.ellipse(~center=(x, y), ~radx=32, ~rady=32, env)
    | TriangleShip => ()
  };
};
let dispatcher = (entityState, action) => switch(action) {
  | AddHealth(value) => {...entityState, health: entityState.health + value }
  | AddDef(value) => {...entityState, def: entityState.def + value}
  | AddAtk(value) => {...entityState, atk: entityState.atk + value}
  | CollideWith(entityType) => {...entityState, status: Dead }
  | AddMoveTo(x, y) => {
      let (posX, posY) = entityState.position;
      {...entityState, position: (posX + x, posY + y)};
    }
  | NoStateChange => entityState
};

