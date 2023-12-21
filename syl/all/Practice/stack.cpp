#include <iostream>

using namespace std;

class stack
{
private:
    int arr[100];
    int top = -1;

public:
    void push(int i)
    {
        top++;
        arr[top] = i;
    }

    int pop()
    {
        if (isempty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            int r = arr[top];
            top--;
            return r;
        }
    }

    bool isempty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
