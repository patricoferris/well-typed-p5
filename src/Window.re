/* Adding the functions to the window */
type window;
[@bs.val "window"][@bs.scope ("window")] external window : window = "window";
[@bs.set] external set_draw: (window, unit => unit) => unit = "draw";
[@bs.set] external set_setup: (window, unit => unit) => unit = "setup";
set_draw(window, Sketch.draw);
set_setup(window, Sketch.setup);