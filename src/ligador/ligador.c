#include "ligador.h"

void inicializaarquivos() {
	arq_saida = fopen(saida, "w");
}

void finalizaarquivos() {

	fclose(arq_saida);
	free(entrada);

}

void inicializa_programa( programa_t** prog ){
	(*prog) = ( programa_t* ) malloc ( sizeof( programa_t ));
	
	faz_lista_vazia( &(*prog)->comandos );
	faz_lista_vazia( &(*prog)->simbolos );
	faz_lista_vazia( &(*prog)->progs );
}

void atualiza_tabela_simbolos( FILE *arq, int offset, programa_t* prog){
	char* linha, *simbolo;
	int ilc;
	item_t item;
	
	linha = ( char* ) malloc ( TAM_LINHA * sizeof( char ));
	simbolo = ( char* ) malloc ( TAM_SIMBOLO * sizeof( char ));
	
	fgets( linha, TAM_LINHA, arq );
	
	while( 1 ){
		fgets( linha, TAM_LINHA, arq );

		if( (strcmp( linha, "=*=*= FINAL TABELA SIMBOLOS =*=*=\n") == 0)  )
			break;
			
		sscanf(linha,"%s %d",simbolo,&ilc);
		
		item = gera_item( simbolo, strlen(simbolo) + 1, ilc + offset );
		insere( item, &(prog->simbolos) );
	}
}


int atualiza_comandos( FILE *arq, int offset, programa_t* prog){
	char* linha;
	int tamanho = 0;
	item_t item;
	
	linha = ( char* ) malloc ( TAM_LINHA * sizeof( char ));

	while( 1 ){
		fgets( linha, TAM_LINHA, arq );
		
		if( feof( arq ) )
			break;
		
		tamanho++;
		
		item = gera_item( linha, strlen(linha) + 1, 0 );
		insere( item, &(prog->comandos) );
		
	}
	
	return tamanho;
}

void insere_programa( char* arquivo, programa_t* prog ){
	item_t item;	
	static int offset = 0;
	FILE* arquivo_atual;

	item = gera_item( arquivo, strlen(arquivo) + 1, offset );
	insere( item, &(prog->progs) );

	arquivo_atual = fopen( arquivo, "r" );

	atualiza_tabela_simbolos( arquivo_atual, offset, prog );

	offset += atualiza_comandos( arquivo_atual, offset, prog );
	
	fclose( arquivo_atual );
}

void monta_programa( programa_t* prog){
	int ilc = 0;
	item_t item_atual, *item_simbolo;
	char* rotulo, *first, *second;
	int lidos;

	rotulo = ( char* ) malloc ( TAM_LINHA * sizeof( char ));
	first = ( char* ) malloc ( TAM_LINHA * sizeof( char ));
	second = ( char* ) malloc ( TAM_LINHA * sizeof( char ));
	
	while( !vazia( &(prog->comandos) ) ){
		item_atual = retira_primeiro( &(prog->comandos) );
		ilc++;
		
		rotulo = obtem_rotulo( item_atual );
		
		lidos = sscanf( rotulo, "%s %s", first, second );
		
		if( lidos == 2 ){
			item_simbolo = busca_item( second, &(prog->simbolos) );
			
			if( item_simbolo == NULL )
				printf("\nERROR - SIMBOLO %s DESCONHECIDO\n",second);
			
			fprintf( arq_saida, "%d\n", obtem_valor( *item_simbolo ) - ilc );
		}
		else{
			fprintf( arq_saida, "%s\n", first );
		}

	}
}

void destroi_programa( programa_t* prog ){
	
	libera_lista( &(prog->comandos) );
	libera_lista( &(prog->simbolos) );
	libera_lista( &(prog->progs) );
	
	free( prog );
}
