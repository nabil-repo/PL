#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class cllinkedlist
{
public:
    node *head;

    cllinkedlist()
    {
        head = NULL;
    }

    void insertAtLast(int val)
    {
        node *temp = new node(val);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }

    void display()
    {
        node *p = head;
        cout << "Linked list is: ";
        while (p != NULL)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
    }
};

int main()
{
    cllinkedlist l;
    int val, ch;
    do
    {
        cout << "Enter the element to the linked list: ";
        cin >> val;
        l.insertAtLast(val);
        cout << "Do you want to enter more elements (1/0): ";
        cin >> ch;
    } while (ch == 1);

    l.display();

    return 0;
}
