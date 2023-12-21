#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    float sgpa;
    string department;
};

class StudData
{
private:
    static const int MAX_STUD = 20;
    Student stud[MAX_STUD];

public:
    int numStud;
    void readData()
    {
        cout << "Enter the number of students: ";
        cin >> numStud;

        for (int i = 0; i < numStud; ++i)
        {
            cout << "\nEnter details for student " << i + 1 << ":\n";
            cout << "Roll No: ";
            cin >> stud[i].rollNo;

            cout << "Name: ";
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, stud[i].name);

            cout << "SGPA: ";
            cin >> stud[i].sgpa;

            cout << "Department: ";
            cin >> stud[i].department;
        }
    }

    void displayData()
    {
        cout << "\nStudent sdb:\n";
        cout << "Roll No\tName\tSGPA\tDepartment\n";
        for (int i = 0; i < numStud; ++i)
        {
            cout << stud[i].rollNo << "\t" << stud[i].name << "\t" << stud[i].sgpa << "\t" << stud[i].department << "\n";
        }
    }

    void bubbleSortByRollNo()
    {
        for (int i = 0; i < numStud - 1; ++i)
        {
            for (int j = 0; j < numStud - i - 1; ++j)
            {
                if (stud[j].rollNo > stud[j + 1].rollNo)
                {
                    swap(stud[j], stud[j + 1]);
                }
            }
        }
    }

    void insertionSortByName()
    {
        int i, j;
        Student key;
        for (i = 1; i < numStud; i++)
        {
            key = stud[i];
            j = i - 1;

            while (j >= 0 && stud[j].name > key.name)
            {
                stud[j + 1] = stud[j];
                j = j - 1;
            }
            stud[j + 1] = key;
        }
    }

    void quickSortTopTen(int low, int high)
    {
        if (low < high)
        {
            int pi = partitionForTopTen(low, high);

            if (pi > 10)
            {
                quickSortTopTen(low, pi - 1);
            }
            else if (pi < 10)
            {
                quickSortTopTen(pi + 1, high);
            }
        }
    }

    int partitionForTopTen(int low, int high)
    {
        int pivot = stud[high].sgpa;
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (stud[j].sgpa >= pivot)
            {
                i++;
                swap(stud[i], stud[j]);
            }
        }

        swap(stud[i + 1], stud[high]);
        return i + 1;
    }

    void linearSearchBySGPA(float key)
    {
        cout << "\nStudents with SGPA " << key << ":\n";
        bool found = false;
        for (int i = 0; i < numStud; ++i)
        {
            if (stud[i].sgpa == key)
            {
                cout << stud[i].rollNo << "\t" << stud[i].name << "\t" << stud[i].department << "\n";
                found = true;
            }
        }

        if (!found)
        {
            cout << "No student found with SGPA " << key << "\n";
        }
    }

    void binarySearchByName(string key)
    {
        int low = 0, high = numStud - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (stud[mid].name == key)
            {
                int start = mid, end = mid;

                // Check for adjacent names
                while (start >= 0 && stud[start].name == key)
                {
                    start--;
                }

                while (end < numStud && stud[end].name == key)
                {
                    cout << stud[end].rollNo << "\t" << stud[end].sgpa << "\t" << stud[end].department << "\n";
                    end++;
                }
                return;
            }
            else if (stud[mid].name < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << "Student with name " << key << " not found\n";
    }

    void fibonacciSearchByDepartment(string key)
    {
        int fib2 = 0;
        int fib1 = 1;
        int fib = fib1 + fib2;

        while (fib < numStud)
        {
            fib2 = fib1;
            fib1 = fib;
            fib = fib1 + fib2;
        }

        int offset = -1;

        while (fib > 1)
        {
            int i = min(offset + fib2, numStud - 1);

            if (stud[i].department == key)
            {
                cout << "Student found in class\n";
                return;
            }
            else if (stud[i].department < key)
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }
            else
            {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }
        }

        cout << "Student not found in class\n";
    }
};

int main()
{
    StudData sdb;
    string nameToS;
    string deptToS;
    float sgpaToS;

    int choice;

    do
    {
        cout << "\n---------\nMenu:\n1. Read Data\n2. Display Data\n3. Bubble Sort (By Roll No)\n4. Insertion Sort (By Name)\n5. Quick Sort (Top Ten)\n6. Linear Search (By SGPA)\n7. Binary Search (By Name)\n8. Fibonacci Search (By Department)\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sdb.readData();
            break;
        case 2:
            sdb.displayData();
            break;
        case 3:
            sdb.bubbleSortByRollNo();
            break;
        case 4:
            sdb.insertionSortByName();
            break;
        case 5:
            sdb.quickSortTopTen(0, sdb.numStud - 1);
            break;
        case 6:
            cout << "Enter SGPA to search: ";
            cin >> sgpaToS;
            sdb.linearSearchBySGPA(sgpaToS);
            break;
        case 7:

            cout << "Enter Name to search: ";
            cin.ignore();
            getline(cin, nameToS);
            sdb.binarySearchByName(nameToS);
            break;
        case 8:
            cout << "Enter Department to search: ";
            cin.ignore();
            getline(cin, deptToS);
            sdb.fibonacciSearchByDepartment(deptToS);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
