
#include <iostream>
using namespace std;

const int N = 8;

// Function to print the chessboard with queens placed
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a queen can be placed at a position without attacking other queens
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check left side of the row
    for (i = 0; i < col; ++i)
    {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; ++i, --j)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// Function to solve the 8 Queens problem recursively
bool solveNQueensUtil(int board[N][N], int col)
{
    if (col == N)
    {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; ++i)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1) || res;
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

// Function to solve the 8 Queens problem
void solveNQueens()
{
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0))
    {
        cout << "Solution does not exist" << endl;
    }
}

int main()
{
    solveNQueens();
    return 0;
}
