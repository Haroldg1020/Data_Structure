#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

int main(){
    int n = 1, temp;
    deque<int>cola1;
    deque<int>estacion;
    vector<int>vec;
    vector<int>B;
    while(n != 0){ // O(t*n)
        scanf("%d", &n);
        if(n != 0){
            bool flag = true;
            while(flag){
                for(int i = 1 ; i <= n ; i ++){ // n
                    cola1.push_back(i);
                    scanf("%d", &temp);
                    if(temp == 0){
                        cola1.pop_back();
                        i = n + 1;
                        flag = false;
                    }else{
                    vec.push_back(temp);
                    }
                }
                if(flag){
                    for(int i = 0 ; i < n ; i ++){ // n
                        if(estacion.empty() or estacion.back() != vec[i]){
                            while(!cola1.empty() and vec[i] != cola1.front()){
                                estacion.push_back(cola1.front());
                                cola1.pop_front();
                            }
                            if(not cola1.empty()){
                                estacion.push_back(cola1.front());
                                cola1.pop_front();
                            }
                        }
                        if(not estacion.empty() and estacion.back() == vec[i]){
                            B.push_back(estacion.back());
                            estacion.pop_back();
                        }
                    }
                    if(B == vec){ // n
                        printf("Yes\n");
                    }else{
                        printf("No\n");
                    }
                    vec.clear(); // n
                    B.clear(); // n
                    estacion.clear(); // n
                }
                else printf("\n");
            }
        }
    }
    return 0;
    /*
        La complejidad total del algoritmo es O(t*n) siendo t = los casos de prueba
        pues recorremos los vagones linealmente usando 3 estructuras: 2 colas y 2 vectores.
    */
} 