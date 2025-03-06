#ifndef __LIVRO_H__
#define __LIVRO_H__

#include "listaReversivel.h"

typedef struct livro
{
    char titulo[TAM], autor[TAM], editora[TAM], idioma[TAM];
    int paginas;
    data *publicacao;
} livro;

livro *criaLivro(char *titulo, char *autor, char *editora, char *idioma, int pagina, int dia, int mes, int ano);
int comparaLivro(void *v, void *ch);
void imprimeLivro(void *v);

#endif