#include <iostream>
using namespace std;

class Node
{
public:
    string itemName;
    int quantity;
    Node *next;
    Node *prev;

    Node(string name, int qty) : itemName(name), quantity(qty), next(NULL), prev(NULL) {}
};

class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque() : front(NULL), rear(NULL) {}

    void insertFront(string itemName, int quantity)
    {
        Node *newNode = new Node(itemName, quantity);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Item \"" << itemName << "\" with quantity " << quantity << " inserted at the front.\n";
    }

    void insertRear(string itemName, int quantity)
    {
        Node *newNode = new Node(itemName, quantity);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Item \"" << itemName << "\" with quantity " << quantity << " inserted at the rear.\n";
    }

    // Delete from Front
    void deleteFront()
    {
        if (front == NULL)
        {
            cout << "Deque is empty. Cannot delete from the front.\n";
        }
        else
        {
            Node *temp = front;
            front = front->next;
            if (front != NULL)
            {
                front->prev = NULL;
            }
            else
            {
                rear = NULL;
            }
            cout << "Item \"" << temp->itemName << "\" with quantity " << temp->quantity << " deleted from the front.\n";
            delete temp;
        }
    }

    // Delete from Rear
    void deleteRear()
    {
        if (front == NULL)
        {
            cout << "Deque is empty. Cannot delete from the rear.\n";
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            if (rear != NULL)
            {
                rear->next = NULL;
            }
            else
            {
                front = NULL;
            }
            cout << "Item \"" << temp->itemName << "\" with quantity " << temp->quantity << " deleted from the rear.\n";
            delete temp;
        }
    }

    void display()
    {
        cout << "Deque contents: ";
        Node *current = front;
        while (current != NULL)
        {
            cout << "(" << current->itemName << ", " << current->quantity << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque d;
    int choice;

    do
    {
        cout << "\n-------------------------" << endl;
        cout << "Shopping Mall Deque Menu" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Input Restricted Deque (Insert Front)" << endl;
        cout << "2. Output Restricted Deque (Insert Rear)" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string itemName;
            int quantity;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << "Enter quantity: ";
            cin >> quantity;
            d.insertFront(itemName, quantity);
            break;
        }
        case 2:
        {
            string itemName;
            int quantity;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << "Enter quantity: ";
            cin >> quantity;
            d.insertRear(itemName, quantity);
            break;
        }
        case 3:
            d.deleteFront();
            break;
        case 4:
            d.deleteRear();
            break;
        case 5:
            d.display();
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}
