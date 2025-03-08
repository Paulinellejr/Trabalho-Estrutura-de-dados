
#include "chocolate.h"

chocolate *criaChocolate()
{
    chocolate *novo = (chocolate *)calloc(1, sizeof(chocolate));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para chocolate.\n");
        return NULL;
    }

    novo->fabricacao = (data *)malloc(sizeof(data));
    if (novo->fabricacao == NULL)
    {
        printf("Erro ao alocar memória para data.\n");
        free(novo);
        return NULL;
    }
    novo->validade = (data *)malloc(sizeof(data));
    if (novo->validade == NULL)
    {
        printf("Erro ao alocar memória para data.\n");
        free(novo);
        return NULL;
    }

    printf("Nome: ");
    getc(stdin);
    scanf("%[^\n]", novo->nome);
    printf("Marca: ");
    getc(stdin);
    scanf("%[^\n]", novo->marca);
    printf("Tipo de chocolate (ao leite, amargo ou branco): ");
    getc(stdin);
    scanf("%[^\n]", novo->tipo);
    if (strcmp(novo->tipo, "amargo") == 0)
    {
        printf("Porcentagem de cacau: ");
        scanf("%f", &novo->porcentagem);
    }
    printf("Quantidade de paginas: ");
    scanf("%f", &novo->peso);
    printf("Data da fabricação {dd mm aa}: ");
    scanf("%d %d %d", &novo->fabricacao->dia, &novo->fabricacao->mes, &novo->fabricacao->ano);
    printf("Data da Validade {dd mm aa}: ");
    scanf("%d %d %d", &novo->validade->dia, &novo->validade->mes, &novo->validade->ano);

    return novo;
}

int comparaChocolate(void *v, void *ch)
{
    chocolate *aux = (chocolate *)v;
    char *chocolate = (char *)ch;
    return strcmp(aux->nome, chocolate);
}

void imprimeChocolate(void *v)
{
    chocolate *aux = (chocolate *)v;
    printf("\nNome: %s\n", aux->nome);
    printf("Marca: %s\n", aux->marca);
    printf("Origem: %s\n", aux->origem);
    printf("Tipo: %s\n", aux->tipo);
    printf("porcentagem: %.1f%%\n", aux->porcentagem);
    printf("peso: %.1fg\n", aux->peso);
    printf("Fabricação: %d/%d/%d\n", aux->fabricacao->dia, aux->fabricacao->mes, aux->fabricacao->ano);
    printf("validade: %d/%d/%d\n", aux->validade->dia, aux->validade->mes, aux->validade->ano);
}
