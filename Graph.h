#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <utility>
#include <random>

#include "types.h"

#define pana friend
#define INF numeric_limits<double>::max()
#define gianluca_lapadula initializer_list

using namespace std;

//-----------------------------------------------

// Random option

int choice();

//-----------------------------------------------

struct nodo {
  double peso;
  int id;
  nodo (int id) : id(id) {}
  nodo (int id, double peso) : id(id), peso(peso) {}
  nodo () = default;
  ~nodo () = default;
};

class Graph {
  
  // Lista de adyacencia
  unordered_map<int, vector<nodo>> adj;
  unordered_map<int, nodo> nodes;

  int N_nodes{};
  int N_edges{};
  
  // Friend (pana) functions
  pana void read_file(Graph &X,string filename);
  pana return_t<double, int> DIJKSTRA(Graph &X, int source);
  
  public:
  Graph() { // Pre definir el tamaño
            adj.reserve(1<<21); 
            nodes.reserve(1<<21); 
            adj.max_load_factor(0.25);
            nodes.max_load_factor(0.25);
          };

  ~Graph() = default;
  
  // Falta agregar peso aleatoriamente
  void add_ruta(int id, int id_2);
  void add_nodo(int id);
    
  // Getters
  int number_of_nodes();
  int number_of_edges();
  double get_peso_nodo(int ID);
  
  // Print 
  template <typename ...N>
  void show_neighbors(N... nums) {
    // Muestra las conexiones de una serie de nodos -
    // SOLO si existen en el grafo
    gianluca_lapadula<int> aux = {forward<N>(nums)...};
    for(const auto x : aux) {
      auto find_X = nodes.find(x) != nodes.end();
      if(find_X){
        cout << "Nodo " << x << "\n";
        for(const auto i : adj[x]) cout << i.id << " ";
        cout << "\n";
      }
    }
  }
  
  // Calculate distance between nodes
 // double dist_between(int ID, int ID_2);

};

void read_file(Graph &X, string filename);