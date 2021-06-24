#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <initializer_list>
#include <utility>

#include "Graph.h"
#include "functions.h"

using namespace std;

#define all(x) begin(x), end(x)


//---------------------------------

// Random option

// Con Semaforo (CS)
// Sin Semaforo (SS)
// Proporción CS:SS -> 1:2.2 -> 5:11

random_device rd; 
mt19937 gen(rd()); 

// ¿CS o SS?
uniform_int_distribution<> distr(0, 16);
// CS
uniform_real_distribution<> distr_CS(30, 90);
// SS
uniform_real_distribution<> distr_SS(4, 5);

int weights[] = {5, 11};

int choice () {
  int rnd = distr(gen);
  int ans;
  for(int i=0; i<2; i++) {
    if(rnd < weights[i]) return i;
    rnd -= weights[i];
  }
  // Revisar este último return
  return true;
}

//--------------------------------


// Adición de arista no dirigida
void Graph::add_ruta(int ID, int ID_2){

  // Si ambos nodos no existen...
  auto find_ID = nodes.find(ID) != nodes.end();
  auto find_ID_2 = nodes.find(ID_2) != nodes.end();
  if(!find_ID && !find_ID_2){
    // Generar peso aleatorio (INCOMPLETO)
    double random_N = (choice())? distr_SS(gen) : distr_CS(gen);
    double random_M = (choice())? distr_SS(gen) : distr_CS(gen);
    nodo F (ID, random_M);
    nodo F2 (ID_2, random_N);
    nodes[ID] = F;
    nodes[ID_2] = F2;
    adj[ID].push_back(F2);
    adj[ID_2].push_back(F);
    return;
  }

  // Si uno de ambos nodos no existe...
  if(!find_ID || !find_ID_2) {
    // Generar peso aleatorio (INCOMPLETO)
    double random_N = (choice())? distr_SS(gen) : distr_CS(gen);
    if(!find_ID) {
      nodo F (ID, random_N);
      nodes[ID] = F;
      adj[ID].push_back(nodes[ID_2]);
      adj[ID_2].push_back(F);
    }
    else{
      nodo F (ID_2, random_N);
      nodes[ID_2] = F;
      adj[ID_2].push_back(nodes[ID]);
      adj[ID].push_back(F);
    }
    return;
  }

  // Se hace un "check" de si ya existe la ruta entre
  // el nodo ID e ID_2 (ambos existen)
  auto func = [&ID_2] (const nodo& A) { return A.id == ID_2;};
  auto it = find_if(all(adj[ID]), func);
  // Si ya existe termina la función
  if(it != end(adj[ID])) {
    cout << "Ya existe una ruta entre ambos nodos.\n"; 
    return;
  }

  // Si no existe ruta se vuelven "neighbors"
  adj[ID].push_back(nodes[ID_2]);
  adj[ID_2].push_back(nodes[ID]);

  N_edges++;
  N_nodes = adj.size();
}


void Graph::add_nodo(int id) {
  auto find_id = nodes.find(id) != nodes.end();
  if(!find_id) {
    double random_N = (choice())? distr_SS(gen) : distr_CS(gen);
    nodo F(id, random_N);
    nodes[id] = F;
  }
  // Ver si se puede crear un while-loop de
  // verificacion hasta que se ingrese un nodo
  // que no existe en el grafo
  else cout << "Ya existe ese nodo." << endl;
}

// Getters
int Graph::number_of_nodes() { return N_nodes; };
int Graph::number_of_edges() { return N_edges; };
double Graph::get_peso_nodo(int ID) { return nodes[ID].peso; }

void read_file(Graph &X, string filename){
  ifstream f(filename);
  int nodo_1, nodo_2; 
  while(f >> nodo_1 >> nodo_2){
    X.add_ruta(nodo_1, nodo_2);
  }
  f.close();
}
