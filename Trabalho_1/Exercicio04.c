#include <stdio.h>
#include <stdlib.h>

int*** aloca_matriz (int m, int n, int z){
    int*** matriz;
    matriz = (int***)malloc(m*sizeof(int**));
    for(int i=0;i<m;i++){
        matriz[i] = (int**)malloc(n*sizeof(int*));
        for(int j=0;j<n;j++){
            matriz[i][j] = (int*)malloc(z*sizeof(int));
        }
    }
    return matriz;
}

void preenche_matriz (int m, int n, int z, int ***mat){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<z;k++){
                printf("Digite o valor da posição [%d][%d][%d]",i,j,k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }
}

void imprime_matriz (int m, int n, int z, int ***mat){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<z;k++){
                printf("%2d", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void main(){
    int*** mat;
    int m, n, z;
    printf("Digite o valor de M, N e Z:\n");
    scanf("%d %d %d", &m, &n, &z);
    system("clear");
    mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    system("clear");
    imprime_matriz(m, n, z, mat);
}
