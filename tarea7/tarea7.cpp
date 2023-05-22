#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


void eliminarPosicionesPila(stack<int>&pil, list<int>&l){
    list<int>::iterator i;
    stack<int>aux;
    int pos = 0;
    /*
    La complejidad del siguiente codigo es O(n), porque el numero de iteraciones que se haceb depende del tamaño que tenga la lista y la pila. 
    Es lineal.
    */
    for(i = l.begin(); i != l.end(); i++){
        for(pos ; pos < *i; pos++){
            aux.push(pil.top());
            pil.pop();
        }
        pil.pop();
        pos++;
    }
    while(not aux.empty()){
        pil.push(aux.top());
        aux.pop();
    }
}

void ordenarConMonticulo(vector<int>& vec) {
    make_heap(vec.begin(), vec.end()); // Convertir el vector en un montículo // make_heap es lineal
    vector<int>respuesta;
    while (!vec.empty()) {
        pop_heap(vec.begin(), vec.end()); // Mover el elemento máximo al final // pop_heap es logaritmico
        int maxElemento = vec.back(); // Obtener el elemento máximo
        vec.pop_back(); // Eliminar el elemento máximo del montículo
        respuesta.push_back(maxElemento);
    }
    vec = respuesta;
    //reverse(vec.begin(), vec.end()); // de menor a mayor

    // Al final la complejidad total del siguiente codigo es n*log(n)
}

bool verificarOrdenadoCola(queue<int>cola){
    int variable;
    bool ansMayor = true;
    bool ansMenor = true;
    bool ans;

    for(int i = 0; i < cola.size()-1; i++){
        cola.push(cola.front());
        variable = cola.front();
        cola.pop(); 
        if(variable < cola.front()){
            ansMayor = false;
        }
        if(variable > cola.front()){
            ansMenor = false;
        }
        
    }
    return ansMayor or ansMenor;
}

int obtenerMenorCosto(vector<int>vect1){
    int total = 0;
    sort(vect1.begin(), vect1.end());
    for(int i = 0; i < vect1.size()-1; i++){
        vect1[i+1] += vect1[i];
        total += vect1[i+1];
    }
    return total;
}

