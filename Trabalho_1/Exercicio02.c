#include <stdio.h>
#include <stdlib.h>

struct lista { //lista de valores não nulos da matriz esparsa. Os elementos não nulos da matriz são armazenados nesta lista. Os valores restantes, q são nulos, não são armazenados em nenhum lugar.
    int linha; // linha onde se encontra o elemento não nulo
    int coluna;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct esparsa {
    int linhas;
    int colunas;
    struct lista* prim;
};
typedef struct esparsa Esparsa;

void main(){

}
