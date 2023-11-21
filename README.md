# Conway's Game of Life in C++

Welcome to the Conway's Game of Life implementation in C++! This simple yet fascinating cellular automaton comes to life in the world of C++. Explore the mesmerizing patterns that emerge from just a few basic rules.

## How to Run

To run the Conway's Game of Life simulation, follow these steps:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/conway-game-of-life-cpp.git
   ```

2. Navigate to the project directory:

   ```bash
   cd conway-game-of-life-cpp
   ```

3. Compile the source code:

   ```bash
   g++ -o conway_game conway_game.cpp
   ```

4. Run the executable:

   ```bash
   ./conway_game
   ```

## Rules of the Game

The Game of Life is a cellular automaton devised by mathematician John Conway. The rules are simple:

1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

## Customize the Simulation

Feel free to tweak the initial configuration and experiment with different patterns.

## License

This Conway's Game of Life implementation is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Enjoy the mesmerizing world of cellular automata! 🚀
