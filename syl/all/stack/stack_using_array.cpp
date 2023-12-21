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
            cout << "Stack is Empty..." << endl;
            return "";
        } else {
            temp = s[top];
            top--;
            return temp;
        }
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

class expression : Stack {
public:
    string infix, postfix;

    bool isoperator(char x) {
        if (x == '+' || x == 'x' || x == '-' || x == '/' || x == '^') {
            return true;
        }
        return false;
    }

    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        } else if (op == '^') {
            return 3;
        } else {
            return 0;
        }
    }

    void infixToPostFix() {
        cout << "Enter infix expression: ";
        cin >> infix;
        postfix = "";  

        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            if (isalpha(c) || isdigit(c)) {
                postfix += c;  
            } else if (c == '(') {
                push(string(1, c));  
            } else if (c == ')') {
                while (!isempty() && s[top] != "(") {
                    postfix += s[top];
                    pop();  
                }
                pop();  
            } else if (isoperator(c)) {
                while (!isempty() && precedence(s[top][0]) >= precedence(c)) {
                    postfix += s[top];
                    pop();  
                }
                push(string(1, c));  
            }
        }

        while (!isempty()) {
            postfix += s[top];
            pop();  
        }
        

        cout << "Postfix expression: " << postfix << endl;
    }
};
int main()
{
    // Stack s;
    // s.push("a");
    // s.push("+");
    // s.push("c");
    // s.push("d");

    //s.display();

    //s.pop();
    expression e;
    e.infixToPostFix();
    //s.display();
    

    // k+l-m*n+(o^p)*w/u/v*tpq

    return 0;
}
