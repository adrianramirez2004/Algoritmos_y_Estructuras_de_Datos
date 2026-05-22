# Algoritmos y Estructuras de Datos Avanzadas en C++

Este repositorio contiene una biblioteca completa de estructuras de datos lineales, jerárquicas y de red desarrolladas de forma nativa en C++. El enfoque del proyecto está orientado a objetos, implementando **programación genérica (Templates)**, optimización en el manejo dinámico de memoria mediante punteros y aplicaciones prácticas resueltas en evaluaciones técnicas avanzadas.

---

## Arquitectura del Proyecto (src/)

El código fuente está estructurado de manera modular, separando la lógica de las colecciones de sus respectivos componentes de almacenamiento primario (Nodos).

1. Estructuras Lineales y Nodos Base
`Nodo.hpp`: Celda base con apuntadores de enlace simple de tipo genérico.
`Lista.hpp`: Lista enlazada dinámica con operaciones de inserción, búsqueda, eliminación y algoritmos de ordenamiento nativos (`ordenarascendente`, `ordenardescendente`).
`Cola.hpp` y `Pila.hpp`: Implementaciones de estructuras de flujo restrictivo FIFO y LIFO respectivamente, con soporte para operaciones de inversión y copia profunda de estructuras.

2. Estructuras Jerárquicas (Árboles)
`NodoBin.hpp` y `ArbolBin.hpp`: Representación y manipulación de árboles binarios; incluye algoritmos de cálculo de caminos, recorridos cruzados y reconstrucción a partir de secuencias *Preorden* y *Postorden*.
`NodoN.hpp` y `ArbolN.hpp`: Implementación de árboles generales (N-arios) utilizando la representación optimizada de **Hijo Izquierdo - Hermano Derecho**, ideal para estructuras de datos jerárquicas complejas y ramificación no binaria.

3. Estructuras de Red y Conectividad (Grafos)
`NodoVertice.hpp` y `NodoAdy.hpp`: Infraestructura de nodos maestros para la lista de vértices y nodos de adyacencia para listas de aristas ponderadas con costos asociados.
`Grafo.hpp`: Clase base abstracta que centraliza operaciones comunes de redes, cálculo de predecesores, sucesores y algoritmos fundamentales de búsqueda de caminos.
`GrafoDirigido.hpp`: Especialización que restringe y evalúa flujos en una sola dirección; integra algoritmos de recorrido en amplitud (**BFS**) y profundidad (**DFS**).
`GrafoNoDirigido.hpp`: Especialización para relaciones simétricas bidireccionales; incluye cálculo de caminos óptimos con bloqueos dinámicos, búsquedas de caminos máximos y detección de componentes y arcos críticos (Puentes mediante `puentesM` / `esConexoM`).

## Aplicaciones y Casos de Estudio (Exámenes Parciales)

Para demostrar el comportamiento y robustez de la biblioteca, se incluyen las soluciones a tres problemas algorítmicos complejos:

 Parcial 1: Juego de Eliminación Circular (`Parcial1Progra2-2025.cpp`)
 Problema: Simulación dinámica de eliminación de participantes dispuestos en anillo (Problema de tipo *Josephus* modificado).
Solución Técnica: Emplea flujos dinámicos combinando `Lista` y condiciones matemáticas basadas en propiedades pares/impares para alterar los patrones de saltos de eliminación en tiempo de ejecución hasta determinar un único ganador.

 Parcial 2: Máximo Subconjunto Independiente en Árboles (`Parcial2Progra2-2025.cpp`)
Problema: Optimización jerárquica y cálculo del Máximo Subconjunto Independiente (MSI) dentro de una estructura no lineal.
Solución Técnica: Construcción dinámica de un `ArbolN` genérico evaluando de forma recursiva la inclusión o exclusión óptima de pesos de nodos contiguos (evitando la adyacencia directa de nodos padre-hijo) mediante programación dinámica/recursión avanzada.

 Parcial 3: Optimización y Caminos Máximos en Grafos (`Parcial3Progra2-2025.cpp`)
Problema: Exploración exhaustiva de caminos, modelado de subgrafos y aislamiento de rutas óptimas bajo restricciones de vecindad alfabética y conectividad.
Solución Técnica Hace uso intensivo de `GrafoNoDirigido` aplicando técnicas de mapeo de tipos (`mapear`), vectores de control de visitas (Backtracking) y ordenamiento de colecciones para aislar y procesar el subgrafo con la máxima cantidad de conexiones válidas consecutivas.

## Tecnologías y Conceptos Clave Demostrados

C++ Estándar: Modularización limpia mediante archivos de cabecera (`.hpp`) desacoplados.
Genericidad: Uso extendido de `template <typename element>` para reutilización de estructuras.
Programacion Orientado a Objetos: Uso estricto de encapsulamiento, herencia de clases (`class GrafoDirigido: public Grafo`) y polimorfismo.
Manejo Explicito de Memoria: Destrucción y vaciado controlado de estructuras dinámicas para prevenir fugas de memoria.
