#ifndef __VINHO_H__
#define __VINHO_H__

/*Inclusão de bibliotecas necessárias para o pacote*/
#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */
typedef struct vinho
{
    char nome[TAM], vinicola[TAM], pais[TAM], uva[TAM], regiao[TAM], tipo[TAM];
    data *fabricacao;
} vinho;

/* Cabeçalhos das funções com suas respectivas descrições */

/*
Função: refazer
Descrição:
??
Entrada:
ListaGen *L:??
void (*cb)(void *):??
Sai­da:
Não retorna nada.
*/
vinho *criaVinho(char *nome, char *pais, char *regiao, char *tipo, char *vinicola, char *uva, int dia, int mes, int ano);

/*
Função: refazer
Descrição:
??
Entrada:
ListaGen *L:??
void (*cb)(void *):??
Sai­da:
Não retorna nada.
*/
int comparaVinho(void *v, void *ch);

/*
Função: refazer
Descrição:
??
Entrada:
ListaGen *L:??
void (*cb)(void *):??
Sai­da:
Não retorna nada.
*/
void imprimeVinho(void *v);

#endif
