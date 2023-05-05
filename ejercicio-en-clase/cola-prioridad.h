#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;


typedef int Elemento;

class Nodo
{
public:
    Elemento dato;
    Nodo *sig;
    Nodo *ant;
};

class Cola
{

private:
    Nodo *act;

public:

    Cola();
    Elemento front();
    void deque();
    void enqueue(Elemento);
    bool vaciaCola();

};

#endif
