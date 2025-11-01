# Snake :snake::video_game:

![screenshot](/assets/screenshot.png)

Controls:
- WASD/Arrow Keys: Changing direction of the snake.
- R: Restarts the game.
- ESC: Quits from the game.

SDL2 is a required dependency.

For mac/linux systems, compile and run with: `gcc src/main.c src/renderer.c src/snake.c src/input.c src/game.c -o snake $(pkg-config --cflags --libs sdl2) && ./snake`

New features to be added can be found in the [todo](/docs/todo.md) document.
