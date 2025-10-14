# Snake_Game

Note: This is an early prototype. Apples can sometimes spawn on top of the snake. Might fix later if I am motivated enough.

Controls:
- WASD/Arrow Keys: changing direction of snake.
- R: restarting the game.
- ESC: quitting the game.

sdl2 is a required dependency

for mac/linux systems, compile and run with: gcc src/main.c src/game.c src/renderer.c src/snake.c src/input.c -o snake $(pkg-config --cflags --libs sdl2) && ./snake

![example](/assets/screenshot.png "example")
