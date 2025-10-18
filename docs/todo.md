# TODO List

- Redesign game engine class for ease of adding on to.
  - Change game function naming style.
    - Main Functions will be denoted as game_create(), game_run(), etc.
    - Helper Functions will be denoted as _game_helper(), _game_foo(), etc.

- Create a "dead screen."
  - Currently, the game class abruptly closes the program when a collision has been detected.
  - What should happen is the game goes into a "paused" state and renders the frame it left off on.
    - The snake will be rendered standing still and colored grey.
    - The apple is still in the same position.
  - The game still reads for input.
    - If 'R' is pressed, the game restarts itself.
    - The game closes as usual if 'ESC' is pressed.
