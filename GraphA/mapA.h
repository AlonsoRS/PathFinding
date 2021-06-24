#include <list>
#include <algorithm>
#include <iostream>
#include "nodeA.h"

struct map {
  char m[0][0]; //Inicializa el m
  int w, h;

  map() {
    char t[5][5] = {
      {0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0},
      {1, 0, 1, 1, 0},
      {0, 0, 0, 1, 0},
      {0, 1, 1, 0, 0},
    };
    w=5; h=5; //Tamaño de la matriz (largo / ancho)
    for (int i=0; i<h; i++) {
      for (int j = 0; j < i; j++) {
        m[j][i] = t[i][j];
      }
    }
  };

  int operator () (int x, int y) {return m[x][y];}

};