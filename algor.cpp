#include <iostream>

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // La condición para desplazar arr[j] a la derecha (j+1) es:
        // 1. Si arr[j] es impar y key es par (los pares van primero).
        // 2. Si ambos son pares, y arr[j] > key (orden ascendente de pares).
        // 3. Si ambos son impares, y arr[j] > key (orden ascendente de impares).
        while (j >= 0 && (
            (arr[j] % 2 != 0 && key % 2 == 0) || 
            (arr[j] % 2 == 0 && key % 2 == 0 && arr[j] > key) || 
            (arr[j] % 2 != 0 && key % 2 != 0 && arr[j] > key)
        )) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    // Ejemplo proporcionado en el ejercicio
    int arr[] = {8, 5, 2, 7, 4, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);

    // Imprimir el arreglo modificado
    std::cout << "Salida: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << (i < n - 1 ? " " : "");
    }
    std::cout << std::endl;

    return 0;
}