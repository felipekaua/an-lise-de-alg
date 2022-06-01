#include <stdio.h>
#include <stdlib.h>

void acharEntrada(int entrada, int i, int j, int z, int y){
    if(i>=0){     
            if(entrada!=z){
                z++;
                acharEntrada(entrada, i-1, j, z, y);
            }else{
                j=j-i;
                printf("linha: %d", i);
                printf("\ncoluna: %d", j);
            }
    }else{
            y++;
            i=i+y;
            j=i;
            acharEntrada(entrada, i, j, z, y);
    }
}

int main(){
    int i=-1, j=0, y=0, z=0;
    int entrada;
    printf("Insira um numero: ");
    scanf("%d", &entrada);
    acharEntrada(entrada, i, j, z, y);
    
    return 0;
}