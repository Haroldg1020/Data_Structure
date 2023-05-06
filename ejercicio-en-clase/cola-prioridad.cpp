#include "cola-prioridad.h"

Cola::Cola(){
  act=NULL;
}

Elemento Cola::front(){
  return act->dato;
}
int Cola::size(){
  int ans;
  if(vaciaCola())
    ans = 0;
  else{
    Nodo* tmp, *primero;
    int cont = 1;
    tmp = act;
    primero = act;

    while(tmp->sig != primero){
      tmp = tmp->sig;
      cont++;
    }
    ans = cont;
  }
  return ans;
}


void Cola::enqueue(Elemento elem){ // 7
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  nuevo->ant = NULL;
  if(act == NULL){
    act = nuevo;
    act->sig = act;
    act->ant = act;
  }else if(act->dato <= elem){
      tmp = act->ant;
      tmp->sig = nuevo;
      nuevo->ant = tmp;
      nuevo->sig = act;
      act->ant = nuevo;
      act = nuevo;
    }else{
      tmp = act;
      int iteraciones = 1, tamano = size();
      //cout << "el tamano es " << tamano << endl;
      while(tmp->sig->dato > elem and iteraciones < tamano){
        tmp = tmp->sig;
        //cout << tmp->dato << endl; 
        iteraciones++;
      }
      nuevo->sig = tmp->sig;
      nuevo->ant = tmp;
      tmp->sig->ant = nuevo;
      tmp->sig = nuevo;
    }
}

void Cola::deque(){
  int tamano;
  if (act == NULL)
    tamano = 0;
  else
  {
    Nodo *tmp, *primero;
    int cont = 1;
    tmp = act;
    primero = act;

    while (tmp->sig != primero)
    {
      tmp = tmp->sig;
      cont++;
    }

    tamano = cont;
  }

  Elemento pos = 1;
  Nodo *tmp, *borrar;
  if (act != act->sig){ // Hay mas de un nodo
      tmp = act->ant;
      borrar = tmp->sig;
      act = act->sig;
      act->ant = tmp;
      tmp->sig = act;
  }else{ // ocurre si solo hay un nodo.
      borrar = act;
      act = NULL;
  }
  delete borrar;
}

bool Cola::vaciaCola()
{
    bool ans;
    if (act == NULL)
    ans = true;
    else
        ans = false;
    return ans;
}