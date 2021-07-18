#pragma once

#include <list>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include "AStar.h"

using namespace std;

void print_mapa () {
  int x = 0, y = 0;
  map m1(25,25);
  pointA p1, e;
  Astar as;
  bool band = false;
  
  cout << "Ingresa una coordenada x para tu punto inicial: "; cin >> x;
  while(x > 24){
    system("clear");
    cout << "Ingresa una coordenada x para tu punto inicial: "; cin >> x;
  }

  cout << "Ingresa una coordenada y para tu punto inicial: "; cin >> y;
  while(y > 24){
    system("clear");
    cout << "Ingresa una coordenada y para tu punto inicialnicial: "; cin >> y;
  }
  p1.set_x(x);
  p1.set_y(y);
  
  cout << "Ingresa una coordenada x para tu punto final: "; cin >> x;
  while(x > 24){
    system("clear");
    cout << "Ingresa una coordenada x para tu punto final: "; cin >> x;
  }

  cout << "Ingresa una coordenada y para tu punto final: "; cin >> y;
  while(y > 24){
      system("clear");
      cout << "Ingresa una coordenada y para tu punto final: "; cin >> y;
  }

  e.set_x(x);
  e.set_y(y);

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
