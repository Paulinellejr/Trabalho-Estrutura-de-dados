#include "listaReversivel.h"

ListaGen *cria_listagen(void *v)
{
    ListaGen *novo = (ListaGen *)calloc(1, sizeof(ListaGen));
    if (!novo)
    {
        printf("Nao foi possivel alocar memoria!");
        exit(1);
    }
    novo->info = v;
    return novo;
}

ListaGen *insere(ListaGen *L, void *v)
{
    ListaGen *novo = cria_listagen(v);
    return novo;
}

void percorre_listagen(ListaGen *L, void (*cb)(void *))
{
    ListaGen *aux = L;
    while (aux != NULL)
    {
        cb(aux->info);
        aux = aux->prox;
    }
}
