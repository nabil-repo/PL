#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int newData) : data(newData), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node*& head, int newData) {
    Node* newNode = new Node(newData);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;
}

Node* mergeAlternate(Node* list1, Node* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    Node* current1 = list1;
    Node* current2 = list2;

    while (current1 != nullptr && current2 != nullptr) {
        Node* next1 = current1->next;
        Node* next2 = current2->next;

        current1->next = current2;
        current2->prev = current1;

        if (next1 != nullptr) {
            current2->next = next1;
            next1->prev = current2;
        } else {
            current2->next = nullptr;
        }

        current1 = next1;
        current2 = next2;
    }

    return list1;
}

Node* sortDoublyList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* current, *index;
    int temp;

    for (current = head; current->next != nullptr; current = current->next) {
        for (index = current->next; index != nullptr; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insertEnd(list1, 2);
    insertEnd(list1, 5);
    insertEnd(list1, 8);
    insertEnd(list1, 14);

    insertEnd(list2, 3);
    insertEnd(list2, 7);
    insertEnd(list2, 10);
    insertEnd(list2, 12);

    cout << "List 1: ";
    displayList(list1);
    cout << "List 2: ";
    displayList(list2);

    list1 = mergeAlternate(list1, list2);
    cout << "Merged List: ";
    displayList(list1);

    list1 = sortDoublyList(list1);
    cout << "Sorted Merged List: ";
    displayList(list1);

    return 0;
}
