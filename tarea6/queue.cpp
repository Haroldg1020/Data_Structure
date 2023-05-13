#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int main(){
    int p = 1, c = 1, E_numero;
    char letra;
    deque<int>cola;
    deque<int>cola2;
    // 4 * 10 * 1000 * 1000 = 4 * 1e7
    int casoActual = 1;
    while(p != 0 && c != 0){ // max. 10
        
        scanf("%d %d", &p, &c);
        if(p != 0){
            printf("Case %d:\n", casoActual++);
            for(int i = 1; i < min(p+1, 1000); i++){ // O(min(p, 1e3))
                cola.push_back(i);
            }
            for (int i = 0; i < c; i++){ // c
                scanf(" %c", &letra);
                if(letra == 'N'){
                    printf("%d\n", cola.front()); // 1
                    cola.push_back(cola.front()); // 1
                    cola.pop_front(); // 1
                }
                else{
                    scanf("%d", &E_numero); // 1
                    while(!cola.empty()){ // O(min(p, 1e3))
                        if(cola.front() == E_numero){ // 1
                            cola.pop_front();//1
                        }
                        else{
                            cola2.push_back(cola.front()); // 1
                            cola.pop_front();//1
                        }
                    }
                    cola2.push_front(E_numero); //1
                    cola = cola2; // O(min(p, 1e3))
                    cola2.clear(); // O(min(p, 1e3))
                }
            }
            cola.clear();
        }
    }
    return 0;

}