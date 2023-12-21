#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
    int s[100];
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

    void push(int str)
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

    int pop()
    {
        int temp;
        if (isempty())
        {
            return 0;
        }
        else
        {
            temp = s[top];
            top--;
            return temp;
        }
    }
};

class Expression : Stack
{
public:
    string infix, postfix;

    void postfixEval()
    {
        cout << "Enter postfix expression: ";
        cin >> postfix;
        char c;

        int l = postfix.size();

        for (int i = 0; i < l; ++i)
        {
            char c = postfix[i];
            if (isdigit(c))
            {
                push(c - '0');
            }
            else
            {
                double o2 = pop();
                double o1 = pop();

                switch (postfix[i])
                {
                case '+':
                    push(o1 + o2);
                    break;
                case '-':
                    push(o1 - o2);
                    break;
                case '*':
                    push(o1 * o2);
                    break;
                case '/':
                    push(o1 / o2);
                    break;
                }
            }
        }

        double result = pop();
        cout << "Evaluation: " << result << endl;
    }
};

int main()
{
    Expression e;
    e.postfixEval();
    return 0;
}
