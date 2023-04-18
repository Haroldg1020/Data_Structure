#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::insListaOrdenada(int v){ // complejidad total: O(n^2)
    int tam = longLista(), pos = 0; // n por longLista
    bool hayQueAnexar = false; // 1
    if(tam == 0){ 
      hayQueAnexar = true; // 1
    }else{
        /*
            El numero de operaciones es 1 + 2 + 3 + ... + n
            que es igual a n*(n+1) / 2
            Lo que indica una complejidad computacional de n^2
        */
        for(int i = 1 ; i <= tam ; i ++){ // n (total: n^2)
            if(infoLista(i) < v){ // i
                pos = i; // 1
            }else{
                i = tam + 1; // 1
            }
        }
        pos ++; // 1
        if(pos == tam+1)hayQueAnexar = true; // 1
    }
    if(hayQueAnexar){// codigo de anexar en lista
      Nodo* tmp; // 1
      Nodo* nuevo = new Nodo; // 1
      nuevo->dato = v; // 1
      nuevo->sig = NULL; // 1

      if(act == NULL) // 1
        act = nuevo; // 1
      else{
        tmp = act; // 1
        while(tmp->sig != NULL) // n (tamano)
          tmp = tmp->sig; // 1
        tmp->sig = nuevo; // 1
      }
    }else{ // mismo codigo para insLista(v, pos);
      Nodo *nuevo, *tmp; // 1
      nuevo = new Nodo; // 1
      nuevo->dato = v; // 1
      nuevo->sig = NULL; // 1

      if(pos >= 1 && pos <= longLista()){ // n
        if(pos == 1){ // 1
          nuevo->sig = act; // 1
          act = nuevo; // 1
        }
        else{
          tmp = act; // 1
          for(int i = 0; i < pos - 2; i++) // n
            tmp = tmp->sig; // 1
          nuevo->sig = tmp->sig; // 1
          tmp->sig = nuevo; // 1
        }
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
