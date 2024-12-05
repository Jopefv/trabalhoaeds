#include <stdio.h>
#include <string.h>
#include "pizza.h"

#define MAX_PIZZAS 100

Pizza pizzas[MAX_PIZZAS];
int qtd_pizzas = 0;

void exportarPizzas() {
    FILE *arquivo = fopen("eximppizza.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar pizzas.\n");
        return;
    }

    for (int i = 0; i < qtd_pizzas; i++) {
        fprintf(arquivo, "%d;%s;%c;%.2f;%d\n",
                pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho,
                pizzas[i].preco, pizzas[i].qtd_ingredientes);

        for (int j = 0; j < pizzas[i].qtd_ingredientes; j++) {
            fprintf(arquivo, "%d;%s\n", pizzas[i].ingredientes[j].id, pizzas[i].ingredientes[j].nome);
        }
    }

    fclose(arquivo);
}

void importarPizzas() {
    FILE *arquivo = fopen("eximppizza.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao importar pizzas.\n");
        return;
    }

    qtd_pizzas = 0; // Reiniciar a lista de pizzas

    while (fscanf(arquivo, "%d;%[^;];%c;%f;%d\n",
                  &pizzas[qtd_pizzas].id, pizzas[qtd_pizzas].nome,
                  &pizzas[qtd_pizzas].tamanho, &pizzas[qtd_pizzas].preco,
                  &pizzas[qtd_pizzas].qtd_ingredientes) == 5) {
        for (int i = 0; i < pizzas[qtd_pizzas].qtd_ingredientes; i++) {
            fscanf(arquivo, "%d;%[^\n]\n",
                   &pizzas[qtd_pizzas].ingredientes[i].id, pizzas[qtd_pizzas].ingredientes[i].nome);
        }
        qtd_pizzas++;
    }

    fclose(arquivo);
    printf("Pizzas importadas com sucesso.\n");
}

void adicionarPizza() {
    if (qtd_pizzas >= MAX_PIZZAS) {
        printf("Limite de pizzas atingido.\n");
        return;
    }

    Pizza novaPizza;
    novaPizza.id = qtd_pizzas + 1;

    printf("Nome da pizza: ");
    scanf(" %[^\n]", novaPizza.nome);

    printf("Tamanho (P/M/G): ");
    scanf(" %c", &novaPizza.tamanho);

    printf("Preco base: ");
    scanf("%f", &novaPizza.preco);

    printf("Numero de ingredientes padrao: ");
    scanf("%d", &novaPizza.qtd_ingredientes);

    for (int i = 0; i < novaPizza.qtd_ingredientes; i++) {
        printf("Ingrediente %d (id e nome): ", i + 1);
        scanf("%d %[^\n]", &novaPizza.ingredientes[i].id, novaPizza.ingredientes[i].nome);
    }

    pizzas[qtd_pizzas++] = novaPizza;
    exportarPizzas();
    printf("Pizza adicionada com sucesso!\n");
}

void visualizarPizzas() {
    printf("\n--- Cardapio de Pizzas ---\n");
    for (int i = 0; i < qtd_pizzas; i++) {
        printf("ID: %d | Nome: %s | Tamanho: %c | Preco: %.2f\n",
               pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);

        printf("Ingredientes:\n");
        for (int j = 0; j < pizzas[i].qtd_ingredientes; j++) {
            printf("\tID: %d | Nome: %s\n",
                   pizzas[i].ingredientes[j].id, pizzas[i].ingredientes[j].nome);
        }
    }
}

void editarPizza() {
    int id;
    printf("ID da pizza para editar: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd_pizzas; i++) {
        if (pizzas[i].id == id) {
            printf("Novo nome: ");
            scanf(" %[^\n]", pizzas[i].nome);
            printf("Novo tamanho (P/M/G): ");
            scanf(" %c", &pizzas[i].tamanho);
            printf("Novo preco: ");
            scanf("%f", &pizzas[i].preco);

            printf("Editar quantidade de ingredientes (atual: %d): ", pizzas[i].qtd_ingredientes);
            scanf("%d", &pizzas[i].qtd_ingredientes);

            for (int j = 0; j < pizzas[i].qtd_ingredientes; j++) {
                printf("Ingrediente %d (id e nome): ", j + 1);
                scanf("%d %[^\n]", &pizzas[i].ingredientes[j].id, pizzas[i].ingredientes[j].nome);
            }

            exportarPizzas();
            printf("Pizza editada com sucesso!\n");
            return;
        }
    }
    printf("Pizza nao encontrada.\n");
}

void removerPizza() {
    int id;
    printf("ID da pizza para remover: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd_pizzas; i++) {
        if (pizzas[i].id == id) {
            for (int j = i; j < qtd_pizzas - 1; j++) {
                pizzas[j] = pizzas[j + 1];
            }
            qtd_pizzas--;
            exportarPizzas();
            printf("Pizza removida com sucesso!\n");
            return;
        }
    }
    printf("Pizza nao encontrada.\n");
}


void venderPizza() {
    int idPizza, qtdExtras, idExtra;
    float precoFinal = 0;

    printf("\n--- Realizar Venda de Pizza ---\n");

    // Exibir pizzas disponíveis
    visualizarPizzas();

    // Selecionar pizza
    printf("\nDigite o ID da pizza que deseja vender: ");
    scanf("%d", &idPizza);

    // Buscar pizza pelo ID
    Pizza *pizzaSelecionada = NULL;
    for (int i = 0; i < qtd_pizzas; i++) {
        if (pizzas[i].id == idPizza) {
            pizzaSelecionada = &pizzas[i];
            break;
        }
    }

    if (pizzaSelecionada == NULL) {
        printf("Pizza não encontrada!\n");
        return;
    }

    // Exibir detalhes da pizza selecionada
    printf("\nPizza Selecionada: %s\n", pizzaSelecionada->nome);
    printf("Preço Base: %.2f\n", pizzaSelecionada->preco);
    precoFinal = pizzaSelecionada->preco;

    // Adicionar ingredientes extras
    printf("\nDeseja adicionar ingredientes extras? (0 = Não, 1 = Sim): ");
    int adicionarExtras;
    scanf("%d", &adicionarExtras);

    if (adicionarExtras) {
        printf("Quantos ingredientes extras deseja adicionar? ");
        scanf("%d", &qtdExtras);

        for (int i = 0; i < qtdExtras; i++) {
            // Exibir ingredientes disponíveis
            visualizarIngredientes();

            printf("\nDigite o ID do ingrediente extra %d: ", i + 1);
            scanf("%d", &idExtra);

            // Buscar ingrediente pelo ID
            Ingrediente *ingredienteSelecionado = NULL;
            for (int j = 0; j < qtd_ingredientes; j++) {
                if (ingredientes[j].id == idExtra) {
                    ingredienteSelecionado = &ingredientes[j];
                    break;
                }
            }

            if (ingredienteSelecionado == NULL) {
                printf("Ingrediente não encontrado! Ignorando...\n");
                continue;
            }

            // Adicionar preço do ingrediente ao preço final
            printf("Ingrediente Adicionado: %s (%.2f)\n", ingredienteSelecionado->nome, ingredienteSelecionado->preco);
            precoFinal += ingredienteSelecionado->preco;
        }
    }

    // Exibir preço final
    printf("\n--- Venda Finalizada ---\n");
    printf("Pizza: %s\n", pizzaSelecionada->nome);
    printf("Preço Final: %.2f\n", precoFinal);
    printf("--------------------------\n");
}