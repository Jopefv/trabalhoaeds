#include <stdio.h>
#include <string.h>
#include "pizza.h"

#define MAX_PIZZAS 100

Pizza pizzas[MAX_PIZZAS];
int qtd_pizzas = 0;


void exportarPizzas() {
    FILE *arquivo = fopen("eximppizza.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao exportar pizzas.\n");
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
    printf("Pizzas exportadas com sucesso para arquivo.\n");
}

void importarPizzas() {
    FILE *arquivo = fopen("eximppizza.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao importar pizza.\n");
        return;
    }

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
    printf("Pizza adicionada com sucesso!\n");
}

void visualizarPizzas() {
    printf("\n--- Cardapio de Pizzas ---\n");
    for (int i = 0; i < qtd_pizzas; i++) {
        printf("ID: %d | Nome: %s | Tamanho: %c | Preco: %.2f\n",
               pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);
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
            printf("Pizza removida com sucesso!\n");
            return;
        }
    }
    printf("Pizza nao encontrada.\n");
}
