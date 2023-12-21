#include <iostream>
using namespace std;

void rightRotateByOne(int arr[], int arr_size) {
    int last = arr[arr_size - 1];
    for (int i = arr_size - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = last;
}

void leftRotateByOne(int arr[], int arr_size) {
    int first = arr[0];
    for (int i = 0; i < arr_size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[arr_size - 1] = first;
}

void leftRotate(int arr[], int k, int arr_size) {
    for (int i = 0; i < k; i++) {
        leftRotateByOne(arr, arr_size);
    }
}

void rightRotate(int arr[], int k, int arr_size) {
    for (int i = 0; i < k; i++) {
        rightRotateByOne(arr, arr_size);
    }
}

void printArray(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

int main() {
    const int maxSize = 100; 
    int arr[maxSize];
    int arr_size;


    cout << "Enter the size of the array: ";
    cin >> arr_size;


    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }

    cout << "Original Array = ";
    printArray(arr, arr_size);

    int rotationCount;
    cout << "Enter the number of positions to rotate: ";
    cin >> rotationCount;

    cout << "Left shift array by " << rotationCount << " = ";
    leftRotate(arr, rotationCount, arr_size);
    printArray(arr, arr_size);

    cout << "Right shift array by " << rotationCount << " = ";
    rightRotate(arr, rotationCount, arr_size);
    printArray(arr, arr_size);

    return 0;
}
