#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{

    struct Celula *anterior;
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct{
    Celula *primeiro;
    int qtde;
} Lista;

Celula *criar_celula(int valor){
    
}
int main(void){
    printf("Hello World!");
}
