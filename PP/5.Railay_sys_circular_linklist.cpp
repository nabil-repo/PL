#include <iostream>
using namespace std;

class Node
{
public:
    int seatNumber;
    bool isReserved;
    Node *next;

    Node(int seat) : seatNumber(seat), isReserved(false), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to add a new seat to the circular linked list
    void addSeat(int seat)
    {
        Node *newNode = new Node(seat);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to display the available seats
    void displaySeats()
    {
        if (head == nullptr)
        {
            cout << "No seats available." << endl;
            return;
        }

        Node *temp = head;
        cout << "Available Seats: ";
        do
        {
            if (!temp->isReserved)
            {
                cout << temp->seatNumber << " ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Function to reserve a seat
    void reserveSeat(int seat)
    {
        Node *temp = head;
        do
        {
            if (temp->seatNumber == seat && !temp->isReserved)
            {
                temp->isReserved = true;
                cout << "Seat " << seat << " reserved successfully." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Seat " << seat << " not available or already reserved." << endl;
    }
};

int main()
{
    CircularLinkedList trainSeats;

    // Adding seats to the circular linked list
    for (int i = 1; i <= 10; ++i)
    {
        trainSeats.addSeat(i);
    }

    // Displaying available seats
    trainSeats.displaySeats();

    // Reserving seats
    trainSeats.reserveSeat(5);
    trainSeats.reserveSeat(8);

    // Displaying available seats after reservations
    trainSeats.displaySeats();

    return 0;
}
