#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void insertBack(Node*& head, Node*& tail, int value) {
    Node* nuevo = new Node(value);

    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;
        return;
    }

    tail->next = nuevo;
    nuevo->prev = tail;
    tail = nuevo;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void ReverseList(Node*& head) {
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;   // guardamos el siguiente original

        current->next = current->prev; // invertimos next
        current->prev = nextNode;      // invertimos prev

        head = current;                // actualizamos la nueva cabecera
        current = nextNode;            // avanzamos al siguiente original
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertBack(head, tail, 10);
    insertBack(head, tail, 20);
    insertBack(head, tail, 30);
    insertBack(head, tail, 40);

    cout << "Antes: ";
    printList(head);

    ReverseList(head);

    cout << "Despues: ";
    printList(head);

    return 0;
}