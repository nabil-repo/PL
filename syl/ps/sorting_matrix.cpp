#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
   
    int a[3][3] = {{2, 4, 3}, {5, 3, 6}, {3, 9, 7}};
   
    
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <=2; i++)
        {
            //sorting row
            if (a[i][j] > a[i][j + 1])
            {
                int temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
            }
            
        }
        
       
    }

    

    return 0;
}
