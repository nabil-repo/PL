#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
    string s[100];
    int max = 100;
    int top;

    Stack()
    {
        top = -1;
    }

    bool isfull()
    {
        return (top == max - 1);
    }

    bool isempty()
    {
        return (top == -1);
    }

    void push(string str)
    {
        if (isfull())
        {
            cout << "Stack is full..." << endl;
        }
        else
        {
            top++;
            s[top] = str;
        }
    }

    string pop()
    {
        string temp;
        if (isempty())
        {

            return "";
        }
        else
        {
            temp = s[top];
            top--;
            return temp;
        }
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

class expression : Stack
{
public:
    string infix, prefix;

    bool isoperator(char x)
    {
        if (x == '+' || x == '*' || x == '-' || x == '/' || x == '^')
        {
            return true;
        }
        return false;
    }

    int precedence(char op)
    {
        if (op == '+' || op == '-')
        {
            return 1;
        }
        else if (op == '*' || op == '/')
        {
            return 2;
        }
        else if (op == '^')
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }

    void infixToPrefix()
    {
        cout << "Enter infix expression: ";
        cin >> infix;
        prefix = "";
        string rinfix = "";
        string rprefix = "";

        int l = infix.size();

        for (int i = l - 1; i >= 0; i--)
        {
            rinfix += infix[i];
        }

        for (int i = 0; i < infix.length(); i++)
    {
        char c = rinfix[i];

        if (isalpha(c) || isdigit(c))
        {
            prefix += c;
        }
        else if (c == '(')
        {
            push(string(1, c));
        }
        else if (c == ')')
        {
            while (!isempty() && s[top] != "(")
            {
                prefix += s[top];
                pop();
            }
            if (!isempty() && s[top] == "(")
            {
                pop(); 
            }
        }
        else if (isoperator(c))
        {
            while (!isempty() && precedence(s[top][0]) >= precedence(c))
            {
                prefix += s[top];
                pop();
            }
            push(string(1, c));
        }
    }

    while (!isempty())
    {
        prefix += s[top];
        pop();
    }


        for (int i = l - 1; i >= 0; i--)
        {
            rprefix += prefix[i];
        }

        cout << "Prefix expression: " << rprefix << endl;
    }
};
int main()
{

    expression e;
    e.infixToPrefix();

    // k+l-m*n+(o^p)*w/u/v*tpq

    return 0;
}
