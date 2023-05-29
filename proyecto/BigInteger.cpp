/*
Harold David Guerrero Caicedo
8976203
Estructura de Datos
Proyecto Final

*/

#include "BigInteger.h"
/*
Función esNegativo
Entrada: Ninguna.
Salida: Un valor booleano.
Descripción: Esta función devuelve un valor booleano que indica si el objeto BigInteger actual es negativo o no.
*/
bool BigInteger::esNegativo()const{
    return negativo; // 1 
}



void BigInteger::invertir(){
	negativo = !negativo; // 1
}
BigInteger BigInteger::absoluteValue()const{
	BigInteger ret = *this; // n
	if(ret.esNegativo())ret.invertir(); // 1
	return ret; // 1
}

bool BigInteger::operator==(const BigInteger valor)const{ // O(n).
    bool ans = true; // 1
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
    return ans; // 1
}

bool BigInteger::operator<(const BigInteger valor)const{
    bool ans = false; // 1
    if(numero.size() < valor.tamanoN()){ //1
        ans = true; //1
        if(valor.esNegativo() == true){ //1
            ans = false; //1
        }
        
    }
    else if(numero.size() > valor.tamanoN()){ //1
        ans = false; //1
        if(negativo == true){ //1
            ans = true; //1
        }
        
    }
    else{
        for(int i = numero.size()-1; i >= 0; i--){ //n
			
            if(numero[i] < valor.info(i)){ //n
                ans = true; //n
                i = 0; //n
                if(negativo != false && valor.esNegativo() == true){ //n
                    ans = false; //n
                }
                
            }
            else if(numero[i] > valor.info(i)){ //n
                ans = false; //n
                i = 0; //n
                if(negativo != false && valor.esNegativo() == true){ //n
                    ans = true; //n
                }
                
            }
        }
        if(negativo == true && valor.esNegativo() == false){ //n
            ans = true; //n
        }
        if(negativo == false && valor.esNegativo() == true){ //n
            ans = false; //n 
             
        }
    }
    return ans; //1
}

bool BigInteger::operator<=(const BigInteger valor)const{
    bool ans; //1
    if(*this < valor || *this == valor){ //1
        ans = true; //1
    }
    else{ //1
        ans = false; //1
    }
    return ans; //1
}



int BigInteger::info(int valor)const{
    return numero[valor]; // 1
}
int BigInteger::tamanoN()const{
    return numero.size(); // 1
}
/*
Constructor BigInteger
Entrada: Un valor entero largo (long long).
Salida: Ninguna.
Descripción: Este constructor crea un objeto BigInteger a partir del valor entero largo proporcionado. El valor se almacena en forma de dígitos individuales dentro del objeto BigInteger.
*/
BigInteger::BigInteger(long long valor){
	numero.clear(); // 1
    int numeroR; // 1
    negativo = false; // 1
    string aux; // 1
    if(valor < 0){ // 1
        negativo = true; // 1
    }
    valor = abs(valor); // 1
    
    aux = to_string(valor); // 1
    for(int i = aux.size()-1; i >= 0; i--){ // n, depende del tamaño de aux. Se recorre de atras hacia adelante.
        numeroR = aux[i] - '0'; // n
        numero.push_back(numeroR); // n
    }
}
/*
Constructor BigInteger
Entrada: Una cadena de caracteres (string).
Salida: Ninguna.
Descripción: Este constructor crea un objeto BigInteger a partir de una cadena de caracteres proporcionada. La cadena se interpreta como un número y se almacena en forma de dígitos individuales dentro del objeto BigInteger.
*/
BigInteger::BigInteger(const string &cadena){
	numero.clear(); // 1
    int numeroR = 1; // 1
    negativo = false; // 1
    if(cadena[0] == '-'){ // 1
        negativo = true; // 1
    }
    
    for(int i = cadena.size()-1; i >= 1; i--){ // n veces depende del tamaño de la cadena
        numeroR = cadena[i] - '0'; //resto un caracter con '0'(48) n
        numero.push_back(numeroR); // n
    }
    if(!negativo)numero.push_back(cadena[0]-'0'); // 1
}
/*
Constructor BigInteger
Entrada: Un objeto BigInteger (referencia constante).
Salida: Ninguna.
Descripción: Este constructor crea un nuevo objeto BigInteger a partir de otro objeto BigInteger proporcionado. El nuevo objeto es una copia exacta del objeto de entrada.
*/

BigInteger::BigInteger(const BigInteger &argumento){ // O(n)
	numero.clear(); // 1
    negativo = argumento.esNegativo(); // 1
    for(int i = 0; i < argumento.tamanoN(); i++){ // n veces depende del tamaño de agumento
        numero.push_back(argumento.info(i)); // n
    }
}

void BigInteger::add(BigInteger valor){ // O(n)
	/*Suma al objeto actual el valor que le pasan como argumento:
	 * Si son de igual signo:
	 * Recorre desde la cifra menos significativa a la mas significativa, las va sumando, y si se pasan de 10, se le suma al siguiente 1.
	 * Y si son de diferente signo hace uso de la funcion substract.
	*/
	if(valor.esNegativo() == negativo){ // Los signos de los numeros son iguales
		for(int i = 0; i < numero.size(); i++){ // Recorrer el objeto actual O(n)
			if(i == valor.tamanoN() ){ // Si se llega al final del valor.
				while(i < numero.size() && numero[i] >= 10){ // Para verificar si hay que pasarle al siguiente.
					numero[i]-=10;
					if(i == numero.size()-1){
						numero.push_back(1);
					}
					else{
						numero[i+1] += 1;
					}
					i++;
				}
				i = numero.size();
			}
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
			 
		}
		for(int i = numero.size(); i < valor.tamanoN(); i++){ // Si valor es mas grande, lo terminamos de recorrer sumando con 0.
			numero.push_back(valor.info(i));
		}
		negativo = valor.esNegativo();
	}else{
		bool negativoAns = false;
		/*
		Si los signos son distintos, se resta el del mayor valor absoluto con el menor (en valor absoluto), y se mantiene el signo del mayor.
		* 
		* 
		* this es un puntero al objeto donde estamos. Por lo tanto para acceder a sus miembros, es necesario usar la sintaxis de 
		* this->miembro. Y para tomar el objeto como tal (y poder usar los operadores definidos) usamos *this.
		*/
		if((this->absoluteValue()) < valor.absoluteValue()){ // Si valor tiene mayor valor absoluto
			
			negativoAns = valor.esNegativo(); // guardo el signo de valor
			*this = ((valor.absoluteValue())-(this->absoluteValue()));  // resto los valores absolutos de valor y el objeto actual
			negativo = negativoAns; // El signo de la respuesta es el valor.
		}else if(valor.absoluteValue() < this->absoluteValue()){ // Misma logica de arriba.
			negativoAns = negativo;
			*this = this->absoluteValue();
			this->substract(valor.absoluteValue());
			negativo = negativoAns;
		}else{ // Son de igual tamano, la suma da 0.
			*this = 0;
		}
		
	}
}

void BigInteger::product(BigInteger valor){ // O(n^2)
	if(*this == BigInteger(0) or valor == BigInteger(0)){ // Si alguno es 0, el resultado da 0.
		*this = BigInteger(0);
	}else{
		vector<int>aux1;
		int resp;
		for(int  i = 0; i < numero.size() + valor.tamanoN()+2; i++){ // Llenamos un vector con los 0 necesarios para guardar la respuesta
			aux1.push_back(0); // n
		}
		// Este es el mismo algoritmo que usamos los humanos para la multiplicacion, multiplicando cada cifra de un numero, con cada cifra del otro.
		for(int i = 0; i < numero.size(); i++){ // n
			for(int j = 0; j < valor.tamanoN(); j++){ // n*n
				resp = numero[i] * valor.info(j);
				aux1[j+i] += resp;
				if(aux1[j+i] >= 10){ // pasarle las decenas del resultado de la multiplicacion de dos cifras, al resultado en la siguiente cifra.
					aux1[j+i+1] += aux1[j+i] / 10;
					aux1[j+i] = aux1[j+i] % 10;
				}
			}
		}
		while(aux1.back()==0)aux1.pop_back(); // n
		numero = aux1;
		negativo = (valor.esNegativo() != negativo); // Si los signos son diferentes da negativo.
	}
}


void BigInteger::substract(BigInteger valor){ // O(n).
	if(valor.esNegativo()){ // 10-(-20) = 10 + 20
		this->add(valor.absoluteValue()); // Se llama a la funcion suma, pues la resta con un negativo es una suma.O(n).
	}else if(negativo){ // -10-20 = -(10+20)
		*this = (this->absoluteValue()+valor); // Se suman los valores absolutos O(n).
		this->invertir(); // El signo es negativo.
	}else{ // ambos son positivos.
		if(valor < *this){// Que no de negativo  25 - 10
			/*
			 * Aun que hay dos ciclos, el segundo se encarga de recorrer las cifras que faltaron, para que verifique
			 * si al pedir prestado al siguiente, algun digito quedo por debajo de 0. 
			 */
			for(int i = 0; i < numero.size(); i++){ // O(n) Recorre el mas grande. 
				if(i == valor.tamanoN()){ // Si llega al final del segundo numero
					while(i < numero.size()+1 && numero[i] < 0){ // Pedir prestado si hace falta a los siguientes
						numero[i] += 10;
						numero[i+1] -= 1;
						i++;
					}
					i = numero.size(); // Se termina el ciclo.
				}
				else{
					if(numero[i] >= valor.info(i)){ // Resta cifra por cifra.
						numero[i] -= valor.info(i);
					}
					else{ // Le tiene que pedir prestado al siguiente.
						numero[i] += 10;
						numero[i+1] -= 1;
						numero[i] -= valor.info(i);
					}
				}
			}
			while(numero.back() == 0 and numero.size() >= 2)numero.pop_back(); // O(n).
		}else{ // Si da negativo, entonces que haga la resta al reves:   10-20 = -(20-10)
			if(valor == *this){
				*this = 0;
			}else{ // 10-20 = -(20-10)
				*this = (valor-*this); // O(n)
				this->invertir();
			}
		}
	}
}


void BigInteger::quotient(BigInteger valor){ // O(n*10) = O(n^2).
    BigInteger t = 0;
    bool flag = true;
    string respuesta="";
    bool neg = (valor.esNegativo() != negativo); // Si son diferentes los signos, es negativo el resultado
    // Guardamos antes el signo para poderlos operar como positivos:
    *this = this->absoluteValue(); 
	valor = valor.absoluteValue();
    if(*this<valor){
        numero = {0};
        negativo = false;
    }
    else if (valor == BigInteger(0)){
        printf("Error, no se puede dividir por 0.");
        numero = {0};
        negativo = false;
    }
    else{
        int i;
        // Agarramos desde la cifra mas significativa, hasta que el numero que vamos a dividir sea mayor que el divisor.
        for(i = numero.size()-1; i >= 0 && flag == true; i--){ // O(n).
            t = (t* BigInteger(10) );
            t = t + BigInteger(numero[i]);
            if(valor <= t){
                flag = false;
                i++;
                
            }    
        }
        // A partir de aqui, ya podemos ir "bajando" cifra por cifra del dividendo.
        for(i ; i >= 0; i--){ // O(n)
            long long c = 9; // n
            for(c ; c >= 0; c--){ // O(n*10) = O(n).
				// O(n*10*n) = O(n^2) pues la multiplicacion tiene complejidad del producto del largo de sus factores
				// y en este caso c tiene un tamano de 1 digito.
                if(BigInteger(c) * valor <= t){ // O(n*10*n) = O(n^2)
                    respuesta += '0'+c;
                    
                    BigInteger aux = BigInteger(c) * valor; // O(n*10*n) = O(n^2).
                    t = t - aux; // O(n^2)
                    c = -1;
                    if(i >= 1){ // Verificar si queda otra cifra por bajar.
                        t = t* BigInteger((long long) 10) + BigInteger(numero[i-1]); // n^2.
                    }
                }
            }
        }
        numero.clear(); // Limpiamos el numero para guardar la respuesta.
        for(int j = respuesta.size()-1; j >= 0 ; j--){  // O(n)
            numero.push_back(respuesta[j]-'0'); // respuesta es un string, pasamos los caracteres a enteros.
        }
        negativo = neg; // es negativo si los signos son diferentes.
    }
}

void BigInteger::remainder(BigInteger valor){ // O(n^2).
	/*
	 * El algoritmo es exactamente el mismo al de la division, pero el resultado es lo que sobro en la variable t.
	 */
    BigInteger t = BigInteger("0");
    string resp;
    bool flag = true;
    string respuesta;
    bool neg = (valor.esNegativo() != negativo); // Si son diferentes los signos, es negativo el resultado.
    *this = this->absoluteValue();
	valor = valor.absoluteValue();
    if(valor.tamanoN() == 1 && valor.info(0) == 0){
        printf("Error, no se puede dividir por 0.");
    }
    else{
        int i;
        for(i = numero.size()-1; i >= 0 && flag == true; i--){
            t = t* BigInteger((long long) 10) + BigInteger(numero[i]);
            if(valor <= t){
                flag = false;
                i++;
                
            }    
        }
        for(i ; i >= 0; i--){
            long long c = 9;
            for(c ; c >= 0; c--){
                if(BigInteger(c) * valor <= t){
                    BigInteger aux = BigInteger(c) * valor;
                    t = t - aux;
                    c = -1;
                    if(i >= 1){
                        t = t* BigInteger((long long) 10) + BigInteger(numero[i-1]);
                    }
                }
            }
        }
        respuesta = t.toString(); // La respuesta es lo que sobro en t.
        numero.clear();
        for(int j = respuesta.size()-1; j >= 0 ; j--){
            numero.push_back(respuesta[j]-'0');
        }
        negativo = neg; // Si son diferentes los signos, es negativo.
        
    }
}
/*
Función toString
Entrada: Ninguna.
Salida: Una cadena de caracteres (string).
Descripción: Esta función convierte el objeto BigInteger en una cadena de caracteres que representa su valor.
*/
string BigInteger::toString(){ // O(n)
    string s =""; // 1
    if(negativo)s.push_back('-'); // 1
    for(int i = numero.size()-1; i >= 0; i--){ // n veces, depende del tamaño de numero
        s += to_string(numero[i]); // n
    }
    return s; // 1
}
/*
Función expo
Entrada: Dos objetos BigInteger (base y valor).
Salida: Un objeto BigInteger.
Descripción: Esta función realiza la operación de exponente para calcular la potencia de la base elevada al valor (exponente) proporcionado. Devuelve el resultado como un objeto BigInteger.

*/
BigInteger BigInteger::expo(BigInteger base, BigInteger valor){ // log2(n)*n^2.
	/*
	 * La complejidad es log2(e)*n^2. Siendo e = valor (exponente), y n = el tamano de los numeros que multiplicamos.
	 */
    BigInteger ans = 0;
    BigInteger mitad = 0;
    if(valor == BigInteger(1)){ // Caso base: base^1 = base.
        ans = base;
    }
    else{
		// Dividimos el exponente entre dos
        mitad = valor/BigInteger(2);
        ans = expo(base, mitad); // Hallamos el resultado de nuestra base elevada a la mitad de nuestro exponente
        ans = ans*ans; // Multiplicamos este resultado. (complejidad multiplicacion: n^2.)
        if(valor % BigInteger(2) == BigInteger(1)){ // Si el exponente es impar... (complejidad division: n^2.)
            ans = ans*base; // Tenemos que multiplicar lo que nos falto (multiplicar por base^1) complejidad multiplicacion: n^2.
        }
    }
    return ans;
}
/*
Función pow
Entrada: Un objeto BigInteger (valor).
Salida: Ninguna.
Descripción: Esta función realiza la operación de potencia para elevar el objeto BigInteger actual a la potencia especificada por el valor proporcionado. Modifica el objeto BigInteger actual con el resultado.
*/
void BigInteger::pow(BigInteger valor){ // O(log2(n)*n^2).
	// La exponenciacion solo va a estar definida para el exponente en los enteros positivos.
    bool sign = negativo; // 1
    *this = expo(this->absoluteValue(), valor); // Operamos con el valor absoluto. O(log2(n)*n^2).
    if(valor%2==1){ // si el exponente es impar se mantiene el signo inicial.
		negativo = sign;
	}
}

BigInteger BigInteger::operator+(BigInteger valor){
    BigInteger respuesta = *this; // 1
    respuesta.add(valor); // 1
    return respuesta; // 1
}

BigInteger BigInteger::operator-(BigInteger valor){
    BigInteger respuesta = *this; // 1
    respuesta.substract(valor); // 1
    return respuesta; // 1
}

BigInteger BigInteger::operator*(BigInteger valor){
    BigInteger respuesta = *this; // 1
    respuesta.product(valor); // 1
    return respuesta; // 1
}

BigInteger BigInteger::operator/(BigInteger valor){
    BigInteger respuesta = *this; // 1
    respuesta.quotient(valor); // 1
    return respuesta; // 1
}

BigInteger BigInteger::operator%(BigInteger valor){
    BigInteger respuesta = *this; // 1
    respuesta.remainder(valor); // 1
    return respuesta; // 1
}
/*
Función sumarListaValores
Entrada: Una lista de objetos BigInteger (vector1).
Salida: Un objeto BigInteger.
Descripción: Esta función calcula la suma de todos los valores en la lista de objetos BigInteger proporcionada y devuelve el resultado como un nuevo objeto BigInteger.
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger>&vector1){ // O(n)
    BigInteger suma = 0; // 1
    list<BigInteger>::iterator i = vector1.begin(); // 1
    for(;i!=vector1.end() ; i ++){ // n veces, depende del tamaño del vector1
		suma = suma + *i; // n veces, depende del tamaño del vector1
	}
    return suma; // 1
}
/*
Función multiplicarListaValores
Entrada: Una lista de objetos BigInteger (vector1).
Salida: Un objeto BigInteger.
Descripción: Esta función calcula el producto de todos los valores en la lista de objetos BigInteger proporcionada y devuelve el resultado como un nuevo objeto BigInteger.
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>&vector1){
    BigInteger producto = 1; // 1
    list<BigInteger>::iterator i = vector1.begin(); //1
    for(;i!=vector1.end() ; i ++){ // n veces, depende del tamaño de vector1
		producto = producto * *i; // n veces, depende del tamaño de vector1
	}
    return producto; // 1
}
