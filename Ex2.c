#include <stdio.h>
#include <stdlib.h>

struct S {
    int mat;
    double g1, g2, media;
    struct S* prox;
};

struct S* new(int mat, double g1, double g2) {
    struct S* novo = malloc(sizeof(*novo)); 

    if (novo == NULL) { 
        fprintf(stderr, "Erro ao alocar\n");
        exit(1);  
    }
    
    novo->mat = mat;
    novo->g1 = g1;
    novo->g2 = g2;
    novo->media = 0.0;  
    novo->prox = NULL;
    return novo;
}

void add(struct S** lista, int mat, double g1, double g2) {
    struct S* novo = new(mat, g1, g2);
    novo->prox = *lista;
    *lista = novo;
}

void calcMedia(struct S* lista) {
    struct S* atual = lista;
    while (atual != NULL) {
        atual->media = (atual->g1 + atual->g2) / 2.0;
        atual = atual->prox;
    }
}

void printa(struct S* lista) {
    struct S* atual = lista;
    while (atual != NULL) {
        printf("Matricula: %d | G1: %.2lf | G2: %.2lf | Media: %.2lf\n", 
               atual->mat, atual->g1, atual->g2, atual->media);
        atual = atual->prox;
    }
}

struct S* maior(struct S* lista) {
    struct S* atual = lista;
    struct S* maior = lista;

    while (atual != NULL) {
        if (atual->media > maior->media) {
            maior = atual;
        }
        atual = atual->prox;
    }
    return maior;
}

void sort(struct S** lista) {
    if (*lista == NULL || (*lista)->prox == NULL) return;

    struct S* i, *j;
    double tempMedia;
    int tempMat;
    double tempG1, tempG2;

    for (i = *lista; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->media < j->media) {
                tempMat = i->mat;
                tempG1 = i->g1;
                tempG2 = i->g2;
                tempMedia = i->media;

                i->mat = j->mat;
                i->g1 = j->g1;
                i->g2 = j->g2;
                i->media = j->media;

                j->mat = tempMat;
                j->g1 = tempG1;
                j->g2 = tempG2;
                j->media = tempMedia;
            }
        }
    }
}

void printaSub(struct S* lista) {
    struct S* atual = lista;
    while (atual != NULL) {
        if (atual->media < 7.0) {
            printf("Matricula: %d | G1: %.2lf | G2: %.2lf | Media: %.2lf\n", 
                   atual->mat, atual->g1, atual->g2, atual->media);
        }
        atual = atual->prox;
    }
}

void ler(int* mat, double* g1, double* g2) {
    printf("Matricula: ");
    scanf("%d", mat);
    printf("G1: ");
    scanf("%lf", g1);
    printf("G2: ");
    scanf("%lf", g2);
}

int main() {
    struct S* lista = NULL;
    int mat;
    double g1, g2;
    char continuar;

    do {
        ler(&mat, &g1, &g2);  
        add(&lista, mat, g1, g2);  

        printf("Cadastrar outro? (Y/n): ");
        scanf(" %c", &continuar); 
    } while (continuar == 'y' || continuar == 'Y');

    calcMedia(lista);  

    struct S* bestdosor = maior(lista);
    printf("\nBest do sor:\n");
    printf("Mat: %d | G1: %.2lf | G2: %.2lf | Media: %.2lf\n", 
           bestdosor->mat, bestdosor->g1, bestdosor->g2, bestdosor->media);

    sort(&lista);
    printf("\nSort media:\n");
    printa(lista);

    printf("\nLista Substituicao:\n");
    printaSub(lista);

    struct S* atual = lista;
    while (atual != NULL) {
        struct S* temp = atual;
        atual = atual->prox;
        free(temp); 
    }

    return 0;
}
