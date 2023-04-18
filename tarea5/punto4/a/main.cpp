#include "lista.cpp"
#include <iostream>

void concatenarListas(Lista &l1, Lista &l2){
    int tam = l2.longLista();
    /*
    el siguiente ciclo hace (1 + taml1) + (2 + taml1 +1) + (3 + taml1 + 2) + ...
    = 1 + taml1 + 3 + taml1 + 5 + taml1 + 7 + taml1... (taml2-1)+taml2 + taml1
                                                        2*taml2-1
    taml1 * taml2 (pues el ciclo se repite taml2 veces) + taml2^2 (pues 1+3+5+7...+(2*n-1) = n^2)
    Conclusion: la complejidad es O(taml1*taml2 + taml2^2)
    */
    for(int i = 1 ; i <= tam ; i ++){ // tamL2 veces 
        l1.anxLista(l2.infoLista(i)); // i + taml1
    }
}

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

    concatenarListas(ejemplo, ejemplo2);
    int tam = ejemplo.longLista();
    for(int i = 1 ; i<= tam ; i++)
        printf("%d ", ejemplo.infoLista(i));
    return 0;
}
