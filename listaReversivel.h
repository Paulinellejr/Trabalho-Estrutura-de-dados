#ifndef __LISTAREVERSIVEL_H__
#define __LISTAREVERSIVEL_H__

/* Declaração de constantes */

#define TAM 63

/* Inclusão de bibliotecas necessárias para o pacote */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Definição de estruturas e declaração de variáveis locais */

typedef struct data
{
    int dia, mes, ano;
} data;

typedef struct listagen
{
    void *info;
    struct listagen *prox;
} ListaGen;

typedef struct versao
{
    ListaGen *Lista;
    int quantV;
    struct versao *prox;

} Versao;

/* Cabeçalhos das funções com suas respectivas descrições */

////////////////////////////////////////////////////////////////////////

/* Funções referentes às versões do código */

/**
 * - Função: criaVersao
 * 
 * - Descrição: Aloca dinamicamente uma estrutura Versao e inicializa a lista com o dado passado como parâmetro.
 * 
 * @param L Ponteiro para a lista genérica.
 * 
 * @return Retorna um ponteiro para a estrutura Versao alocada dinamicamente.
 */
Versao *criaVersao(ListaGen *L);

/**
 * - Função: empilha
 * 
 * - Descrição: Empilha uma versão na pilha de versões.
 * 
 * @param V Ponteiro para a pilha de versões.
 * @param L Ponteiro para a lista genérica.
 * 
 * @return Retorna a nova pilha de versões com a versão empilhada.
 */
Versao *empilha(Versao **V, ListaGen *L);

/**
 * - Função: desempilha
 * 
 * - Descrição: Desempilha uma versão da pilha de versões.
 * 
 * @param V Ponteiro para a pilha de versões.
 * 
 * @return Retorna a pilha de versões com a versão desempilhada.
 */
Versao *desempilha(Versao **V);

/**
 * - Função: destroiAntigo
 * 
 * - Descrição: Destroi as versões antigas da pilha de versões.
 * 
 * @param V Ponteiro para a pilha de versões.
 * 
 * @return Retorna a pilha de versões com as versões antigas removidas.
 */
Versao *destroiAntigo(Versao *V);

////////////////////////////////////////////////////////////////////////

/* Funções referentes à lista reversível */

/**
 * - Função: criaListagen
 * 
 * - Descrição: Aloca dinamicamente uma estrutura ListaGen e inicializa o campo info com o dado passado como parâmetro.
 * 
 * @param dado Dado genérico a ser armazenado na lista.
 * 
 * @return Retorna um ponteiro para a estrutura ListaGen alocada dinamicamente.
 */
ListaGen *criaListagen(void *dado);

/**
 * - Função: insere
 * 
 * - Descrição: Insere um novo elemento na lista reversível, realizando a comparação com a chave de busca.
 * 
 * @param L Ponteiro para a lista reversível.
 * @param cb Função responsável por comparar as chaves.
 * @param ch Chave de busca a ser inserida.
 * 
 * @return Retorna a lista com o novo elemento inserido.
 */
ListaGen *insere(ListaGen *L, int (*cb)(void *, void *), void *ch);

/**
 * - Função: busca
 * 
 * - Descrição: Realiza a busca de um elemento na lista reversível, comparando com a chave de busca.
 * 
 * @param L Ponteiro para a lista reversível.
 * @param cb Função responsável por comparar as chaves.
 * @param ch Chave de busca a ser encontrada.
 * 
 * @return Retorna o ponteiro para o elemento encontrado, ou NULL se não encontrado.
 */
ListaGen *busca(ListaGen *L, int (*cb)(void *, void *), void *ch);

/**
 * - Função: removeChave
 * 
 * - Descrição: Remove um elemento da lista reversível, com base na chave de busca fornecida.
 * 
 * @param L Ponteiro para a lista reversível.
 * @param cb Função responsável por comparar as chaves.
 * @param ch Chave de busca a ser removida.
 * 
 * @return Retorna a lista com o elemento removido.
 */
ListaGen *removeChave(ListaGen *L, int (*cb)(void *, void *), void *ch);

/**
 * - Função: percorreListagen
 * 
 * - Descrição: Percorre a lista reversível, aplicando a função de callback em cada elemento.
 * 
 * @param L Ponteiro para a lista reversível.
 * @param cb Função de callback a ser aplicada em cada elemento da lista.
 * 
 * @return Não retorna nada, apenas executa a função de callback em cada elemento.
 */
void percorreListagen(ListaGen *L, void (*cb)(void *));

/**
 * - Função: desfazer
 * 
 * - Descrição: Desfaz a última operação realizada na lista reversível.
 * 
 * @param L Ponteiro para a lista reversível.
 * @param pilhaDesfazer Ponteiro para a pilha de versões de desfazer.
 * @param pilhaResfazer Ponteiro para a pilha de versões de refazer.
 * 
 * @return Retorna a lista após desfazer a operação.
 */
ListaGen *desfazer(ListaGen *L, Versao **pilhaDesfazer, Versao **pilhaResfazer);

/**
 * - Função: refazer
 * 
 * - Descrição: Refaz a última operação desfeita na lista reversível.
 * 
 * @param L Ponteiro para a lista reversível.
 * @param pilhaDesfazer Ponteiro para a pilha de versões de desfazer.
 * @param pilhaResfazer Ponteiro para a pilha de versões de refazer.
 * 
 * @return Retorna a lista após refazer a operação.
 */
ListaGen *refazer(ListaGen *L, Versao **pilhaDesfazer, Versao **pilhaResfazer);

#endif
