#include <stdio.h>
#include <stdlib.h>

typedef struct sElemento{
  struct sElemento *next;
  struct sElemento *prev;
  int dado;
} Elemento;

typedef struct sLista{
  struct sElemento *head;
  struct sElemento *tail;
  int size;
} Lista;

Lista* cria();
void insere(Lista *lista, Elemento *pivo, int valor);
void remove(Lista *lista, Elemento *pivo);
Elemento* busca(Lista *lista, int dado);
void imprime(Lista *lista);


int main(){
  Lista *lista = cria();


	insere(lista,lista->head,20);
	insere(lista,lista->tail,30);
	insere(lista,lista->head->next,25);
  // remove(lista,NULL);
	// remove(lista, lista->head);
  Elemento *elemento = busca(lista, 31);
  
  imprime(lista);

  return 0;
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

void remove(Lista *lista, Elemento *pivo){
  Elemento *antigo = (Elemento*) malloc(sizeof(Elemento));
  if(lista->size == 0){
    printf("Lista vazia \n"); //retorna lista vazia 
  }
  if(pivo == NULL){
    antigo = lista->head;
    lista->head = lista->head->next;

    if(lista->head==NULL){
      lista->tail = NULL; 
    }
  }else{
    if(pivo->next==NULL){
      printf("Fim da lista \n");
    }
    antigo = pivo->next;
    pivo->next = pivo->next->next;

    if(pivo->next==NULL){
      lista->tail = pivo;
    }
  }
  printf("Elemento %d Apagado \n", antigo->dado);
  free(antigo);
  lista->size--;
}

void imprime(Lista *lista){
	Elemento *aux=(Elemento*)malloc(sizeof(Elemento));
	aux=lista->head;
	int i=0;
	for(i=0;i<=lista->size;i++){
		printf("%d ",aux->dado);
		aux=aux->next;
	}
}

Elemento* busca(Lista *lista, int dado){
  Elemento *aux =(Elemento*)malloc(sizeof(Elemento));
  aux=lista->head;
  int i = 0;
  for ( i = 0; i < lista->size; i++){
    if(aux->dado == dado){
      printf("Elemento %d achado na posicao %d\n", aux->dado, i);
      return aux;
    }
    aux = aux->next;
  }
  printf("Nao foi achado o valor %d dentro da lista\n",dado );
  return NULL; 
}
