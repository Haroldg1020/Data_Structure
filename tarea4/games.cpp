    #include <iostream>
    #include <string>
    #include <vector>
    #include<algorithm>
    using namespace std;


    int main(){
        int n;
        scanf("%d", &n);
        while(n != 0){
            vector<string>vec;
            char temp [1001];
            for(int i = 0 ; i < n ; i ++){
                scanf("%s", temp);
                vec.push_back(temp);
            }
            sort(vec.begin(), vec.end());
            string antes = vec[(n/2)-1], despues = vec[(n/2)], respuesta = "";
            for(int i = 0 ; i < antes.size() ; i ++){
                if(antes[i] == despues[i]){
                    respuesta+=antes[i];
                }
                else{
                    if(despues[i] > antes[i]+1 or i < despues.size() - 1){
                        if(i == antes.size() - 1){
                            respuesta+= antes[i];
                        }
                        else{
                            respuesta+=(antes[i]+1);
                            i = antes.size();
                        }
                    }
                    else{
                        respuesta+=antes[i];

                        for(int j = i+1 ; j < antes.size() ; j ++){
                            if(j == antes.size()-1){
                                respuesta+= antes[j];
                            }
                            else if(antes[j] != 'Z'){
                                respuesta+=(antes[j]+1);
                                i = antes.size();
                                j= antes.size();
                            }
                            else{
                                respuesta+='Z';
                            }
                        }
                        i = antes.size();
                    }
                }
            }
            cout << respuesta << endl; 
            scanf("%d", &n);
        }
    }
