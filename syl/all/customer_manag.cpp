/*Assignment no 1 :- Cutomer management system
Name:- Nabil Ansari
MSID:- 219
PRN:- 202302040004
Date:- 23 sept 2023*/

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    string name, email, phone;

public:
    void add_cust()
    {
        cout << "Enter customer Name: ";
        cin >> name;

        cout << "Enter customer Email: ";
        cin >> email;

        cout << "Enter customer Phone no.: ";
        cin >> phone;
    }

    void display_cust()
    {
        cout << "Name: " << name << "\nEmail: " << email << "\nPhone no.: " << phone << endl;
    }

    void update_cust()
    {
        cout << "Update customer Name: ";
        cin >> name;

        cout << "Update customer Email: ";
        cin >> email;

        cout << "Update customer Phone no.: ";
        cin >> phone;
    }
};

void remove_cust(Customer s[], int &size, int id)
{
    if (id < 0 || id >= size)
    {
        cout << "Invalid customer id." << endl;
        return;
    }

    for (int i = id; i < size - 1; i++)
    {
        s[i] = s[i + 1];
    }

    size--;
}

int main()
{
    int MAX_CUST = 1000;
    Customer cust[MAX_CUST];
    int size = 0;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add customer\n";
        cout << "2. Update customer\n";
        cout << "3. Remove customer\n";
        cout << "4. Display customer data\n";
        cout << "5. Display all customer data\n";
        cout << "6. Exit\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (size < MAX_CUST)
            {
                int id = size;
                cust[id].add_cust();
                cout << "------------------------------\nCustomer Data Saved As: \nCust_id: " + to_string(id) << endl;
                cust[id].display_cust();
                size++;
            }
            else
            {
                MAX_CUST++;
            }
            break;

        case 2:
            cout << "Enter customer id: ";
            int updateId;
            cin >> updateId;
            if (updateId >= 0 && updateId < size)
            {
                cust[updateId].update_cust();
            }
            else
            {
                cout << "Invalid customer id." << endl;
            }
            break;

        case 3:
            cout << "Enter customer id to remove: ";
            int removeId;
            cin >> removeId;
            remove_cust(cust, size, removeId);
            break;

        case 4:
            cout << "Enter customer id to Display: ";
            int displayId;
            cin >> displayId;
            if (displayId >= 0 && displayId < size)
            {
                cust[displayId].display_cust();
            }
            else
            {
                cout << "Invalid customer id." << endl;
            }
            break;

        case 5:
            for (int i = 0; i < size; i++)
            {
                cout << "Cust_id: " << i << ":" << endl;
                cust[i].display_cust();
                cout << "-----------------------" << endl;
            }
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
