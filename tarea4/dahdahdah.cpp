#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main(){
    int T;
    string arrSy[30] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string numerosTraducidos[30] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string simbolosTraducidos[30] = {".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"};
    string letras[30] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    string numeros[30] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    string simbolos[30] = {".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
    string arr;
    int n = 1;
    scanf("%d", &T);
    cin.ignore();
    while(T--){
        string resp = "";
        getline(cin, arr);
        int p = 0;
        for(int i = 0; i < arr.size() ; i++){
           if(arr[i] == ' '){

                string temp = "";
                for(int j = p; j < i; j++){
                    temp += arr[j];
                }
                for (int j = 0; j < 26; j++){
                    if (temp == letras[j]){
                        resp += arrSy[j];
                    }
                }
                for (int j = 0; j < 10; j++){
                    if (temp == numeros[j]){
                        resp += numerosTraducidos[j];
                    }
                }
                for (int j = 0; j < 17; j++){
                    if (temp == simbolos[j]){
                        resp += simbolosTraducidos[j];
                    }
                }
        
                p = i + 1;
                if (arr[i+1] == ' '){
                    resp+=" ";
                    i++;
                    p = i + 1;
                }
            }
        }
        string temp = "";
        for(int j = p; j < arr.size(); j++){
            temp += arr[j];
        }
        for (int j = 0; j < 26; j++){
            if (temp == letras[j]){
                resp += arrSy[j];
            }
        }
        for (int j = 0; j < 10; j++){
            if (temp == numeros[j]){
                resp += numerosTraducidos[j];
            }
        }
        for (int j = 0; j < 17; j++){
            if (temp == simbolos[j]){
                resp += simbolosTraducidos[j];
            }
        }
        printf("Message #%d\n", n);
        const char* respuestaPuntero = resp.c_str();
        printf("%s\n", respuestaPuntero);
        if(T)printf("\n");
        n++;
    }   

    return 0;
}