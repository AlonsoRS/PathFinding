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
#include "GraphA/print_map.h"

#define all(x) begin(x), end(x)

using namespace std;

#include <queue>

int main() {

  print_mapa();
  /*
  Graph G;
  read_file(G, "scratch.txt");
  G.show_neighbors(1, 2, 3, 6);

  for(int i = 0; i < 7; i++){
    if(i == 6 || i == 5) continue;
    cout << "Nodo " << i << " " << G.get_peso_nodo(i) << endl;
  }

  auto [dist, prev] = DIJKSTRA(G, 1);
  for(int i = 0; i < 5; i++) {
    cout << "Nodo " << i << " " << dist[i] << endl;
  }
  cout << endl;
  */
  return 0;
} 

/*
 Graph G;
  read_file(G, "scratch.txt");
  G.show_neighbors(1, 2, 3, 6);

  for(int i = 0; i < 7; i++){
    if(i == 6 || i == 5) continue;
    cout << "Nodo " << i << " " << G.get_peso_nodo(i) << endl;
  }

  auto [dist, prev] = DIJKSTRA(G, 1);
  for(int i = 0; i < 5; i++) {
    cout << "Nodo " << i << " " << dist[i] << endl;
  }
  cout << endl;
*/