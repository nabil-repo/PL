#include <iostream>

using namespace std;

class search
{

    int a[20], n;

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

    void linear_search()
    {

        int x, flag = 0;
        cout << "\nEnter the element to be searched: ";
        cin >> x;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                cout << "\nElement found at index: " << i << endl;
                flag = 1;
                return;
            }
        }
        if (flag == 0)
        {
            cout << x << "  not found" << endl;
        }
    }

    void binary_search()
    {

        int x, flag = 0, mid, l, h;
        cout << "\nEnter the element to be searched: ";
        cin >> x;
        l = 0;
        h = n - 1;

        while (l <= h)
        {
            mid = (l + h) / 2;

            if (a[mid] == x)
            {
                cout << "\nElement found at index: " << mid << endl;
                flag = 1;
                return;
            }
            else if (a[mid] < x)
            {
                l = mid + 1;
            }
            else if (a[mid] > x)
            {
                h = mid - 1;
            }
        }

        if (flag == 0)
        {
            cout << x << "  not found" << endl;
        }
    }

    void fibonacci_search()
    {
        // 10 22 35 40 45 50 80 82 85 90 100

        int x, flag = 0, f, f1, f2, offset = 0, i;
        cout << "\nEnter the element to be searched: ";
        cin >> x;

        f1 = 1;
        f2 = 0;
        f = f1 + f2;

        while (f < n)
        {
            f2 = f1;
            f1 = f;
            f = f1 + f2;
        }
        offset = 0;

        while (f > 1)
        {

            i = min(f2, n);
            if (a[i] == x)
            {
                cout << "\nElement found at index: " << i << endl;
                flag = 1;
                return;
            }
            else if (a[i] < x)
            {
                f = f1;
                f1 = f2;
                f2 = f - f1;
                offset = i;
            }
            else if (a[i] > x)
            {
                f = f2;
                f1 = f1 - f2;
                f2 = f - f1;
            }
        }
        if (flag == 0)
        {
            cout << x << "  not found" << endl;
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
};

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

int main(int argc, char const *argv[])
{
    search s;
    // s.read();
    // s.bubble_sort();
    // s.display();
    // s.fibonacci_search();
    int n = 5;
    int a[n] = {6, 4, 5, 8, 10};

    quick_sort(a, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}
