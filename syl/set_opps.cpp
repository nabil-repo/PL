#include <iostream>
using namespace std;

void Union(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    while (i < m)
    {
        cout << arr1[i] << " ";
        i++;
    }

    while (j < n)
    {
        cout << arr2[j] << " ";
        j++;
    }

    cout << endl;
}

void Intersection(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    cout << endl;
}

void Difference(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < m)
    {
        cout << arr1[i] << " ";
        i++;
    }

    cout << endl;
}

void SymmetricDifference(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < m)
    {
        cout << arr1[i] << " ";
        i++;
    }

    while (j < n)
    {
        cout << arr2[j] << " ";
        j++;
    }

    cout << endl;
}

int main()
{
    int array1[] = {1, 3, 4, 5, 7};
    int array2[] = {2, 3, 5, 6};
    int m = sizeof(array1) / sizeof(array1[0]);
    int n = sizeof(array2) / sizeof(array2[0]);

    cout << "Union: ";
    Union(array1, m, array2, n);
    cout << "Intersection: ";
    Intersection(array1, m, array2, n);
    cout << "Difference (arr1 - arr2): ";
    Difference(array1, m, array2, n);
    cout << "Symmetric Difference: ";
    SymmetricDifference(array1, m, array2, n);

    return 0;
}
