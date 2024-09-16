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

int isEmpty(Queue *queue){
  return queue->qtde == 0;
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

int dequeue(Queue *queue){
  if(isEmpty(queue)){
    return -1;
  }
  queue->qtde--;
  return queue->dados[queue->head++ % CAP];
}


void mostrar(Queue *queue){
  printf("HEAD -> ");
  for(int i = queue->head; i < queue->tail; i++){
    printf("%d ", queue->dados[i % CAP]);
    
  }
  printf(" <- TAIL");
  printf("\n");
}


int main(){

    Queue queue;
    
    inicilizar(&queue);

    for(int num = 89; num > 0; num -= 7){
        enqueue(&queue, num);
        mostrar(&queue);
    }

    for(int num = 0; num < 15; num ++){
        printf("Valor removido %d\n", dequeue(&queue));
        mostrar(&queue);
    }

    

    return 0;
}