# Práctica I – Ordenamiento de Dataset
Matias Zapata Rojas
Miguel Angel Jimenez Gomez

---

## Contexto
El objetivo de esta práctica es implementar y comparar tres estrategias de ordenamiento 
sobre un dataset de 100,000 palabras en C++, analizando su comportamiento en términos 
de tiempo de ejecución y uso de memoria.

---

## Estructura del ProyectoPractica/
├── CMakeLists.txt
├── data/
│   └── dataset.txt
├── include/
│   ├── dataset.h
│   ├── quicksort.h
│   ├── heapsort.h
│   └── AVLtree.h
└── src/
├── main.cpp
├── dataset.cpp
├── quicksort.cpp
├── heapsort.cpp
└── AVLtree.cpp

---

## Implementación

### QuickSort
Se implementó sobre un `std::vector<string>`. Se utiliza el último elemento como pivote.
La función `partition()` reorganiza los elementos y `quickSort()` aplica la recursión 
sobre cada mitad resultante.
- Complejidad: **O(n log n)** promedio, **O(n²)** peor caso

### HeapSort
Se construyó un Max-Heap a partir del vector original mediante `heapify()`. Luego se 
extrae el máximo repetidamente y se coloca al final del arreglo. Opera in-place sin 
memoria adicional significativa.
- Complejidad: **O(n log n)** siempre

### AVL Tree
Se insertaron las 100,000 palabras en el árbol, aplicando rotaciones simples y dobles 
para mantener el balance. El ordenamiento final se obtiene mediante un recorrido inorden 
(izquierda → raíz → derecha), que produce las palabras en orden alfabético.
- Complejidad: **O(n log n)** inserción + **O(n)** recorrido

---

## Resultados

| Algoritmo | Tiempo (ms) | Memoria estimada | Complejidad |
|-----------|-------------|-----------------|-------------|
| QuickSort | ~318 ms | ~3,125 KB | O(n log n) prom. |
| HeapSort | ~510 ms | ~3,125 KB | O(n log n) siempre |
| AVL Tree | ~236 ms | ~8,593 KB | O(n log n) + O(n) |

---

## Análisis

**¿Cuál algoritmo fue más rápido?**
El AVL Tree resultó ser el más rápido con 236ms, seguido de QuickSort con 318ms, 
y HeapSort fue el más lento con 510ms.

**¿Por qué la complejidad teórica difiere de los resultados prácticos?**
El Big O solo mide el número de operaciones, pero ignora factores reales como:
- **Cache del procesador** — HeapSort accede a posiciones distantes del arreglo 
  generando cache misses
- **Constantes ocultas** — dos algoritmos O(n log n) pueden tener trabajo interno muy diferente
- **Datos de entrada** — QuickSort depende del pivot; con datos ordenados puede llegar a O(n²)

**Ventajas y desventajas de cada estructura:**

| Estructura | Ventajas | Desventajas |
|------------|----------|-------------|
| Vector + QuickSort | Rápido, bajo consumo de memoria | Peor caso O(n²) |
| Binary Heap + HeapSort | Siempre O(n log n), in-place | Lento por cache misses |
| AVL Tree | Balanceado, búsquedas en O(log n) | Mayor uso de memoria, complejo |

---

## Conclusión
Los tres algoritmos producen el mismo resultado correcto pero con rendimientos distintos.
QuickSort ofrece el mejor balance entre velocidad y memoria. HeapSort es preferible cuando 
se necesita garantía estricta de O(n log n). El AVL Tree es útil cuando además del 
ordenamiento se requieren búsquedas e inserciones dinámicas frecuentes.

---
