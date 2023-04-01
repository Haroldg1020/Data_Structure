#include<iostream>
using namespace std;
int tc(int g, int p){
    int v = 0;
    if(g == 0 and p == 0){
        v = 1;
    }
    else{    
    int carreras[g][p];

    for(int i = 0 ; i < g ; i ++){
        for(int j = 0 ; j < p ; j ++){
            scanf("%d", &carreras[i][j]);
        }
    }

    int s;

    scanf("%d", &s);
    for(int i = 0 ; i < s ; i ++){
        int k;
        scanf("%d", &k);
        int arreglo[p];
        for(int j = 0 ; j < p ; j ++)arreglo[j] = 0;

        for(int j = 0 ; j < k ; j ++){

            scanf("%d", &arreglo[j]);

        }
        int puntaje[p];
        for(int j = 0 ; j < p ; j ++)puntaje[j] = 0;
        int maximaPuntuacion = -1;
        for(int carrera = 0 ; carrera < g ; carrera++){
            for(int jugador = 0 ; jugador < p ; jugador ++){
                puntaje[jugador] += arreglo[carreras[carrera][jugador]-1];
                if(puntaje[jugador] > maximaPuntuacion){
                    maximaPuntuacion = puntaje[jugador];
                }
            }
        }
        int ultimo ;
        for(int i = 0 ; i < p ; i ++){
            if(puntaje[i] == maximaPuntuacion){
                ultimo = i;
            }
        }
        for(int i = 0 ; i < p ; i ++){
            if(puntaje[i] == maximaPuntuacion){
                printf("%d", i+1);
                if(i != ultimo)printf(" ");
            }
        }
        printf("\n");
    }
    }
    return v;
}
int main(){
    int g, p;
    scanf("%d %d", &g, &p);
    bool iterador = tc(g, p);
    while(!iterador){
        scanf("%d %d", &g, &p);
        iterador = tc(g, p);
    }
}