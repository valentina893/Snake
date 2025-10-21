# Snake_Game

Note: This is a near-finished project. Apples can sometimes spawn on top of the snake.

Planned updates are listed in the [todo.md](docs/todo.md) file.

Controls:
- WASD/Arrow Keys: changing direction of snake.
- R: restarting the game.
- ESC: quitting the game.

sdl2 is a required dependency

for mac/linux systems, compile and run with: gcc src/main.c src/game.c src/renderer.c src/snake.c src/input.c -o snake $(pkg-config --cflags --libs sdl2) && ./snake

![example](/assets/screenshot.png "example")
