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
Função: criaChocolate
Descrição: Aloca dinamicamente uma estrutura Chocolate e inicializa o campo info passando com o dado como parametro.
Entrada:
char *nome:
char *marca:
char *origem:
char *tipo:
float porcentagem:
float peso:
int fDia:
int fMes:
int fAno:
int vDia:
int vMes:
int vAno:
Sai­da:
ponteiro para a estrutura Chocolate alocada dinâmicamente.
*/
chocolate *criaChocolate();

/*
Função: comparaChocolate
Descrição: Função responsavel por comparar a chave de busca.
Entrada:
void * v: chave do nó da lista.
void *  ch: chave de busca;
Sai­da:
Retorna zero se as chaves forem iguais;
menor que zero primeiro caractere que não corresponde possui um valor inferior na chave do nó do que na chave de busca;
maior que zero primeiro caractere que não corresponde possui um valor maior na chave do nó do que na chave de busca;
*/
int comparaChocolate(void *v, void *ch);

/*
Função: imprimeChocolate
Descrição: Função resposavel  por  imprimir o dado.
Entrada:
void * dado: Dado genérico a ser impresso.
Sai­da:
Nao retorna nada.
*/
void imprimeChocolate(void *v);
#endif
