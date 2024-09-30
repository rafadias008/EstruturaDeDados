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

int main() {

    int countPe = 0, countCe = 0, countChe = 0;

    Stack *pilha = criar_pilha();
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    for(int num = 0; expr[num] != '\0'; num++){

        if(expr[num] == 123 && countCe == 0 && countPe == 0){
            countChe++;
            push(&pilha, expr[num]);
        } 
        else if(expr[num] == 125 && countChe == 0){
            printf("Incorreto");
            break;
        }
        else if(expr[num] == 91 && countChe == 0){
            countCe++;
            push(&pilha, expr[num]);
        }
        else if(expr[num] == 93 && countCe == 0){
            printf("Incorreto");
            break;
        }
        else if(expr[num] == 40){
            countPe++;
            push(&pilha,expr[num]);
        }
        else if(expr[num] == 41 && countPe == 0){
            printf("Incorreto");
            break;
        }

	return 0;
    }
}