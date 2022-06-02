#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>

typedef struct elemento {
   int conteudo;
   struct elemento *prox;
}celula;

void insere (int x, celula *p)
{
   celula *nova;
   nova = (celula*)malloc (sizeof(celula));
   nova->conteudo = x;
   nova->prox = p->prox;
   p->prox = nova;
}

void remove(int y, celula *num, int a)
{
   if(a>=0){
   celula *p, *q;
   p = num;
   q = num->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free (q);
      remove(y, num, a-1);
   }
   }
}
int scanear(int y, celula *p){
    p=p->prox;
    int a=0;
    while(p!=NULL)
    {
        if(p->conteudo==0){
            a++;
        }
        p=p->prox;
    }
    return a;
}

void imprime(celula *p){
    p=p->prox;
    while(p!=NULL)
    {
        printf("%d ",p->conteudo);
        p=p->prox;
    }
}

int main(){
    int x, k=0;

    printf("Digite um valor: ");
    scanf("%d", &x);

    celula *num;
    num = (celula*)malloc(sizeof(celula));
    num->prox = NULL;

    int arrayListagem[x];

    for(int i=0; i<x; i++){
        arrayListagem[i]=rand() % 100;
    }

    for(int i=0; i<x; i++){
        if(arrayListagem[i]%2!=0){
            insere(rand() % 10, num);
        }else{
            insere(0, num);
        }
    }

    printf("\nLista Encadeada com numeros nulos:\n");
    imprime(num);
    k = scanear(0, num);
    remove(0, num, k);
    printf("\nLista Encadeada sem numeros nulos:\n");
    imprime(num);



    return 0;
}