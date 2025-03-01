#include "listaReversivel.h"

ListaGen *criaListagen(void *dado)
{
    ListaGen *novo = (ListaGen *)calloc(1, sizeof(ListaGen));
    if (!novo)
    {
        printf("Nao foi possivel alocar memoria!");
        exit(1);
    }
    novo->info = dado;
    return novo;
}

ListaGen *insere(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    ListaGen *novo = criaListagen(ch);
    ListaGen *aux = L;
    ListaGen *pred = NULL;

    if (!L)
        return novo;

    while (aux != NULL && cb(aux->info, ch) < 0) // aux->info == struct
    {
        pred = aux;
        aux = aux->prox;
    }

    if (pred == NULL)
    {
        novo->prox = L;
        L = novo;
    }
    else
    {
        novo->prox = aux;
        pred->prox = novo;
    }

    return L;
}

void percorreListagen(ListaGen *L, void (*cb)(void *))
{
    ListaGen *aux = L;
    while (aux != NULL)
    {
        cb(aux->info);
        aux = aux->prox;
    }
}
