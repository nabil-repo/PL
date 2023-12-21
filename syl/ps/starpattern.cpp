#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n =5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout<<"* ";
        }
        for (int j = 1; j < i; j++)
        {
            cout<<" ";
        }
         for (int j = 1; j <i; j++)
        {
            cout<<" ";
        }
         for (int j = n; j >= i; j--)
        {
            cout<<"* ";
        }

        cout<<endl;
        
        
    }
    
    return 0;
}
