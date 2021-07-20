[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=432781&assignment_repo_type=GroupAssignmentRepo)

# Proyecto 2021-1 - POO_2
##  __Searching Path__

El presente proyecto es realizado por estudiantes del curso de Programación Orientada a Objetos 2. En esta primera entrega (solicitada por el profesor) se podrá observar dos implementaciones, donde ambas son utilizadas para hallar la ruta más corta. En primer lugar, utilizaremos el algoritmo Dijkstra que se basa en un archivo con información sobre nodos y pesos, para posteriormente interpretar la data y calcular la ruta más corta. En segundo lugar, se utilizará el algoritmo A* (A-estrella), el cual se basa en la interpretación de un mapa con valores binarios; donde este detecta velozmente la ruta más corta con espacios no permitidos, es decir restricciones en el mapa propuesto. Por último, se busca mostrar de forma gráfica ambas implementaciones para un mejor entendimiento (actualmente se continua trabajando en ello).

##  __Grupo 11__
### _Integrantes:_
- Gabriel Vásquez
- Juan Sara
- Juan Torres
- Alonso Rios

## __Objetivos:__
1. Para el agoritmo de Dijkstra el objetivo es la estimación de ruta más corta en términos de tiempo respecto al tiempo perdido por reducción de velocidad en cada intersección. La data será extraida de un archivo con información sobre correteras en California.
2. Para el algoritmo A* el objetivo es hallar y mostrar las coordenadas que forman la ruta más corta de un punto hacia otro. En el presente algoritmo debemos tener en cuenta que esta basado un mapa con obstaculos represetados de forma binaria (0 -> espcio libre / 1 -> espcio no disponible).

## __Implementaciones bajo similar concepto a mayor escala:__
Actualmente, implementaciones similares o de mayor escala y eficacia (no necesariamente el algoritmo Dijstra), se ven en aplicaciones de uso diario con la finalida de hallar la ruta más corta, sin trafico o menos interrupciones, tal como Google Maps, Uber, Waze, entre otros. Además se sabe que el algoritmo A* es frecuentemente utilizado en videojuegos donde el usuario marca un punto y la animación automaticamente detecta una ruta óptima mediante posiciones guardadas.

## __Estructura:__
<!--
Esta implementación nos permite hallar el camino más corto en términos de tiempo de una intersección a otra. De esta forma, consideramos como algoritmo adicional el algoritmo A* (A-Estrella). Este es ampliamente usado para juegos con mapas con posiciones guardadas. Por ello, funcionaría para nuestra propuesta pero para, probablemente, ciudades, ya que al guardar coordenadas se tendría que usar mucha memoria para los espacios que no son caminos.
-->

### Algoritmo Dijkstra:
Esta implementacion nos permite hallar el camino más corto en términos de tiempo de una intersección a otra.

__Representación del grafo y nodos:__ \
Archivos: Graph.h | Graph.cpp \
Para representar la red de caminos de nuestro proyecto empleamos un objeto de clase Graph. Para esto se crea la clase Graph que puede ser usado tanto para un grafo dirigido como uno no dirigido (en este caso uno no dirigido). Asimismo, se crea una estructura nodo para representar cada nodo que puede ser ingresado a un objeto de clase Graph. Cabe mencionar esta clase permite agregar aristas y leer archivos.

__Implementación de algoritmo:__ \
Archivos: dijkstra.h | dijkstra.cpp \
Se implementa el algoritmo de Dijkstra de manera que se permite saber el tiempo perdido por reducción de velocidad en cada intersección. 

__Funciones:__ \
Arhivos: functions.h | functions.cpp \
Se definirán e implementarán las multiples funciones que sean neceasrias para el correcto funcionamiento del proyecto. (No se visualizan una gran cantida de funciones puesto que la gran parte necesaria para el funcionamiento se encuentran dentro de los archivo Graph.h y Graph.cpp)

### Algoritmo A*:
La presente implementacion nos permite hallar el camino más corto en terminos de espacios disponibles en el mapa propuesto dentro del codigo. Respecto al costo  de camino optimo, se considera (dentro del código) el peso de 1 unidad para cada espacio abierto como nodo. 

__Representación del mapa:__ \
Archivos: mapA.h \
Se presenta el mapa en forma de matriz, este será utilizado para hallar la ruta más corta con obstaculos o puntos no disponibles. Además para evitar la lectura de un mapa dentro del código, se podrá leer 3 mapas predeterminados y guardados en archivos .txt con los nombres (rute1.txt | rute2.txt | rute3.txt)

__Structura de nodos:__ \
Archivos: nodeA.h \
Un "struct" que contiene los atributos necesarios para lograr identifcar un nuevo nodo en el mapa.

__Structura de coordenadas:__ \
Archivos: pointA.h \
Un "struct" que representa las coordenadas (x, y) en el mapa, con la finalidad de identificar los puntos con facilidad y despues mostrar un ruta en base a la secuencia de estos puntos. 

__Implementación de algoritmo:__ \
Archivos: AStar.cpp | AStar.h \
En la presente clase "Astar" se pueden observar todos los metodos necesarios para calcular, identificar y mostrar la ruta más corta de un punto hacia otro dentro del mapa propuesto.

__Lectura de mapas predeterminados:__ \
Archivos: armar_map.cpp | armar_map.h \
En los presentes archivos se presenta la función que permite la lectura de los archivos donde se encuentran almacenados los mapas predeterminados para utilizarlos mediante el algoritmo A*.

__Mostrando el camino A*:__ \
Archivos: print_map.h
Aqui mediante un menu de elección de camino, el usuario podrá elegir uno de los mapas predeterminados y insertar su punto de partida y llegada para que el algoritmo pueda analizar el camino más óptimo. Al mismo, tiempo la función incluido en el archivo podrá mostrar en consola, de forma ordenada, el camino que el algoritmo opto por seguir. 
