/*
 * constantes.h
 *
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_

//Variaveis globais
int memory[1000];
int reg[8];
int PC;
int SP;
char PEP[2];

#define TAM_LINHA 100
#define TAM_SIMBOLO 100

//numero de arquivos para serem ligados
int num_arq_ligar;

//Modo de exibicao
char *modo;

//arquivo entrada
//char entrada[100][100];
typedef struct stEntrada{
	char *entrada;
}stEntrada;
stEntrada *entrada;
FILE* arq_entrada;
char *arquivo_main;

//arquivo saida
char *saida;
FILE* arq_saida;

/*
 * Estrutura que o mantem uma tabela de valores de opcode
 * */
enum OPCODE{
	opcode_ADD = 1,
	opcode_SUB = 2,
	opcode_AND = 3,
	opcode_OR = 4,
	opcode_XOR = 5,
	opcode_NOT = 6,
	opcode_JUMP = 7,
	opcode_JZ = 8,
	opcode_JNZ = 9,
	opcode_JN = 10,
	opcode_JNN = 11,
	opcode_PUSH = 12,
	opcode_POP = 13,
	opcode_CALL = 14,
	opcode_LOAD = 15,
	opcode_STORE = 16,
	opcode_READ = 17,
	opcode_WRITE = 18,
	opcode_COPY = 19,
	opcode_RET = 20,
	opcode_HALT = 21,
	opcode_WORD = 22,
	opcode_END = 23
};

#endif /* CONSTANTES_H_ */
