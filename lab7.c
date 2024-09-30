#include <stdio.h>
#include <stdlib.h>
#define CAP 10

typedef struct Celula {
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct {
    Celula *topo;
    int qtd;
} Stack;

Celula *criar_celula(int valor) {
    Celula *celula = malloc(sizeof(Celula));
    celula->proximo = NULL;
    celula->valor = valor;
    return celula;
}

Stack *start_stack() {
    Stack *pilha = malloc(sizeof(Stack));
    pilha->topo = NULL;
    pilha->qtd = 0;
    return pilha;
}

void push(Stack *pilha, int valor) {
    Celula *novo = criar_celula(valor);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->qtd++;
}

int pop(Stack *pilha) {
    if (pilha->qtd == 0) {
        return -1;
    }
    int valor = pilha->topo->valor;
    Celula *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    pilha->qtd--;
    free(temp);
    return valor;
}

void show(Stack *pilha) {
    Celula *atual = pilha->topo;
    printf("TOPO -> ");
        while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- BASE\n");
}

int main() {
    Stack *stack = start_stack();
    char expr[100];
    int flag = 1;
    int colchete = 0;
    int chave = 0;
    int parenteses = 0;

   
    fgets(expr, sizeof(expr), stdin);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '{') {
            push(stack, expr[i]);
            chave++;
            if (colchete > 0) {
                flag = 0;
                break;
                }
        }
        if (expr[i] == '[') {
            push(stack, expr[i]);
            colchete++;
            if (parenteses > 0) {
                flag = 0;
                break;
            }
        }
        if (expr[i] == '(') {
            push(stack, expr[i]);
            parenteses++;
        }

        if (expr[i] == '}' && colchete == 0) {
            char x = pop(stack);
            if (x != '{') {
                flag = 0;
                break;
            }
            chave--;
        }

        if (expr[i] == ']' && parenteses == 0) {
            char x = pop(stack);
            if (x != '[') {
                flag = 0;
                break;
            }
            colchete--;
        }

        if (expr[i] == ')') {
            char x = pop(stack);
            if (x != '(') {
                flag = 0;
                break;
            }
            parenteses--;
        }
    }

    if (stack->qtd == 0 && flag == 1) {
        printf("correto");
    } else {
        printf("incorreto");
    }

    return 0;
}