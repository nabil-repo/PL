#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;

    Node(char value) : data(value), next(NULL), prev(NULL) {}
};

class Deque
{
public:
    Node *front;
    Node *rear;
    Deque() : front(NULL), rear(NULL) {}

    ~Deque()
    {
        while (!isEmpty())
        {
            popFront();
        }
    }

    bool isEmpty() const
    {
        return front == NULL;
    }

    void pushFront(char value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void pushBack(char value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void popFront()
    {
        if (isEmpty())
        {
            cerr << "Deque is empty. Cannot pop from front." << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front != NULL)
        {
            front->prev = NULL;
        }
        else
        {
            rear = NULL; // The deque is now empty
        }

        delete temp;
    }

    void popBack()
    {
        if (isEmpty())
        {
            cerr << "Deque is empty. Cannot pop from back." << endl;
            return;
        }

        Node *temp = rear;
        rear = rear->prev;

        if (rear != NULL)
        {
            rear->next = NULL;
        }
        else
        {
            front = NULL; // The deque is now empty
        }

        delete temp;
    }

    void display() const
    {
        Node *current = front;
        while (current != NULL)
        {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

bool isPalindrome(const string &str)
{
    Deque charDeque;

    for (char c : str)
    {
        charDeque.pushBack(c);
    }

    while (!charDeque.isEmpty())
    {
        if (charDeque.front->data != charDeque.rear->data)
        {
            return false;
        }
        charDeque.popFront();
        if (!charDeque.isEmpty())
        {
            charDeque.popBack();
        }
    }

    return true;
}

int main()
{
    string input;

    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
