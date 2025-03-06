#ifndef __CHOCOLATE_H__
#define __CHOCOLATE_H__

#include "listaReversivel.h"

typedef struct chocolate
{
    char nome[TAM], marca[TAM], origem[TAM], tipo[TAM]; // ao leite, amargo ou branco
    float porcentagem, peso;
    data *fabricacao, *validade;
} chocolate;

chocolate *criaChocolate(char *nome, char *marca, char *origem, char *tipo, float porcentagem, float peso, int fDia, int fMes, int fAno, int vDia, int vMes, int vAno);
int comparaChocolate(void *v, void *ch);
void imprimeChocolate(void *v);
#endif
