#include "vinho.h"

vinho *criaVinho()
{
    vinho *novo = (vinho *)calloc(1, sizeof(vinho));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria para vinho.\n");
        return NULL;
    }

    printf("Nome: ");
    getc(stdin);
    scanf("%[^\n]", novo->nome);
    strcpy(novo->nome, transMin(novo->nome));

    printf("Vinicola: ");
    getc(stdin);
    scanf("%[^\n]", novo->vinicola);

    int OpEx = 0;
    while (OpEx == 0)
    {
        printf("Tipo (tinto, branco, rose, espumante branco, espumante rose): ");
        getc(stdin);
        scanf("%[^\n]", novo->tipo);

        strcpy(novo->tipo, transMin(novo->tipo));
        if (strcmp(novo->tipo, "tinto") != 0 && strcmp(novo->tipo, "branco") != 0 && strcmp(novo->tipo, "rose") != 0 && strcmp(novo->tipo, "rose") != 0 && strcmp(novo->tipo, "espumante branco") != 0 && strcmp(novo->tipo, "espumante rose") != 0)
        {
            printf("\nOPCAO INEXISTENTE!\n\n");
        }
        else
            OpEx++;
    }

    printf("Pais: ");
    getc(stdin);
    scanf("%[^\n]", novo->pais);

    printf("Uva: ");
    getc(stdin);
    scanf("%[^\n]", novo->uva);

    printf("Regiao: ");
    getc(stdin);
    scanf("%[^\n]", novo->regiao);

    printf("Ano da fabricacao: ");
    scanf("%d", &novo->fabricacao);

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
    printf("Ano de fabricacao: %d\n", aux->fabricacao);
}
