#include <iostream>
using namespace std;

bool areDisjoint(int set1[], int size1, int set2[], int size2)
{
    for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            if (set1[i] == set2[j])
            {
                // Found a common element, sets are not disjoint
                return false;
            }
        }
    }
    // No common elements found, sets are disjoint
    return true;
}

int main()
{
    int setA[] = {1, 2, 3, 4};
    int sizeA = sizeof(setA) / sizeof(setA[0]);

    int setB[] = {5, 6, 7};
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    if (areDisjoint(setA, sizeA, setB, sizeB))
    {
       cout << "The sets are disjoint" <<endl;
    }
    else
    {
       cout << "The sets are not disjoint" <<endl;
    }

    return 0;
}
