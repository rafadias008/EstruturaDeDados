#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
  int valor;
  struct Celula *proximo;
} Celula;

typedef struct{
  Celula *primeira;
  int qtde;
} Lista;

Lista *inicializa_lista(){
  Lista *lista = malloc(sizeof(Lista));
  lista->primeira = NULL;
  lista->qtde = 0;
  return lista;
}

Celula *inicializa_celula(int valor){
  Celula *celula = malloc(sizeof(Celula));
  celula->proximo = NULL;
  celula->valor = valor;
  return celula;
}

void inserir(Lista *lista, int valor){
  Celula *nova = inicializa_celula(valor);
  Celula *atual = lista->primeira;
  Celula *anterior = NULL;
  
  if(lista->qtde == 0){
    lista->primeira = nova;
    lista->qtde++;
  }else{
    //while(atual != NULL && nova->valor >= atual->valor){}
    while(atual != NULL && atual->valor <= nova->valor){
      anterior = atual;
      atual = atual->proximo;
    }
    if(anterior == NULL){
      nova->proximo = lista->primeira;
      lista->primeira = nova;
      lista->qtde++;
    }else{
      if(atual == NULL){
        anterior->proximo = nova;
        lista->qtde++;
      }else{
        anterior->proximo = nova;
        nova->proximo = atual;
        lista->qtde++;
      }
      
    }
  }
}

void imprimir(const Lista *lista) {
  Celula *novo = lista->primeira;
  while (novo != NULL){
    printf("%d ", novo->valor);
    novo = novo->proximo;
    
  }
  printf("\n");
  
}

void remover(Lista *lista, int valor) {
  Celula *atual = lista->primeira;
  Celula *anterior = NULL;

  
  while (atual != NULL && atual->valor != valor) {
    anterior = atual;
    atual = atual->proximo;
  }

  //Verifica se o atual é nulo
  if (atual == NULL){
    return;
  }

  if (anterior == NULL) {
    lista->primeira = atual->proximo;
  }
  else if (atual->proximo == NULL){
    anterior->proximo = NULL;
  }
  else{
    anterior->proximo = atual->proximo;
  }
  free(atual);
  lista->qtde--;
 
}



int main(void) {
  Lista *l = inicializa_lista();
  int valores[] = {2, 1, 0, 9, 3, 8, 5, 7, 6, 4};

  // Inserção
  for (int i = 0; i < 10; i++) {
      inserir(l, valores[i]);
      imprimir(l);
  }

  //Remoção
  for (int i = 0; i < 10; i++) {
      remover(l, valores[i]);
      imprimir(l);
  }

  free(l); // Liberar memória alocada para a lista
  return 0;
}
