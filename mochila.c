#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_STRING 50

struct Item {
    char nome[TAM_STRING];
    char tipo[TAM_STRING];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===============================\n");
        printf(" MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
        printf("===============================\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                if (totalItens >= MAX_ITENS) {
                    printf("\n Mochila cheia! Capacidade máxima atingida.\n");
                    break;
                }

                printf("\n--- ADICIONAR ITEM ---\n");
                printf("Nome do item: ");
                fgets(mochila[totalItens].nome, TAM_STRING, stdin);
                mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0;

                printf("Tipo do item: cura, arma, municao, etc.: ");
                fgets(mochila[totalItens].tipo, TAM_STRING, stdin);
                mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0;

                printf("Quantidade: ");
                scanf("%d", &mochila[totalItens].quantidade);
                getchar();

                printf("\nItem '%s' adicionado com sucesso!\n", mochila[totalItens].nome);
                totalItens++;

                // Mostrar listagem após adicionar
                printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", totalItens, MAX_ITENS);
                printf("------------------------------------------------------------\n");
                printf("NOME                 | TIPO            | QUANTIDADE\n");
                printf("------------------------------------------------------------\n");
                for (int i = 0; i < totalItens; i++) {
                    printf("%-20s | %-15s | %-10d\n",
                           mochila[i].nome,
                           mochila[i].tipo,
                           mochila[i].quantidade);
                }
                printf("------------------------------------------------------------\n");
                break;
            }

            case 2: {
                if (totalItens == 0) {
                    printf("\n Nenhum item na mochila para remover.\n");
                    break;
                }

                char nomeRemover[TAM_STRING];
                printf("\n--- REMOVER ITEM ---\n");
                printf("Digite o nome do item que deseja remover: ");
                fgets(nomeRemover, TAM_STRING, stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = 0;

                int encontrado = 0;
                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        for (int j = i; j < totalItens - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        totalItens--;
                        encontrado = 1;
                        printf("\n Item '%s' removido com sucesso!\n", nomeRemover);
                        break;
                    }
                }

                if (!encontrado) {
                    printf("\n Item nao encontrado.\n");
                } else {
                    printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", totalItens, MAX_ITENS);
                    printf("------------------------------------------------------------\n");
                    printf("NOME                 | TIPO            | QUANTIDADE\n");
                    printf("------------------------------------------------------------\n");
                    if (totalItens == 0)
                        printf("Mochila vazia.\n");
                    else {
                        for (int i = 0; i < totalItens; i++) {
                            printf("%-20s | %-15s | %-10d\n",
                                   mochila[i].nome,
                                   mochila[i].tipo,
                                   mochila[i].quantidade);
                        }
                    }
                    printf("------------------------------------------------------------\n");
                }
                break;
            }

            case 3: {
                printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", totalItens, MAX_ITENS);
                printf("------------------------------------------------------------\n");
                printf("NOME                 | TIPO            | QUANTIDADE\n");
                printf("------------------------------------------------------------\n");

                if (totalItens == 0) {
                    printf("Mochila vazia.\n");
                } else {
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s | %-15s | %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }

                printf("------------------------------------------------------------\n");
                break;
            }

            case 0:
                printf("\n Encerrando o programa... Boa sorte na ilha!\n");
                break;

            default:
                printf("\n Opcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
