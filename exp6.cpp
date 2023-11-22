#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;
    node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printnode(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertatead(node* &head, int d) {
    node* temp = new node(d);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void insertattail(node* &tail, int d) {
    node* temp = new node(d);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

bool findelem(node* &head, int elem) {
    node* temp = head;
    while (temp) {
        if (temp->data == elem) return true;
        temp = temp->next;
    }
    return false;
}

void deleteNodeAtPosition(node* &head, int position) {
    if (head == NULL) return;
    
    node* temp = head;
    if (position == 0) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }
    
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) return;
    
    node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    delete toDelete;
}

int main(int argc, char const* argv[]) {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    insertatead(head, 10);
    insertattail(tail, 100);
    insertattail(tail, 100);
    insertattail(tail, 20);
    insertattail(tail, 1230);
    insertatead(head, 10223);
    insertatead(head, 1032323);

    cout << "Original List:" << endl;
    printnode(head);

    if (findelem(head, 100)) cout << "Element present" << endl;
    else {
        cout << "Element not found" << endl;
    }

    // Delete node at position 2 (0-based index)
    deleteNodeAtPosition(head, 2);

    cout << "List after deleting node at position 2:" << endl;
    printnode(head);

    return 0;
}
