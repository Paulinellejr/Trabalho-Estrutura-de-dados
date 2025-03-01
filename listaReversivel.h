#ifndef __LISTAREVERSIVEL_H__
#define __LISTAREVERSIVEL_H__

#define TAM 63

/*Inclusão de bibliotecas necessárias para o pacote*/
#include <stdio.h>
#include <stdlib.h>

/* Definição de estruturas e declaração de variáveis locais */

typedef struct data
{
    int dia, mes, ano;
} data;

typedef struct listagen
{
    void *info;
    struct listagen *prox;
} ListaGen;

/* Cabeçalhos das funções com suas respectivas descrições */

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/

ListaGen *criaListagen(void *dado);

/*
Função: insere
Descrição:
??
Entrada:
ListaGen *L: Ponteiro para lista reversivel.
int (*cb)(void *, void *): função responsavel por comparar as chaves. Retorna 0 caso as chaves forem iguais, maior que 0  caso o valor do primeiro for maior que o segundo e menor que 0 caso o valor do primeiro for menor que o segundo
void *ch: chave de busca a ser inserida.
Sai­da:
ponteiro para a estrutura ListaGen alocada dinâmicamente.
*/

ListaGen *insere(ListaGen *L, int (*cb)(void *, void *), void *ch);

/*
Função: percorreListagen
Descrição:
??
Entrada:
ListaGen *L:??
void (*cb)(void *):??
Sai­da:
Não retorna nada.
*/

void percorreListagen(ListaGen *L, void (*cb)(void *));

#endif
