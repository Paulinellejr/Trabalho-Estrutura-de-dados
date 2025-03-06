
#include "livro.h"

livro *criaLivro(char *titulo, char *autor, char *editora, char *idioma, int pagina, int dia, int mes, int ano)
{
    livro *novo = (livro *)malloc(sizeof(livro));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para livro.\n");
        return NULL;
    }

    novo->publicacao = (data *)malloc(sizeof(data));
    if (novo->publicacao == NULL)
    {
        printf("Erro ao alocar memória para data.\n");
        free(novo);
        return NULL;
    }

    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    strcpy(novo->editora, editora);
    strcpy(novo->idioma, idioma);
    novo->paginas = pagina;
    novo->publicacao->dia = dia;
    novo->publicacao->mes = mes;
    novo->publicacao->ano = ano;

    return novo;
}

int comparaLivro(void *v, void *ch)
{
    livro *aux = (livro *)v;
    char *string = (char *)ch;
    return strcmp(aux->titulo, string);
}

void imprimeLivro(void *v)
{
    livro *aux = (livro *)v;
    printf("\nTitulo: %s\n", aux->titulo);
    printf("Autor: %s\n", aux->autor);
    printf("Editora: %s\n", aux->editora);
    printf("Idioma: %s\n", aux->idioma);
    printf("Paginas: %d\n", aux->paginas);
    printf("Publicação: %d/%d/%d\n", aux->publicacao->dia, aux->publicacao->mes, aux->publicacao->ano);
}
