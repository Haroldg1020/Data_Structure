/*
Harold David Guerrero
Estructura de Datos
Tarea 7

*/
#include <iostream>
#include <stack>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>
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
    while(! aux.empty()){
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

void evaluarExpresion(list<char>&lista){
    stack<int>aux;
    list<int>::iterator i;
    for(i = lista.begin(); i != lista.end(); i++){

    }
}


int verificarRepetidos(queue<char>col){

    vector<bool>m;
    int cont = 0;
    for(int i = 0; i < 27; i++){
        m.push_back(0);
    }
    while(col.empty() != false){
        col.front();
        if(m[col.front() - 'a'] == true){
            cont++;
        }
        else{
            m[col.front() - 'a'] = true;
        } 
        col.pop();
    }
    return cont;
}


map<char, vector<int> > obtenerPosicionesOcurrencias(string cad){
	map<char, vector<int> >mapa; // {'a', {1, 2, 3}}
	for(int i = 0 ; i < (int)cad.size() ; i ++)mapa[cad[i]].push_back(i);
	return mapa;
}

vector<list <pair<int, int> >> crearMatrizDispersa(vector<vector <int>> matriz){
    vector<list <pair<int, int> >> resultado;
    pair<int, int> parejas;
    for(int i = 0; i < matriz.size(); i++){
        list<pair<int, int>> lis1;
        for(int j = 0; j < matriz[i].size(); j++){
            if(matriz[i][j] != 0){
                parejas.first = matriz[i][j];
                parejas.second = i;
                lis1.push_back(parejas);
            }
        }
        resultado.push_back(lis1);
    }
    return resultado;
}
/*
En el siguiente código podemos ver que tiene una complejidad total de log2(n)*n, eso debido al la función sort. 
Los demas ciclos se recorren n veces dependiendo del tamaño que tenga la cola y esta sera igual al tamaño del vector.
*/
bool verificarRepetidosCola(queue<int>cola){
    vector<int>vect1; // 1
    bool ans = false; // 1
    while(cola.empty() != true){ // n
        vect1.push_back(cola.front()); //n
        cola.pop(); //n
    }
    sort(vect1.begin(), vect1.end()); //log2(n)*n
    for(int i = 0; i < vect1.size()-1; i++){ // n
        if(vect1[i] == vect1[i+1]){ // n
            ans = true; // 1
            i = vect1.size(); // 1
        }
    }
    return ans; // 1
}

/*
La complejidad total es N veces, ya que se recorre N veces dependiendo del tamaño que tenga la col.
*/

stack<int> filtrarColaNParesCola(queue<int>col, int N){
    stack<int>nPares; //1
    int aux; //1
    while(col.empty() != true){ //n
        if(col.front() % 2 == 0){ //n
            nPares.push(col.front()); //n
        }
        col.pop(); //n

    }
    aux = nPares.size() - N; // 1
    while(aux--){ // n 
        nPares.pop(); // n
    }
    return nPares;//1
}
