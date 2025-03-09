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

ListaGen *criaListagen(void *dado)
{
    ListaGen *novo = (ListaGen *)calloc(1, sizeof(ListaGen));
    if (!novo)
    {
        printf("ERRO: Nao foi possivel alocar memoria!");
        exit(1);
    }
    novo->info = dado;
    return novo;
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

Versao *destroiAntigo(Versao *V)
{
    Versao *aux = V;
    Versao *pred = NULL;
    ListaGen *auxL;
    ListaGen *temp;

    while (aux->prox != NULL)
    {
        pred = aux;
        aux = aux->prox;
    }
    pred->prox = NULL;
    auxL = aux->Lista;

    while (auxL != NULL)
    {
        temp = auxL;
        auxL = auxL->prox;
        free(temp);
    }

    free(aux);

    return V;
}

Versao *esvaziar(Versao *V)
{
    Versao *aux = V;
    ListaGen *auxL;
    ListaGen *temp;

    while (V != NULL)
    {
        aux = V;
        V = aux->prox;
        auxL = aux->Lista;
        while (auxL != NULL)
        {
            temp = auxL;
            auxL = auxL->prox;
            free(temp);
        }
        free(aux);
    }

    return V;
}

ListaGen *copiaLista(ListaGen *L)
{
    ListaGen *L2 = NULL;
    ListaGen *aux = L;
    ListaGen *aux2 = NULL;
    while (aux != NULL)
    {
        if (L2 == NULL)
        {
            L2 = criaListagen(L->info);
            aux2 = L2;
        }
        else
        {
            aux2->prox = criaListagen(aux->info);
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }
    return L2;
}

ListaGen *insere(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    if (busca(L, cb, ch) != NULL)
    {
        printf("\nNao foi possivel inserir: chave ja existente na lista.\n");
        return L; // Retorna a lista original sem modificar
    }

    ListaGen *aux = L;
    ListaGen *novo = criaListagen(ch);
    ListaGen *aux2 = NULL;
    ListaGen *L2 = NULL;

    if (!L)
    {
        return novo;
    }

    while (aux->prox != NULL && cb(aux->info, ch) < 0)
    {
        if (L2 == NULL)
        {
            L2 = criaListagen(L->info);
            aux2 = L;
        }
        else
        {
            aux2->prox = criaListagen(aux->info);
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }

    if (aux2 == NULL)
    {
        novo->prox = L;
        L2 = novo;
    }
    else
    {
        novo->prox = aux;
        aux2->prox = novo;
    }
    printf("\nItem inserido com sucesso!\n");
    return L2;
}

ListaGen *removeChave(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    ListaGen *aux = L;  // auxiliar de copia
    ListaGen *auxB = L; // auxiliar de  busca
    ListaGen *pred = NULL;
    ListaGen *L2 = NULL;
    ListaGen *aux2 = NULL;

    while (auxB != NULL && cb(auxB->info, ch) != 0)
    {
        pred = auxB;
        auxB = auxB->prox;
    }

    if (auxB != NULL)
    {
        if (pred == NULL) // caso aux no inicio
        {
            L2 = aux->prox;
        }
        else
        {
            while (cb(aux->info, ch) != 0)
            {
                if (L2 == NULL)
                {
                    L2 = criaListagen(L->info);
                    aux2 = L2;
                }
                else
                {
                    aux2->prox = criaListagen(aux->info);
                    aux2 = aux2->prox;
                }
                aux = aux->prox;
            }
            aux2 = aux->prox;
        }
        printf("A chave foi removida da lista");
        return L2;
    }
    printf("Chave nao encontrada na lista.\n");

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

ListaGen *busca(ListaGen *L, int (*cb)(void *, void *), void *ch)
{
    ListaGen *aux = L;

    while (aux != NULL && cb(aux->info, ch) != 0)
    {
        aux = aux->prox;
    }
    return aux;
}

char *transMin(char aux[TAM])
{
    int tamanho = strlen(aux);
    for (int i = 0; i < tamanho; i++)
        aux[i] = tolower(aux[i]);
    return aux;
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
