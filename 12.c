#include "stdio.h"
#include "stdlib.h"
void insert(char in[], int loc, char rp);
int getsize(char in[]);
int main(){
    char input[100];
    for (int i = 0;; i++){
        char g = getchar();
        if(g=='\n'){
            input[i] = '\0';
            break;
        }
        else{
            input[i] = g;
        }
    }
    for (int i = 0; input[i] != '\0'; i++){
        if(input[i]==' '){
            input[i] = '%';
            insert(input, i + 1, '2');
            insert(input, i + 2, '0');
            i += 2;
        }
    }
    for (int i = 0; input[i] != '\0'; i++){
        putchar(input[i]);
    }
    printf("\n%d", getsize(input));
    return 0;
}
void insert(char in[], int loc, char rp){
    int len = getsize(in);
    for (int i = len; i > loc; i--){
        in[i] = in[i - 1];
    }
    in[loc] = rp;
    in[len + 1] = '\0';
    return;
}
int getsize(char in[]){
    int i = 0;
    while (in[i] != '\0'){
        i++;
    }
    return i;
}