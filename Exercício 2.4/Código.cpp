#include <stdio.h>
#include <stdlib.h>

int algRecursivo(int K, int n, int x){
    if(n>0){
        x = K * algRecursivo(K, n-1, x);
        return x;
    }else{
        return 1;
    }
}

int main(){
    int K, n, x;
    int y;
    printf("Digite um numero inteiro: ");
    scanf("%d", &K);
    printf("\nDigite seu expoente: ");
    scanf("%d", &n);
    while(K>=0){
        while(n>=0){
            y=algRecursivo(K, n, x);
            printf("%d^%d=%d", K, n, y);
    }   }
        printf("\nSem entradas validas!");
    return 0;
}