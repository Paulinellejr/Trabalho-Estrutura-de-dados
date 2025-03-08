#ifndef __FILME_H__
#define __FILME_H__

/* Inclusão de bibliotecas necessárias para o pacote */

#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */

typedef struct filme
{
    char titulo[TAM], diretor[TAM], genero[TAM], distribuidor[TAM], pais[TAM];
    int duracao; // em segundos
} filme;

/* Cabeçalhos das funções com suas respectivas descrições */

/**
 * - Função: criaFilme
 * 
 * - Descrição: Aloca dinamicamente uma estrutura Filme e inicializa os campos com os dados passados como parâmetro.
 * 
 * @param titulo Título do filme.
 * @param diretor Nome do diretor do filme.
 * @param distribuidor Nome do distribuidor do filme.
 * @param pais País de origem do filme.
 * @param duracao Duração do filme em segundos.
 * @param dia Dia de lançamento do filme.
 * @param mes Mês de lançamento do filme.
 * @param ano Ano de lançamento do filme.
 * 
 * @return Retorna um ponteiro para a estrutura Filme alocada dinamicamente.
 */
filme *criaFilme();

/**
 * - Função: comparaFilme
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
int comparaFilme(void *v, void *ch);

/**
 * - Função: imprimeFilme
 * 
 * - Descrição: Função responsável por imprimir os dados de um filme.
 * 
 * @param v Ponteiro para o dado genérico (filme) a ser impresso.
 * 
 * @return Não retorna nada, apenas imprime os dados.
 */
void imprimeFilme(void *v);

#endif
