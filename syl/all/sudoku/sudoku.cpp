#include <iostream>
#include <cmath>
#define n 4
using namespace std;

void print(int a[n][n])
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << a[r][c] << " ";
        }
        cout << "\n";
    }
}

int issafe(int a[n][n], int r, int c, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (a[r][i] == num || a[i][c] == num)
        {
            return false;
        }
    }

    int subgrid = sqrt(n);
    int sr = r - r % subgrid;
    int sc = c - c % subgrid;

    for (int x = 0; x < subgrid; x++)
    {
        for (int y = 0; y < subgrid; y++)
        {
            if (a[sr + x][sc + y] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool sol_sudoku(int a[n][n])
{
    int r, c;
    bool isempty = false;

    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (a[r][c] == 0)
            {
                isempty = true;
                break;
            }
        }
        if (isempty)
        {
            break;
        }
    }

    if (!isempty)
    {
        return true;
    }

    for (int num = 1; num <= n; num++)
    {
        if (issafe(a, r, c, num))
        {
            a[r][c] = num;

            if (sol_sudoku(a))
            {
                return true;
            }
            a[r][c] = 0;
        }
    }
    return false;
}

int main()
{
    int arr[n][n] = {};

    cout << "Enter sudoku puzzle (4x4), 0 -> Empty cell: \n";
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cin >> arr[r][c];
        }
    }

    if (sol_sudoku(arr))
    {
        cout << "Solution: \n";
        print(arr);
    }
    else
    {
        cout << "Can't solve the Sudoku puzzle!\n";
    }
    return 0;
}
