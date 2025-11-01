# Snake win_feature branch

This branch has two specific goals:
1. Implementing win condition logic
  - If the snake size is equal to the area of the grid, the program ends and will render the full snake golden.
2. Refactoring existing code
  - Improving readability, organization, and efficiency of the core game logic without changing gameplay behavior.

**WARNING:**
This branch is under active development and may contain unstable or incomplete code.
Running or compiling the project from this branch could result in errors, crashes, or unexpected behavior.

If you want to play or test the stable version of the game, please switch to the [main](https://github.com/valentina893/Snake/tree/main)
 branch instead.
SDL2 is a required dependency.

For mac/linux systems, compile and run with: 
```
gcc src/main.c src/renderer.c src/snake.c src/input.c src/game.c -o snake $(pkg-config --cflags --libs sdl2) && ./snake
```

New features to be added can be found in the [todo](/docs/todo.md) document.
