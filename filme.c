

#include "filme.h"

void imprimeFilme(void *v)
{
    filme *aux = (filme *)v;
    printf("Titulo: %c\n", aux->titulo);
    printf("Diretor: %c\n", aux->diretor);
    printf("Distribuidor: %c\n", aux->distribuidor);
    printf("Pais: %c\n", aux->pais);
    printf("Duração: %d\n", aux->duracao);
    printf("Publicação: %d/%d/%d\n", aux->publicacao->dia, aux->publicacao->mes, aux->publicacao->ano);
}
