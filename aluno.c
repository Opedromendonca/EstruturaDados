#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    double g1, g2, media;
} Aluno;

int main() {
    Aluno *alunos = NULL;  
    int numAlunos = 0;  
    char continuar;

    do {
        alunos = (Aluno*)realloc(alunos, (numAlunos + 1) * sizeof(Aluno));

        printf("Digite a matricula do aluno: ");
        scanf("%d", &alunos[numAlunos].matricula);
        printf("Digite a nota G1: ");
        scanf("%lf", &alunos[numAlunos].g1);
        printf("Digite a nota G2: ");
        scanf("%lf", &alunos[numAlunos].g2);

        alunos[numAlunos].media = (alunos[numAlunos].g1 + alunos[numAlunos].g2) / 2.0;

        numAlunos++;

        printf("Deseja continuar cadastro cadastrar(s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
