#include <iostream>
using namespace std;

const int MAX = 100;

void insert(int matrix[MAX][MAX], int r, int c)
{
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
           // cout << "Enter element at position [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void display(int matrix[MAX][MAX], int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(const int mat1[MAX][MAX], const int mat2[MAX][MAX], int res[MAX][MAX], int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(const int mat1[MAX][MAX], const int mat2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
    {
        cerr << "Matrix multiplication not possible." << endl;
        return;
    }

    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; ++k)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2;

    cout << "Enter the number of r and columns for the first matrix:" << endl;
    cin >> r1 >> c1;
    insert(mat1, r1, c1);

    cout << "Enter the number of r and columns for the second matrix:" << endl;
    cin >> r2 >> c2;
    insert(mat2, r2, c2);

    cout << "Matrix 1:" << endl;
    display(mat1, r1, c1);

    cout << "Matrix 2:" << endl;
    display(mat2, r2, c2);

    if (r1 == r2 && c1 == c2)
    {
        addMatrices(mat1, mat2, res, r1, c1);
        cout << "Sum of matrices:" << endl;
        display(res, r1, c1);
    }
    else
    {
        cout << "Matrices must have the same dimensions for addition." << endl;
    }

    if (c1 == r2)
    {
        multiplyMatrices(mat1, mat2, res, r1, c1, r2, c2);
        cout << "Product of matrices:" << endl;
        display(res, r1, c2);
    }

    return 0;
}
