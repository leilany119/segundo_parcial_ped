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