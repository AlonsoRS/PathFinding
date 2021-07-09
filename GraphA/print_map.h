#pragma once

#include <list>
#include <algorithm>
#include <iostream>
#include "AStar.h"

using namespace std;

void print_mapa () {
  map m1;
  pointA p1, e(11,11);
  Astar as;
  bool band = false;

  if(as.buscar(p1, e, m1)){
    list<pointA> path_;
    int g = as.path(path_);
    for(int x = -1; x < 26; x++){
      for(int y = -1; y < 26; y++){
        if(x < 0 || y < 0 || x > 24 || y > 24 || m1(x,y) == 1){
          cout<< "|";
        }
        else{
          if (find(path_.begin(), path_.end(), pointA(x, y)) != path_.end()) {
            cout << "x"; //coloca casilla recorrida
          }
          else{
            cout << "."; //casilla revisada pero no optm
          }
        }
      }
      cout<<endl;
    }
    cout << "\nCosto: " << g << ": " << endl;
    for(auto i = path_.begin(); i != path_.end(); i++){
      cout<< "(" << (*i).x << ", " << (*i).y << ") ";
    }
  }
  else{
    cout<<"NO EXISTE UN CAMINO OPTIMO DEBIDO A LAS RESTRICCIONES DEL MAPA";
  }
  cout<<"\n\n";
}
