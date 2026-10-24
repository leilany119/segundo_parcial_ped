#include <queue>
#include <iostream>

#include <iostream>
#include <queue>

void SeparateRequests(std::queue<int>& requests, std::queue<int>& priority) {
    // Si la cola está vacía, no hacemos nada (cumple el requisito de no fallar)
    if (requests.empty()) {
        return;
    }

    // Guardamos el tamaño original para saber cuántos elementos evaluar
    int n = requests.size();

    for (int i = 0; i < n; ++i) {
        int actual = requests.front();
        requests.pop();

        // Si es múltiplo de 3, se va a la cola priority
        if (actual % 3 == 0) {
            priority.push(actual);
        } else {
            // Si no, lo volvemos a encolar al final de requests
            requests.push(actual);
        }
    }
}

int main() {
    std::queue<int> requests;
    std::queue<int> priority;
    
    // Insertamos los valores del ejemplo: 4 6 9 2 12 5 7 3
    int valores[] = {4, 6, 9, 2, 12, 5, 7, 3};
    for (int i = 0; i < 8; i++) {
        requests.push(valores[i]);
    }

    SeparateRequests(requests, priority);

    // Imprimir requests (debe mostrar: 4 2 5 7)
    std::cout << "requests: ";
    while (!requests.empty()) {
        std::cout << requests.front() << " ";
        requests.pop();
    }
    std::cout << "\n";

    // Imprimir priority (debe mostrar: 6 9 12 3)
    std::cout << "priority: ";
    while (!priority.empty()) {
        std::cout << priority.front() << " ";
        priority.pop();
    }
    std::cout << "\n";

    return 0;
}
