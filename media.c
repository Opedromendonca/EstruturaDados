#include <stdio.h>
#include <stdlib.h>

#define MEDIA_MINIMA 6.0

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
    int indiceMaior = 0;
    for (int i = 1; i < n; i++) 
    {
        if (alunos[i].media > alunos[indiceMaior].media) 
        {
            indiceMaior = i;
        }
    }
    printf("\nAluno com matricula %d tem a maior media: %.2lf\n", 
        alunos[indiceMaior].matricula, alunos[indiceMaior].media);


     qsort(alunos, n, sizeof(struct ALUNOS), compararMedia);


 printf("\n=== Lista de %d alunos ordenados por media ===\n", n);
 for (int i = 0; i < n; i++) {
     printf("Matricula: %d - Media: %.2lf\n", alunos[i].matricula, alunos[i].media);
    }

    printf("\n=== Alunos que precisam de substituicao ===\n");
    for (int i = 0; i < n; i++) 
    {
        if (alunos[i].media < MEDIA_MINIMA) 
        {
            printf("Matricula: %d - G1: %.2lf - G2: %.2lf - Media: %.2lf\n",alunos[i].matricula, alunos[i].g1, alunos[i].g2, alunos[i].media);
        }
    }

    return 0;
}