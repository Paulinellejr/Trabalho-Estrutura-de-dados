#include "listaReversivel.h"

#include "filme.h"

int main()
{
    ListaGen *aux;
    ListaGen *V = NULL;
    filme *chave = criaFilme("Titulo", "Diretor", "Distribuidor", "Pais", 2000, 1, 2, 3000);
    V = insere(V, comparaFilme, chave);
    chave = criaFilme("MAchado", "autor", "Editora", "Idioma", 2000, 1, 2, 3000);
    V = insere(V, comparaFilme, chave);
    percorreListagen(V, imprimeFilme);
    V = removeChave(V, comparaFilme, chave);
    aux = Busca(V, comparaFilme, "Titulo");
    if (aux != NULL)
    {
        imprimeFilme(aux->info);
    }
    printf("\nRemove\n");
    percorreListagen(V, imprimeFilme);

    return 0;
}
// int dp, op;

// while (dp != 0)
// {

//     printf("Escolha\n");
//     printf("1 - Chocolate \n");
//     printf("2 - Vinho\n");
//     printf("3 - Livro\n");
//     printf("4 - Filme\n ");
//     printf("0 - Sair\n");
//     printf("Digite a opcao: ");
//     scanf("%d", &dp);
//     while (op != 0 || dp != 0)
//     {

//         printf("Opcao: \n");
//         printf("1 - Inserir \n");
//         printf("2 - remover \n");
//         printf("3 - imprimir  \n");
//         printf("4 - desfazer");
//         printf("5 - refazer");
//         printf("0 - Sair \n");
//         printf("Digite a opcao: ");
//         scanf("%d", &op);
//         switch (op)
//         {
//         case 0:
//             printf("Saindo... ");
//             break;
//         case 1:
//             printf("Digite a chave:  ");
//             printf("\n");
//             break;
//         case 2:
//             printf("Digite a chave: ");
//             printf("\n");
//             break;
//         case 3:
//             printf("Imprime\n");
//             percorreListagen(C, imprimeChocolate);
//             break;
//         case 4:
//             printf("undo");
//             break;
//         case 5:
//             printf("redo");
//             break;
//         default:
//             printf("opcao inexistente!");
//             break;
//         }
//     }
// }