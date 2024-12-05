#ifndef PIZZA_H_INCLUDED
#define PIZZA_H_INCLUDED

#include "ingredientes.h"

#define MAX_INGREDIENTES 10
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    char tamanho;
    float preco;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int qtd_ingredientes;
} Pizza;


void adicionarPizza();
void visualizarPizzas();
void editarPizza();
void removerPizza();

#endif // PIZZA_H_INCLUDED
