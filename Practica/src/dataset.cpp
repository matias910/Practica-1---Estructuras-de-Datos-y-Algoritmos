//
// Created by matias on 3/21/26.
//

#include "dataset.h"
#include <fstream>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <iostream>

std::vector<std::string> generateDataset(const std::string& sourcePath,
                                          const std::string& outputPath,
                                          int count)
{
    std::ifstream src(sourcePath);
    if (!src.is_open())
        throw std::runtime_error("Cannot open: " + sourcePath);

    std::vector<std::string> all;
    std::string word;
    while (src >> word)
        all.push_back(word);
    src.close();

    if ((int)all.size() < count)
        throw std::runtime_error("Not enough words in source file.");

    std::mt19937 rng(std::random_device{}());
    std::shuffle(all.begin(), all.end(), rng);
    all.resize(count);

    std::ofstream out(outputPath);
    if (!out.is_open())
        throw std::runtime_error("Cannot create: " + outputPath);
    for (const auto& w : all)
        out << w << "\n";
    out.close();

    std::cout << "[Dataset] " << count << " words saved to " << outputPath << "\n";
    return all;
}