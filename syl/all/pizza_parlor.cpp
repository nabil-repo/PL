//Pizza parlor using circular linked list
//Fist Come First serve
#include <iostream>
using namespace std;

class node
{
public:
    string item;
    int qty;
    float price;
    node *next;
    int id;

    node(string item, int qty, float price, int id)
    {
        this->item = item;
        this->qty = qty;
        this->price = price;
        this->next = NULL;
        this->id = id;
    }
};

class pizza
{
    node *head;

public:
    pizza()
    {
        head = NULL;
    }

    void create(string item, int qty, float price, int id)
    {
        node *temp = new node(item, qty, price, id);
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            node *ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = head;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Pizza list is empty." << endl;
            return;
        }
        else
        {

            cout << "\n---------------\nPizza Orders:" << endl;
            cout << "ID: \t Item: \t Qty: \t Price: \n";
            node *ptr = head;
            do
            {

                cout << ptr->id << " \t " << ptr->item << " \t " << ptr->qty << " \t " << ptr->price << endl;
                ptr = ptr->next;
            } while (ptr != head);
        }
    }

    void search(int id)
    {
        if (head == NULL)
        {
            cout << "Pizza list is empty." << endl;
            return;
        }
        else
        {
            node *ptr = head;

            do
            {
                if (ptr->id == id)
                {
                    cout << "\n---------------\nPizza Order:" << endl;
                    cout << "ID: \t Item: \t Qty: \t Price: \n";
                    cout << ptr->id << " \t " << ptr->item << " \t " << ptr->qty << " \t " << ptr->price << endl;
                    return;
                }
                ptr = ptr->next;

            } while (ptr != head);
        }
    }

    void del()
    {
        if (head == NULL)
        {
            cout << "Pizza list is empty!!!" << endl;
            return;
        }
        else
        {
            node *ptr = head;
            node *last = head;

            while (last->next != head)
            {
                last = last->next;
            }
            if (ptr->next == head)
            {
                delete ptr;
                head = NULL;
            }
            else
            {

                last->next = ptr->next;

                head = ptr->next;

                delete ptr;
            }

            cout << "Order deleted." << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    pizza p;
    int nextid = 0;

    int ch;

    while (ch != 0)
    {

        cout << "--------------\nPizza parlour\nMENU:";
        cout << "\n1.Order\n2.Disply\n3.Search\n4.Delete\n0.Exit" << endl;
        int ch;
        cin >> ch;
        int ch2 = 0;

        switch (ch)
        {
        case 1:
            do
            {

                string item;
                int qty;
                float price;
                cout << "Enter item, quantity and price" << endl;
                cin >> item >> qty >> price;
                p.create(item, qty, price, nextid++);

                cout << "Do you want to add more items (1 for yes, 0 for no): ";
                cin >> ch2;
            } while (ch2 != 0);
            break;
        case 2:
            p.display();
            break;

        case 3:
            cout << "Enter the order id to search:";
            int val;
            cin >> val;
            p.search(val);
            break;
        case 4:
            p.del();
            break;

        case 0:
            return 0;

        default:
            break;
        }
    }

    return 0;
}
