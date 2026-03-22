//
// Created by matias on 3/21/26.
//

#include "dataset.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

std::vector<std::string> loadDataset(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("No se pudo abrir: " + path);

    std::vector<std::string> words;
    std::string word;
    while (file >> word)
        words.push_back(word);

    file.close();
    std::cout << "[Dataset] " << words.size() << " palabras cargadas.\n";
    return words;
}