#ifndef __FILME_H__
#define __FILME_H__

/*Inclusão de bibliotecas necessárias para o pacote*/
#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */
typedef struct filme
{
    char titulo[TAM], diretor[TAM], genero[TAM], distribuidor[TAM], pais[TAM];
    int duracao; // em segundos
    data *publicacao;
} filme;

/* Cabeçalhos das funções com suas respectivas descrições */

/*
Função: criaFilme
Descrição: Aloca dinamicamente uma estrutura Filme e inicializa o campo info passando com o dado como parametro.
Entrada:
char *titulo:
char *diretor:
char *distribuidor:
char *pais:
int duracao:
int dia:
int mes:
int ano:
Sai­da:
ponteiro para a estrutura Filme alocada dinâmicamente.
*/
filme *criaFilme(char *titulo, char *diretor, char *distribuidor, char *pais, int duracao, int dia, int mes, int ano);

/*
Função: comparaFilme
Descrição: Função responsavel por comparar a chave de busca.
Entrada:
void * v: chave do nó da lista.
void *  ch: chave de busca;
Sai­da:
Retorna zero se as chaves forem iguais;
menor que zero primeiro caractere que não corresponde possui um valor inferior na chave do nó do que na chave de busca;
maior que zero primeiro caractere que não corresponde possui um valor maior na chave do nó do que na chave de busca;*/
int comparaFilme(void *v, void *ch);

/*
Função: imprimeFilme
Descrição: Função resposavel  por  imprimir o dado.
Entrada:
void * dado: Dado genérico a ser impresso.
Sai­da:
Nao retorna nada.
*/
void imprimeFilme(void *v);

#endif