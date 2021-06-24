#include <list>
#include <algorithm>
#include <iostream>
#include "pointA.h"

using namespace std;

struct nodeA {
  pointA pos; //Posicion del nuevo nodo 
  pointA parent; // nodo anterior
  int distancia; //distancia del nodo
  int costo; //costo del nuevo nodo

  bool operator == (const nodeA& x) {return pos == x.pos;}
  bool operator == (const pointA& x) {return pos == x;}
  bool operator < (const nodeA& x) {return distancia + costo < x.distancia + x.costo; }
};