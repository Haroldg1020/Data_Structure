#include "lista.cpp"
#include <iostream>

void insertarEnListaOrdenada(Lista &l, int v){ // O(n^2)
    int tam = l.longLista(), pos = 0;
    if(tam == 0){
      l.anxLista(v);
    }else{
        /*
            El numero de operaciones es 1 + 2 + 3 + ... + n
            que es igual a n*(n+1) / 2
            Lo que indica una complejidad computacional de n^2
        */
        for(int i = 1 ; i <= tam ; i ++){ // n
            if(l.infoLista(i) < v){ // i
                pos = i;
            }else{
                i = tam + 1;
            }
        }
        pos ++;
        if(pos == tam+1)l.anxLista(v); // n
        else l.insLista(v, pos); // n
    }
}


int main(){
    Lista ejemplo;
    insertarEnListaOrdenada(ejemplo, 5);
    insertarEnListaOrdenada(ejemplo, 3);
    insertarEnListaOrdenada(ejemplo, 8);
    insertarEnListaOrdenada(ejemplo, 10);
    insertarEnListaOrdenada(ejemplo, 1);
    insertarEnListaOrdenada(ejemplo, 9);


    int tam = ejemplo.longLista();
    for(int i = 1 ; i <= tam ; i ++)
        printf("%d", ejemplo.infoLista(i));
    return 0;
}
