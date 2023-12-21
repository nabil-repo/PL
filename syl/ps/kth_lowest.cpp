#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int kth = 2;
    int n = 0;
    int a[3][3] = {{2, 4, 3}, {5, 2, 6}, {1, 9, 7}};

    int s[6];
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            s[n] = a[i][j];
            // cout << s[n] << endl;
            n++;
        }
    }

    // Sorting
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (s[j] > s[j + 1])
            {
                int temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    cout << "kth lowest :" << endl;
   
    cout << s[kth-1] << " ";
  
    cout << endl;

    return 0;
}
