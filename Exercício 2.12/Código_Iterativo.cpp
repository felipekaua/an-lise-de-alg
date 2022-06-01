#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

int main(){
    int x;

    printf("Digite um valor: ");
    scanf("%d", &x);

    int arrayExemplo[x];
    int arrayListagem[x];

    srand(time(NULL));

    for(int i=0; i<x; i++){
        arrayListagem[i]=rand() % 100;
    }
    for(int i=0; i<x; i++){
        if(arrayListagem[i]%2!=0){
            arrayExemplo[i]=rand() % 10;
        }else{
            arrayExemplo[i]=0;
        }
    }
    printf("Array com numeros nulos: \n");
    for(int i=0; i<x; i++){
        printf("%d ", arrayExemplo[i]);
    }
    int newSize=0;
    for(int i=0; i<x; i++){
        if(arrayExemplo[i]!=0){
            newSize++;
        }
    } 
    int newArray[newSize-1];
    printf("\nArray sem numeros nulos: \n");
    int j=0;
    for(int i=0; i<x; i++){  
        if(arrayExemplo[i]!=0){
            newArray[j]=arrayExemplo[i];
            j++;   
        }
    }

    for(int i=0; i<newSize; i++){
        printf("%d ", newArray[i]);
    }

    return 0;
}