#include "lista.h"

char* obtem_rotulo(item_t item){
	return item.rotulo;
}

int obtem_valor(item_t item){
	return item.valor;
}

item_t gera_item(chave_t rotulo,int tamanho,int valor){
	item_t item;

	item.rotulo = ( char* ) malloc ( tamanho * sizeof( char ));

	item.rotulo = strdup( rotulo );
	item.valor = valor;

	return item;
}

void faz_lista_vazia(lista_t *lista){
	lista->primeiro = (apontador_t) malloc (sizeof(celula_t));
	lista->primeiro->prox = NULL;
	lista->ultimo = lista->primeiro;
	lista->tamanho = 0;
}

int vazia(lista_t *lista){
	return (lista->primeiro == lista->ultimo);
}

void insere(item_t item,lista_t *lista){

	lista->ultimo->prox = (apontador_t) malloc (sizeof(celula_t));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->prox = NULL;
	
	lista->ultimo->item = item;
	
	lista->tamanho ++;
}

item_t retira_primeiro( lista_t *lista ){
	item_t item_ret;
	apontador_t temp;

	lista->tamanho--;

	temp = lista->primeiro->prox;
	item_ret = temp->item;
	
	lista->primeiro->prox = temp->prox;
	
	if( temp->prox == NULL )
		lista->ultimo = lista->primeiro;
	
	free( temp );
	return item_ret;
}

void imprime(lista_t *lista){
	apontador_t aux;

	aux = lista->primeiro->prox;

	while(aux != NULL){
		printf("%s\t%d\n",aux->item.rotulo,aux->item.valor);
		aux = aux->prox;
	}

	printf("-------------------\n");

}

item_t* busca_item( char* rotulo,lista_t *lista){
	apontador_t aux;

	aux = lista->primeiro;

	while(aux->prox != NULL){

		if( strcmp(aux->prox->item.rotulo,rotulo) == 0 ){
			return &(aux->prox->item);
		}
		aux = aux->prox;
	}

	return NULL;
}

void libera_lista( lista_t * lista ){
	
	while( !vazia( lista ) ){
		retira_primeiro( lista );
	}

	free(lista);
}

