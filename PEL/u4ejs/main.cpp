#include <iostream>
#include "list.h"

using namespace std;
/*
1.
Declara una clase “punto” que represente un punto dentro de un plano
(coordenadas x e y), y genera una clase Nodo cuyo campo de valor sea
“punto”
*/
class Punto{
    private:
    int x;
    int y;
    public:
    Punto();
    Punto(int x,int y){this->x = x; this->y = y;};
    int getX(){return this->x;};
    int getY(){return this->y;};
};
class Nodo{
    private:
    Punto punto;
    Nodo* enlace;
    public:
    Nodo(Punto punto){ this->punto = punto; this->enlace = 0;};
    Nodo(Punto punto, Nodo* enlace){ this->punto = punto; this->enlace = enlace;};
   
    Punto getPunto() const {return this->punto;};
    Nodo* getEnlace() const {return this-> enlace;};
    void setEnlace(Nodo* nodo){this->enlace = nodo;};
};
/*
2.
Crea una lista enlazada de elementos que almacene como dato números
enteros. Debe contener al menos 5 números enteros.
*/
void Ej2(){
  List intList;
  for (int i = 0; i<4; ++i)
  {intList.InsertInHead(i);}
}

/*
3.
Utilizando la lista de números enteros desarrollada en el apartado anterior, inserta
tres nuevos elementos. Uno en la cabeza, otro en la cola y otro entre dos nodos.
*/
void Ej3(){
    List intList;
    for (int i = 0; i<4; ++i)
    {intList.InsertInHead(i);}

    intList.InsertInHead(0);
    intList.InsertInTail(1);
    intList.InsertBetween(intList.Last()->NodeJoint(),2);
}



int main(int, char**) {
    Ej2();
    Ej3();
}