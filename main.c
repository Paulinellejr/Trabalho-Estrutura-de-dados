
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
    int dp, op;
    char chave[TAM];

    while (dp != 0)
    {
        printf("Escolha um Produto\n");
        printf("1 - Chocolate \n");
        printf("2 - Vinho\n");
        printf("3 - Livro\n");
        printf("4 - Filme\n ");
        printf("0 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &dp);
        while (op != 0 || dp != 0)
        {

            printf("___________________________ \n");
            printf("1 - Inserir \n");
            printf("2 - remover \n");
            printf("3 - imprimir  \n");
            printf("4 - desfazer");
            printf("5 - refazer");
            printf("0 - Sair \n");
            printf("Digite a opcao: ");
            scanf("%d", &op);
            switch (op)
            {
            case 0:
                printf("Saindo... ");
                break;
            case 1:
                if (dp == 1)
                {
                }
                pilhaDesfazer = empilha(&pilhaDesfazer, V);
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
                    percorreListagen(V, imprimeChocolate);
                }
                else if (dp == 3)
                {
                    printf(" Livro\n");
                    percorreListagen(L, imprimeChocolate);
                }
                else
                {
                    printf(" Filme\n");
                    percorreListagen(F, imprimeChocolate);
                }

                break;
            case 4:
                printf("undo");
                if (dp == 1)
                    pilhaDesfazer = desfazer(C, pilhaDesfazer, pilhaRefazer);
                else if (dp == 2)
                    pilhaDesfazer = desfazer(C, pilhaDesfazer, pilhaRefazer);
                else if (dp == 3)
                    pilhaDesfazer = desfazer(C, pilhaDesfazer, pilhaRefazer);
                else
                    pilhaDesfazer = desfazer(C, pilhaDesfazer, pilhaRefazer);
                printf("\n");
                break;
            case 5:
                printf("redo");
                break;
            default:
                printf("opcao inexistente!");
                break;
            }
        }
    }

    return 1;
}