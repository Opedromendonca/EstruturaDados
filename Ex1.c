#include <stdio.h>
#include <stdlib.h>

struct ALUNO {
  int matricula;
  double g1, g2, media;

};

int preenchendo_alunos(struct ALUNO *alunos, int qnt){
  
  int i;
  
  for (i=0; i< qnt; i++) {
    printf("======== ALUNO %d ========\n", i+1);

    printf("Matrícula: ");
    scanf("%d", &alunos[i].matricula);

    printf("Nota G1: ");
    scanf("%lf", &alunos[i].g1);

    printf("Nota G2: ");
    scanf("%lf", &alunos[i].g2);

    alunos[i].media = (alunos[i].g1 + alunos[i].g2) / 2.0;
    
    
  }
  
  return 200;
  
};

int ordenar_por_media(struct ALUNO *alunos, int n) {
    // Ordena por media  usado o metodo selection
  
    int i, j, maior;
    struct ALUNO temp;

    for (i = 0; i < n; i++) {
        maior = i;
        for (j = i + 1; j < n; j++) {
            if (alunos[j].media > alunos[maior].media) {
                maior = j;
            }
        }
        if (maior != i) {
            temp = alunos[i];
            alunos[i] = alunos[maior];
            alunos[maior] = temp;
        }
    }
  
  return 200;
};

int imprimir_alunos(struct ALUNO *alunos, int n) {
  // 1. Aluno com maior média 
    printf("\nAluno com maior média:\n");
    printf("Matrícula: %d\n", alunos[0].matricula);
    printf("Média: %.2lf\n", alunos[0].media);

    // 2. Imprimir todos os alunos
    printf("\nMEDIA ALUNOS\n");
    for (int i = 0; i < n; i++) {
        printf("%d: MATRÍCULA: %d\n", i + 1, alunos[i].matricula);
        printf("   G1: %.2lf\n", alunos[i].g1);
        printf("   G2: %.2lf\n", alunos[i].g2);
        printf("   MÉDIA: %.2lf\n\n", alunos[i].media);
    }

    // 3. Imprimir os alunos em recuperação
    printf("==== EM RECUPERAÇÃO ====\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i].media < 6.0) {
            printf("%d: MATRÍCULA: %d\n", i + 1, alunos[i].matricula);
            printf("   G1: %.2lf\n", alunos[i].g1);
            printf("   G2: %.2lf\n", alunos[i].g2);
            printf("   MÉDIA: %.2lf\n\n", alunos[i].media);
        }
    }

  return 200;
}

int main(){

  // Alocacao dinamica de memoria para o vetor alunos
  int qnt;
  struct ALUNO *alunos;

  printf("Quantos\n");
  scanf("%i", &qnt);

  alunos = malloc(qnt*sizeof(struct ALUNO));
  if (alunos == NULL) {
    //erro nao alocou
    return 10;
  }

  preenchendo_alunos(alunos, qnt);
  ordenar_por_media(alunos, qnt);
  imprimir_alunos(alunos, qnt);

  free(alunos);
}

