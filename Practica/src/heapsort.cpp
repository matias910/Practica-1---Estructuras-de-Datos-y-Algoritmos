//
// Created by matias on 3/21/26.
//

#include "heapsort.h"
#include <algorithm>

void heapify(std::vector<std::string>& arr, int n, int i) {
    int largest = i; // parent
    int left    = 2 * i + 1; // hijo izquierda
    int right   = 2 * i + 2; // hijo derecha

    if (left  < n && arr[left]  > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    // Verifica que el mayor no sea el padre, si no, intercambia y heapifica el subárbol afectado



    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    // si el hijo es mayor al padre lo swapea
}

void heapSort(std::vector<std::string>& arr) {
    int n = (int)arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    // Pone el nodo padre


    // Extrae elementos uno por uno y al mayor le asigna index 0
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
