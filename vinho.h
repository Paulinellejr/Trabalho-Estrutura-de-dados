#ifndef __VINHO_H__
#define __VINHO_H__

#include "listaReversivel.h"

typedef struct vinho
{
    char nome[TAM], vinicola[TAM], pais[TAM], uva[TAM], regiao[TAM], tipo[TAM];
    data *fabricacao;
} vinho;

void imprimeVinho(void *v);
#endif
