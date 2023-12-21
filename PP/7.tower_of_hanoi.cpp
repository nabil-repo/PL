#include <iostream>
using namespace std;

// Function to perform Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int numDisks = 3; // Change the number of disks here

    cout << "Steps to solve the Tower of Hanoi with " << numDisks << " disks:" << endl;
    towerOfHanoi(numDisks, 'A', 'B', 'C'); // 'A', 'B', and 'C' are the names of the rods

    return 0;
}
