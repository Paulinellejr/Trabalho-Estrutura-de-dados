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
Função: criaVinho
Descrição: Aloca dinamicamente uma estrutura Vinho e inicializa o campo info passando com o dado como parametro.
Entrada:
char *nome:
char *pais:
char *regiao:
char *tipo:
char *vinicola:
char *uva:
int dia:
int mes:
int ano:
Sai­da:
ponteiro para a estrutura Vinho alocada dinâmicamente.
*/
vinho *criaVinho();

/*
Função: comparaVinho
Descrição: Função responsavel por comparar a chave de busca.
Entrada:
void * v: chave do nó da lista.
void *  ch: chave de busca;
Sai­da:
Retorna zero se as chaves forem iguais;
menor que zero primeiro caractere que não corresponde possui um valor inferior na chave do nó do que na chave de busca;
maior que zero primeiro caractere que não corresponde possui um valor maior na chave do nó do que na chave de busca;
*/
int comparaVinho(void *v, void *ch);
/*
Função: imprimeVinho
Descrição: Função resposavel  por  imprimir o dado.
Entrada:
void * dado: Dado genérico a ser impresso.
Sai­da:
Nao retorna nada.
*/
void imprimeVinho(void *v);

#endif
