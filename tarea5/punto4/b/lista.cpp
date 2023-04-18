#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
	tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}

Lista Lista::operator+(Lista otro){ // O(tamano lista1 ^ 2) O(n^2)
  Lista copia;
  int tam = longLista(); // tamLista
  /*
    el siguiente ciclo hace (1 + 0) + (2 + 1) + (3 + 2)... (tamLista1 + tamLista1-1)
    (tamLista1 * (tamLista1+1) / 2) + ((tamLista1 - 1) * (tamLista1) / 2)

    eso es aproximadamente tamLista1^2
    = O (n^2)
    */
  for(int i = 1 ; i<= tam ;i ++){ // tamlista1 veces 
    copia.anxLista(infoLista(i)); // i + tamListaCopia
  }
  if(copia.act == NULL)
    copia.act = otro.act; // 1
  else{
    Nodo *tmp = copia.act;
    while(tmp->sig != NULL) // n (tamano de la lista1)
      tmp = tmp->sig; // 1
    tmp->sig = otro.act; // 1
  }
  return copia;
}
