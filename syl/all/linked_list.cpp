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

class linkedlist
{
public:
    node *head;
    linkedlist()
    {
        head = NULL;
    }
    void insert(int val)
    {
        node *temp;
        temp = new node(val);
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *p;
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }

    void display()
    {
        node *p;
        p = head;
        cout << "Linked list is: " << endl;
        while (p != NULL)
        {
            cout << " Data: " << p->data << " -> ";
            p = p->next;
        }
        cin;
    }
    void del(int val)
    {
        node *p = head;
        node *prev;
        while (p != NULL)
        {
            if (p->data == val)
            {
                if (prev == p)
                {
                    head = head->next;
                }
                prev->next = p->next;

                delete p;
                cout << "\nElement deleted!!! ";
                display();
                return;
            }
            else
            {
                cout << "\nElement is not present!!! ";
            }
            prev = p;
            p = p->next;
        }
    }

    void insertAtPos(int key, int val)
    {
        node *p = head;
        node *temp = new node(val);

        while (p != NULL)
        {
            if (p->data == key)
            {
                temp->next = p->next;
                p->next = temp;

                cout << "Element Inserted!!!" << endl;
                display();
                return;
            }

            p = p->next;
        }

        cout << "\nKey not present!!! ";
    }
};

int main()
{
    linkedlist l;
    int val, ch, ch2;

    while (true)
    {
        cout << "\n-------------------\nMenu:";
        cout << "\n1.Insert\n2.InsertAtPos\n3.Delete\n4.Display\n5.Exit\n";
        cin >> ch;
        if (ch == 1)
        {
            do
            {
                cout << "Enter the element to the linkedlist: ";
                cin >> val;
                l.insert(val);
                cout << "Do you want to enter more element(y=1/n=0):";
                cin >> ch2;
            } while (ch2 == 1);

            l.display();
        }
        else if (ch == 2)
        {
            int key;
            cout << "\nEnter the key and value: ";
            cin >> val >> key;
            l.insertAtPos(val, key);
        }

        else if (ch == 3)
        {
            int val;
            cout << "\nEnter the element to delete:";
            cin >> val;
            l.del(val);
        }
        else if (ch == 4)
        {
            l.display();
        }

        else if (ch == 5)
        {
            return 0;
        }
    }
}
