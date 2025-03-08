#include "filme.h"

filme *criaFilme()
{
    filme *novo = (filme *)malloc(sizeof(filme));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria para filme.\n");
        return NULL;
    }

    printf("Titulo: ");
    getc(stdin);
    scanf("%[^\n]", novo->titulo);

    printf("Diretor: ");
    getc(stdin);
    scanf("%[^\n]", novo->diretor);

    printf("Genero: ");
    getc(stdin);
    scanf("%[^\n]", novo->genero);

    printf("Distribuidor: ");
    getc(stdin);
    scanf("%[^\n]", novo->distribuidor);

    printf("Duracao do filme em minutos: ");
    scanf(" %d", &novo->duracao);

    printf("Pais de origem: ");
    getc(stdin);
    scanf("%[^\n]", novo->pais);

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
    printf("Duracao: %dmin\n", aux->duracao);
    printf("Pais: %s\n", aux->pais);
}
