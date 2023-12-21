#include <iostream>
using namespace std;

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;

    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

void insertTerm(Node *&head, int coef, int exp)
{
    Node *newNode = new Node(coef, exp);
    if (head == nullptr || exp > head->exponent)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr && exp < current->next->exponent)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayPolynomial(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->coefficient << "x^" << current->exponent;
        if (current->next != nullptr)
        {
            std::cout << " + ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = nullptr;
    Node *current1 = poly1;
    Node *current2 = poly2;

    while (current1 != nullptr && current2 != nullptr)
    {
        if (current1->exponent == current2->exponent)
        {
            insertTerm(result, current1->coefficient + current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->exponent > current2->exponent)
        {
            insertTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        }
        else
        {
            insertTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
    }

    while (current1 != nullptr)
    {
        insertTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != nullptr)
    {
        insertTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}


int main()
{
    Node *poly1 = nullptr;
    Node *poly2 = nullptr;

    int coef, exp;
    cout << "Enter 1st Polynomial(coef,exp): " << endl;
    while (true)
    {
        std::cin >> coef >> exp;
        if (coef == -1 && exp == -1)
        {
            break;
        }
        insertTerm(poly1, coef, exp);
    }

    cout << "Enter 2nd Polynomial(coef,exp): " << endl;
    while (true)
    {
        std::cin >> coef >> exp;
        if (coef == -1 && exp == -1)
        {
            break;
        }
        insertTerm(poly2, coef, exp);
    }

    std::cout << "First polynomial: ";
    displayPolynomial(poly1);
    std::cout << "Second polynomial: ";
    displayPolynomial(poly2);

    Node *result = addPolynomials(poly1, poly2);
    std::cout << "Sum of polynomials: ";
    displayPolynomial(result);

    return 0;
}
