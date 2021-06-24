#pragma once

#include <vector>
#include <queue>

#include "Graph.h"

using namespace std;

constexpr const int MAXN = 2e6;

//-------------------------------------------------------

// Se emplea "extern" para indicar al compilador
// que ya existe esta variable al llamar este header 
// en otro archivo y no se cometan re declaraciones 
// o algo por el estilo

// La definicion se realiza a parte sin el uso de extern
// en el archivo cpp de DIJKSTRA_1

extern double dist[MAXN];

//-------------------------------------------------------

void DIJKSTRA_1 (Graph &X, int source);