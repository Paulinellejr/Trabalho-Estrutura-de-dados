#include "vinho.h"

vinho *criaVinho(char *nome, char *pais, char *regiao, char *tipo, char *vinicola, char *uva, int dia, int mes, int ano)
{
    vinho *novo = (vinho *)malloc(sizeof(vinho));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para vinho.\n");
        return NULL;
    }

    novo->fabricacao = (data *)malloc(sizeof(data));
    if (novo->fabricacao == NULL)
    {
        printf("Erro ao alocar memória para data.\n");
        free(novo);
        return NULL;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->pais, pais);
    strcpy(novo->regiao, regiao);
    strcpy(novo->tipo, tipo);
    strcpy(novo->vinicola, vinicola);
    strcpy(novo->uva, uva);

    novo->fabricacao->ano = ano;
    novo->fabricacao->mes = mes;
    novo->fabricacao->dia = dia;
    return novo;
}

int comparaVinho(void *v, void *ch)
{
    vinho *aux = (vinho *)v;
    char *chave = (char *)ch;
    return strcmp(aux->nome, chave);
}

void imprimeVinho(void *v)
{
    vinho *aux = (vinho *)v;
    printf("\nNome: %s\n", aux->nome);
    printf("Vinicola: %s\n", aux->vinicola);
    printf("Pais: %s\n", aux->pais);
    printf("Uva: %s\n", aux->uva);
    printf("Regiao: %s\n", aux->regiao);
    printf("Tipo: %s\n", aux->tipo);
    printf("Fabricação: %d/%d/%d\n", aux->fabricacao->dia, aux->fabricacao->mes, aux->fabricacao->ano);
}
