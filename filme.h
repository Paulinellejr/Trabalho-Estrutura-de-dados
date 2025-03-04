#ifndef __FILME_H__
#define __FILME_H__

#include "listaReversivel.h"

typedef struct filme
{
    char titulo[TAM], diretor[TAM], genero[TAM], distribuidor[TAM], pais[TAM];
    int duracao; // em segundos
    data *publicacao;
} filme;

void imprimeFilme(void *v);

#endif