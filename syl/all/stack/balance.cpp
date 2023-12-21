#include <iostream>
#include <cstring>

using namespace std;

class Stack
{
private:
    char *stackArray;
    int maxSize;
    int top;

public:
    Stack(int size)
    {
        maxSize = size;
        top = -1;
        stackArray = new char[maxSize];
    }

    void push(char value)
    {
        if (top < maxSize - 1)
        {
            stackArray[++top] = value;
        }
        else
        {
            cout << "Stack Overflow. " << value << endl;
        }
    }

    char pop()
    {
        if (top >= 0)
        {
            return stackArray[top--];
        }
        else
        {
            cout << "Stack Underflow." << endl;
            return '\0';
        }
    }

    bool isEmpty() const
    {
        return top == -1;
    }
};

bool checkBalance(const char *str)
{
    int length = strlen(str);
    Stack stack(length);

    for (int i = 0; i < length; ++i)
    {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{')
        {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (stack.isEmpty())
            {
                return false;
            }

            char poppedChar = stack.pop();

            if ((c == ')' && poppedChar != '(') ||
                (c == ']' && poppedChar != '[') ||
                (c == '}' && poppedChar != '{'))
            {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Is '" << str << "' balanced: " << boolalpha << checkBalance(str.c_str()) << endl;

    return 0;
}
