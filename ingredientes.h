#ifndef INGREDIENTES_H_INCLUDED
#define INGREDIENTES_H_INCLUDED


#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
} Ingrediente;


void adicionarIngrediente();
void visualizarIngredientes();
void editarIngrediente();
void removerIngrediente();

#endif // INGREDIENTES_H_INCLUDED
