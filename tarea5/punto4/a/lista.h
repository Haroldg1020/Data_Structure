#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;

typedef int Elemento;

class Nodo{
   public:
        Elemento dato;
        Nodo* sig;
     
};

class Lista{
  private:
    Nodo* act;

  public:

    /* Constructoras */
    Lista();

    /* Modificadoras */
    void anxLista(Elemento elem);
    void insLista(Elemento elem, int pos);
    void elimLista(int pos);

    /* Analizadoras */
    Elemento infoLista(int pos);
    int longLista();
    bool vaciaLista();
};

#endif