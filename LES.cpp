#include <stdio.h>
#include <stdlib.h>


typedef struct sElemento{
  struct sElemento *next;
  int dado;
} Elemento;

typedef struct sLista{
  struct sElemento *head;
  struct sElemento *tail;
  int size;
} Lista;

Lista* cria();
void insere(Lista *lista, Elemento *pivo, int valor);
int remove(Lista *lista, Elemento *pivo);
void imprime(Lista *lista);


main(){
  Lista *lista = cria();
}

Lista* cria(){
  Lista *lista = (Lista*) malloc(sizeof(Lista));
  lista->head=NULL;
  lista->tail=NULL;
  lista->size=0;
  return lista;
}

void insere(Lista *lista, Elemento *pivo, int valor){
  Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
  novo->dado = valor;
  if(pivo == NULL){
    if(lista->size == 0){
      lista->tail= novo; 
    }
    novo->next = lista->head;
    lista->head = novo;
  }else{
    if(pivo->next==NULL){
      lista->tail = novo;
    }
    novo->next = pivo->next;
    pivo->next = novo;
  }
  lista->size++;
}

int remove(Lista *lista, Elemento *pivo){
  Elemento *antigo = (Elemento*) malloc(sizeof(Elemento));
  if(lista->size == 0){
    return 1; //retorna lista vazia 
  }
  if(pivo == NULL){
    antigo = lista->head;
    lista->head = lista->head->next;

    if(lista->head==NULL){
      lista->tail = NULL; 
    }
  }else{
    if(pivo->next==NULL){
      return 2; //retorna fim da lista
    }
    antigo = pivo->next;
    pivo->next = pivo->next->next;

    if(pivo->next==NULL){
      lista->tail = pivo;
    }
  }
  free(antigo);
  lista->size--;
}