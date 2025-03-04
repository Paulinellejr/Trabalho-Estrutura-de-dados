#include "listaReversivel.h"
#include "chocolate.h"
#include "vinho.h"
#include "livro.h"
#include "filme.h"

int main()
{
    ListaGen *C = NULL;
    ListaGen *V = NULL;
    ListaGen *L = NULL;
    ListaGen *F = NULL;

    int dp, op;

    while (dp != 0)
    {

        printf("Escolha\n");
        printf("1 - Chocolate \n");
        printf("2 - Vinho\n");
        printf("3 - Livro\n");
        printf("4 - Filme\n ");
        printf("0 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &dp);
        while (op != 0 || dp != 0)
        {

            printf("Opcao: \n");
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
                printf("Digite a chave:  ");
                printf("\n");
                break;
            case 2:
                printf("Digite a chave: ");
                printf("\n");
                break;
            case 3:
                printf("Imprime\n");
                percorreListagen(C, imprimeChocolate);
                break;
            case 4:
                printf("undo");
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
