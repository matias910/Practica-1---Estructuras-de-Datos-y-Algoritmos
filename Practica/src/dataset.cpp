//
// Created by matias on 3/21/26.
//

#include "dataset.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

std::vector<std::string> loadDataset(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("No se pudo abrir: " + path);

    std::vector<std::string> words;
    std::string line;


    while (std::getline(file, line)) {
        // Eliminar caracteres extraños al inicio y fin
        line.erase(0, line.find_first_not_of(" \t\r\n\xef\xbb\xbf"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        if (!line.empty())
            words.push_back(line);
    }while (std::getline(file, line)) {
    // Dejar solo letras a-z
    std::string clean;
    for (char c : line) {
        if (c >= 'a' && c <= 'z')
            clean += c;
    }
    if (!clean.empty())
        words.push_back(clean);
}

    file.close();
    std::cout << "[Dataset] " << words.size() << " palabras cargadas.\n";
    return words;
}