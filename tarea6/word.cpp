#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

/*
    Sea n = 1000 el numero de palabras en puzzle (casos) y tambien el numero de 
    palabras en el diccionario
    Tambien tomaremos l = 25 como el tamano de estas palabras.

*/


    vector<string>alfabeto; 
    vector<string>puzzle;
    string palabras = "0";
    string palabras2 = "0";
    int cont = 0, x;
    string comp1, comp2, aux;

    while(palabras != "#"){ // O(n * l * log2 l)
        cin>>palabras;
        if(palabras != "#"){
            sort(palabras.begin(), palabras.end());
            alfabeto.push_back(palabras);     
        }
    }
    cin.ignore();
    while(palabras2 != "#"){ // O(n * l * log2(l))
        getline(cin, palabras2);
        if(palabras2 != "#"){
            aux = "";
        for(int i = 0; i < palabras2.size(); i+=2){
            aux += palabras2[i];
        }
        sort(aux.begin(), aux.end());
        puzzle.push_back(aux);
        }
        
    }
    aux = "";
    for(int i = 0; i < puzzle.size(); i++){ // n
        for(int j = 0; j < alfabeto.size(); j++){ // n*n
            x = 0;
            for(int l = 0; l < alfabeto[j].size(); l++){ // l
                for(int z = x; z < puzzle[i].size() ; z++){ // l
                   if(alfabeto[j][l] == puzzle[i][z]){
                    x = z+1;
                    z = puzzle[i].size();
                    aux += alfabeto[j][l];
                   } 
                }
                
         
            } 
        if(aux == alfabeto[j]){
          cont++; 
        }
        aux = "";
        }
        printf("%d\n", cont);
        cont = 0;
        
    }
    return 0;
}