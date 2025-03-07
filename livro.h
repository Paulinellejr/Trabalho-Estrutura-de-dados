#ifndef __LIVRO_H__
#define __LIVRO_H__

/*Inclusão de bibliotecas necessárias para o pacote*/

#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */
typedef struct livro
{
    char titulo[TAM], autor[TAM], editora[TAM], idioma[TAM];
    int paginas;
    data *publicacao;
} livro;

/* Cabeçalhos das funções com suas respectivas descrições */

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
livro *criaLivro(char *titulo, char *autor, char *editora, char *idioma, int pagina, int dia, int mes, int ano);

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
int comparaLivro(void *v, void *ch);

/*
Função: criaListagen
Descrição: Aloca dinamicamente uma estrutura ListeGen e inicializa o campo info passando com o dado como parametro.
Entrada:
void * dado: Dado genercido.
Sai­da:
ponteiro para a estrutura ListaGen  alocada dinâmicamente.
*/
void imprimeLivro(void *v);

#endif