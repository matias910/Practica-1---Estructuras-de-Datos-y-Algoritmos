//
// Created by matias on 3/21/26.
//

#ifndef PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_DATASET_H
#define PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_DATASET_H


#pragma once
#include <string>
#include <vector>

std::vector<std::string> generateDataset(const std::string& sourcePath,
                                          const std::string& outputPath,
                                          int count = 100000);



#endif //PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_DATASET_H