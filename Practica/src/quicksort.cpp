//
// Created by matias on 3/21/26.
//

#include "quicksort.h"
#include <algorithm>

int partition(std::vector<std::string>& arr, int low, int high) {
    std::string pivot = arr[high]; // asigna el ultimo elemento como pivote
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]); // si un elemento es menor al pivote lo mueve a la izquierda
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1; // devuelve el pivote a su posicion correcta
}

void quickSort(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); // compara con los elementos de la izquierda para ubicarlo
        quickSort(arr, pi + 1, high); // compara con los elementos de la derecha para ubicarlo
    }
}