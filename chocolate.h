#ifndef __CHOCOLATE_H__
#define __CHOCOLATE_H__

/*Inclusão de bibliotecas necessárias para o pacote*/
#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */
typedef struct chocolate
{
    char nome[TAM], marca[TAM], origem[TAM], tipo[TAM]; // ao leite, amargo ou branco
    float porcentagem, peso;
    data *fabricacao, *validade;
} chocolate;

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
chocolate *criaChocolate(char *nome, char *marca, char *origem, char *tipo, float porcentagem, float peso, int fDia, int fMes, int fAno, int vDia, int vMes, int vAno);
/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
int comparaChocolate(void *v, void *ch);
/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
void imprimeChocolate(void *v);
#endif
