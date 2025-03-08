#include "vinho.h"

vinho *criaVinho()
{
    vinho *novo = (vinho *)calloc(1, sizeof(vinho));
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

    printf("\nNome: ");
    getc(stdin);
    scanf("%[^\n]", novo->nome);
    printf("Viculo: ");
    getc(stdin);
    scanf("%[^\n]", novo->vinicola);
    printf("Tipo (tinto, branco, rosé, espumante branco, espumante rosé): ");
    getc(stdin);
    scanf("%[^\n]", novo->tipo);
    printf("Pais: ");
    getc(stdin);
    scanf("%[^\n]", novo->pais);
    printf("Uva: ");
    getc(stdin);
    scanf("%[^\n]", novo->uva);
    printf("Regiao: ");
    getc(stdin);
    scanf("%[^\n]", novo->regiao);
    printf("Ano da fabricação {dd mm aa} : ");
    scanf("%d %d %d", &novo->fabricacao->dia, &novo->fabricacao->mes, &novo->fabricacao->ano);

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
