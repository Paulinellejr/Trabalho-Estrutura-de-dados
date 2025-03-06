#include "filme.h"

filme *criaFilme(char *titulo, char *diretor, char *distribuidor, char *pais, int duracao, int dia, int mes, int ano)
{
    filme *novo = (filme *)malloc(sizeof(filme));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para filme.\n");
        return NULL;
    }

    novo->publicacao = (data *)malloc(sizeof(data));
    if (novo->publicacao == NULL)
    {
        printf("Erro ao alocar memória para data de publicação.\n");
        free(novo);
        return NULL;
    }

    strcpy(novo->titulo, titulo);
    strcpy(novo->diretor, diretor);
    strcpy(novo->distribuidor, distribuidor);
    strcpy(novo->pais, pais);
    novo->duracao = duracao;
    novo->publicacao->dia = dia;
    novo->publicacao->mes = mes;
    novo->publicacao->ano = ano;

    return novo;
}

int comparaFilme(void *v, void *ch)
{
    filme *aux = (filme *)v;
    char *chave = (char *)ch;
    return strcmp(aux->titulo, chave);
}

void imprimeFilme(void *v)
{
    filme *aux = (filme *)v;
    printf("\nTitulo: %s\n", aux->titulo);
    printf("Diretor: %s\n", aux->diretor);
    printf("Distribuidor: %s\n", aux->distribuidor);
    printf("Pais: %s\n", aux->pais);
    printf("Duração: %dmin\n", aux->duracao);
    printf("Publicação: %d/%d/%d\n", aux->publicacao->dia, aux->publicacao->mes, aux->publicacao->ano);
}
