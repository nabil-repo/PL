#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findUnion(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0;
    cout << "Union: ";
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i++] << " ";
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j++] << " ";
        }
        else
        {
            cout << arr1[i++] << " ";
            j++;
        }
    }
    while (i < size1)
    {
        cout << arr1[i++] << " ";
    }
    while (j < size2)
    {
        cout << arr2[j++] << " ";
    }
    cout << endl;
}

void findSymmetricDifference(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0;
    cout << "Symmetric Difference: ";
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i++] << " ";
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j++] << " ";
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < size1)
    {
        cout << arr1[i++] << " ";
    }
    while (j < size2)
    {
        cout << arr2[j++] << " ";
    }
    cout << endl;
}

int main()
{
    int array1[] = {4, 2, 9, 1, 5};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {5, 2, 8, 3};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    cout << "Array 1 before sorting: ";
    printArray(array1, size1);
    cout << "Array 2 before sorting: ";
    printArray(array2, size2);

    sort(array1, size1);
    sort(array2, size2);

    cout << "Array 1 after sorting: ";
    printArray(array1, size1);
    cout << "Array 2 after sorting: ";
    printArray(array2, size2);

    findUnion(array1, size1, array2, size2);
    findSymmetricDifference(array1, size1, array2, size2);

    return 0;
}
