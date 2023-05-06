/*
Harold David Guerrero Caicedo
8976203
Estructura de Datos
Proyecto Final

*/

#include<iostream>
#include"BigInteger.cpp"

int main(){
    string cad = "1993212";
    string cad2 = "1239449";
    BigInteger numero1(cad);
    BigInteger numero2(cad2);
    numero1.add(numero2);
    for(int i = 0; i < numero1.tamanoN(); i++){
        printf("%d", numero1.info(i));
    }
    return 0;
}
