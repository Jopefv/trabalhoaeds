#include <stdio.h>
#include <string.h>
#include "ingredientes.h"

#define MAX_INGREDIENTES 100

Ingrediente ingredientes[MAX_INGREDIENTES];
int qtd_ingredientes = 0;

void exportarIngredientes() {
    FILE *arquivo = fopen("eximpingredientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao exportar ingrediente.\n");
        return;
    }

    for (int i = 0; i < qtd_ingredientes; i++) {
        fprintf(arquivo, "%d;%s;%.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }

    fclose(arquivo);
    printf("Dados exportados com sucesso o arquivo.\n");
}


void importarIngredientes() {
    FILE *arquivo = fopen("eximpingredientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao importar ingrediente.\n");
        return;
    }

    while (fscanf(arquivo, "%d;%[^;];%f\n", &ingredientes[qtd_ingredientes].id,
                  ingredientes[qtd_ingredientes].nome, &ingredientes[qtd_ingredientes].preco) == 3) {

        qtd_ingredientes++;
    }

    fclose(arquivo);
    printf("Dados importados com sucesso.\n");
}



void adicionarIngrediente() {
    if (qtd_ingredientes >= MAX_INGREDIENTES) {
        printf("Limite de ingredientes atingido.\n");
        return;
    }

    Ingrediente novoIngrediente;
    novoIngrediente.id = qtd_ingredientes + 1;

    printf("Nome do ingrediente: ");
    scanf(" %[^\n]", novoIngrediente.nome);

    printf("Preco do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    ingredientes[qtd_ingredientes++] = novoIngrediente;
    printf("Ingrediente adicionado com sucesso!\n");
}

void visualizarIngredientes() {
    printf("\n--- Lista de Ingredientes ---\n");
    for (int i = 0; i < qtd_ingredientes; i++) {
        printf("ID: %d | Nome: %s | Preco: %.2f\n",
               ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

void editarIngrediente() {
    int id;
    printf("ID do ingrediente para editar: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            printf("Novo nome: ");
            scanf(" %[^\n]", ingredientes[i].nome);
            printf("Novo preco: ");
            scanf("%f", &ingredientes[i].preco);
            printf("Ingrediente editado com sucesso!\n");
            return;
        }
    }
    printf("Ingrediente nao encontrado.\n");
}

void removerIngrediente() {
    int id;
    printf("ID do ingrediente para remover: ");
    scanf("%d", &id);

    for (int i = 0; i < qtd_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            for (int j = i; j < qtd_ingredientes - 1; j++) {
                ingredientes[j] = ingredientes[j + 1];
            }
            qtd_ingredientes--;
            printf("Ingrediente removido com sucesso!\n");
            return;
        }
    }
    printf("Ingrediente nao encontrado.\n");
}


