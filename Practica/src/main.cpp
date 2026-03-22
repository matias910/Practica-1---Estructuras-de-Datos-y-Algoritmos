#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "../include/dataset.h"
#include "../include/quicksort.h"
#include "../include/heapsort.h"
#include "../include/AVLtree.h"

int main() {
    // Cargar dataset
    const std::string DATASET = "../data/dataset.txt";
    std::vector<std::string> words = loadDataset(DATASET);  // Guarda las palabras en words

    // QuickSort
    std::vector<std::string> qsWords = words;
    auto t1 = std::chrono::high_resolution_clock::now(); // empieza a contar el reloj
    quickSort(qsWords, 0, (int)qsWords.size() - 1); // ordena
    auto t2 = std::chrono::high_resolution_clock::now(); // para el tiempo
    double qsTime = std::chrono::duration<double, std::milli>(t2 - t1).count(); // calcula el tiempo

    // HeapSort
    std::vector<std::string> hsWords = words;
    auto t3 = std::chrono::high_resolution_clock::now();
    heapSort(hsWords);
    auto t4 = std::chrono::high_resolution_clock::now();
    double hsTime = std::chrono::duration<double, std::milli>(t4 - t3).count();

    // AVL Tree
    AVLTree tree;
    auto t5 = std::chrono::high_resolution_clock::now();
    for (const auto& w : words)
        tree.insert(w);
    std::vector<std::string> avlWords;
    tree.inorder(avlWords);
    auto t6 = std::chrono::high_resolution_clock::now();
    double avlTime = std::chrono::duration<double, std::milli>(t6 - t5).count();

    // ── Estimación de memoria ─────────────────────────────────────────────
    size_t qsMem  = qsWords.size()  * sizeof(std::string);
    size_t hsMem  = hsWords.size()  * sizeof(std::string);
    size_t avlMem = tree.memoryUsage();

    // ── Resultados ────────────────────────────────────────────────────────
    std::cout << "\n===== RESULTADOS =====\n";
    std::cout << "QuickSort  -> Tiempo: " << qsTime  << " ms | Memoria: " << qsMem  / 1024 << " KB\n";
    std::cout << "HeapSort   -> Tiempo: " << hsTime  << " ms | Memoria: " << hsMem  / 1024 << " KB\n";
    std::cout << "AVL Tree   -> Tiempo: " << avlTime << " ms | Memoria: " << avlMem / 1024 << " KB\n";

    std::cout << "\n===== PRIMERAS 5 PALABRAS ORDENADAS =====\n";
    std::cout << "QuickSort : ";
    for(int i = 0; i < 5; i++)
        std::cout << "[" << qsWords[i] << "] ";
    std::cout << "\n";

    std::cout << "HeapSort  : ";
    for(int i = 0; i < 5; i++)
        std::cout << "[" << hsWords[i] << "] ";
    std::cout << "\n";

    std::cout << "AVL Tree  : ";
    for(int i = 0; i < 5; i++)
        std::cout << "[" << avlWords[i] << "] ";
    std::cout << "\n";
    return 0;
}