#include <stdio.h>

#define LEN 100

typedef struct {
	char dados[LEN];
	int head;
	int tail;
	int qtde;
} Queue;

int is_full(Queue *queue){
    return queue->qtde == LEN;
}

int isEmpty(Queue *queue){
  return queue->qtde == 0;
}

void enqueue(Queue *queue, char caracter) {
    if(is_full(queue)){
        return 0;
    }

    queue->dados[queue->tail % LEN] = caracter;
    queue->tail++;
    queue->qtde++;
}

int dequeue(Queue *queue) {
    if(isEmpty(queue)){
        return -1;
    }
    queue->qtde--;
    return queue->dados[queue->head++ % LEN];
}

void show(Queue *queue) {
    for(int i = queue->head; i < queue->tail; i++){
        printf("%c", queue->dados[i % LEN]);
    
    }
}

void start_queue(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;
}

int main(void) {
    char s[LEN];

    Queue queue;
    int countEsq = 0;
    int countDir = 0;
    start_queue(&queue);

	fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0'; i++){
        enqueue(&queue,s[i]);
        show(&queue);
        
    }

    for (int num = 0; s[num] != '\0'; num++){
        if(s[num] == '('){
            countEsq = countEsq + 1;
            dequeue(&queue);
            show(&queue);
            printf("%d", countDir);
            printf("%d", countEsq);
        }
        else if (s[num] == ')'){
            countDir = countDir + 1;
            dequeue(&queue);
            show(&queue);
            printf("%d", countDir);
            printf("%d", countEsq);
        }
    }

    if (countDir == countEsq){
        printf("Correto");
    } else {
        printf("Incorreto");
    }
    

    return 0;
}