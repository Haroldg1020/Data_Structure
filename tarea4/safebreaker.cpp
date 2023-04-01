#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool>valido;
int solucionesValidas;
vector<string>inicial;

bool laSolucionEsValida(string solucion, int fijas, int picas, string prueba){
    int f = 0, p = 0;
    string pruebaCopia = prueba;
    string solucionCopia = solucion;
    for(int i = 0 ; i < 4 ; i ++){
        if(solucion[i] == prueba[i]){
            f++;
            pruebaCopia[i] = 'a';
            solucionCopia[i] = 'a';
        }
    }
    for(int i = 0 ; i < 4 ; i ++){
        if(solucionCopia[i] != 'a'){
            for(int j = 0 ; j < 4 ; j ++){
                if(j != i and pruebaCopia[j] != 'a' and solucionCopia[i] == pruebaCopia[j]){
                    p++;
                    pruebaCopia[j] = 'a';
                    j = 5;
                }
            }
        }
    }
    return f == fijas and p == picas;
}

void validar(string numero, int fijas, int picas){
    for(int i = 0 ; i < inicial.size() ; i ++){
        if(valido[i]){
            bool esValido = laSolucionEsValida(inicial[i], fijas, picas, numero);
            if(!esValido){
                solucionesValidas--;
                valido[i] = false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    int n, g, fijas, picas;
    string numero, otro, stringFinal, temp;
    scanf("%d\n", &n);
    for(int i = 0 ; i <= 9999 ; i ++ ){
        temp = to_string(i);
        if(temp.size()==4){
            stringFinal="";
        }else if(temp.size()==3){
            stringFinal="0";
        }else if(temp.size()==2){
            stringFinal="00";
        }else if(temp.size()==1){
            stringFinal="000";
        }
        inicial.push_back(stringFinal+temp);
        valido.push_back(true);
    }
    while(n--){
        solucionesValidas = 10000;
        scanf("%d\n", &g);
        for(int i = 0 ; i <= 9999 ; i ++){
            valido[i] = true;
        }

        for(int i = 0 ; i < g ; i ++){
            cin>>numero >> otro;
            fijas = otro[0]-'0';
            picas = otro[2]-'0';
            if(solucionesValidas != 0)validar(numero, fijas, picas);
        }
        
        if(solucionesValidas == 0){
            printf("impossible\n");
        }else if(solucionesValidas > 1){
            printf("indeterminate\n");
        }else{
            for(int i = 0 ; i < inicial.size() ; i ++){
                if(valido[i]){
                    cout << inicial[i] << "\n";
                    i = inicial.size();
                }
            }
        }
    }
    return 0;
}