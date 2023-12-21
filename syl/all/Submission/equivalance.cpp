#include <iostream>

using namespace std;

bool isReflexive(int matrix[10][10], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (matrix[i][i] != 1)
        {
            return false;
        }
    }
    return true;
}

bool isSymmetric(int matrix[10][10], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(int matrix[10][10], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j] == 1)
            {
                for (int k = 0; k < size; ++k)
                {
                    if (matrix[j][k] == 1 && matrix[i][k] != 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int size;

    cout << "Enter the size of the matrix: ";
    cin >> size;

    int matrix[10][10];

    cout << "Enter the elements of the matrix (0 or 1):\n";
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // Check properties
    if (isReflexive(matrix, size))
    {
        cout << "The matrix represents a reflexive relation." << endl;
    }
    else
    {
        cout << "The matrix does not represent a reflexive relation." << endl;
    }

    if (isSymmetric(matrix, size))
    {
        cout << "The matrix represents a symmetric relation." << endl;
    }
    else
    {
        cout << "The matrix does not represent a symmetric relation." << endl;
    }

    if (isTransitive(matrix, size))
    {
        cout << "The matrix represents a transitive relation." << endl;
    }
    else
    {
        cout << "The matrix does not represent a transitive relation." << endl;
    }

    cin;

    return 0;
}
