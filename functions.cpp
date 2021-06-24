/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Graph.h"
#include "functions.h"

using namespace std;


void read_file(Graph &X, string filename){
  ifstream f(filename);
  int nodo_1, nodo_2; 
  while(f >> nodo_1 >> nodo_2){
    nodo temp(nodo_2);
    X.add_ruta(nodo_1, nodo_2);
  }
  f.close();
}*/