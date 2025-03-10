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
    int dp = 0, op = 0;

    while (dp != 5)
    {
        system("cls || clear");
        printf("\n+----------------------------+\n");
        printf("|     ESCOLHA UM PRODUTO     |\n");
        printf("+----------------------------+\n");
        printf("1 - Chocolate \n");
        printf("2 - Vinho\n");
        printf("3 - Livro\n");
        printf("4 - Filme\n");
        printf("5 - Sair\n");
        printf("------------------------------\n");
        printf("Digite a opcao: ");
        scanf("%d", &dp);

        if (dp < 5 && dp > 0)
        {
            op = 0;
            while (op != 7 && dp != 5)
            {
                system("cls || clear");
                printf("\n+----------------------------+\n");
                printf("|     ESTOQUE DO PRODUTO     |\n");
                printf("+----------------------------+\n");
                printf("1 - Inserir\n");
                printf("2 - Remover\n");
                printf("3 - Imprimir\n");
                printf("4 - Buscar\n");
                printf("5 - Desfazer\n");
                printf("6 - Refazer\n");
                printf("7 - Voltar\n");
                printf("------------------------------\n");
                printf("Digite a opcao: ");
                scanf("%d", &op);
                system("cls || clear");

                switch (op)
                {
                case 7:
                    if (dp == 1)
                        C = copiaLista(C);
                    else if (dp == 2)
                        V = copiaLista(V);
                    else if (dp == 3)
                        L = copiaLista(L);
                    else
                        F = copiaLista(F);
                    pilhaDesfazer = esvaziar(pilhaDesfazer);
                    pilhaRefazer = esvaziar(pilhaRefazer);
                    system("cls || clear");
                    break;

                case 1:
                    if (dp == 1)
                    {
                        printf("\nInserindo Chocolate:\n\n");
                        chaveC = criaChocolate();
                        C = insere(C, comparaChocolate, chaveC);
                        pilhaDesfazer = empilha(&pilhaDesfazer, C);
                    }
                    else if (dp == 2)
                    {
                        printf("\nInserindo Vinho:\n\n");
                        chaveV = criaVinho();
                        V = insere(V, comparaVinho, chaveV);
                        pilhaDesfazer = empilha(&pilhaDesfazer, V);
                    }
                    else if (dp == 3)
                    {
                        printf("\nInserindo Livro:\n\n");
                        chaveL = criaLivro();
                        L = insere(L, comparaLivro, chaveL);
                        pilhaDesfazer = empilha(&pilhaDesfazer, L);
                    }
                    else if (dp == 4)
                    {
                        printf("\nInserindo Filme:\n\n");
                        chaveF = criaFilme();
                        F = insere(F, comparaFilme, chaveF);
                        pilhaDesfazer = empilha(&pilhaDesfazer, F);
                    }

                    pilhaDesfazer->quantV++;

                    if (pilhaDesfazer->quantV == 20)
                    {
                        pilhaDesfazer = destroiAntigo(pilhaDesfazer);
                        pilhaDesfazer->quantV = 0;
                    }
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
                    break;

                case 2:
                    printf("Digite o Nome/Titulo a ser removido: ");
                    getc(stdin);
                    scanf("%[^\n]", chave);

                    if (dp == 1)
                    {
                        C = removeChave(C, comparaChocolate, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, C);
                    }
                    else if (dp == 2)
                    {
                        V = removeChave(V, comparaVinho, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, V);
                    }
                    else if (dp == 3)
                    {
                        L = removeChave(L, comparaLivro, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, L);
                    }
                    else
                    {
                        F = removeChave(F, comparaFilme, chave);
                        pilhaDesfazer = empilha(&pilhaDesfazer, F);
                    }
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
                    break;

                case 3:
                    printf("\nEstoque de ");
                    if (dp == 1)
                    {
                        printf("Chocolate\n");
                        printf("------------------------------\n");
                        percorreListagen(C, imprimeChocolate);
                    }
                    else if (dp == 2)
                    {
                        printf("Vinho\n");
                        printf("------------------------------\n");
                        percorreListagen(V, imprimeVinho);
                    }
                    else if (dp == 3)
                    {
                        printf("Livro\n");
                        printf("------------------------------\n");
                        percorreListagen(L, imprimeLivro);
                    }
                    else
                    {
                        printf("Filme\n");
                        printf("------------------------------\n");
                        percorreListagen(F, imprimeFilme);
                    }
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
                    break;

                case 4:
                    printf("\nDigite a chave a ser buscada: ");
                    getc(stdin);
                    scanf("%[^\n]", chave);
                    if (dp == 1)
                    {
                        aux = busca(C, comparaChocolate, chave);
                        if (aux)
                        {
                            imprimeChocolate(aux->info);
                        }
                        else
                        {
                            printf("Chocolate nao encontrado.\n");
                        }
                    }
                    else if (dp == 2)
                    {
                        aux = busca(V, comparaVinho, chave);
                        if (aux)
                        {
                            imprimeVinho(aux->info);
                        }
                        else
                        {
                            printf("Vinho nao encontrado.\n");
                        }
                    }
                    else if (dp == 3)
                    {
                        aux = busca(L, comparaLivro, chave);
                        if (aux)
                        {
                            imprimeLivro(aux->info);
                        }
                        else
                        {
                            printf("Livro nao encontrado.\n");
                        }
                    }
                    else
                    {
                        aux = busca(F, comparaFilme, chave);
                        if (aux)
                        {
                            imprimeFilme(aux->info);
                        }
                        else
                        {
                            printf("Filme nao encontrado.\n");
                        }
                    }
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
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
                    printf("\nOperacao desfeita!\n");
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
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
                    printf("\nOperacao refeita!\n");
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
                    break;

                default:
                    printf("\nOpcao inexistente!\n");
                    printf("\nPressione 'Enter' para continuar...\n");
                    getc(stdin);
                    getc(stdin);
                    break;
                }
            }
        }
        else if (dp != 5)
        {
            system("cls || clear");
            printf("\nOPCAO INEXISTENTE!\n");
            printf("\nPressione 'Enter' para continuar...\n");
            getc(stdin);
            getc(stdin);
        }
    }
    system("cls || clear");

    printf("\n+----------------------------+\n");
    printf("|    RELATORIO DE ESTOQUE    |\n");
    printf("+----------------------------+\n");
    printf("Estoque de Chocolate:\n");
    percorreListagen(C, imprimeChocolate);
    printf("\n------------------------------\n");
    printf("Estoque de Vinho:\n");
    percorreListagen(V, imprimeVinho);
    printf("\n------------------------------\n");
    printf("Estoque de Livro:\n");
    percorreListagen(L, imprimeLivro);
    printf("\n------------------------------\n");
    printf("Estoque de Filme:\n");
    percorreListagen(F, imprimeFilme);
    printf("\n------------------------------\n");

    printf("\nSaindo do programa...\n\n");

    return 0;
}
