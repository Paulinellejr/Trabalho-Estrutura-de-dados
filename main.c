#include "listaReversivel.h"
#include "chocolate.h"

int main()
{

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

            printf("__Arvore_Binaria_de_Busca__ \n");
            printf("1 - Inserir chave \n");
            printf("2 - remover chave \n");
            printf("3 - imprimir Arvore \n");
            printf("4 - undo");
            printf("5 - redo");
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
                printf("Arvore Binaria de Busca:\n");
                break;
            default:
                printf("opcao inexistente!");
                break;
            }
        }
    }
    return 1;
}
