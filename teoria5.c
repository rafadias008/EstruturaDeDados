#include <stdio.h>
#define CAP 10

typedef struct{
    int dados[CAP];
    int head;
    int tail;
    int qtde;
} Queue;

void inicilizar(Queue *queue){
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;

}



int main(){


}