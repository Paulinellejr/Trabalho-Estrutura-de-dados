#ifndef __LIVRO_H__
#define __LIVRO_H__

#include "listaReversivel.h"

typedef struct livro
{
    char titulo[TAM], autor[TAM], editora[TAM], idioma[TAM];
    int paginas;
    data *publicacao;
} livro;

void imprimeLivro(void *v);

#endif