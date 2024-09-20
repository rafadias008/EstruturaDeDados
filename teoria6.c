 #include <stdio.h>
 #include <stdlib.h>

 typedef struct Celula{

    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
 }Celula;

 typedef struct {

    Celula *head;
    Celula *tail;
    int qtde;
 } Queue;


 Celula *cria_celula(int valor){

    Celula *celula = malloc(sizeof(Celula));
    celula->proximo = NULL;
    celula->anterior = NULL;
    celula->valor = valor;

    return celula;
 }

Queue *cria_queue(){

    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->qtde = 0;

    return queue;
}

int enqueue (Queue *queue, int valor){
    Celula *novo = cria_celula(valor);

    if(queue->qtde == 0){
        queue->head = novo;
    } else{
        queue->tail->proximo = novo;
        novo->anterior = queue->tail;
    }

    queue->tail = novo;
    queue->qtde++;
}

int dequeue(Queue *queue){
    Celula *temp = queue->head;
    int valor = queue->head->valor;
    
    if(queue->qtde == 0){
        return -1;
    }

    if(queue->qtde == 1){
        
        queue->head =  NULL;
        queue->tail = NULL;
        
    } else if(queue->qtde > 1){
    
        queue->head = queue->head->proximo;
        queue->head->anterior = NULL;
        
    }

    free(temp);
    queue->qtde--;

    return valor;
    
}

void show(Queue *queue){

    Celula *atual = queue->head;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    print("\n");
}

void show_invertido(Queue *queue){

    Celula *atual = queue->tail;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

int main(void){

    Queue *queue = cria_queue();

    for(int num = 89; num > 0; num-=7){
        enqueue(queue, num);
        show(queue);
        show_invertido(queue);
    }
    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("Removido: %d\n", dequeue(queue));
        show(queue);
        show_invertido(queue);
    }
}