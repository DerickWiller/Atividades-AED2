#include <stdio.h>

#define NUM_ALUNOS 30
#define FREQUENCIA_MINIMA 75
#define NOTA_MINIMA 6.0

int main() {
    double notas[NUM_ALUNOS];
    int frequencias[NUM_ALUNOS];
    int aprovados = 0, reprovados = 0;
    int reprovados_frequencia = 0, reprovados_nota = 0, reprovados_ambos = 0;
    double soma_notas = 0.0, media_turma;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%lf", &notas[i]);
        printf("Digite a frequencia do aluno %d (em %%): ", i + 1);
        scanf("%d", &frequencias[i]);

        soma_notas += notas[i];
    }

    for (int i = 0; i < NUM_ALUNOS; i++) {
        if (frequencias[i] < FREQUENCIA_MINIMA && notas[i] < NOTA_MINIMA) {
            reprovados++;
            reprovados_ambos++;
        } else if (frequencias[i] < FREQUENCIA_MINIMA) {
            reprovados++;
            reprovados_frequencia++;
        } else if (notas[i] < NOTA_MINIMA) {
            reprovados++;
            reprovados_nota++;
        } else {
            aprovados++;
        }
    }

    media_turma = soma_notas / NUM_ALUNOS;

    printf("\nMedia geral da turma: %.2f\n", media_turma);
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados: %d\n", reprovados);
    printf("Reprovados por frequencia: %d\n", reprovados_frequencia);
    printf("Reprovados por nota: %d\n", reprovados_nota);
    printf("Reprovados por ambos: %d\n", reprovados_ambos);

    return 0;
}
