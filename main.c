
#include "listaReversivel.h"
#include "filme.h"
#include "livro.h"
#include "vinho.h"
#include "chocolate.h"

int main()
{
    ListaGen *V = NULL;
    Versao *pilhaDesfazer = NULL;
    Versao *pilhaResfazer = NULL;

    // Exemplo de uso:
    // Insere um novo elemento
    vinho *chave = criaVinho("Nome", "pais", "regiao", "tipo", "vinicola", "uva", 1, 2, 2000);
    // Salva o estado atual na pilha "undo" antes da inserção
    V = insere(V, comparaVinho, chave);
    pilhaDesfazer = empilha(&pilhaDesfazer, V);
    chave = criaVinho("Juduca", "pais", "regiao", "tipo", "vinicola", "uva", 1, 2, 2000);

    V = insere(V, comparaVinho, chave);
    pilhaDesfazer = empilha(&pilhaDesfazer, V);
    chave = criaVinho("Butuca", "pais", "regiao", "tipo", "vinicola", "uva", 1, 2, 2000);

    V = insere(V, comparaVinho, chave);
    pilhaDesfazer = empilha(&pilhaDesfazer, V);

    percorreListagen(V, imprimeVinho);

    V = desfazer(V, &pilhaDesfazer, &pilhaResfazer);

    printf("________________________________________\n");

    // Desfaz a inserção

    percorreListagen(V, imprimeVinho);
    V = refazer(V, &pilhaDesfazer, &pilhaResfazer);
    printf("________________________________________\n");

    percorreListagen(V, imprimeVinho);

    // Refaz a inserçã
    // Código de limpeza aqui...

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