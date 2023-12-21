#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isReflexive(const vector<pair<int, int>> &relation)
{
    for (const auto &pair : relation)
    {
        if (pair.first != pair.second)
        {

            return false;
        }
    }
    return true;
}

bool isSymmetric(const vector<pair<int, int>> &relation)
{
    for (const auto &pair : relation)
    {
        // Check if the reverse pair (b, a) exists in the relation
        if (find(relation.begin(), relation.end(), make_pair(pair.second, pair.first)) == relation.end())
        {
            return false;
        }
    }
    return true;
}

bool isTransitive(const vector<pair<int, int>> &relation)
{
    for (const auto &pair1 : relation)
    {
        for (const auto &pair2 : relation)
        {
            // Check if (a, b) and (b, c) implies (a, c)
            if (pair1.second == pair2.first && find(relation.begin(), relation.end(), make_pair(pair1.first, pair2.second)) == relation.end())
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number of ordered pairs: ";
    cin >> n;

    vector<pair<int, int>> relation;

    cout << "Enter the ordered pairs (separated by spaces):" << endl;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        relation.push_back(make_pair(a, b));
    }

    // Check properties
    if (isReflexive(relation))
    {
        cout << "The relation is reflexive." << endl;
    }
    else
    {
        cout << "The relation is not reflexive." << endl;
    }

    if (isSymmetric(relation))
    {
        cout << "The relation is symmetric." << endl;
    }
    else
    {
        cout << "The relation is not symmetric." << endl;
    }

    if (isTransitive(relation))
    {
        cout << "The relation is transitive." << endl;
    }
    else
    {
        cout << "The relation is not transitive." << endl;
    }

    return 0;
}
