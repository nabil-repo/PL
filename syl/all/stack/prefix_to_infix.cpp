#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    string s[100];
    int max = 100;
    int top;

    Stack() {
        top = -1;
    }

    bool isfull() {
        return (top == max - 1);
    }

    bool isempty() {
        return (top == -1);
    }

    void push(string str) {
        if (isfull()) {
            cout << "Stack is full..." << endl;
        } else {
            top++;
            s[top] = str;
        }
    }

    string pop() {
        string temp;
        if (isempty()) {
            return "";
        } else {
            temp = s[top];
            top--;
            return temp;
        }
    }
};

class expression : Stack {
public:
    string infix, prefix;

    bool isoperator(char x) {
        if (x == '+' || x == '*' || x == '-' || x == '/' || x == '^') {
            return true;
        }
        return false;
    }

    void prefixToInfix() {
        cout << "Enter prefix expression: ";
        cin >> prefix;

        int l = prefix.size();

        for (int i = l - 1; i >= 0; i--) {
            if (isoperator(prefix[i])) {
                string op1 = pop();
                string op2 = pop();

                string temp = "(" + op1 + prefix[i] + op2 + ")";
                push(temp);
            } else {
                push(string(1, prefix[i]));
            }
        }

        infix = pop();

        cout << "Infix expression: " << infix << endl;
    }
};

int main() {
    expression e;
    e.prefixToInfix();
    return 0;
}
