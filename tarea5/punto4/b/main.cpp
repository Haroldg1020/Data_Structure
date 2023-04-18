#include "lista.cpp"
#include <iostream>

int main(){
    Lista ejemplo, ejemplo2;
    ejemplo.anxLista(1);
    ejemplo.anxLista(2);
    ejemplo.anxLista(3);
    ejemplo.anxLista(4);
    ejemplo.anxLista(5);
    ejemplo2.anxLista(6);
    ejemplo2.anxLista(7);
    ejemplo2.anxLista(8);
    ejemplo2.anxLista(9);
    ejemplo2.anxLista(10);

    Lista unida = ejemplo + ejemplo2;
    int tam = unida.longLista();
    for(int i = 1 ; i <= tam ; i ++)
        printf("%d ", unida.infoLista(i));
    Lista otra = unida + unida;
    tam = otra.longLista();
    printf("\n");
    for(int i = 1 ; i <= tam ; i ++)
        printf("%d ", otra.infoLista(i));



    return 0;
}
