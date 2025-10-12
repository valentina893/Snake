# Snake_Game

Note: This is an early prototype. Collision detection with walls or the snake’s body has not yet been implemented — the only interactions currently handled are with apples.

sdl2 is a required dependency

for mac/linux systems, compile and run with: gcc src/main.c src/game.c src/renderer.c src/snake.c src/input.c -o snake $(pkg-config --cflags --libs sdl2) && ./snake

![example](/assets/screenshot.png "example")
