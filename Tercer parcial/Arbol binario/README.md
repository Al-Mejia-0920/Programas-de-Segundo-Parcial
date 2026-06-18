#  Proyecto: Árbol Binario de Búsqueda con Persistencia de Datos

**Materia:** Abstracción y Uso de Datos
**Departamento:** Tercer Departamental (UPIICSA)

---

## Descripción del Programa
Este programa, desarrollado en **C++**, implementa la estructura de datos de un **Árbol Binario de Búsqueda (BST)**. Su objetivo principal es organizar de forma jerárquica un conjunto de nodos (caracteres) extraídos dinámicamente de archivos de texto estructurados. 

El sistema está diseñado para leer archivos integrales del equipo y **filtrar exclusivamente la información pertinente al árbol** (las etiquetas de los Nodos), demostrando diferentes tipo de recoridos eficientes y modularidad en el código.

##  Características Principales
* **Lectura de Archivos XML y JSON:** Utiliza flujos de entrada nativos de C++ (`std::ifstream`) para leer estructuras sin necesidad de librerías externas.
* **Filtrado Inteligente:** Ignora automáticamente las propiedades de conexiones, aristas, tiempos y costos, extrayendo únicamente los identificadores de los nodos.
* **Ordenamiento Automático:** Inserta los caracteres en la estructura del árbol respetando la regla binaria (menores a la izquierda, mayores a la derecha).
* **Recorridos Matemáticos:** Despliega en consola la información utilizando algoritmos de recorrido recursivos:
    * **Inorden:** Muestra los nodos ordenados alfabéticamente.
    * **Preorden:** Muestra la jerarquía de clonación del árbol.
    * **Postorden:** Muestra la jerarquía para la eliminación segura de hojas a raíz.
* **Estructura Visual:** Dibuja el árbol horizontalmente en la consola de comandos para facilitar la comprensión de sus niveles y ramificaciones.

## Estructura de Archivos
El proyecto se compone de los siguientes archivos:
* `main.cpp`: Archivo principal que orquesta la carga de datos y la impresión de recorridos.
* `Arboles.h`: Archivo de cabecera que contiene la definición de la estructura `NodoArbol` y la clase `ArbolBinario`.
* `Arboles.cpp`: Archivo de implementación con la lógica matemática y de lectura de archivos.
* `datos_arbol.xml` y `datos_arbol.json`: Archivos de prueba que contienen los nodos a procesar.

##  Compilación y Ejecución
Para ejecutar este programa desde la terminal (en sistemas basados en Unix/macOS o Linux), asegúrate de estar en el directorio raíz del proyecto y ejecuta el siguiente comando:

```bash
g++ main.cpp Arboles.cpp -o programa && ./programa