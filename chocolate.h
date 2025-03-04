#ifndef __CHOCOLATE_H__
#define __CHOCOLATE_H__

#include "listaReversivel.h"

typedef struct chocolate
{
    char nome[TAM], marca[TAM], origem[TAM], tipo[TAM]; // ao leite, amargo ou branco
    float porcentagem, peso;
    data *fabricacao, *validade;
} chocolate;

void imprimeChocolate(void *v);
#endif
