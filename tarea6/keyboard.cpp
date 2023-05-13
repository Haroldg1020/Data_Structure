#include <iostream>
#include <deque>
using namespace std;
int main(){
	string s;
    deque<char>cola;
	while(cin >> s){ // # de casos de prueba.
		
		for ( int i = 0 ; i < s.size() ; i ++ ){ // n
            //cout << i << endl;
			if(s[i] == ']'){
				
			}else if(s[i] == '['){
				int finalPalabra = s.size();  // n
				for(int j = i+1 ; j < s.size() ; j ++){ // n
					if(s[j] == '[' or s[j] == ']'){
						finalPalabra = j; // n
						j = s.size(); // n
					}
				}
				for(int j = finalPalabra-1 ; j > i ; j --){ // n
					cola.push_front(s[j]); //n
				}
				i = finalPalabra-1; // n
			}else{
				cola.push_back(s[i]); // n
			}
		}
		// cola.size() = 0
		while(not cola.empty()){ // n
			printf("%c", cola.front()); // n
			cola.pop_front(); // n
		}
        printf("\n");
	}
	
	/*
	* La complejidad total del algoritmo es O(2n) = O(n)
	* La variable i toma valores estrictamente diferentes a la 
	* variable j. Por lo que la anidacion de ciclos mantiene
	* el numero de iteraciones en n. En caso de encontrar un 
	* '[', se recorre la palabra hasta el siguiente simbolo especial
	* hacia adelante y hacia atras. Y esa seria el numero de operaciones
	* en el peor de los casos (2n).
	*/
	return 0;
}