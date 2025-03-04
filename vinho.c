#include "vinho.h"

void imprimeVinho(void *v)
{
    vinho *aux = (vinho *)v;
    printf("Nome: %c\n", aux->nome);
    printf("Vinicola: %c\n", aux->vinicola);
    printf("Pais: %c\n", aux->pais);
    printf("Uva: %c\n", aux->uva);
    printf("Regiao: %c\n", aux->regiao);
    printf("Tipo: %c\n", aux->tipo);
    printf("Fabricação: %d/%d/%d\n", aux->fabricacao->dia, aux->fabricacao->mes, aux->fabricacao->ano);
}
