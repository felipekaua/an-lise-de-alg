#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

void imprimeVetor(int *y, int z, int p){
    if(p<z){
        printf("%d ", *(y+p));
        imprimeVetor(y, z, p+1);
    }    
}

void atribuirVetor(int *l, int *y, int x, int p, int j){
    if(x>=0){ 
        if(*(y+p)!=0){
            *(l+j)=*(y+p);
            j++;   
        }
        atribuirVetor(l, y, x-1, p+1, j);
    }
}

void criaVetor(int *y, int x, int z){
    int j=0, p=0;
    int newArray[z];
    int *l;
    l=newArray;
    atribuirVetor(l, y, x, p, j);
    printf("\nArray sem numeros nulos: \n");
    imprimeVetor(l, z, p);
    
}

void novoVetor(int *y, int x, int z, int k){
    if(k>=0){
        k=k-1;
        if(*(y+k)==0){
            novoVetor(y, x, z, k);
        }else{
            novoVetor(y, x, z+1, k);
        }
    }else{
        criaVetor(y, x, z-1);   
    } 
}

int main(){
    int x;
    int *y=0;

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

    int z=0, k;
    y=arrayExemplo;
    k=x;
    novoVetor(y, x, z, k);


    return 0;
}