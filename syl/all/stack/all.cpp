#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
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

    bool isFull()
    {
        return (top == max - 1);
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    void push(string str)
    {
        if (isFull())
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
        if (isEmpty())
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

    int popi()
    {
        int temp;
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            temp = atoi(s[top].c_str());
            top--;
            return temp;
        }
    }
};

class Expression : public Stack
{
public:
    string infix, prefix, postfix;

    bool isOperator(char x)
    {
        return (x == '+' || x == '*' || x == '-' || x == '/' || x == '^');
    }

    int precedence(char x)
    {
        if (x == '^')
            return 3;
        if (x == '*' || x == '/')
            return 2;
        if (x == '+' || x == '-')
            return 1;
        return -1;
    }

    void getExpression()
    {
        cout << "Enter expression: ";
        cin >> infix;
    }

    void prefixToInfix()
    {
        stack<string> s;

        int l = prefix.size();

        for (int i = l - 1; i >= 0; i--)
        {
            if (isOperator(prefix[i]))
            {
                string op1 = pop();
                string op2 = pop();

                string temp = "(" + op1 + prefix[i] + op2 + ")";
                push(temp);
            }
            else
            {
                push(string(1, prefix[i]));
            }
        }

        infix = pop();
        cout << "Infix expression: " << infix << endl;
    }

    void infixToPostfix()
    {
        Stack s;

        int l = infix.size();

        for (int i = 0; i < l; i++)
        {
            if (isalnum(infix[i]))
            {
                postfix += infix[i];
            }
            else if (infix[i] == '(')
            {
                s.push("" + infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!s.isEmpty() && s.pop() != "(")
                {
                    postfix += s.pop();
                }
                s.pop(); // Pop '('
            }
            else
            {
                while (!s.isEmpty() && precedence(infix[i]) <= precedence(s.popi()))
                {
                    postfix += s.pop();
                }
                s.push("" + infix[i]);
            }
        }

        while (!s.isEmpty())
        {
            postfix += s.pop();
        }
    }

    int evaluatePostfix()
    {
        Stack s;

        int l = postfix.size();

        for (int i = 0; i < l; i++)
        {
            if (isdigit(postfix[i]))
            {
                s.push(postfix[i] + ""); // Convert char to int
            }
            else if (isOperator(postfix[i]))
            {
                int operand2 = s.popi();
                int operand1 = s.popi();

                switch (postfix[i])
                {
                case '+':
                    s.push("" + operand1 + operand2);
                    break;
                case '-':
                    s.push("" + operand1 - operand2);
                    break;
                case '*':
                    s.push("" + operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                    {
                        s.push("" + operand1 / operand2);
                    }
                    else
                    {
                        cout << "Error: Division by zero" << endl;
                        return 0; // Error handling
                    }
                    break;
                case '^':
                    int p = pow(operand1, operand2);
                    s.push("" + p);
                    break;
                }
            }
        }

        return s.popi();
    }
};

int main()
{
    Expression e;
    int choice;

    do
    {
        cout << "Menu:\n1. Enter Expression\n2. Prefix to Infix\n3. Infix to Postfix\n4. Evaluate Postfix\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            e.getExpression();
            break;
        case 2:
            e.prefixToInfix();
            break;
        case 3:
            e.infixToPostfix();
            cout << "Postfix expression: " << e.postfix << endl;
            break;
        case 4:
            cout << "Result of postfix expression: " << e.evaluatePostfix() << endl;
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
