#include <iostream>
#include <iomanip>

int FindLargestSmaller(const int values[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1; // Por defecto retorna -1 si no hay elementos menores

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (values[mid] < target) {
            // Si el elemento es estrictamente menor, es un candidato válido.
            // Guardamos su índice y buscamos a la derecha para ver si hay uno mayor.
            result = mid;
            left = mid + 1;
        } else {
            // Si el elemento es mayor o igual al target, no nos sirve.
            // Buscamos elementos más pequeños a la izquierda.
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    // El arreglo exacto del ejercicio
    int values[] = {2, 4, 4, 7, 9, 12, 15};
    int n = sizeof(values) / sizeof(values[0]);

    // Los casos de prueba (targets) de la tabla del ejercicio
    int targets[] = {6, 4, 2, 20};
    int num_targets = sizeof(targets) / sizeof(targets[0]);

    std::cout << std::left << std::setw(10) << "target" << "| " << "Resultado" << std::endl;
    std::cout << "-----------------------" << std::endl;

    for (int i = 0; i < num_targets; ++i) {
        int target = targets[i];
        int resultado = FindLargestSmaller(values, n, target);
        std::cout << std::left << std::setw(10) << target << "| " << resultado << std::endl;
    }

    return 0;
}