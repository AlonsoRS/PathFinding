/*
Objetivo: 
Estimación de ruta más corta en términos de tiempo
respecto al tiempo perdido por reducción de velocidad
en cada intersección. 

Integrantes:
- Gabriel Vásquez
- Juan Sara
- Juan Torres 
- Alonso Rios
*/

#include <iostream>
#include <random>
#include <vector>

#include "Graph.h"
#include "functions.h"
#include "DIJKSTRA_1.h"

#define all(x) begin(x), end(x)

using namespace std;

#include <queue>

int main() {
  
  Graph G;
  read_file(G, "scratch.txt");
  G.show_neighbors(1, 2, 3, 6);

  cout << G.get_peso_nodo(0) << endl;
  cout << G.get_peso_nodo(1) << endl;
  cout << G.get_peso_nodo(2) << endl;
  cout << G.get_peso_nodo(3) << endl;
  cout << G.get_peso_nodo(6) << endl;

  DIJKSTRA_1(G, 1);
  for(int i = 0; i <= 6; i++) cout << dist[i] << " ";
  cout << endl;
  
  return 0;
} 