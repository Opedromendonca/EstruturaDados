#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int matricula;
    double g1, g2, media;
} Aluno;

void calcularMedias(Aluno* alunos, int n) {
    for (int i = 0; i < n; i++) {
        alunos[i].media = (alunos[i].g1 + alunos[i].g2) / 2;
    }
}

int encontrarMelhorAluno(Aluno* alunos, int n) {
    int melhor = 0;
    for (int i = 1; i < n; i++) {
        if (alunos[i].media > alunos[melhor].media) {
            melhor = i;
        }
    }
    return melhor;
}

void ordenarPorMedia(Aluno* alunos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alunos[j].media < alunos[j + 1].media) {
                Aluno aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }
}

void imprimirAlunos(Aluno* aluno, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Matricula: %d | G1: %.2lf | G2:%.2lf | Media: %.2lf \n",
        aluno[i].matricula, aluno[i].g1, aluno[i].g2, aluno[i].media);
    }
}

void imprimirSubstituicao(Aluno* alunos, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (alunos[i].media < 7.0)
        {
            printf("Matricula: %d | G1: %.2lf | G2: %.2lf | Media: %.2lf \n", 
            alunos[i].matricula, alunos[i].g1, alunos[i].g2, alunos[i].media);
        }
    }
}

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

    calcularMedias(alunos, numAlunos);
}