#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    struct Celula *proximo;
    int valor
} Celula;

typedef struct {
    Celula *topo;
    int qtde;
} Stack;

Celula *criar_celula(int valor){
    Celula *celula = malloc(sizeof(Celula));
    celula->proximo = NULL;
    celula->valor = valor;
    return celula;
}

Stack *criar_pilha(){
    Stack *pilha = malloc(sizeof(Stack));
    pilha->topo = NULL;
    pilha->qtde = 0;
    return pilha;
}

void push(Stack *pilha, int valor){
    Celula *novo = criar_celula(valor);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->qtde++;
}

int pop(Stack *pilha){

    if(pilha->qtde == 0){
        return -1;
    }
    int valor = pilha->topo->valor;
    Celula *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    pilha->qtde--;
    free(temp);
    return valor;
}

void show(Stack *pilha){
    Celula *atual = pilha->topo;

    printf("Topo ->");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- Base");
    printf("\n");
}

int main(){

    Stack *pilha = criar_pilha();

    for(int num = 0; num < 15; num++){
        push(pilha, num);
        show(pilha);
    }

    for(int i = 0; i < 15; i++){
        printf("POP em %d\n" , pop(pilha));
        show(pilha);
    }

    return 0;
}