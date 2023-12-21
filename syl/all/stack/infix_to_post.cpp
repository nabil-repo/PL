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
};

class expression : Stack
{
public:
    string infix, postfix;

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
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

    void infixToPostfix()
    {
        cout << "Enter infix expression: ";
        getline(cin, infix);

        int l = infix.size();

        for (int i = 0; i < l; i++)
        {
            char ch = infix[i];
            if (isalpha(ch) || isdigit(ch))
            {
                postfix += ch;
            }
            else if (ch == '(')
            {
                push(string(1, ch));
            }
            else if (ch == ')')
            {
                while (!isempty() && s[top] != "(")
                {
                    postfix += pop();
                }
                pop();
            }
            else if (isoperator(ch))
            {
                while (!isempty() && precedence(s[top][0]) >= precedence(ch))
                {
                    postfix += pop();
                }
                push(string(1, ch));
            }
        }

        while (!isempty())
        {
            postfix += pop();
        }

        cout << "Postfix expression: " << postfix << endl;
    }
};

int main()
{
    expression e;
    e.infixToPostfix();
    return 0;
}
