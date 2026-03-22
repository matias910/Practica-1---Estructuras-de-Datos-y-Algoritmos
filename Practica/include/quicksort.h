//
// Created by matias on 3/21/26.
//

#ifndef PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_QUICKSORT_H
#define PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_QUICKSORT_H
#pragma once
#include <vector>
#include <string>

void quickSort(std::vector<std::string>& arr, int low, int high);
int  partition(std::vector<std::string>& arr, int low, int high);

#endif //PRACTICA_1_ESTRUCTURAS_DE_DATOS_Y_ALGORITMOS_QUICKSORT_H