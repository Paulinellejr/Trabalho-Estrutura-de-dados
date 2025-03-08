
#include "listaReversivel.h"
#include "filme.h"
#include "livro.h"
#include "vinho.h"
#include "chocolate.h"

int main()
{
    ListaGen *V = NULL;
    ListaGen *C = NULL;
    ListaGen *L = NULL;
    ListaGen *F = NULL;
    Versao *pilhaDesfazer = NULL;
    Versao *pilhaRefazer = NULL;
    vinho *chaveV;
    filme *chaveF;
    chocolate *chaveC;
    livro *chaveL;
    ListaGen *aux;
    char chave[TAM];
    int dp, op;

    while (dp != 5)
    {
        printf("___________________\n");
        printf("Escolha um Produto\n");
        printf("1 - Chocolate \n");
        printf("2 - Vinho\n");
        printf("3 - Livro\n");
        printf("4 - Filme\n");
        printf("5 - Sair\n");
        printf("___________________\n");
        printf("Digite a opcao: ");
        scanf("%d", &dp);
        if (dp < 5 && dp > 0)
        {
            while (op != 7 && dp != 5)
            {
                printf("___________________\n");
                printf("Estoque do Produto:\n");
                printf("1 - Inserir\n");
                printf("2 - Remover\n");
                printf("3 - Imprimir\n");
                printf("4 - Buscar\n");
                printf("5 - Desfazer\n");
                printf("6 - Refazer\n");
                printf("7 - Sair\n");
                printf("___________________\n");
                printf("Digite a opcao: ");
                scanf("%d", &op);
                switch (op)
                {
                case 7:
                    printf("\n\nSaindo...\n\n");
                    break;
                case 1:
                    if (dp == 1)
                    {
                        chaveC = criaChocolate();
                        C = insere(C, comparaChocolate, chaveC);
                        pilhaDesfazer = empilha(&pilhaDesfazer, C);
                    }
                    else if (dp == 2)
                    {
                        chaveV = criaVinho();
                        V = insere(C, comparaChocolate, chaveV);
                        pilhaDesfazer = empilha(&pilhaDesfazer, V);
                    }
                    else if (dp == 3)
                    {
                        chaveL = criaLivro();
                        L = insere(L, comparaChocolate, chaveL);
                        pilhaDesfazer = empilha(&pilhaDesfazer, L);
                    }
                    else
                    {
                        chaveF = criaFilme();
                        F = insere(C, comparaChocolate, chaveF);
                        pilhaDesfazer = empilha(&pilhaDesfazer, F);
                    }
                    pilhaDesfazer->quantV++;
                    if (pilhaDesfazer->quantV == 20)
                    {
                        pilhaDesfazer = destroeAntigo(pilhaDesfazer);
                        pilhaDesfazer->quantV = 0;
                    }
                    printf("\n");
                    break;
                case 2:
                    printf("Digite a Nome/Titulo a ser removido: ");
                    getc(stdin);
                    scanf("%[^\n]", chave);
                    if (dp == 1)
                    {
                        C = removeChave(C, comparaChocolate, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, C);
                    }
                    else if (dp == 2)
                    {
                        V = removeChave(C, comparaChocolate, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, V);
                    }
                    else if (dp == 3)
                    {
                        L = removeChave(C, comparaChocolate, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, L);
                    }
                    else
                    {
                        F = removeChave(C, comparaChocolate, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, F);
                    }
                    printf("\n");
                    break;
                case 3:
                    printf("Estoque de");
                    if (dp == 1)
                    {
                        printf(" Chocolate\n");
                        percorreListagen(C, imprimeChocolate);
                    }
                    else if (dp == 2)
                    {
                        printf(" Vinho\n");
                        percorreListagen(V, imprimeVinho);
                    }
                    else if (dp == 3)
                    {
                        printf(" Livro\n");
                        percorreListagen(L, imprimeLivro);
                    }
                    else
                    {
                        printf(" Filme\n");
                        percorreListagen(F, imprimeFilme);
                    }

                    break;
                case 4:
                    if (dp == 1)
                    {
                        aux = busca(C, comparaChocolate, chave);
                        if (aux)
                        {
                            imprimeChocolate(aux);
                        }
                        else
                        {
                            printf("Chocolate nao encotrado.");
                        }
                    }
                    else if (dp == 2)
                    {
                        aux = busca(V, comparaVinho, chave);
                        if (aux)
                        {
                            imprimeVinho(aux);
                        }
                        else
                        {
                            printf("Vinho nao encotrado.");
                        }
                    }
                    else if (dp == 3)
                    {
                        aux = busca(L, comparaLivro, chave);
                        if (aux)
                        {
                            imprimeLivro(aux);
                        }
                        else
                        {
                            printf("Livro nao encotrado.");
                        }
                    }
                    else
                    {
                        aux = busca(F, comparaFilme, chave);
                        if (aux)
                        {
                            imprimeFilme(aux);
                        }
                        else
                        {
                            printf("Filme nao encotrado.");
                        }
                    }
                    break;
                case 5:
                    if (dp == 1)
                        C = desfazer(C, &pilhaDesfazer, &pilhaRefazer);
                    else if (dp == 2)
                        V = desfazer(V, &pilhaDesfazer, &pilhaRefazer);
                    else if (dp == 3)
                        L = desfazer(L, &pilhaDesfazer, &pilhaRefazer);
                    else
                        F = desfazer(F, &pilhaDesfazer, &pilhaRefazer);
                    printf("\n");
                    break;
                case 6:
                    if (dp == 1)
                        C = refazer(C, &pilhaDesfazer, &pilhaRefazer);
                    else if (dp == 2)
                        V = refazer(V, &pilhaDesfazer, &pilhaRefazer);
                    else if (dp == 3)
                        L = refazer(L, &pilhaDesfazer, &pilhaRefazer);
                    else
                        F = refazer(F, &pilhaDesfazer, &pilhaRefazer);
                    break;
                default:
                    printf("opcao inexistente!");
                    break;
                }
            }
        }
        else if (dp != 5)
        {
            printf("\n\nERRO: OPÇÃO INEXISTENTE!!\n\n ");
        }
    }
    printf("|--------------------|\n");
    printf("|Relatorio de estoque|\n");
    printf("|--------------------|\n");
    printf(" Estoque de Chocolate:\n");
    percorreListagen(C, imprimeChocolate);
    printf("\n\n");
    printf(" Estoque de Vinho:\n");
    percorreListagen(V, imprimeChocolate);
    printf("\n\n");
    printf(" Estoque de Livro:\n");
    percorreListagen(L, imprimeChocolate);
    printf("\n\n");
    printf(" Estoque de Filme\n");
    percorreListagen(F, imprimeChocolate);
    return 1;
}