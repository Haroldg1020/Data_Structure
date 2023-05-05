#include "cola-prioridad.h"

Cola::Cola()
{
}

Elemento Cola::front()
{
    
  Nodo *tmp = act;
  Elemento pos = 1;
  for (int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;

}

void Cola::enqueue(Elemento e)
{
  Nodo *tmp, *primero;
  Nodo *nuevo = new Nodo;
  nuevo->dato = e;
  nuevo->sig = nuevo;
  nuevo->ant = nuevo;

  if (act == NULL)
    act = nuevo;
  else
  {
    tmp = act->ant;
    tmp->sig = nuevo;
    nuevo->ant = tmp;
    nuevo->sig = act;
    act->ant = nuevo;
  }
}

void Cola::deque()
{
  int ans;
  if (act == NULL)
    ans = 0;
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

    ans = cont;
  }

  Elemento pos = 1;
  Nodo *tmp, *borrar;
  if (pos >= 1 && pos <= ans)
  {
    if (pos == 1)
    {
      if (act != act->sig)
      {
          tmp = act->ant;
          borrar = tmp->sig;
          act = act->sig;
          act->ant = tmp;
          tmp->sig = act;
      }
      else
      {
          borrar = act;
          act = NULL;
      }
    }
    else
    {
      tmp = act;
      for (int i = 0; i < pos - 2; i++)
          tmp = tmp->sig;
      borrar = tmp->sig;
      Nodo *sig = tmp->sig->sig;
      tmp->sig = sig;
      sig->ant = tmp;
    }

    delete borrar;
  }
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