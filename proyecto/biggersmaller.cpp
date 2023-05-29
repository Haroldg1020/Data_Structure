/*
Harold David Guerrero Caicedo
8976203
Estructura de Datos
Proyecto Final

*/
/*

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class BigInteger{
    private:
    vector<int>numero; // al usar char ocupa un byte
    bool negativo;

    public:
    int info(int valor)const; //Utilizo const para poder especificar que estas funciones no editan ni adiccionan valores en el objeto. Evita errores al compilar.
    int tamanoN()const;
    bool esNegativo()const;
    BigInteger(const string &cadena);
    BigInteger(const BigInteger &argumento);
    BigInteger(long long valor);
    bool operator==(const BigInteger valor)const;
    bool operator<(const BigInteger valor)const;
    string toString();


};

bool BigInteger::esNegativo()const{
    return negativo; // 1
}
int BigInteger::info(int valor)const{
    return numero[valor];
}
int BigInteger::tamanoN()const{
    return numero.size();
}
BigInteger::BigInteger(long long valor){
	numero.clear();
    int numeroR;
    negativo = false;
    string aux;
    if(valor < 0){
        negativo = true;
    }
    valor = abs(valor);
    
    aux = to_string(valor);
    for(int i = aux.size()-1; i >= 0; i--){
        numeroR = aux[i] - '0';
        numero.push_back(numeroR);
    }

    
}
BigInteger::BigInteger(const string &cadena){
	numero.clear();
    int numeroR = 1;
    negativo = false;
    if(cadena[0] == '-'){
        negativo = true;
    }
    
    for(int i = cadena.size()-1; i >= 1; i--){
        numeroR = cadena[i] - '0'; //resto un caracter con '0'(48)
        numero.push_back(numeroR);
    }
    if(!negativo)numero.push_back(cadena[0]-'0');
}
BigInteger::BigInteger(const BigInteger &argumento){
	numero.clear();
    negativo = argumento.esNegativo();
    for(int i = 0; i < argumento.tamanoN(); i++){
        numero.push_back(argumento.info(i));
    }

}
string BigInteger::toString(){
    string s ="";
    if(negativo)s.push_back('-');
    for(int i = numero.size()-1; i >= 0; i--){
        s += to_string(numero[i]);
    }
    return s;
}
bool BigInteger::operator==(const BigInteger valor)const{ // O(n).
    bool ans = true;
    if(numero.size() != valor.tamanoN() || valor.esNegativo() != negativo){ // 1
        ans = false; // 1
    }
    else{
        for(int i = 0; i < numero.size(); i++){ // O(n)
            if(numero[i] != valor.info(i)){ // n
                ans = false; // n
            }
        }
    }
    return ans; 
}

bool BigInteger::operator<(const BigInteger valor)const{
    bool ans = false;
    if(numero.size() < valor.tamanoN()){
        ans = true;
        if(valor.esNegativo() == true){
            ans = false;
        }
        
    }
    else if(numero.size() > valor.tamanoN()){
        ans = false;
        if(negativo == true){
            ans = true;
        }
        
    }
    else{
        for(int i = numero.size()-1; i >= 0; i--){
			
            if(numero[i] < valor.info(i)){
                ans = true; 
                i = 0;
                if(negativo != false && valor.esNegativo() == true){
                    ans = false;
                }
                
            }
            else if(numero[i] > valor.info(i)){
                ans = false;
                i = 0;
                if(negativo != false && valor.esNegativo() == true){
                    ans = true;
                }
                
            }
        }
        if(negativo == true && valor.esNegativo() == false){
            ans = true;
        }
        if(negativo == false && valor.esNegativo() == true){
            ans = false;
        }
    }
    return ans;
}

/*
Función main
Entrada: Lectura de números desde la entrada estándar.
Salida: Impresión de resultados en la salida estándar, imprime si los números son iguales, si uno es mayor o si es menor.
Descripción: Esta función realiza la lectura de pares de números desde la entrada estándar y compara sus valores. Luego imprime el resultado de la comparación en la salida estándar.
*/

int main(){
    string numero1; // 1
    string numero2; // 1
    int i; // 1
    int n = 1; // 1
    while(cin >> numero1 >> numero2){ // se va a ejercutar mientras reciba casos de prueba, osea t veces

        string entero1; //t
        string decimal1; //t
        string entero2; //t
        string decimal2; //t
        cout<<"Case "<<n<<": "; //t
        pair<BigInteger, BigInteger>pareja1 = {0, 0}; // t
        pair<BigInteger, BigInteger>pareja2 = {0, 0}; // t 
        // Se obtiene la parte entera y la parte decimal del primer numero
        for(i = 0; numero1[i] != '.'; i++){ // se recorre hasta que encuentre un ".", t*n
            entero1.push_back(numero1[i]); // t*n
        }
        i++; //t
        for(i; i < numero1.size(); i++){ // se itera dependiendo de la cantidad de números que tenga numero1. t veces
            decimal1.push_back(numero1[i]); // se hace t*n veces
        }
        // Se obtiene la parte entera y decimal del segundo numero
        for(i = 0; numero2[i] != '.'; i++){ // se recorre n veces hasta que se encuentre un "."
            entero2.push_back(numero2[i]); // se hace t*n veces

        }
        i++; // se ejecuta dependiendo del número de casos de entrada, t
        for(i; i < numero2.size(); i++){ // se itera dependiendo de la cantidad de números que tenga numer2. n veces.
            decimal2.push_back(numero2[i]); // se hace t*n veces
        }
        // Se ajustan las longitudes decimales.
        while(decimal1.size() < decimal2.size()){ // se ejecuta mientras el tamaño decimal1 sea menor que decimal2, t
            decimal1.push_back('0'); // se hace t*n veces
        }
        while(decimal1.size() > decimal2.size()){ // se ejecuta mientras el tamaño decimal2 sea menor que decimal1, t
            decimal2.push_back('0'); // se hace t*n veces
        }
        // Se eliminan los ceros no significativos en la parte decimal.  
        reverse(decimal1.begin(), decimal1.end()); // se hace t veces
        while(decimal1.back() == '0' && decimal1.size() >= 2){ // se ejecuta mientras los números de atras de decimal1 sean 0 y mientras el tamaño de este sea mayor o igual a 2, n
            decimal1.pop_back(); // se hace t*n veces
        }
        reverse(decimal1.begin(), decimal1.end()); // se hace t veces


        reverse(decimal2.begin(), decimal2.end()); // se hace t veces
        while(decimal2.back() == '0' && decimal2.size() >= 2){ // se ejecuta mientras los numeros de atras de decimal2 sean 0 y mientras el tamaño de esta sea mayor o igual a 2, n
            decimal2.pop_back(); // se hace t*n veces
        }
        reverse(decimal2.begin(), decimal2.end()); // se hace t veces       

        // Asigno los valores a las parejas de enteros y decimales
        pareja1.first = entero1; // n
        pareja1.second = decimal1; // n

        pareja2.first = entero2; // n
        pareja2.second = decimal2; // n
        // Comparo las parejas de números
        if(pareja1 < pareja2){ // n
            cout<<"Smaller"<<endl; // n

        }
        else if(pareja1 > pareja2){ // n
            cout<<"Bigger"<<endl; // n

        }
        else{ // n
            cout<<"Same"<<endl; // n

        }
        n++; // n
    }
    return 0;    
}
