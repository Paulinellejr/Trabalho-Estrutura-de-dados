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
Função: criaLivro
Descrição: Aloca dinamicamente uma estrutura Livro e inicializa o campo info passando com o dado como parametro.
Entrada:
char *titulo:
char *autor:
char *idioma:
char *pais:
int pagina:
int dia:
int mes:
int ano:
Sai­da:
ponteiro para a estrutura Livro alocada dinâmicamente.
*/
livro *criaLivro(char *titulo, char *autor, char *editora, char *idioma, int pagina, int dia, int mes, int ano);

/*
Função: comparaLivro
Descrição: Função responsavel por comparar a chave de busca.
Entrada:
void * v: chave do nó da lista.
void *  ch: chave de busca;
Sai­da:
Retorna zero se as chaves forem iguais;
menor que zero primeiro caractere que não corresponde possui um valor inferior na chave do nó do que na chave de busca;
maior que zero primeiro caractere que não corresponde possui um valor maior na chave do nó do que na chave de busca;*/
int comparaLivro(void *v, void *ch);

/*
Função: imprimeLivro
Descrição: Função resposavel  por  imprimir o dado.
Entrada:
void * dado: Dado genérico a ser impresso.
Sai­da:
Nao retorna nada.
*/
void imprimeLivro(void *v);

#endif