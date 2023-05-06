/*
Harold David Guerrero Caicedo
8976203
Estructura de Datos
Proyecto Final

*/

#include "BigInteger.h"


int BigInteger::info(int valor)const{
    return numero[valor];
}
int BigInteger::tamanoN()const{
    return numero.size();
}

BigInteger::BigInteger(const string &cadena){
    int numeroR;
    for(int i = cadena.size()-1; i >= 0; i--){
        numeroR = cadena[i] - '0'; //resto un caracter con '0'(48)
        numero.push_back(numeroR);
    }
}

BigInteger::BigInteger(const BigInteger &argumento){
    for(int i = 0; i < argumento.tamanoN(); i++){
        numero.push_back(argumento.info(i));
    }
    
}

void BigInteger::add(BigInteger& valor){
    for(int i = 0; i < numero.size(); i++){
        numero[i] += valor.info(i);
        if(numero[i] >= 10){
            numero[i]-= 10;
            if(i == numero.size()-1){
                numero.push_back(1);
            }
            else{
            numero[i+1] += 1;
            }
        }
        if(i == valor.tamanoN() -1){
            i = numero.size();
        } 
    }
    for(int i = numero.size(); i < valor.tamanoN(); i++){
        numero.push_back(valor.info(i));
    }
}