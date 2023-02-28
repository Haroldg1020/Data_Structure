#include <stdio.h>
int distancia(int a, int b, int s){
    int op;
    if (a == b)
        op = 0;
    else{
        if (s == 1){
            if (b >= a){
                op = (b - a) * 9;
            }
            else{
                op = (40 - (a - b)) * 9;
            }
        }
        else{
            if (b >= a){
                op = (40 - (b - a)) * 9;
            }
            else{
                op = (a - b) * 9;
            }
        }
    }
    return op;
}
int main(){
    int arreglo[4];
    int x = 0;
    while (x == 0){
        int sum = 0;
        int resp;
        for (int i = 0; i < 4; i++){
            scanf("%d", &arreglo[i]);
            sum += arreglo[i];
        }
        if (sum == 0){
            x = 1;
        }
        else{
            resp = 1080 + distancia(arreglo[0], arreglo[1], -1) + distancia(arreglo[1], arreglo[2], 1) + distancia(arreglo[2], arreglo[3], -1);
            printf("%d\n", resp);
        }
    }
        return 0;
}