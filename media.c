#include <stdio.h>
#include <stdlib.h>

struct ALUNOS {
    int matricula;
    double g1, g2, media;
};

int compararMedia(const void *a, const void *b) {
    struct ALUNOS *alunoA = (struct ALUNOS *)a;
    struct ALUNOS *alunoB = (struct ALUNOS *)b;
    if (alunoA->media > alunoB->media) return 1;
    if (alunoA->media < alunoB->media) return -1;
    return 0;
}

int main() {
    int n;
    printf("# Quantos você quer cadastrar?\n");
    scanf("%d", &n);

    struct ALUNOS alunos[n];

    for (int i = 0; i < n; i++) {
        printf("# Digite Matricula aluno %d:\n", i);
        scanf("%d", &alunos[i].matricula);
        printf("# Digite Nota G1 aluno %d:\n", i);
        scanf("%lf", &alunos[i].g1);
        printf("# Digite Nota G2 aluno %d:\n", i);
        scanf("%lf", &alunos[i].g2);
        alunos[i].media = (alunos[i].g1 + alunos[i].g2) / 2.0;
    }

    return 0;
}