#include <iostream>

using namespace std;

int a[20], n;

class sorting
{

public:
    void read()
    {
        cout << "Enter the no. of elements: ";
        cin >> n;
        cout << "\nEnter the elements of the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void display()
    {
        cout << "\nThe array is: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }

    void bubble_sort()
    {
        int i, temp;
        for (i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int partition(int arr[], int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;

        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, r);
        return i + 1;
    }

    void quick_sort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int pi = partition(arr, l, r);
            quick_sort(arr, l, pi - 1);
            quick_sort(arr, pi + 1, r);
        }
    }
};

int main(int argc, char const *argv[])
{
    sorting s;
    // s.read();
    // s.bubble_sort();
    // s.display();

    // s.quick_sort(a, 0, n - 1);
    // s.display();
    int ch;
    do
    {

        cout << "\n---------\nMenu:\n1. Read \n2. Display \n3. Bubble sort\n4. Quick sort\n0. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.read();
            break;
        case 2:
            s.display();
        case 3:
            s.bubble_sort();
            break;
        case 4:
            s.quick_sort(a, 0, n - 1);
            break;
        case 0:
            return 0;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}
