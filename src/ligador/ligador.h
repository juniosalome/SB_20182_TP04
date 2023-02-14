#ifndef LIGADOR_H
#define LIGADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "lista.h"

typedef struct{
	lista_t comandos;
	lista_t simbolos;
	lista_t progs;
	
} programa_t; 

void inicializa_programa( programa_t** prog );

void insere_programa( char* arquivo, programa_t* prog );

void monta_programa( programa_t* prog);

void destroi_programa( programa_t* prog );

void inicializaarquivos();

void finalizaarquivos();

#endif
