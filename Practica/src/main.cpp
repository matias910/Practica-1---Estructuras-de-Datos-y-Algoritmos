#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "dataset.h"
#include "quicksort.h"
#include "heapsort.h"
#include "AVLtree.h"

int main() {
    // ── Paths ─────────────────────────────────────────────────────────────
    const std::string SOURCE  = "../data/words_alpha.txt";
    const std::string DATASET = "../data/dataset.txt";

    // ── Generate dataset ──────────────────────────────────────────────────
    std::cout << "Generating dataset...\n";
    std::vector<std::string> words = generateDataset(SOURCE, DATASET);

    // ── QuickSort ─────────────────────────────────────────────────────────
    std::vector<std::string> qsWords = words;
    auto t1 = std::chrono::high_resolution_clock::now();
    quickSort(qsWords, 0, (int)qsWords.size() - 1);
    auto t2 = std::chrono::high_resolution_clock::now();
    double qsTime = std::chrono::duration<double, std::milli>(t2 - t1).count();

    // ── HeapSort ──────────────────────────────────────────────────────────
    std::vector<std::string> hsWords = words;
    auto t3 = std::chrono::high_resolution_clock::now();
    heapSort(hsWords);
    auto t4 = std::chrono::high_resolution_clock::now();
    double hsTime = std::chrono::duration<double, std::milli>(t4 - t3).count();

    // ── AVL Tree ──────────────────────────────────────────────────────────
    AVLTree tree;
    auto t5 = std::chrono::high_resolution_clock::now();
    for (const auto& w : words)
        tree.insert(w);
    std::vector<std::string> avlWords;
    tree.inorder(avlWords);
    auto t6 = std::chrono::high_resolution_clock::now();
    double avlTime = std::chrono::duration<double, std::milli>(t6 - t5).count();

    // ── Memory estimates ──────────────────────────────────────────────────
    size_t qsMem  = qsWords.size()  * sizeof(std::string);
    size_t hsMem  = hsWords.size()  * sizeof(std::string);
    size_t avlMem = tree.memoryUsage();

    // ── Results ───────────────────────────────────────────────────────────
    std::cout << "\n===== RESULTS =====\n";
    std::cout << "QuickSort  -> Time: " << qsTime  << " ms | Memory: " << qsMem  / 1024 << " KB\n";
    std::cout << "HeapSort   -> Time: " << hsTime  << " ms | Memory: " << hsMem  / 1024 << " KB\n";
    std::cout << "AVL Tree   -> Time: " << avlTime << " ms | Memory: " << avlMem / 1024 << " KB\n";

    std::cout << "\n===== FIRST 5 SORTED WORDS (each algorithm) =====\n";
    std::cout << "QuickSort : "; for(int i=0;i<5;i++) std::cout << qsWords[i]  << " "; std::cout << "\n";
    std::cout << "HeapSort  : "; for(int i=0;i<5;i++) std::cout << hsWords[i]  << " "; std::cout << "\n";
    std::cout << "AVL Tree  : "; for(int i=0;i<5;i++) std::cout << avlWords[i] << " "; std::cout << "\n";

    return 0;
}