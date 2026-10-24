#include <iostream>
#include <stack>

void RemoveConsecutiveDuplicates(std::stack<int>& values) {
    if (values.empty()) {
        return;
    }

    std::stack<int> auxStack;

    auxStack.push(values.top());
    values.pop();

    while (!values.empty()) {
        if (values.top() != auxStack.top()) {
            auxStack.push(values.top());
        }
        values.pop();
    }

    while (!auxStack.empty()) {
        values.push(auxStack.top());
        auxStack.pop();
    }
}

int main() {
    std::stack<int> miPila;
    
    // Insertamos los valores del primer ejemplo: 5 5 5 8 8 3 7 7 2 2
    // Los insertamos al revés para que el tope (5) quede arriba.
    int valores[] = {2, 2, 7, 7, 3, 8, 8, 5, 5, 5};
    for (int i = 0; i < 10; i++) {
        miPila.push(valores[i]);
    }

    RemoveConsecutiveDuplicates(miPila);

    // Imprimir el resultado (debe mostrar: 5 8 3 7 2)
    std::cout << "Pila resultante: ";
    while (!miPila.empty()) {
        std::cout << miPila.top() << " ";
        miPila.pop();
    }
    std::cout << std::endl;

    return 0;
}