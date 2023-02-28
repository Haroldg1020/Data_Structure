#include <stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) == 1){
        int arr[n];
        int diferencias[n - 1];
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if (i != 0){
                if (arr[i] > arr[i - 1]){
                    diferencias[i - 1] = arr[i] - arr[i - 1];
                }
                else{
                    diferencias[i - 1] = arr[i - 1] - arr[i];
                }
            }
        }

        int existe[n];
        for (int i = 0; i < n; i++){
            existe[i] = 0;
        }
        for (int i = 0; i < n - 1; i++){
            if (diferencias[i] < n){
                existe[diferencias[i]] = 1;
            }
        }
        int estamal = 0;
        for (int i = 1; i <= n - 1; i++){
            if (existe[i] != 1){
                estamal = 1;
            }
        }
        if (estamal){
            printf("Not jolly\n");
        }
        else{
            printf("Jolly\n");
        }
    }
    return 0;
}