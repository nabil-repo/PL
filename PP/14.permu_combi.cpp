#include <iostream>
#include <string>

using namespace std;

void permute(string str, int left, int right)
{
    if (left == right)
    {
        cout << "Permutation: " << str << endl;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(str[left], str[i]);
            permute(str, left + 1, right);
            swap(str[left], str[i]); // backtrack
        }
    }
}

void findPermutations(string input_str)
{
    int length = input_str.length();
    permute(input_str, 0, length - 1);
}

void combine(string str, string out, int index)
{
    for (int i = index; i < str.length(); ++i)
    {
        out.push_back(str[i]);
        cout << "Combination: " << out << endl;
        combine(str, out, i + 1);
        out.pop_back();
    }
}

void findCombinations(string input_str)
{
    combine(input_str, "", 0);
}

int main()
{
    string input_string = "abc";

    cout << "Permutations:" << endl;
    findPermutations(input_string);

    cout << "\nCombinations:" << endl;
    findCombinations(input_string);

    return 0;
}
