#include <iostream>
#include <cstddef>
#include <queue>
#include <stack>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void InsertionSortByParity(int arr[], int n) { como
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 &&
               ((arr[j] % 2 != 0 && key % 2 == 0) ||
                ((arr[j] % 2 == 0) == (key % 2 == 0) && arr[j] > key))) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}




void SwapAdjacentPairs(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;
    Node* previousPairTail = nullptr;

    while (current != nullptr && current->next != nullptr) {
        Node* first = current;
        Node* second = current->next;
        Node* nextPairStart = second->next;

        if (previousPairTail != nullptr) {
            previousPairTail->next = second;
            second->prev = previousPairTail;
        } else {
            head = second;
            second->prev = nullptr;
        }

        second->next = first;
        first->prev = second;
        first->next = nextPairStart;

        if (nextPairStart != nullptr) {
            nextPairStart->prev = first;
        }

        previousPairTail = first;
        current = nextPairStart;
    }
}

void RemoveConsecutiveDuplicates(std::stack<int>& values) {
    std::stack<int> aux;

    while (!values.empty()) {
        int current = values.top();
        values.pop();

        if (!aux.empty() && aux.top() == current) {
            continue;
        }

        aux.push(current);
    }

    while (!aux.empty()) {
        values.push(aux.top());
        aux.pop();
    }
}

void SeparateRequests( 
    std::queue<int>& requests,
    std::queue<int>& priority) {
    const std::size_t requestCount = requests.size();

    for (std::size_t i = 0; i < requestCount; ++i) {
        int request = requests.front();
        requests.pop();

        if (request % 3 == 0) {
            priority.push(request);
        } else {
            requests.push(request);
        }
    }
}

int main () {
    int numeros[] = {8, 5, 2, 7, 4, 1, 6};
    int cantidad = sizeof(numeros) / sizeof(numeros[0]);

    InsertionSortByParity(numeros, cantidad);

    std::cout << "Ordenado por paridad: ";
    for (int i = 0; i < cantidad; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    std::stack<int> pila; //se crea una pila de enteros
    pila.push(5);
    pila.push(5);
    pila.push(5);
    pila.push(8);
    pila.push(8);
    pila.push(3);
    pila.push(7);
    pila.push(7);
    pila.push(2);
    pila.push(2);

    RemoveConsecutiveDuplicates(pila);

    while (!pila.empty()) {
        std::cout << pila.top() << " ";
        pila.pop();
    }
    std::cout << std::endl;

    return 0;
} 