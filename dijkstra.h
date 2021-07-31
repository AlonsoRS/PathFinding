#pragma once

#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <utility>

#include "Graph.h"

using namespace std;
/*
template <typename ID_t, typename w_t>
auto order = [] (const node<ID_t, w_t> &A,const node<ID_t, w_t> &B){ 
  return A.peso > B.peso;
};

// Dijkstra´s Algorithm - Shortest Path Tree (SPT)
template <typename D_id, typename D_w>
return_t<D_id, D_w> dijkstra (graph<D_id, D_w> &X, D_id source){

    using node_t = node<D_id, D_w>;

    priority_queue<node_t, vector<node_t>, decltype(order<D_id,D_w>)>q(order<D_id,D_w>);

    // #Nodos: 0, 1, 2, 3, ... n
    vector<D_w> distance (X.number_of_nodes() + 1, INF);
    vector<D_id> parent (X.number_of_nodes() + 1, 0);

    q.push(node_t(source, 0));
    distance[source] = 0;

    while(!q.empty()) {

        D_id x = q.top().id;
        D_w d = q.top().peso;

        q.pop();

        if(d != distance[x]) continue;

        for(const auto neighbor : X.adj[x]) {

            D_id to = neighbor.get().id;

            // Peso de nodo
            D_w w = neighbor.get().peso;

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
*/