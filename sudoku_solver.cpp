#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>> &board)
{
    if (board.empty() || board.size() != 9 || board[0].size() != 9)
    {
        cout << "Invalid board size!" << endl;
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isValidForCorrect(const vector<vector<int>> &board)
{
    if (board.empty() || board.size() != 9 || board[0].size() != 9)
    {
        cout << "Invalid board size!" << endl;
        return false;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] < 1 || board[i][j] > 9)
            {
                cout << "Invalid number at position (" << i + 1 << ", " << j + 1 << ")!" << endl;
                return false;
            }
        }
    }

    return true;
}

bool isValidForSolution(const vector<vector<int>> &board)
{
    if (board.empty() || board.size() != 9 || board[0].size() != 9)
    {
        cout << "Invalid board size!" << endl;
        return false;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] < 0 || board[i][j] > 9)
            {
                cout << "Invalid number at position (" << i + 1 << ", " << j + 1 << ")!" << endl;
                return false;
            }
        }
    }

    return true;
}

bool isCorrect(const vector<vector<int>> &board)
{
    if (!isValidForCorrect(board))
    {
        cout << "Not valid for checking correctness!" << endl;
        return false;
    }

    vector<vector<int>> row(9, vector<int>(10, 0)), col(9, vector<int>(10, 0)), box(9, vector<int>(10, 0));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int num = board[i][j];
            if (row[i][num] || col[j][num] || box[3 * (i / 3) + j / 3][num])
                return false;

            row[i][num] = 1;
            col[j][num] = 1;
            box[3 * (i / 3) + j / 3][num] = 1;
        }
    }

    return true;
}

bool solveSudokuHelper(int i, int j, vector<vector<int>> &board,
                       vector<vector<int>> &row, vector<vector<int>> &col, vector<vector<int>> &box)
{
    if (i == 9)
        return true;

    if (board[i][j])
    {
        return solveSudokuHelper((j + 1) % 9 == 0 ? i + 1 : i, (j + 1) % 9, board, row, col, box);
    }

    for (int val = 1; val <= 9; val++)
    {
        if (row[i][val] || col[j][val] || box[3 * (i / 3) + j / 3][val])
            continue;

        board[i][j] = val;
        row[i][val] = 1;
        col[j][val] = 1;
        box[3 * (i / 3) + j / 3][val] = 1;

        if (solveSudokuHelper((j + 1) % 9 == 0 ? i + 1 : i, (j + 1) % 9, board, row, col, box))
            return true;

        row[i][val] = 0;
        col[j][val] = 0;
        box[3 * (i / 3) + j / 3][val] = 0;
        board[i][j] = 0;
    }

    return false;
}

bool solveSudoku(vector<vector<int>> &board)
{
    vector<vector<int>> row(9, vector<int>(10, 0));
    vector<vector<int>> col(9, vector<int>(10, 0));
    vector<vector<int>> box(9, vector<int>(10, 0));

    if (!isValidForSolution(board))
    {
        cout << "Not valid for solving the Sudoku!" << endl;
        return false;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j])
            {
                int num = board[i][j];
                row[i][num] = 1;
                col[j][num] = 1;
                box[3 * (i / 3) + j / 3][num] = 1;
            }
        }
    }

    return solveSudokuHelper(0, 0, board, row, col, box);
}

int main()
{
    vector<vector<int>> board(9, vector<int>(9, 0));

    cout << "Enter the Sudoku board (empty cells as 0):" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board))
    {
        cout << "\nSolved Sudoku Board:\n";
        printBoard(board);
        cout << (isCorrect(board) ? "Solution is correct!" : "Solution is not correct!") << endl;
    }
    else
    {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}