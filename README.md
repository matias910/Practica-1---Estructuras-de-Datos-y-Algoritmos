# Práctica I – Estructura de Datos y Algoritmos
Matias Zapata Rojas - Miguel Angel Jimenez Gomez

Universidad EAFIT

Docente: Alexander Narvaez Berrio

---
## Descripcion
Elaborar un programa en C++ que permita ordenar un conjunto de 100,000 palabras usando 3 enfoques distintos (HeapSort, QuickSort, AVL Tree).

---
## Objetivos
Examinar cómo diferentes algoritmos y estructuras de datos responden al trabajar con grandes volúmenes de información, evaluando su desempeño en terminos de:

⏱️ Tiempo de ejecución

💾 Uso de memoria

📈 Complejidad algorítmica

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
## Estructura del Proyecto
├── CMakeLists.txt   

├── data/

│   └── dataset.txt  

├── include/  

│   ├── dataset.h

│   ├── quicksort.h

│   ├── heapsort.h

│   └── AVLtree.h

└── src/

│  ├── main.cpp

│   ├── dataset.cpp

│   ├── quicksort.cpp

│   ├── heapsort.cpp

│   └── AVLtree.cpp

---
## Salida del programa

/home/matias/Documents/Universidad/Practica-1---Estructuras-de-Datos-y-Algoritmos/Practica/cmake-build-debug/Practica

[Dataset] 100000 palabras cargadas.


===== RESULTADOS =====

QuickSort  -> Tiempo: 323.725 ms | Memoria: 3125 KB

HeapSort   -> Tiempo: 762.193 ms | Memoria: 3125 KB

AVL Tree   -> Tiempo: 450.68 ms | Memoria: 8593 KB


===== PRIMERAS 5 PALABRAS ORDENADAS =====

QuickSort : [a] [aahing] [aaliis] [aaronite] [aarrgh] 

HeapSort  : [a] [aahing] [aaliis] [aaronite] [aarrgh] 

AVL Tree  : [a] [aahing] [aaliis] [aaronite] [aarrgh] 

Process finished with exit code 0

---

## Resultados

| Algoritmo 📈 | Tiempo (ms) ⏱️ | Memoria estimada 💾 | Complejidad 🧠 |
|-----------|-------------|-----------------|-------------|
| QuickSort | 323.725 ms | 3,125 KB | O(n log n) prom. |
| HeapSort | 762.193 ms | 3,125 KB | O(n log n) siempre |
| AVL Tree | 450.68 ms | 8,593 KB | O(n log n) + O(n) |

---

## Análisis

**¿Cuál algoritmo fue más rápido?**

El algoritmo mas rapido fue el QuickSort con un tiempo de 323.725 ms, seguido del AVL Tree con 450.68 ms, para terminar con el HeapSort con 762.193 siendo este el mas lento

**¿Por qué la complejidad teórica difiere de los resultados prácticos?**

Aunque los tres métodos presentan complejidad O(n log n), su comportamiento real varía debido a factores como:

💾 Acceso a memoria:
QuickSort trabaja con datos contiguos por lo cual es más eficiente

HeapSort accede a posiciones separadas, por esto tiene un menor rendimiento

AVL utiliza nodos enlazados, gracias a esto es más costoso en accesos

⚡ Costos internos:
Las operaciones dentro de cada algoritmo no tienen el mismo peso en tiempo real.

💻 Interacción con hardware:
La caché del procesador influye significativamente en el rendimiento

**Ventajas y desventajas de cada estructura:**

| Estructura | Ventajas ✅ | Desventajas ❌|
|------------|----------|-------------|
| Vector + QuickSort | Alto rendimiento, uso eficiente de la memoria caché, bajo consumo de memoria adicional| Puede degradarse a O(n²) si el pivote no es adecuado |
| Binary Heap + HeapSort | Complejidad garantizada en todos los casos (O(n log n)), no requiere memoria extra significativa (in-place) | Menor rendimiento práctico debido a accesos no contiguos en memoria |
| AVL Tree | Mantiene el balance automáticamente, permite búsquedas e inserciones eficientes (O(log n)) | Mayor consumo de memoria por uso de nodos y punteros, implementación más compleja |

---

## Conclusiones
Los tres algoritmos producen el mismo resultado correcto pero con rendimientos distintos.

QuickSort ofrece el mejor balance entre velocidad y memoria. 

HeapSort es preferible cuando se necesita garantía estricta de O(n log n). 

El AVL Tree es útil cuando además del ordenamiento se requieren búsquedas e inserciones dinámicas frecuentes.

---
