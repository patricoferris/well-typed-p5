/****** Loading P5 functions ******/ 
[@bs.val] external ellipse : (int, int, int, int) => unit = "ellipse";
[@bs.val] external rect : (int, int, int, int) => unit = "rect";
[@bs.val] external createCanvas : (int, int) => unit = "createCanvas";
[@bs.val] external background : (int) => unit = "background";
type color = (int, int, int);
[@bs.val] external fill : color => unit = "fill";

/****** Shapes ******/ 
type shape = Circle (int, position) | Square (int, position)
and position = (int, int);

let draw_shape = (shape) => 
  switch (shape) {
  | Circle (r, (x, y)) => ellipse(x, y, r, r)
  | Square (d, (x, y)) => rect(x, y, d, d)
  };

/***** P5 Setting up and Draw Loop ******/
let red = (255, 0, 0);

/* Create the canvas and set drawing colour to red */
let setup = () => {
  createCanvas(600, 600);
  fill(red)
}

/* Recurive random point generator */
let rec random_points = (max, n) => {
  switch (n) {
  | 0 => [];
  | n => [(Random.int(max), Random.int(max)), ...(random_points(max, n - 1))];
  }
}

let points = random_points (600, 10);

/* Iterate over a list of pairs and apply the function f*/
let rec iter_pair = (f, lst) => {
  switch (lst) {
  | [] => ();
  | [(x, y), ...xs] => { f(x, y); iter_pair(f, xs) }
  }
}

/* P5 Draw Function - set background */
let draw = () => {
  background(222);
  iter_pair((x, y) => draw_shape(Circle (10, (x, y))), points)
}


