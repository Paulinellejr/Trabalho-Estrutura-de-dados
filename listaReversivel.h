#ifndef __LISTAREVERSIVEL_H__
#define __LISTAREVERSIVEL_H__

#define TAM 63

#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia, mes, ano;
} data;

typedef struct listagen
{
    void *info;
    struct listagen *prox;
} ListaGen;

ListaGen *cria_listagen(void *v);
ListaGen *insere(ListaGen *L, void *v);
void percorre_listagen(ListaGen *L, void (*cb)(void *));

#endif
