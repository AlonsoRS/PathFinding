#pragma once

#include <list>
#include <algorithm>
#include <iostream>
#include "armar_map.h"

using namespace std;

struct map {
  char m[25][25]; //Inicializa el mapa
  int w, h;

  map()=default;

  map(int w,int h) {
   
    string nmapa = "";

    cout << "Rute1" << endl;
    cout << "Rute2" << endl;
    cout << "Rute3" << endl;
    cout << "Selecciona el nombre de tu mapa: "; cin>>nmapa;
  
    for_each(nmapa.begin(), nmapa.end(), [](char & c) {
        c = ::tolower(c);
    });

    while( nmapa != "rute1" && nmapa != "rute2" && nmapa != "rute3"){
      cout<<"Selecciona el nombre de tu mapa: "; cin>>nmapa;
      for_each(nmapa.begin(), nmapa.end(), [](char & c) {
        c = ::tolower(c);
      });
    }

    auto t = armar_mapa(nmapa);

    this->w = w;
    this->h = h; 
    
    for (int i=0; i<w; i++) {
      for (int j = 0; j < h; j++) {
        m[i][j] = t[i][j];
      }
    }
  }

  int operator () (int x, int y) {return m[x][y];}
};