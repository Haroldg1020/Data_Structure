/*
Harold David Guerrero Caicedo
8976203
Estructura de Datos
Proyecto Final

*/


#ifndef __BIGINTEGER_H
#define __BIGINTEGER_H

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class BigInteger{
    private:
    vector<int>numero; // al usar char ocupa un byte

    
    public:
    //constructoras
    BigInteger(const string &cadena);
    BigInteger(const BigInteger &argumento);

    //modificadoras
    void add(BigInteger& valor);
    void product(BigInteger& valor);
    void substract(BigInteger& valor);
    void quotient(BigInteger& valor);
    void remainder(BigInteger& valor);
    void pow(BigInteger& valor);
    string toString(BigInteger& valor);

    
    BigInteger operator+(BigInteger& valor);
    BigInteger operator-(BigInteger& valor);
    BigInteger operator*(BigInteger& valor);
    bool operator==(BigInteger& valor);
    bool operator<(BigInteger& valor);
    bool operator<=(BigInteger& valor);

    //analizadoras
    int info(int valor)const; //Utilizo const para poder especificar que estas funciones no editan ni adiccionan valores en el objeto. Evita errores al compilar.
    int tamanoN()const; 
};

BigInteger sumarListaValores(vector<BigInteger>&vector1); //vector o lista?
BigInteger multiplicarLista (vector<BigInteger>&vector1);

#endif