#include "listaReversivel.h"

Versao *criaVersao(ListaGen *L)
{
    Versao *novaV = (Versao *)calloc(1, sizeof(Versao));
    if (!novaV)
    {
        printf("ERRO: nao foi possivel alocar memoria!\n");
        exit(1);
    }
    novaV->Lista = L;
    return novaV;
}

Versao *empilha(Versao **V, ListaGen *L)
{
    Versao *novaV = criaVersao(L);
    novaV->prox = *V;
    return novaV;
}

Versao *desempilha(Versao **V)
{
    Versao *aux = *V;
    if (!*V)
    {
        return NULL;
    }
    (*V) = (*V)->prox;
    return aux;
}

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

ListaGen *copiarLista(ListaGen *L)
{
    if (!L)
        return NULL;

    ListaGen *novaCabeca = criaListagen(L->info);
    ListaGen *auxOriginal = L->prox;
    ListaGen *auxCopia = novaCabeca;

    while (auxOriginal)
    {
        auxCopia->prox = criaListagen(auxOriginal->info);
        auxCopia = auxCopia->prox;
        auxOriginal = auxOriginal->prox;
    }

    return novaCabeca;
}

ListaGen *insere(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    ListaGen *L2 = copiarLista(L);

    ListaGen *novo = criaListagen(ch);

    if (!L2)
    {
        return novo;
    }

    ListaGen *aux = L2;
    ListaGen *pred = NULL;

    while (aux && cb(aux->info, ch) < 0)
    {
        pred = aux;
        aux = aux->prox;
    }

    if (!pred)
    {
        novo->prox = L2;
        L2 = novo;
    }
    else
    {
        novo->prox = aux;
        pred->prox = novo;
    }

    return L2;
}
ListaGen *Busca(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    ListaGen *aux = L;
    while (aux != NULL && cb(aux->info, ch) != 0)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        printf("\nProduto encotrada!\n");
    }
    else
    {
        printf("\nProduto nao encotrado!\n");
    }
    return aux;
}

ListaGen *removeChave(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    ListaGen *aux = L;
    ListaGen *pred = NULL;
    if (!L)
    {
        printf("Nao ha nada no estoque");
        return NULL;
    }
    else
    {

        while (aux != NULL && cb(aux->info, ch) != 0)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (aux != NULL)
        {
            ListaGen *L2 = criaListagen(aux->info);
            ListaGen *aux2 = L2;
            if (pred == NULL)
            {
                L2 = aux->prox;
            }
            else
            {
                while (cb(aux->info, ch) != 0)
                {
                    aux2->prox = criaListagen(aux->info);
                    aux = aux->prox;
                }
                aux2 = aux->prox;
            }
            return L2;
        }
        else
        {
            printf("Chave nao encontrada na lista.\n");
            return L;
        }
    }
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

ListaGen *desfazer(ListaGen *L, Versao **pilhaDesfazer, Versao **pilhaRefazer)
{
    Versao *versaoAtual = desempilha(pilhaDesfazer);
    if (*pilhaDesfazer == NULL)
    {
        return L;
    }

    if (versaoAtual == NULL)
    {
        return L;
    }

    *pilhaRefazer = empilha(&(*pilhaRefazer), versaoAtual->Lista);

    ListaGen *versaoAnt = NULL;
    if (*pilhaDesfazer != NULL)
    {
        versaoAnt = (*pilhaDesfazer)->Lista;
    }

    free(versaoAtual);

    return versaoAnt;
}
ListaGen *refazer(ListaGen *L, Versao **pilhaDesfazer, Versao **pilhaRefazer)
{

    if (*pilhaRefazer == NULL)
    {
        return L;
    }
    Versao *versaoAtual = desempilha(pilhaRefazer);

    if (versaoAtual == NULL)
    {
        return L;
    }

    *pilhaDesfazer = empilha(&(*pilhaDesfazer), versaoAtual->Lista);

    ListaGen *versaoRef = versaoAtual->Lista;

    free(versaoAtual);

    return versaoRef;
}
