#include <iostream>

using namespace std;

// fun to calculate factorial
long factorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

// fun to calculate permutations (P(n,r))
long permutations(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

// fun to calculate combinations (C(n,r))
long combinations(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r;

    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    if (n < 0 || r < 0 || r > n)
    {
        cout << "Invalid input." << endl;
        return 1;
    }

    long pR = permutations(n, r);
    long cR = combinations(n, r);

    cout << "Permutations (P(n,r)): " << pR << endl;
    cout << "Combinations (C(n,r)): " << cR << endl;
    cin;
    return 0;
}
