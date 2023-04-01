#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
vector<string>equipos;  

struct resultadoEquipo{
    int puntos, diferencia, golesAFavor, golesEnContra, partidosJugados;
};

void imprimirEspacios(int esp){
    for(int i = 0 ; i < esp ; i ++)cout << " ";
}


bool comparar(string a, string b){
    bool ret;
    string minusculasA = "", minusculasB = "";
    for(int i = 0 ; i < a.size() ; i ++){
        if(a[i] < 'a'){
            minusculasA += a[i]+('a'-'A');
        }else{
            minusculasA += a[i];
        }
    }

    for(int i = 0 ; i < b.size() ; i ++){
        if(b[i] < 'a'){
            minusculasB += b[i]+('a'-'A');
        }else{
            minusculasB += b[i];
        }
    }
    if(minusculasA != minusculasB){
        ret = minusculasA < minusculasB;
    }else{

        int idA, idB;
        for(int i = 0 ; i < equipos.size() ; i ++){

            if(equipos[i] == a){
                idA = i;
            }
            if(equipos[i] == b){
                idB = i;
            }
        }
        ret = idA < idB;
    }
    return ret;
}



int main(){
    int t, g;
    int primerTest = 1;
    for(int xx = 0 ; xx < 1; xx){
        cin >>t >> g;
        if( t== g and t == 0){
            xx = 1;
        }else{
            if(primerTest != 1){
                printf("\n");
            }
            primerTest = 0;
            equipos.clear();
            vector<resultadoEquipo>vec;

            string s;
            for(int i = 0 ; i < t ; i ++){
                cin>>s;
                equipos.push_back(s);
                vec.push_back({0, 0, 0, 0, 0});
            }
            for(int partida = 0 ; partida < g ; partida++){
                string eq1, eq2, temp;
                int idxeq1, idxeq2, p1, p2;

                cin>>eq1>>p1>>temp>>p2>>eq2;
                for(int i = 0 ; i < equipos.size() ; i++){
                    if(equipos[i] == eq1){
                        idxeq1 = i;
                    }
                    if(equipos[i] == eq2){
                        idxeq2 = i;
                    }
                }
                if(p1>=p2){
                    if(p1>p2){
                        vec[idxeq1].puntos += 3;
                    }else{
                        vec[idxeq1].puntos++;
                    }
                }
                vec[idxeq1].golesAFavor += p1;
                vec[idxeq1].golesEnContra += p2;
                vec[idxeq1].partidosJugados++;
                vec[idxeq1].diferencia += (p1-p2);

                if(p2>=p1){
                    if(p2>p1){
                        vec[idxeq2].puntos += 3;
                    }else{
                        vec[idxeq2].puntos++;
                    }
                }
                vec[idxeq2].golesEnContra += p1;
                vec[idxeq2].golesAFavor += p2;
                vec[idxeq2].partidosJugados++;
                vec[idxeq2].diferencia += (p2-p1);

            }
            vector<vector<int> >respuesta;
            for(int i = 0 ; i < t ; i ++){
                vector<int>ins;
                ins.push_back(vec[i].puntos);
                ins.push_back(vec[i].diferencia);
                ins.push_back(vec[i].golesAFavor);
                ins.push_back(i);
                respuesta.push_back(ins);
            }

            sort(respuesta.rbegin(), respuesta.rend());
        
            for(int i = 1 ; i <= t ;i){
                imprimirEspacios(2 - to_string(i).size());
                cout << i << ".";
                vector<int>ret;     
                int last = respuesta.size()-1;
                for(int j = i ; j < respuesta.size() ; j ++){
                    if(respuesta[j][0] != respuesta[j-1][0] or respuesta[j][1] != respuesta[j-1][1] or respuesta[j][2] != respuesta[j-1][2]){
                        last = j-1;
                        j = respuesta.size();
                    }
                }
                vector<string>paraOrdenar;
                for(int j = i-1 ; j <= last ; j ++){
                    paraOrdenar.push_back(equipos[respuesta[j][3]]);
                }
                sort(paraOrdenar.begin(), paraOrdenar.end(), comparar);

                for(int x = 0 ; x < paraOrdenar.size() ; x++){
                    imprimirEspacios(16-paraOrdenar[x].size());
                    
                    cout << paraOrdenar[x];
                    int indiceEquipo ;
                    for(int j = 0 ; j < equipos.size() ; j ++){
                        if(equipos[j] == paraOrdenar[x]){
                            indiceEquipo = j;
                            j = equipos.size();
                        }
                    }
                    imprimirEspacios(4 - to_string(vec[indiceEquipo].puntos).size());
                    cout << vec[indiceEquipo].puntos;
                    imprimirEspacios(4 - to_string(vec[indiceEquipo].partidosJugados).size());
                    cout << vec[indiceEquipo].partidosJugados;
                    imprimirEspacios(4 - to_string(vec[indiceEquipo].golesAFavor).size());
                    cout << vec[indiceEquipo].golesAFavor;
                    imprimirEspacios(4 - to_string(vec[indiceEquipo].golesEnContra).size());
                    cout << vec[indiceEquipo].golesEnContra;
                    imprimirEspacios(4 - to_string(vec[indiceEquipo].diferencia).size());
                    cout << vec[indiceEquipo].diferencia;
                    if(vec[indiceEquipo].partidosJugados == 0){
                        cout << "    N/A" << endl;;
                    }else{
                        double porc = 100 * ((double)vec[indiceEquipo].puntos / (3 * vec[indiceEquipo].partidosJugados));
                        if(vec[indiceEquipo].puntos / (3 * vec[indiceEquipo].partidosJugados) == 1)imprimirEspacios(1);
                        else if(porc == 0){
                            imprimirEspacios(3);
                        }else{
                        imprimirEspacios(2);
                        }
                        cout<<fixed<<setprecision(2) << porc << endl;
                    }

                    if(x < paraOrdenar.size()-1){
                        cout << "   ";
                    }
                }
                i+=paraOrdenar.size();
            }

        }
    }


}