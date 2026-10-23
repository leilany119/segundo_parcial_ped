#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void SwapAdjacentPairs(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return; // lista vacía o con un solo nodo
    }

    Node* current = head;
    Node* prev = nullptr;

    // la nueva cabeza será el segundo nodo del primer par
    head = head->next;

    while (current != nullptr && current->next != nullptr) {
        Node* first = current;
        Node* second = current->next;
        Node* nextPair = second->next;

        // reorganizamos los enlaces
        first->next = nextPair;
        second->next = first;

        if (nextPair != nullptr) {
            nextPair->prev = first;
        }

        first->prev = second;
        second->prev = prev;

        if (prev != nullptr) {
            prev->next = second;
        }

        prev = first;
        current = nextPair;
    }
}

// función para imprimir la lista
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // crear lista: 10 <-> 20 <-> 30 <-> 40
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    head = n1;

    cout << "Antes: ";
    printList(head);

    SwapAdjacentPairs(head);

    cout << "Despues: ";
    printList(head);

    return 0;
}