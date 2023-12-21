#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

class dlLinkedList {
public:
    node* head;

    dlLinkedList(){
        head=NULL;
    }

    void insert(int data) {
        node* newNode = new node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void printList() {
        node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
       // cout << "NULL" << endl;
    }
};

node* merge(node* list1, node* list2) {
    node* mergedList = NULL;
    node* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = list1;
                tail = list1;
            } else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = list2;
                tail = list2;
            } else {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return mergedList;
}

void Sort(node* head) {
    if (head == NULL)
        return;

    bool swapped;
    node* ptr;
    node* last = NULL;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

int main() {
    dlLinkedList list1;
    dlLinkedList list2;

    int n1, n2;
    cout << "Enter the number of elements in list 1: ";
    cin >> n1;
    cout << "Enter the elements for list 1: ";
    for (int i = 0; i < n1; ++i) {
        int data;
        cin >> data;
        list1.insert(data);
    }

    cout << "Enter the number of elements in list 2: ";
    cin >> n2;
    cout << "Enter the elements for list 2: ";
    for (int i = 0; i < n2; ++i) {
        int data;
        cin >> data;
        list2.insert(data);
    }

    Sort(list1.head);
    Sort(list2.head);

    node* mergedList = merge(list1.head, list2.head);

    cout << "Merged and sorted list: ";
    while (mergedList != NULL) {
        cout << mergedList->data << " -> ";
        mergedList = mergedList->next;
    }
    //cout << "NULL" << endl;

    return 0;
}
