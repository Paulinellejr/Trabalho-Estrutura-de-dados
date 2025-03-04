#include "chocolate.h"

void imprimeChocolate(void *v)
{
    chocolate *aux = (chocolate *)v;
    printf("Nome: %c\n", aux->nome);
    printf("Marca: %c\n", aux->marca);
    printf("Origem: %c\n", aux->origem);
    printf("Tipo: %c\n", aux->tipo);
    printf("porcentegem: %f\n", aux->porcentagem);
    printf("peso: %f\n", aux->peso);
    printf("Fabricação: %d/%d/%d\n", aux->fabricacao->dia, aux->fabricacao->mes, aux->fabricacao->ano);
    printf("validade: %d/%d/%d\n", aux->fabricacao->dia, aux->fabricacao->mes, aux->fabricacao->ano);
}
