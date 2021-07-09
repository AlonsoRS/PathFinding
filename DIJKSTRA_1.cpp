#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <utility>

#include "DIJKSTRA_1.h"

using namespace std;

auto order = [] (nodo A, nodo B){ 
  return A.peso > B.peso;
};

priority_queue<nodo, vector<nodo>, decltype(order)>q(order);

// Dijkstra´s Algorithm - Shortest Path Tree (SPT)
// Retorna vector de distancias respecto al round_to_nearest
return_t<double, int> DIJKSTRA (Graph &X, int source){
    // Vector de distancias n + 1 nodos (0 es nodo)
    vector<double> dist(X.number_of_nodes() + 1, INF);
    vector<int> prev(X.number_of_nodes() + 1, 0);
    q.push(nodo(source, 0));
    dist[source] = 0;
    while(!q.empty()) {
        int x = q.top().id;
        double d = q.top().peso;
        q.pop();
        if(d != dist[x]) continue;
        for(const auto neigh : X.adj[x]) {
            int to = neigh.id;
            // En vez de usar el peso de una arista
            // se usa el peso del nodo
            double l = neigh.peso;
            if(dist[x] + l < dist[to]) {
                // Actualización de distancia
                dist[to] = dist[x] + l;
                // Actualización de padre en SPT
                prev[to] = x;
                q.push(nodo(to, dist[to]));
            }
        }
    }
    return return_t<double, int>(dist, prev);
};
