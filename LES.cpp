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
Elemento* remove(Lista *lista, Elemento *pivo);
Elemento* busca(Lista *lista, int dado);
void imprime(Lista *lista);


main(){
  Lista *lista = cria();

	remove(lista, lista->head);

	insere(lista,lista->head,20);
	insere(lista,lista->tail,30);
	insere(lista,lista->head->next,25);
	// remove(lista, lista->head);
  Elemento *elemento = busca(lista, 20);
   printf("%d\n", elemento->dado);
  imprime(lista);

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

Elemento* remove(Lista *lista, Elemento *pivo){
  Elemento *antigo = (Elemento*) malloc(sizeof(Elemento));
  if(lista->size == 0){
    return NULL; //retorna lista vazia 
  }
  if(pivo == NULL){
    antigo = lista->head;
    lista->head = lista->head->next;

    if(lista->head==NULL){
      lista->tail = NULL; 
    }
  }else{
    if(pivo->next==NULL){
      return NULL; //retorna fim da lista
    }
    antigo = pivo->next;
    pivo->next = pivo->next->next;

    if(pivo->next==NULL){
      lista->tail = pivo;
    }
  }
  free(antigo);
  lista->size--;
  return antigo;
}

void imprime(Lista *lista){
	Elemento *aux=(Elemento*)malloc(sizeof(Elemento));
	aux=lista->head;
	int i=0;
	for(i=0;i<lista->size;i++){
		printf("%i ",aux->dado);
		aux=aux->next;
	}
}

Elemento* busca(Lista *lista, int dado){
  Elemento *aux =(Elemento*)malloc(sizeof(Elemento));
  aux=lista->head;
  int i = 0;
  for ( i = 0; i < lista->size; i++){
    if(aux->dado == dado){
      return aux;
    }
    aux = aux->next;
  }
  return NULL;
  
}
