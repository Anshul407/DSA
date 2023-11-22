#include<iostream>
#include<cmath>
using namespace std;

class Node {
public:
    int coef;
    int px;
    int py;
    int pz;
    Node* next;
};

void insert(Node*& head, int coef, int px, int py, int pz) {
    Node* temp = new Node;
    temp->coef = coef;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
        temp->next = head;
    }
    else {
        Node* x = head;
        while (x->next != head) {
            x = x->next;
        }
        x->next = temp;
        temp->next = head;
    }
}

int evaluate(Node* head, int x, int y, int z) {
    int result = 0;
    Node* temp = head;
    do {
        result += temp->coef * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz);
        temp = temp->next;
    } while (temp != head);

    return result;
}

Node* addpoly(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    do {
        int coeff = temp1->coef + temp2->coef;
        int px = temp1->px;
        int py = temp1->py;
        int pz = temp1->pz;

        insert(result, coeff, px, py, pz);

        temp1 = temp1->next;
        temp2 = temp2->next;
    } while (temp1 != poly1 && temp2 != poly2);

    return result;
}

void display(Node* head) {
    Node* temp = head;
    do {
        cout << temp->coef << "x^" << temp->px << "y^" << temp->py << "z^" << temp->pz << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    Node* poly3 = nullptr;

    insert(poly1, 6, 2, 2, 1);
    insert(poly1, -4, 0, 1, 5);
    insert(poly1, 3, 3, 1, 1);
    insert(poly1, 2, 1, 5, 1);
    insert(poly1, -2, 1, 1, 3);

    insert(poly2, -2, 2, 2, 1);
    insert(poly2, 4, 0, 1, 5);
    insert(poly2, 1, 3, 1, 1);

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    poly3 = addpoly(poly1, poly2);

    cout << "Resultant Polynomial: ";
    display(poly3);

    return 0;
}
