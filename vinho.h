#ifndef __VINHO_H__
#define __VINHO_H__

/* Inclusão de bibliotecas necessárias para o pacote */

#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */

typedef struct vinho
{
    char nome[TAM], vinicola[TAM], pais[TAM], uva[TAM], regiao[TAM], tipo[TAM];
    data *fabricacao;
} vinho;

/* Cabeçalhos das funções com suas respectivas descrições */

/**
 * - Função: criaVinho
 * 
 * - Descrição: Aloca dinamicamente uma estrutura Vinho e inicializa seus campos.
 * 
 * @return Retorna um ponteiro para a estrutura Vinho alocada dinamicamente.
 */
vinho *criaVinho();

/**
 * - Função: comparaVinho
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
int comparaVinho(void *v, void *ch);

/**
 * - Função: imprimeVinho
 * 
 * - Descrição: Função responsável por imprimir os dados de um vinho.
 * 
 * @param v Ponteiro para o dado genérico (vinho) a ser impresso.
 * 
 * @return Não retorna nada, apenas imprime os dados.
 */
void imprimeVinho(void *v);

#endif
