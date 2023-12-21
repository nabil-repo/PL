#include <iostream>
#include <string>
using namespace std;

const int MAX_FRIENDS = 100;

class Friend
{
public:
    string name;
    string mobileNumber;

    Friend() {}

    Friend(const string &n, const string &mob) : name(n), mobileNumber(mob) {}
};

class PhoneBook
{
private:
    Friend friends[MAX_FRIENDS];
    int friendCount;

public:
    PhoneBook()
    {
        friendCount = 0;
    }

    void insertFriend(const string &name, const string &mobileNumber)
    {
        // Search for the friend using Sentinel search
        Friend sentinelFriend(name, "");
        int i = 0;
        while (name > friends[i].name && i < friendCount)
        {
            ++i;
        }

        // If friend is not present, insert it
        if (i == friendCount || name != friends[i].name)
        {
            if (friendCount < MAX_FRIENDS)
            {
                for (int j = friendCount; j > i; --j)
                {
                    friends[j] = friends[j - 1];
                }

                friends[i] = Friend(name, mobileNumber);
                ++friendCount;
                cout << "Friend " << name << " added to the phone book." << endl;
            }
            else
            {
                cout << "Phone book is full. Cannot add more friends." << endl;
            }
        }
        else
        {
            cout << "Friend " << name << " is already in the phone book." << endl;
        }
    }

    void displayPhoneBook() const
    {
        cout << "Phone Book:" << endl;
        for (int i = 0; i < friendCount; ++i)
        {
            cout << "Name: " << friends[i].name << ", Mobile Number: " << friends[i].mobileNumber << endl;
        }
    }

    bool searchAndAddFriend()
    {
        string searchName;
        cout << "Enter the name to search (enter 'exit' to stop): ";
        cin >> searchName;

        while (searchName != "exit")
        {
            // Search for the friend using Sentinel search
            Friend sentinelFriend(searchName, "");
            int i = 0;
            while (searchName > friends[i].name && i < friendCount)
            {
                ++i;
            }

            // If friend is not present, insert it
            if (i == friendCount || searchName != friends[i].name)
            {
                string searchMobileNumber;
                cout << "Friend " << searchName << " not found. Enter the mobile number to add: ";
                cin >> searchMobileNumber;
                insertFriend(searchName, searchMobileNumber);
            }
            else
            {
                cout << "Friend " << searchName << " is already in the phone book." << endl;
            }

            // Search for the next friend
            cout << "Enter the name to search (enter 'exit' to stop): ";
            cin >> searchName;
        }

        return true;
    }
};

int main()
{
    PhoneBook phoneBook;

    // Insert friends into the phone book
    phoneBook.insertFriend("Alice", "123-456-7890");
    phoneBook.insertFriend("Bob", "987-654-3210");
    phoneBook.insertFriend("Charlie", "555-123-4567");

    // Display the phone book
    phoneBook.displayPhoneBook();

    // Search for a friend using Sentinel search, and add if not present
    phoneBook.searchAndAddFriend();

    // Display the updated phone book
    phoneBook.displayPhoneBook();

    return 0;
}
