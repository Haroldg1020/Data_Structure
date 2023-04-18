#include "lista.cpp"
#include <iostream>



int main(){
    Lista ejemplo, ejemplo2;

    
    ejemplo.insListaOrdenada(5);
    ejemplo.insListaOrdenada(10);
    ejemplo.insListaOrdenada(30);
    ejemplo.insListaOrdenada(2);
    ejemplo.insListaOrdenada(5);
    ejemplo.insListaOrdenada(5); 
    ejemplo.insListaOrdenada(10);
    ejemplo.insListaOrdenada(1);
    
    int tam = ejemplo.longLista();
    for(int i = 1 ; i <= tam ; i ++)
        printf("%d ", ejemplo.infoLista(i));



    return 0;
}
