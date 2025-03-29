#include <stdio.h>

struct ALUNOS {
    int matricula;
    double g1, g2, media;
};

nt main() {
    int n;
    struct ALUNOS alunos[MAX_ALUNOS];

    printf("Quantos alunos serao cadastrados? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Cadastro do aluno %d:\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nota G1: ");
        scanf("%lf", &alunos[i].g1);
        printf("Nota G2: ");
        scanf("%lf", &alunos[i].g2);
    }

    return 0;
}