#include <stdio.h>
#include "pizza.h"
#include "ingredientes.h"

void menuPizzas() {
    int opcao;
    do {
        printf("\n=== Gerenciamento de Pizzas ===\n");
        printf("1. Adicionar Pizza\n");
        printf("2. Visualizar Pizzas\n");
        printf("3. Editar Pizza\n");
        printf("4. Remover Pizza\n");
        printf("0. Voltar ao menu principal\n");
        printf("================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPizza();
                break;
            case 2:
                visualizarPizzas();
                break;
            case 3:
                editarPizza();
                break;
            case 4:
                removerPizza();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuIngredientes() {
    int opcao;
    do {
        printf("\n=== Gerenciamento de Ingredientes ===\n");
        printf("1. Adicionar Ingrediente\n");
        printf("2. Visualizar Ingredientes\n");
        printf("3. Editar Ingrediente\n");
        printf("4. Remover Ingrediente\n");
        printf("0. Voltar ao menu principal\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarIngrediente();
                break;
            case 2:
                visualizarIngredientes();
                break;
            case 3:
                editarIngrediente();
                break;
            case 4:
                removerIngrediente();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void exibirMenu() {
    printf("\n===== Sistema de Gerenciamento de Pizzaria =====\n");
    printf("1. Gerenciar Pizzas\n");
    printf("2. Gerenciar Ingredientes\n");
    printf("3. Realizar Venda\n");
    printf("4. Exportar Dados de Pizzas\n");
    printf("5. Importar Dados de Pizzas\n");
    printf("6. Exportar Dados de Ingredientes\n");
    printf("7. Importar Dados de Ingredientes\n");
    printf("0. Sair do Sistema\n");
    printf("===============================================\n");
}

int main() {
    int opcao;
    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuPizzas();
                break;
            case 2:
                menuIngredientes();
                break;
            case 3:
                printf("Função de vendas ainda não implementada.\n");
                break;
            case 4:
                exportarPizzas();
                break;
            case 5:
                importarPizzas();
                break;
            case 6:
                exportarIngredientes();
                break;
            case 7:
                importarIngredientes();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
