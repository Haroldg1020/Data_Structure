#include <stdio.h>

int siguientePosicion(int p, int n){
    p = (p + 1) % n;
    return p;
}

int testCase(){
    int n;
    scanf("%d", &n);
    int gasolina[n], distancia[n];
    int totalGasolina = 0, totalDistancia = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &gasolina[i]);
        totalGasolina += gasolina[i];
    }

    for (int i = 0; i < n; i++){
        scanf("%d", &distancia[i]);
        totalDistancia += distancia[i];
    }
    int respuesta = -1;
    if (totalDistancia > totalGasolina){
        printf(" Not possible\n");
    }
    else{
        for (int i = 0; i < n; i++){
            int gasolinaActual = 0;
            int ok = 1;
            int pos = i;
            for (int j = 0; j < n && ok == 1; j++){
                gasolinaActual += gasolina[pos];
                gasolinaActual -= distancia[pos];
                if (gasolinaActual < 0){
                    ok = 0;
                    i = pos;
                }
                else{
                    pos = siguientePosicion(pos, n);
                }
            }
            if (ok == 1){
                respuesta = i;
                i = n;
            }
        }
        printf(" Possible from station %d\n", respuesta + 1);
    }

    respuesta++;
    return respuesta;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        printf("Case %d:", i + 1);
        testCase();
    }
}