#include "ligador.h"



int main( int argc, char* argv[] ){

	int i = 0, j = 0;
	num_arq_ligar = argc -5;

	entrada =(stEntrada *) malloc ( num_arq_ligar * sizeof(stEntrada));


	for( i = 1; i <= num_arq_ligar;i++){
		entrada[j].entrada  = argv[i];
		j++;

	}

	for ( j = i  ; j < argc; j++ ){
		if( strcmp( "-m", argv[j] ) == 0 ){
			arquivo_main = argv[j+1];
			j++;
		}
		else if( strcmp( "-o", argv[j] ) == 0 ){
			saida = argv[j+1] ;
			j++;
		}
	}




	inicializaarquivos();
	
	programa_t* programa_final;

	inicializa_programa( &programa_final );

	insere_programa( arquivo_main, programa_final );

	for ( i = 0; i < num_arq_ligar; i++ ){
		insere_programa( entrada[i].entrada, programa_final );
	}



	monta_programa( programa_final);

	finalizaarquivos();


	return 0;
}

