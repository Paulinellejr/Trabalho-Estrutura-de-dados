
#include "livro.h"

livro *criaLivro()
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

    printf("Titulo: ");
    getc(stdin);
    scanf("%[^\n]", novo->titulo);
    printf("Autor: ");
    getc(stdin);
    scanf("%[^\n]", novo->titulo);
    printf("Editora: ");
    getc(stdin);
    scanf("%[^\n]", novo->editora);
    printf("Idioma: ");
    getc(stdin);
    scanf("%[^\n]", novo->idioma);
    printf("Quantidade de paginas: ");
    scanf("%d", &novo->paginas);
    printf("Data de publiicacao {dd mm aa} : ");
    scanf("%d %d %d", &novo->publicacao->dia, &novo->publicacao->mes, &novo->publicacao->ano);

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
