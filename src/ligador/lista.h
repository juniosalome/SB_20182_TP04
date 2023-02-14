#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constantes.h"

typedef char* chave_t;

typedef struct{
	chave_t rotulo;
	int valor;
} item_t;

typedef struct celula_t *apontador_t;

typedef struct celula_t {
	item_t item;
	apontador_t prox;
} celula_t;


typedef struct{
	apontador_t primeiro,ultimo;
	int tamanho;
} lista_t;

void faz_lista_vazia(lista_t *lista);
int vazia(lista_t *lista);

void insere(item_t item,lista_t *lista);
item_t retira_primeiro( lista_t *lista );
item_t* busca_item( char* rotulo, lista_t *lista);
void imprime(lista_t *lista);
item_t gera_item( chave_t rotulo,int tamanho, int valor);
int obtem_valor( item_t item );
char* obtem_rotulo( item_t item );
void libera_lista( lista_t * lista );


#endif 
