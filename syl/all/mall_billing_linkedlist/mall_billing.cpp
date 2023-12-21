#include <iostream>
using namespace std;

class node
{
public:
    string name;
    int quantity;
    double price;
    node *next;

    node(const string &n, int q, double p)
    {
        name = n;
        quantity = q;
        price = p;
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

    void insert(const string &n, int q, double p)
    {
        node *temp;
        temp = new node(n, q, p);
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
        cout << "-------------------\nBill: " << endl;
        double total = 0.0;
        while (p != NULL)
        {
            cout << "Product Name: " << p->name << ", Quantity: " << p->quantity << ", Price: " << p->price << " /- \n";
            total += p->quantity * p->price;
            p = p->next;
        }
        cout << "Total: " << total << " /- \n";
    }

    void del(const string &n)
    {
        node *p = head;
        node *prev = NULL;
        while (p != NULL)
        {
            if (p->name == n)
            {
                if (prev == p)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = p->next;
                }
                delete p;
                cout << "Product removed from cart." << endl;
                display();
                return;
            }
            prev = p;
            p = p->next;
        }
        cout << "Product not found in the cart." << endl;
    }
};

int main()
{
    linkedlist l;
    string name;
    int quantity, ch, ch2;
    double price;

    while (true)
    {
        cout << "\n-------------------\nMall Billing System :" << endl;
        cout << "1. Add Product to Cart" << endl;
        cout << "2. Remove Product from Cart" << endl;
        cout << "3. Display Cart" << endl;
        cout << "4. Exit" << endl;
        cin >> ch;

        if (ch == 1)
        {
            do
            {
                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Price: ";
                cin >> price;
                l.insert(name, quantity, price);
                cout << "Do you want to add more products (1 for yes, 0 for no):";
                cin >> ch2;
            } while (ch2 != 0);
            l.display();
        }
        else if (ch == 2)
        {
            cout << "Enter the Product Name to remove from the cart: ";
            cin.ignore();
            getline(cin, name);
            l.del(name);
        }
        else if (ch == 3)
        {
            l.display();
        }
        else if (ch == 4)
        {
            return 0;
        }
    }
}
