#include <list>
#include <algorithm>
#include <iostream>

using namespace std;
//Clase
struct pointA {
  int x, y;

  pointA(int x=0, int y=0) {
    x=x; 
    y=y;
  }

  bool operator == (const pointA& p) {return p.x == x && p.y == y;}
  point operator + (const pointA& p) {return pointA(p.x + x, p.y + y);}
};