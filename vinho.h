#ifndef __VINHO_H__
#define __VINHO_H__

#include "listaReversivel.h"

typedef struct vinho
{
    char nome[10], vinicola[10], pais[10], uva[10], regiao[10], tipo[10];
    data *fabricacao;
} vinho;

vinho *criaVinho(char *nome, char *pais, char *regiao, char *tipo, char *vinicola, char *uva, int dia, int mes, int ano);
int comparaVinho(void *v, void *ch);
void imprimeVinho(void *v);
#endif
