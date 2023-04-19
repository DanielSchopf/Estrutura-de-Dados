#include <stdio.h>
#include <stdlib.h>

typedef struct diagonal{
    int ordem; //ordem da matriz
    int* v; //o tamanho do vetor � igual a ordem da matriz. Os elementos da diagonal principal s�o armazenados neste vetor
};
typedef struct diagonal Diagonal;

int** alocar_matriz(int ordem){
    int** mat;
    mat = (int**)malloc(ordem*sizeof(int*));
    for(int i=0; i<ordem;i++){
        mat[i] = (int*)malloc(ordem*sizeof(int));
    }
    return mat;
}

void preencher_matriz(int** m, Diagonal *d){
    for(int i=0;i<d->ordem;i++){
        for(int j=0;j<d->ordem;j++){
            if(i==j){
                printf("Insira o valor %d� da diagonal:\n", i+1);
                scanf("%d", &m[i][j]);
                d->v[i] = m[i][j];
            }
            else{
                m[i][j] = 0;
            }
        }
    }
}

void imprimir_matriz(int** m, Diagonal *d){
    for(int i=0;i<d->ordem;i++){
        for(int j=0;j<d->ordem;j++){
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
}

void consultar_matriz(int** m, Diagonal *d){
    int l, c;
    printf("Insira a linha e a coluna: \n");
    scanf("%d %d", &l, &c);
    if(l>=d->ordem || c>=d->ordem){
        printf("Dados inv�lidos\n");
    }
    else{
        for(int i=0;i<d->ordem;i++){
            for(int j=0;j<d->ordem;j++){
                if(i == l && j == c){
                    printf("Valor na posicao (%d,%d): %d", i, j, m[i-1][j-1]);
                }
            }
        }
    }
}

void main(){
    int** m;
    Diagonal* d = (Diagonal*) malloc(sizeof(Diagonal));


    printf("Digite a ordem da matriz: \n");
    scanf("%d", &d->ordem);

    d->v = (Diagonal *)malloc(d->ordem*sizeof(Diagonal));
    m= alocar_matriz(d->ordem);

    preencher_matriz(m, d);
    system("cls");
    int escolha;
    printf("1- IMPRIMIR MATRIZ 2- PROCURAR POSICAO\n");
    scanf("%d", &escolha);
    system("cls");
    switch(escolha) {
        case 1: printf("===MATRIZ===\n\n");
                imprimir_matriz(m, d);
                break;
        case 2: consultar_matriz(m,d);
                break;
        default: printf("Codigo inv�lido!");
    }
}
