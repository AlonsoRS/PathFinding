/*
Objetivo: 
Estimación de ruta más corta en términos de tiempo
respecto al tiempo perdido por reducción de velocidad
en cada intersección. 

Integrantes:
- Gabriel Vásquez 100%
- Juan Sara 100%
- Juan Torres 100%
- Alonso Rios 100%
*/

#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <unordered_map>

//#include "art.h"
#include "Dijkstra/Graph.h"
#include "Dijkstra/dijkstra.h"
#include "art.h"

using namespace std;

#define all(x) begin(x), end(x)

int main() {
  
  /*graph<int, double> G;
  G.read_file("Dijkstra/CA_routes.txt");
  auto res = dijkstra(G, 793);
  int tget = 955;
  G.show_shortest_path(tget, res);
  */

  main_menu();

  return 0;
} 