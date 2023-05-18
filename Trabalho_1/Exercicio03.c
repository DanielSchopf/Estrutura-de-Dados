#include <stdio.h>
#include <stdlib.h>


struct lista {
    int linha;
    int coluna;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct matriz {
    int ordem;
    struct lista* prim;
};
typedef struct matriz Matriz;


Lista* lst_cria(void) {
    return NULL;
}

Lista* lst_insere(Lista* l, int n, int i, int j) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = n;
    novo->linha = i;
    novo->coluna = j;
    novo->prox = NULL;
    if (l == NULL) {
        return novo;
    }
    Lista* aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}

void lst_imprime(Matriz* m) {
    Lista* p;
    for(int i = 0; i < m->ordem; i++) {
        for(int j = 0; j < m->ordem; j++) {
            int encontrado = 0;
            for(p = m->prim; p != NULL; p = p->prox) {
                if(p->linha == i && p->coluna == j) {
                    printf("%2d ", p->info);
                    encontrado = 1;
                    break;
                }
            }
            if(!encontrado) {
                printf("%2d ", 0);
            }
        }
        printf("\n");
    }
}

void verificar_identidade(Matriz* m){
    Lista* p;

    for(p=m->prim;p!=NULL;p=p->prox){
        if((p->linha == p->coluna) && p->info != 1){
            printf("A posicao [%d][%d] da matriz viola a propriedade da matriz identidade\n", p->linha, p->coluna);
        }
        if((p->linha != p->coluna) && p->info != 0){
            printf("A posicao [%d][%d] da matriz viola a propriedade da matriz identidade\n", p->linha, p->coluna);
        }
    }
}

Lista* ler_matriz(Matriz* m, Lista* l){
    int num;
    printf("Digite a ordem da matriz:\n");
    scanf("%d", &m->ordem);

    for(int i=0;i<m->ordem;i++){
        for(int j=0; j<m->ordem;j++){
            printf("Insira o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &num);
            l = lst_insere(l, num, i, j);
        }
    }

    m->prim = l;

    return m->prim;
}



void main(){
    Matriz* m;
    Lista* l;


    m = (Matriz*)malloc(sizeof(Matriz));

    l= lst_cria();

    l = ler_matriz(m,l);


    lst_imprime(m);

    verificar_identidade(m);





}

