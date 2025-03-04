
#include "livro.h"

void imprimeLivro(void *v)
{
    livro *aux = (livro *)v;
    printf("Titulo: %c\n", aux->titulo);
    printf("Autor: %c\n", aux->autor);
    printf("Editora: %c\n", aux->editora);
    printf("Idioma: %c\n", aux->idioma);
    printf("Paginas: %d\n", aux->paginas);
    printf("Publicação: %d/%d/%d\n", aux->publicacao->dia, aux->publicacao->mes, aux->publicacao->ano);
}
