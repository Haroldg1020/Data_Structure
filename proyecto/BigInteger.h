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
#include<list>
#include<iterator>
#include <cmath> // abs
using namespace std;

class BigInteger{
    private:
    vector<int>numero; // al usar char ocupa un byte
    bool negativo;
    
    public:
    //constructoras
    BigInteger(const string &cadena);
    BigInteger(const BigInteger &argumento);
    BigInteger(long long valor);

    //modificadoras
    void invertir();
    void add(BigInteger valor);
    void product(BigInteger valor);
    void substract(BigInteger valor);
    void quotient(BigInteger valor);
    void remainder(BigInteger valor);
    BigInteger expo(BigInteger numero, BigInteger valor);
    void pow(BigInteger valor);
    string toString();

    
    BigInteger operator+(BigInteger valor);
    BigInteger operator-(BigInteger valor);
    BigInteger operator*(BigInteger valor);
    BigInteger operator/(BigInteger valor);
    BigInteger operator%(BigInteger valor);
    
    bool operator==(const BigInteger valor)const;
    bool operator<(const BigInteger valor)const;
    bool operator<=(const BigInteger valor)const;
    /*
	* El const especifica al compilador que esta funcion NO edita el objeto.
	* Y esto importante porque en ocasiones al compilar genera problemas si no se especifica esto.
	* En especial cuando se usa con otros tipos de datos.
	* Por ejemplo, cuando use pair<BigInteger, BigInteger>, y trate de comparar los pairs
	* me pedia que los operadores binarios fueran de esta manera, es decir, que constataran que no editaban el objeto
	*/
    
    BigInteger sumarListaValores(list<BigInteger>&vector1);
    BigInteger multiplicarListaValores(list<BigInteger>&vector1);

    //analizadoras
    int info(int valor)const; //Utilizo const para poder especificar que estas funciones no editan ni adiccionan valores en el objeto. Evita errores al compilar.
    int tamanoN()const;
    bool esNegativo()const;
    BigInteger absoluteValue()const;
};



#endif
