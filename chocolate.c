#include "chocolate.h"

chocolate *criaChocolate(char *nome, char *marca, char *origem, char *tipo, float porcentagem, float peso, int fDia, int fMes, int fAno, int vDia, int vMes, int vAno)
{
    chocolate *novo = (chocolate *)malloc(sizeof(chocolate));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para chocolate.\n");
        return NULL;
    }

    novo->fabricacao = (data *)malloc(sizeof(data));
    if (novo->fabricacao == NULL)
    {
        printf("Erro ao alocar memória para data de fabricação.\n");
        free(novo);
        return NULL;
    }

    novo->validade = (data *)malloc(sizeof(data));
    if (novo->validade == NULL)
    {
        printf("Erro ao alocar memória para data de validade.\n");
        free(novo);
        return NULL;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->marca, marca);
    strcpy(novo->origem, origem);
    strcpy(novo->tipo, tipo);
    novo->porcentagem = porcentagem;
    novo->peso = peso;
    novo->fabricacao->dia = fDia;
    novo->fabricacao->mes = fMes;
    novo->fabricacao->ano = fAno;
    novo->validade->dia = vDia;
    novo->validade->mes = vMes;
    novo->validade->ano = vAno;

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
