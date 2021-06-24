#include <iostream>
#include <list>
#include "nodeA.h"
#include "pointA.h"
#include "mapA.h"

using namespace std;

class Astar { 
public:
  map m; //matriz que simula rutas
  pointA p_fin; // punto final
  pointA p_ini; //punto inicial
  pointA neigh[8]; //puntos cardinales 
  list<nodeA> open; //lista de casillas o nodos que pueden seguir abriendo caminos
  list<nodeA> close; //lista de nodos que ya hemos revisado

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//Se encarga de ponerle puntos cardinales para que verifique si hay una pared o algun objeto que evita que pueda seguir su camino
  Astar(){ 
    neigh[0] = pointA(-1,-1);
    neigh[1] = pointA(1,-1);
    neigh[2] = pointA(-1,1);
    neigh[3] = pointA(1,1);
    neigh[4] = pointA(0,-1);
    neigh[5] = pointA(-1,0);
    neigh[6] = pointA(0,1);
    neigh[7] = pointA(1,0);
  }

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  int calcularDistancia(pointA& p) {
    //Aplicamos la heuristica 
    int x1 = p_fin.x - p.x; //coordenada x del punto final - punto inicial 
    int y1 = p_fin.y - p.y; //coordenada y del punto final - punto inicial
    return (x1 * x1 + y1 * y1)//retornamos la suma al cuadrado para su distancia
  }


  bool validar_p(pointA& p) {
    return (p.x > -1 && p.y > -1 && p.x < m.w && p.y < m.h);
  } //Validar si el punto ingresado es valido para el mapa construido comparando sus coodenadas con los puntos maximos y minimos de la matriz para ver si no sobrepasa el limite del mapa
 
  bool existe_punto (pointA& p, int costo) { //parametro, punto a encontrar y su peso
    auto it; //inicia un iterador
    it = find(close.begin(), close.end(), p); //busca el punto ingresado (p)
    if (it != close.end()) { //Si el punto es encontrado 
      if( (*it).costo + (*it).distancia < costo) {return true;} // Si el peso de punto + su distancia es    menor al peso, entonces retorna verdadero y existe el punto
      else {
        close.erase(it); //elimina los elementos de la lista close y retorna falso
        return false;
      }
    }
    else { retun false; }
  } //Se encarga de determinar si existe un punto por el se pueda pasar
  

  bool pack_disp (nodeA& nd) { //Rellena la lista Open
    int t_cost; // Costo por cada paso que da
    int nc; // nuevo costo
    int distancia;  
    pointA neigh_x; // Punto cercano al nodo 

    for (int i=0; i<5; i++) { // Recorre nuestra matriz
      t_cost = x < 4 ? 1:1; // Determina si el paso o recorrido es recto o diagonal, se puede hacer que la diagonal tenga un costo diferente
      neigh_x = nd.pos + neigh[x]; // Suma la posicion del nodo con cada uno de sus puntos cercanos o cardinales
      if (neigh_x == p_fin) {return true;} // Si el punto cercano es igual al punto final de la matriz entonces retorna true

      //Si el punto nuevo es valido y sus coordenadas son diferentes de 1 osea no es una pared o vereda
      if (validar_p(neigh_x) && m(neigh_x.x, neigh_x.y) != 1) {
        nc = t_cost + nd.costo; //suma del costo por paso mas el costo del nodo da un nuevo costo
        dist = calcularDistancia(neigh_x); //calcular distancia entre el nuevo punto y el punto final
        if (!existe_punto(neigh_x, nc + distancia)) { //si no existe el punto
          nodeA nd1; //se crea un nuevo nodo 
          nd1.costo = nc; //se le da el nuevo costo al nuevo nodo
          nd1.distancia; //inicializamos su distancia
          nd1.parent = nd.pos; //el antiguo nodo recibe la posicion del nodo anterior que se paso como parametro
          open.push_back(nd1); //Se agrega a la lista de nodos abiertos/disponibles
        }
      }
    }
    return false; // retorna false si no es posible llegar al punto teniendo los nodos de la lista
  } 
  

  //Busca desde nuestro  punto inicial hasta nuestro punto final a traves de la matriz
  bool buscar(point& z, point& e, map& matrix){
    nodeA n; //crea un nuevo nodo
    p_fin = e; //el punto e define el punto final
    p_ini = z; //el punto z define el punto inicial
    m = matrix; // m es la matriz

    n.costo = 0; n.pos = z; n.parent = 0; n.distancia = calcularDistancia(z); //Los atributos del nodeA "n" son seteados para la busqueda

    open.push_back(n); //Se añada a la lista inicial "open" los nodos n inicializados

    while(!open.empty()){ //mientras la lista no este vacia
      nodeA n = open.front(); // el primer elemento es el primer nodo 
      open.pop_front(); //lo eliminamos
      close.push_back(n); //lo ponemos dentro de la lista de nodos recorridos
      if(pack_disp(n)) {return true;} //si es posible rellenarlo hasta poder llegar al punto final entonces retorna verdadero
    }
    return false; //sino falso
  }
  
  //determina el costo o la cantidad de puntos o nodos que tuvo que recorrer para llegar a su destino
  int path(list<pointA>& camino){ 
    camino.push_front(p_fin); //se agrega a la lista de puntosA, el punto final
    int cost = 1 + close.back().costo; //"cost" toma el costo del ultimo nodo en la lista de nodos "close"
    camino.push_front(close.back().pos); //se añade a camino la posicion del ultimo nodo de la lista close
    pointA parent = close.back().parent; //el puntoA "parent" toma el valor del parent del ultimo nodo de la lista close

    for(auto i = close.rbegin(); i != close.rend(); i++){ //recorremos desde el final al inicio del close
      if((*i).pos == parent && !((*i).pos == p_ini )){ //si la posicion del elemento es igual a su antiguo nodo y su posicion es diferente a la igualdad entre su posicion inicial
        camino.push_front((*i).pos); //metemos las posiciones del elemento en la lista de caminos o puntos
        parent = (*i).parent; //su antiguo nodo sera el nodo padre del ultimo elemento recorrido
      }
    }
    camino.push_front(p_ini); //se agrega a la lista de puntos "camino" el punto inicial
    return cost; //se retorna el costo total del camino 
  }

};