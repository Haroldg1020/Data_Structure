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
    n1 = tamaño lista
    n2 = tamaño stack
    La complejidad del siguiente codigo es O(n), porque el numero de iteraciones que se haceb depende del tamaño que tenga la lista y la pila. 
    Es lineal.
    */
    for(i = l.begin(); i != l.end(); i++){ // n1
        for(pos ; pos < *i; pos++){ // n2
            aux.push(pil.top()); // n2-1
            pil.pop(); //n2-1
        }
        pil.pop(); //n1
        pos++; //n1
    }
    while(! aux.empty()){ // se recorre mientras aux no este vacio. n2+1
        pil.push(aux.top()); // n2
        aux.pop(); // n2
    }
}


void ordenarConMonticulo(vector<int>& vec) {
    make_heap(vec.begin(), vec.end()); // n ,Convertir el vector en un montículo // make_heap es lineal
    vector<int>respuesta; // 1
    while(! vec.empty()){ // n+1
        pop_heap(vec.begin(), vec.end()); // n*log(n), Mover el elemento máximo al final y ademas vuelve a armar el arbol con el resto de elementos sin el maximo // pop_heap es logaritmico
        int maxElemento = vec.back(); // n, Obtener el elemento máximo
        vec.pop_back(); // Eliminar el elemento máximo del montículo
        respuesta.push_back(maxElemento); //n
    }
    vec = respuesta; // 1
    //reverse(vec.begin(), vec.end()); // de menor a mayor

    // Al final la complejidad total del siguiente codigo es n*log(n)
}

/*
La complejidad del siguiente codigo es O(n), ya que solo recorremos el tamaño de la cola y este depende de la cantidad de números que tenga.
*/
bool verificarOrdenadoCola(queue<int>cola){
    int variable; // 1
    bool ansMayor = true;// 1
    bool ansMenor = true;// 1

    while(0 < cola.size()-1){ // n
        cola.push(cola.front()); // n
        variable = cola.front(); // n
        cola.pop(); // n
        if(variable < cola.front()){ // n
            ansMayor = false; // n
        }
        if(variable > cola.front()){ // n
            ansMenor = false; // n
        }
        
    }
    return ansMayor || ansMenor; // 1
}

/*
El siguiente código tiene complejidad de O(log2(n)*n), la complejidad del sort esta definida como log2(n)*n y el ciclo for que tenemos en el código se recorre según el tamaño del vector.
*/
int obtenerMenorCosto(vector<int>vect1){
    int total = 0; // 1
    sort(vect1.begin(), vect1.end()); // log2(n)*n
    for(int i = 0; i < vect1.size()-1; i++){ // n
        vect1[i+1] += vect1[i]; // n-1
        total += vect1[i+1]; // n-1
    }
    return total; // 1
}

void evaluarExpresion(list<char>&lista){
    stack<int>aux;
    list<int>::iterator i;
    for(i = lista.begin(); i != lista.end(); i++){

    }
}

/*
El siguiente codigo tiene una complejidad de O(n), esta esta en el ciclo while ya que depende de los datos que tenga la cola. En el ciclo for se itera 27 veces simulando un alfabeto.
*/
int verificarRepetidos(queue<char>col){

    vector<bool>m; // 1
    int cont = 0; // 1
    for(int i = 0; i < 27; i++){ // 27+1
        m.push_back(0); // 27
    }
    while(col.empty() == false){ // n
        if(m[col.front() - 'a'] == true){ // n        
            cont++; // n
        }
        else{ // n
            m[col.front() - 'a'] = true; // n
        } 
        col.pop(); // n
    }
    return cont; // 1
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
