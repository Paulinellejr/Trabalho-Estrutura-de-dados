#ifndef __LIVRO_H__
#define __LIVRO_H__

/* Inclusão de bibliotecas necessárias para o pacote */

#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */

typedef struct livro
{
    char titulo[TAM];     // Título do livro.
    char autor[TAM];      // Nome do autor do livro.
    char editora[TAM];    // Nome da editora do livro.
    char idioma[TAM];     // Idioma em que o livro está escrito.
    int paginas;          // Número de páginas que o livro possui.
    data *publicacao;     // Data de publicação do Livro.
} livro;

/* Cabeçalhos das funções com suas respectivas descrições */

/**
 * - Função: criaLivro
 * 
 * - Descrição: Aloca dinamicamente uma estrutura Livro e inicializa seus campos.
 * 
 * @return Retorna um ponteiro para a estrutura Livro alocada dinamicamente.
 */
livro *criaLivro();

/**
 * - Função: comparaLivro
 * 
 * - Descrição: Função responsável por comparar a chave de busca.
 * 
 * @param v Ponteiro para a chave do nó da lista.
 * @param ch Ponteiro para a chave de busca.
 * 
 * @return Retorna zero se as chaves forem iguais.
 * @return Retorna um valor menor que zero se o primeiro caractere que não corresponde possui um valor inferior na chave do nó.
 * @return Retorna um valor maior que zero se o primeiro caractere que não corresponde possui um valor maior na chave do nó.
 */
int comparaLivro(void *v, void *ch);

/**
 * - Função: imprimeLivro
 * 
 * - Descrição: Função responsável por imprimir os dados de um livro.
 * 
 * @param v Ponteiro para o dado genérico (livro) a ser impresso.
 * 
 * @return Não retorna nada, apenas imprime os dados.
 */
void imprimeLivro(void *v);

#endif
