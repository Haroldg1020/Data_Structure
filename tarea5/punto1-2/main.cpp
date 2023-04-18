#include "lista.cpp"
#include <iostream>
int contarOcurrencias(Lista l, int v){ // Complejidad total: O(n^2)

    int ocurrencias = 0, sizeLista = l.longLista(); // 2
    /*
        La complejidad exacta del siguiente ciclo es (n*(n+1))/2
    */
    for(int i = 1 ; i <= sizeLista ; i ++){ // n
        if(l.infoLista(i) == v){ // i
            ocurrencias++; // 1
        }
    }
    return ocurrencias;
}
Lista obtenerMenores(Lista l, int v){ // O(n^2)
    Lista resultado; // 1
    int sizeLista = l.longLista(); // 1

    /*
        La complejidad exacta del siguiente ciclo es (n*(n+1))/2 + n^2
    */
    for(int i = 1 ; i <= sizeLista ; i ++){ // n
        int temp = l.infoLista(i); //i
        if(temp < v){ // 1
            resultado.anxLista(temp); // n
        }
    }
    return resultado;
}



int main(){
    Lista ejemplo;
    ejemplo.anxLista(3);
    ejemplo.anxLista(5);
    ejemplo.anxLista(10);
    ejemplo.anxLista(30);
    ejemplo.anxLista(7);
    ejemplo.anxLista(5);
    ejemplo.anxLista(5); // 5 se repite 3 veces
    ejemplo.anxLista(10); // 10 se repite 2 veces
    cout << contarOcurrencias(ejemplo, 5) << "\n"; // 3
    cout << contarOcurrencias(ejemplo, 10) << "\n"; // 2
    cout << contarOcurrencias(ejemplo, 3) << "\n"; // 1
    cout << contarOcurrencias(ejemplo, 0) << "\n"; // 0

    cout << endl;

    Lista resultado = obtenerMenores(ejemplo, 10);
    int sizeResultado = resultado.longLista();
    for(int i = 1 ; i <= sizeResultado ; i ++)
        cout << resultado.infoLista(i) << " "; // 3 5 7 5 5

    cout << endl;

    resultado = obtenerMenores(ejemplo, 7);
    sizeResultado = resultado.longLista();
    for(int i = 1 ; i <= sizeResultado ; i ++)
        cout << resultado.infoLista(i) << " "; // 3 5 5 5
    cout << endl;

    return 0;
}
