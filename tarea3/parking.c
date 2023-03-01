#include <stdio.h>
int testCase(){
    int arr[100];
    int numeroTiendas;
    scanf("%d", &numeroTiendas);
    int mini = 100, maxi = 0;
    for (int i = 0; i < numeroTiendas; i++){
        scanf("%d", &arr[i]);
        if (arr[i] > maxi){
            maxi = arr[i];
        }
        if (arr[i] < mini){
            mini = arr[i];
        }
    }
    int ans = (maxi - mini) * 2;
    return ans;
}
int main(){
    int nCases;
    scanf("%d", &nCases);
    while (nCases > 0){
        int respuesta = testCase();
        printf("%d\n", respuesta);
        nCases--;
    }
    return 0;
}
