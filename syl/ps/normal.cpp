#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{

    int a[3][3] = {{2, 4, 3}, {5, 3, 6}, {3, 9, 7}};
    int sum = 0;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            sum = sum + a[i][j];
        }
    }

    cout << "Normal is : ";
    cout << sqrt(sum);

    return 0;
}
