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

int is_full(Queue *queue){
    return queue->qtde == CAP;
}

int enqueue(Queue *queue, int valor){

    if(is_full(queue)){
        return 0;
    }

    queue->dados[queue->tail % CAP] = valor;
    queue->tail++;
    queue->qtde++;
    return 1;
}


void mostrar(Queue *queue){

    for(int i = queue->head; i < queue->tail; i++){
        printf("%d " , queue->dados[i % CAP]);
    }
    printf("\n");
}


int main(){

    Queue queue;
    
    inicilizar(&queue);

    for(int num = 89; num > 0; num -= 7){

        enqueue(&queue, num);
        mostrar(&queue);
    }

    

    return 0;
}