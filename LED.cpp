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
void imprimeComeco(Lista *lista);
void imprimeFinal(Lista *lista);
Elemento* busca(Lista *lista, int dado);

int main(){
  Lista *lista = cria();

	insere(lista,NULL,20);
	insere(lista,lista->tail,30);
	insere(lista,lista->head->next,25);
	// insere(lista,NULL,20);
  busca(lista, 25);
  remove(lista,NULL);
	remove(lista, lista->head);
  // Elemento *elemento = busca(lista, 31);
  
  imprimeComeco(lista);
  imprimeFinal(lista);

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

  if((pivo == NULL) && (lista->size != 0)){
    printf("o pivo deve ser null somente na inserção do primeiro elemento");
    exit(0);
  }

  if(lista->size == 0){

    lista->head = novo;
    lista->tail = novo;

  }else{

    novo->next = pivo->next;
    novo->prev = pivo;

    if(pivo->next == NULL){
      lista->tail = novo;
    }else{
      pivo->next->prev = novo;
    }
    
    pivo->next = novo;

  }

  lista->size++;

}

void remove(Lista *lista, Elemento *pivo){
  if((pivo != NULL) && (lista->size != 0)){
    if(pivo == lista->head){
      lista->head = pivo->next;
      if(lista->head == NULL){
        lista->tail = NULL;
      }else {
        pivo->next->prev = NULL;
      }
    }else {
      pivo->prev->next = pivo->next;
      if(pivo->next == NULL){
        lista->tail = pivo->prev;
      }else {
        pivo->next->prev = pivo->prev;
      }
    }
    
    printf("Elemento %d Apagado \n", pivo->dado);

    free(pivo);
    lista->size--;
  } 
  if( pivo == NULL) {
    printf("\nPor favor, passe um elemento que não seja nulo\n");
  }
}

void imprimeFinal(Lista *lista){
  Elemento *aux=(Elemento*)malloc(sizeof(Elemento));

  aux=lista->tail;

  int i;
  printf("\nImprimindo de tras pra frente\n");
  for(i = (lista->size - 1); i >= 0 ; i--){
    printf("%d\n",aux->dado);
    aux=aux->prev;
  }
  
	
} 

void imprimeComeco(Lista *lista){
  Elemento *aux=(Elemento*)malloc(sizeof(Elemento));

  aux=lista->head;
  
  int i;
  printf("\nImprimindo de frente para tras\n");
	
  for(i = 0; i < lista->size ; i++){
    printf("%d\n",aux->dado);
    aux=aux->next;
  }
	
} 

Elemento* busca(Lista *lista, int dado){
  Elemento *aux =(Elemento*)malloc(sizeof(Elemento));
  aux=lista->head;
  for (int i = 0; i < lista->size; i++){
    if(aux->dado == dado){
      printf("Elemento %d achado na posicao %d\n", aux->dado, i);
      return aux;
    }
    aux = aux->next;
  }
  printf("Nao foi achado o valor %d dentro da lista\n",dado );
  return NULL; 
}