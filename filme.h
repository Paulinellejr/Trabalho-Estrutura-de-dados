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
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
filme *criaFilme(char *titulo, char *diretor, char *distribuidor, char *pais, int duracao, int dia, int mes, int ano);

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
int comparaFilme(void *v, void *ch);

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
void imprimeFilme(void *v);

#endif