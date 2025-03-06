#ifndef __FILME_H__
#define __FILME_H__

#include "listaReversivel.h"

typedef struct filme
{
    char titulo[TAM], diretor[TAM], genero[TAM], distribuidor[TAM], pais[TAM];
    int duracao; // em segundos
    data *publicacao;
} filme;

filme *criaFilme(char *titulo, char *diretor, char *distribuidor, char *pais, int duracao, int dia, int mes, int ano);
int comparaFilme(void *v, void *ch);
void imprimeFilme(void *v);

#endif