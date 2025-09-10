Sudoku Solver

A simple C++ console application to solve a Sudoku puzzle using backtracking.
The program takes a partially filled 9×9 Sudoku board as input (empty cells as 0) and outputs the solved board along with a correctness check.

✅ Features

Solves any valid Sudoku puzzle using backtracking.

Validates input for correct dimensions and valid numbers.

Checks if the solved solution is valid according to Sudoku rules.

Simple command-line interface with no external dependencies.

⚡ How to Use
1. Clone or Download the Project
git clone https://github.com/jk9054/sudoku-solver.git
cd sudoku-solver

2. Compile the Program
g++ sudoku_solver.cpp -o sudoku_solver

3. Run the Program
./sudoku_solver

4. Input Format

Enter the 9×9 Sudoku board row by row, using 0 for empty cells.
Example input:

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

✅ Example Output
Solved Sudoku Board:
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 

Solution is correct!

⚡ Notes

Input must be valid (numbers from 0 to 9 only).

If the puzzle is unsolvable, the program will notify you.

Designed for easy customization and learning purposes.
