#include <stdio.h>
#include <stdbool.h>
#define CAP 10


typedef struct{
    int dados[CAP];
    int topo;
} Stack;

bool push(Stack *pilha, int valor){

    if(pilha->topo == CAP){
        printf("Stack overflow!");
        return false;
    }
    pilha->dados[pilha->topo++] = valor;
    return true;

} 

int pop(Stack *pilha){

    if(pilha->topo == 0){
        printf("Stack underflow\n");
        return -1;
    }
    return pilha->dados[--pilha->topo];

}

void show(Stack *pilha){
    printf("Topo -> ");
    for(int i = pilha->topo-1; i >= 0; i--){
        printf("%d ",pilha->dados[i]);
    }
    printf("<- Base");
    printf("\n");
}

int main(){

    Stack pilha = {.topo = 0};

    for(int num = 0;num < 12;num++){
        push(&pilha, num);
        show(&pilha);
    }

    for(int i =0;i < 12; i++){
        printf("Valor desempilhado: %d\n",pop(&pilha));
        show(&pilha);
    }

    return 0;
}