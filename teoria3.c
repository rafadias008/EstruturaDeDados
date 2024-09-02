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
    Celula *celula = malloc(sizeof(Celula));
    celula->anterior = NULL;
    celula->valor = valor;
    celula->proximo = NULL;
    return celula;
}

Lista *criar_lista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->qtde = 0;
    return lista;
}

void inserir(Lista *lista, int valor){
    Celula *novo = criar_celula(valor); 

    //inserção de lista vazia 
    if(lista->primeiro == NULL){
        lista->primeiro = novo;
    } else {
        Celula *atual = lista->primeiro;
        Celula *anterior = NULL;

        while(atual != NULL && atual->valor <= novo->valor){
            anterior = atual;
            atual = atual->proximo;
        }

        //inserção no inicio da lista
        if (anterior == NULL){
            lista->primeiro = novo;
            novo->proximo = atual;
            atual->anterior = novo;
        }

        // inserção no final
        else if(atual == NULL){
            anterior->proximo = novo;
            novo->proximo =  anterior;
        } 
        
        // inserção no meio
        else {
            anterior->proximo = novo;
            novo->anterior = anterior;
            novo->proximo = atual;
            atual->anterior = novo;
        }
    }
    lista->qtde++;
}

void mostrar(Lista *lista){
    Celula *atual = lista->primeiro;

    printf("Inicio -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- Final \n ");
    
}

void remover(Lista *lista, int valor){
    Celula *atual = lista->primeiro;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor != valor){

        //remover no comeco da lista
        if(atual->anterior == NULL){
            atual = atual->proximo;
            free(atual);
        } 
        //remover no final da lista
        else if (atual->proximo == NULL){
            atual = atual->anterior;
            free(atual);
        }
        //remover no meio da lista
        else if(atual->proximo != NULL && atual->anterior != NULL){
            atual->anterior = atual->proximo;
            atual = atual->proximo;
            
        }
 
    }
    free(atual); 
    lista->qtde--;
    

}

int main(void){
    Lista *lista = criar_lista();

    for(int num = 20; num > 0; num--){
        inserir(lista,num);
        mostrar(lista);
        
    }

    for(int num = 20; num > 0; num--){
        remover(lista,num);
        mostrar(lista);
    }

    free(lista);

    return 0;
}
