#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

#include "DIJKSTRA_1.h"

using namespace std;

double dist[MAXN];

auto order = [] (nodo A, nodo B){ 
  return A.peso > B.peso;
};

priority_queue<nodo, vector<nodo>, decltype(order)>q(order);

// En edición
void DIJKSTRA_1 (Graph &X, int source){
    // Pre definir el tamaño
    fill_n(dist, 2e4, INF);
    q.push(nodo(source, 0));
    dist[source] = 0;
    while(!q.empty()){
        int x = q.top().id;
        double d = q.top().peso;
        q.pop();
        if(d != dist[x]) continue;
        for(const auto neigh : X.adj[x]) {
            int to = neigh.id;
            // En vez de usar el peso de una arista
            // se usa el peso del nodo
            double l = neigh.peso;
            if(dist[x] + l < dist[to]){
                dist[to] = dist[x] + l;
                q.push(nodo(to, dist[to]));
            }
        }
    }
};
