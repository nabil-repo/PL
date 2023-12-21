#include <iostream>
using namespace std;

// Structure to represent a patient with name and priority
struct Patient
{
    string name;
    int priority;

    Patient() {}

    Patient(string n, int p)
    {
        name = n;
        priority = p;
    }
};

// Simple priority queue implementation
class PriorityQueue
{
private:
    Patient *patients;
    int maxSize;
    int currentSize;

public:
    PriorityQueue(int size)
    {
        maxSize = size;
        currentSize = 0;
        patients = new Patient[maxSize];
    }

    ~PriorityQueue()
    {
        delete[] patients;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == maxSize;
    }

    void enqueue(const char *name, int priority)
    {
        if (isFull())
        {
            cout << "Priority Queue is full. Cannot enqueue more patients." << endl;
            return;
        }

        patients[currentSize++] = Patient(name, priority);
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty. No patients to dequeue." << endl;
            return;
        }

        int highestPriorityIndex = 0;
        for (int i = 1; i < currentSize; ++i)
        {
            if (patients[i].priority < patients[highestPriorityIndex].priority)
            {
                highestPriorityIndex = i;
            }
        }

        cout << "Dequeued patient: " << patients[highestPriorityIndex].name << " (Priority: " << patients[highestPriorityIndex].priority << ")" << endl;

        for (int i = highestPriorityIndex; i < currentSize - 1; ++i)
        {
            patients[i] = patients[i + 1];
        }
        currentSize--;
    }
};

int main()
{
    PriorityQueue appointments(5); // Change the size of the priority queue here

    appointments.enqueue("John", 2);
    appointments.enqueue("Alice", 1);
    appointments.enqueue("Bob", 3);
    appointments.enqueue("Eva", 2);

    cout << "Appointments:" << endl;
    while (!appointments.isEmpty())
    {
        appointments.dequeue();
    }

    return 0;
}
