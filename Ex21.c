#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    float g1;
    float g2;
    float media;
} Aluno;

typedef struct {
    Aluno *dados;
    int topo;
    int capacidade;
} Pilha;

int empty(Pilha *p) {
    return p->topo == -1;
}

int push(Pilha *p, Aluno a) {
    if (p->topo == p->capacidade - 1) {
        fprintf(stderr, "Erro: Pilha cheia!\n");
        return 0;
    }
    p->dados[++(p->topo)] = a;
    return 1;
}

int pop(Pilha *p, Aluno *removido) {
    if (empty(p)) {
        fprintf(stderr, "Erro: Pilha vazia!\n");
        return 0;
    }
    *removido = p->dados[(p->topo)--];
    return 1;
}


