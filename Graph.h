#pragma once

// Libraries

#include <iostream>
#include <iterator>
#include <vector>
#include <limits>
#include <unordered_map>
#include <utility>
#include <random>
#include <functional>
#include <fstream>
#include <initializer_list>
#include <queue>
#include <algorithm>

#include "types_.h"

// Macros
#define all(x) begin(x), end(x)
#define INF numeric_limits<double>::max()
#define contains(cont, val) cont.find(val) != cont.end()
#define random_choice() (choice())? distr_SS(gen) : distr_CS(gen)

using namespace std;

//-----------------------------------------------

// Random lib declarations - definition in .cpp

extern random_device rd; 
extern mt19937 gen; 

extern uniform_int_distribution<> distr;
extern uniform_real_distribution<> distr_CS;
extern uniform_real_distribution<> distr_SS;

int choice();

//-----------------------------------------------

// node representation
template <typename ID_t, typename weight_t>
struct node {
  weight_t peso;
  ID_t id;
  node (ID_t id) : id(id) {}
  node (ID_t id, weight_t peso) : id(id), peso(peso) {}
  node () = default;
  ~node () = default;
};

// For storing node references in a container
template <typename T, typename T2>
using node_ref = reference_wrapper<node<T, T2>>;

//------------------------------------------------------

// Prueba

template <typename ID_t, typename weight_t>
class graph;

template <typename ID_t, typename w_t>
auto order = [] (const node<ID_t, w_t> &A,const node<ID_t, w_t> &B){ 
  return A.peso > B.peso;
};

// Fin Prueba


// Template class for the graph representation
template<typename ID_t, typename weight_t>
class graph {
  
  // Adjacency list
  unordered_map<ID_t, vector<node_ref<ID_t,weight_t>>> adj;
  
  // Info. for every node
  unordered_map<ID_t, node<ID_t, weight_t>> nodes;

  // Count of #nodes and #edges
  size_t N_nodes{};
  size_t N_edges{};

  // Actual SPT root
  ID_t spt_root = -1;

  
  template<typename D_id, typename D_w> 
  friend return_t< D_id, D_w> dijkstra (graph<D_id, D_w> &X,  D_id source) {

    using node_t = node<D_id, D_w>;

    priority_queue<node_t, vector<node_t>, decltype(order<D_id,D_w>)>q(order<D_id,D_w>);

    // #Nodos: 0, 1, 2, 3, ... n
    //vector<D_w> distance (X.number_of_nodes() + 1, INF);
    //vector<D_id> parent (X.number_of_nodes() + 1, 0);
    
    // Prueba -------------
    unordered_map<D_id, D_w> distance;
    unordered_map<D_id, D_id> parent;
    distance.reserve(1<<19);
    parent.reserve(1<<19);
    distance.max_load_factor(0.25);
    parent.max_load_factor(0.25);
    for(auto& [key, n] : X.nodes) {
      distance[key] = INF;
      parent[key] = -1;
    }
     // --------------------

    q.push(node_t(source, 0));
    distance[source] = 0;
    parent[source] = 0;

    while(!q.empty()) {

        D_id x = q.top().id;
        D_w d = q.top().peso;

        q.pop();

        if(d != distance[x]) continue;

        for(auto neighbour : X.adj[x]) {

            D_id to = neighbour.get().id;

            // Peso de nodo
            D_w w = neighbour.get().peso;

            if(distance[x] + w < distance[to]) {
                // Actualización de distancia
                distance[to] = distance[x] + w;
                // Actualización de padre en SPT
                parent[to] = x;
                q.push(node_t(to, distance[to]));
            }
        }
    }
    X.spt_root = source;
    //return_t<D_id, D_w> ans(distance, parent);
    return return_t<D_id, D_w> (distance, parent);
}; 
  
  public:
  
  // Declaration implies prev. memory reserve
  // in exchange of hash speed (max_load_factor=0.25)
  // See in graph.cpp
  graph() 
  { 
    // Pre definir el tamaño
    // 1<<21
    adj.reserve(1<<20); 
    nodes.reserve(1<<20); 
    adj.max_load_factor(0.25);
    nodes.max_load_factor(0.25);
  };

  // Destructor
  ~graph() = default;
  
  // Add route - specially implemented for the purpose of our project
  // (random weighted nodes)
  // *Can be easily adapted to a general-purpose graph
  void add_route(ID_t id_1, ID_t id_2) {

    auto find_ID = contains(nodes, id_1);
    auto find_ID_2 = contains(nodes, id_2);

    // Alias
    using node_t = node<ID_t, weight_t>;
    
    // Si ambos nodos no existen...
    if(!find_ID && !find_ID_2){
      weight_t random_N = random_choice();
      weight_t random_M = random_choice();
      nodes[id_1] = node_t(id_1, random_M);
      nodes[id_2] = node_t(id_2, random_N);
      adj[id_1].push_back(nodes[id_2]);
      adj[id_2].push_back(nodes[id_1]);
      N_edges++;
      N_nodes += 2;
      return;
    }

    // Si uno de ambos nodos no existe...
    if(!find_ID || !find_ID_2) {
      weight_t random_N = random_choice();
      if(!find_ID) {
        nodes[id_1] = node_t(id_1, random_N);
        adj[id_1].push_back(nodes[id_2]);
        adj[id_2].push_back(nodes[id_1]);
      }
      else{
        nodes[id_2] = node_t(id_2, random_N);
        adj[id_2].push_back(nodes[id_1]);
        adj[id_1].push_back(nodes[id_2]);
      }
      N_edges++;
      N_nodes++;
      return;
    }

    // Se hace un "check" de si ya existe la ruta entre
    // el nodo ID e ID_2 (ambos existen)
    auto func = [&id_2] (const node<ID_t, weight_t> &A) { return A.id == id_2;};
    auto it = find_if(all(adj[id_1]), func);
    // Si ya existe termina la función
    if(it != end(adj[id_1])) {
      cout << "Ya existe una ruta entre ambos nodos.\n"; 
      return;
    }

    // Si no existe ruta se vuelven "neighbors"
    adj[id_1].push_back(nodes[id_2]);
    adj[id_2].push_back(nodes[id_1]);

    N_edges++;
  }

  // Add node - adds a node to the graph
  void add_node(ID_t id) {
    auto find_id = contains(nodes, id);
    if(!find_id) {
      weight_t random_N = random_choice();
      node<ID_t, weight_t> F(id, random_N);
      nodes[id] = F;
      N_nodes++;
    }
    // Ver si se puede crear un while-loop de
    // verificacion hasta que se ingrese un nodo
    // que no existe en el grafo
    else cout << "Ya existe ese nodo." << endl;
}
    
  // Getters
  size_t number_of_nodes() { return N_nodes; };
  size_t number_of_edges() { return N_edges; };
  template <typename ...ids>
  void weight_of(ids... I) 
  { 
    cout << "\n+-------------------------------------\n";
    //cout << number_of_nodes() << "\n";
    //cout << number_of_edges() << "\n";
    initializer_list<ID_t> aux {forward<ids>(I) ...};
    for(const auto &node_identity : aux) {
      cout << "Weight of intersec. #" << node_identity << ": " << nodes[node_identity].peso << "\n";
    }
    cout << "+-------------------------------------\n";
    cout << endl;
  };
  ID_t get_spt_root() 
  {
    if (spt_root == -1) {
      cout << "There is no Shortest Path Tree built yet.\n";
      return -1;
    }
    else return spt_root;
  };

  // Builds vector of nodes' ID in random order
  vector<ID_t> get_nodes_id() {
    vector<ID_t> ans;
    for(auto& [key, val] : nodes)
      ans.push_back(key);
    return ans;
  };

  template <typename ...N> //Void function
  void degree_of(N... ids) {

    cout << "\n+-------------------------------------\n";

    initializer_list<ID_t> aux = {forward<N>(ids) ...};

    for(auto ID_ : aux){
      if(contains(nodes, ID_)){
        // Degree of
        cout << "Roads in intersection #" << ID_  << ": ";
        cout << adj[ID_].size() << "\n";
      }
    }
    cout << "+-------------------------------------\n";
  }
  
  // Show methods
  template <typename ...N>
  void show_neighbors(N... ids) {

    cout << "\n+-------------------------------------\n";
    
    // Perfect forwarding of variated node IDs 
    // into an init_list
    initializer_list<ID_t> aux = {forward<N>(ids)...};
    
    for(auto ID_ : aux) {
      if(contains(nodes, ID_)){
        
        // Node ID
        cout << "Intersection ID: " << ID_ << "\n";
        // Neighbors
        cout << "Next intersections: [ ";

        for(auto neigh : adj[ID_])
          cout << neigh.get().id << " ";

        cout << "]\n";

      }
    }
    cout << "+-------------------------------------\n";
  }

  // Print the route between two intersections
  void show_shortest_path(const ID_t &target_node, return_t<ID_t, weight_t> &SPT_info){
    cout << "\nFrom intersec. " << spt_root << " to intersec. " << target_node << "\n";
    vector<ID_t> path;
    auto temp = target_node;
    while(temp != spt_root) {
      path.push_back(temp);
      temp = SPT_info.p[temp];
    }
    // *
    path.push_back(temp);
    reverse(all(path));
    for(const auto intersec : path)
      if(intersec != path[path.size()-1]) 
        cout << intersec << " -> ";
    cout << path[path.size()-1] << "\n";
    cout << "Time lost: " << SPT_info.d[target_node] << " seconds.\n";
  }

  // Read a text file (edges)
  void read_file(string filename) {
    ifstream f(filename);
    int nodo_1, nodo_2; 
    while(f >> nodo_1 >> nodo_2)
      // En caso se lea un .txt & directed graph:
      // if(nodo_1 < nodo_2) 
      add_route(nodo_1, nodo_2);
    f.close();
  }

};

