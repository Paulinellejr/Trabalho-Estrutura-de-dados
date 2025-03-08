#ifndef __CHOCOLATE_H__
#define __CHOCOLATE_H__

/* Inclusão de bibliotecas necessárias para o pacote */

#include "listaReversivel.h"

/* Definição de estruturas e declaração de variáveis locais */

typedef struct chocolate
{
    char nome[TAM];     // Nome do chocolate
    char marca[TAM];    // Marca do chocolate
    char origem[TAM];   // Origem do chocolate
    char tipo[TAM];     // Tipo do chocolate (ao leite, amargo ou branco)
    float porcentagem;  // percentual de cacau no chocolate
    float peso;          // Peso do chocolate
    data *fabricacao;   // Data de fabricação do chocolate
    data *validade;     // Data de validade do chocolate
} chocolate;

/**
 * - Função: criaChocolate
 * 
 * - Descrição: Aloca dinamicamente uma estrutura Chocolate e inicializa seus campos.
 * 
 * @return Retorna um ponteiro para a estrutura Chocolate alocada dinamicamente.
 */
chocolate *criaChocolate();

/**
 * - Função: comparaChocolate
 * 
 * - Descrição: responsável por comparar a chave de busca com a chave do nó da lista.
 * 
 * @param v Ponteiro para o nó da lista (chave do nó).
 * @param ch Ponteiro para a chave de busca.
 * 
 * @return Retorna zero se as chaves forem iguais;
 * @return Retorna um valor menor que zero se o primeiro caractere não correspondente da chave do nó for menor que o da chave de busca;
 * @return Retorna um valor maior que zero se o primeiro caractere não correspondente da chave do nó for maior que o da chave de busca.
 */
int comparaChocolate(void *v, void *ch);

/**
 * - Função: imprimeChocolate
 * 
 * - Descrição: responsável por imprimir os dados de um chocolate.
 * 
 * @param dado Ponteiro para o dado genérico que será impresso.
 * @return Não retorna nada, apenas imprime os dados do chocolate.
 */
void imprimeChocolate(void *v);

#endif
