#include <stdio.h>

#define TOTAL_ALUNOS 30
#define FREQUENCIA_MINIMA 0.75
#define NOTA_MINIMA 6.0

typedef struct {
    double n1;
    double n2;
    double frequencia;
    double media_final;
    char situacao[30];
} Aluno;

int main() {
    Aluno alunos[TOTAL_ALUNOS];
    int aprovados = 0, reprovadosNota = 0, reprovadosFreq = 0, reprovadosAmbos = 0;
    double somaMedias = 0;

    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        printf("Digite a nota N1 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].n1);

        printf("Digite a nota N2 do aluno %d: ", i + 1);
        scanf("%lf", &alunos[i].n2);

        printf("Digite a frequencia do aluno %d (em porcentagem): ", i + 1);
        scanf("%lf", &alunos[i].frequencia);
        
        alunos[i].frequencia /= 100.0;

        alunos[i].media_final = (alunos[i].n1 + alunos[i].n2) / 2.0;
        somaMedias += alunos[i].media_final;

        if (alunos[i].media_final >= NOTA_MINIMA && alunos[i].frequencia >= FREQUENCIA_MINIMA) {
            aprovados++;
            sprintf(alunos[i].situacao, "Aprovado");
        } else {
            if (alunos[i].media_final < NOTA_MINIMA && alunos[i].frequencia < FREQUENCIA_MINIMA) {
                reprovadosAmbos++;
                sprintf(alunos[i].situacao, "Reprovado por nota e freq.");
            } else if (alunos[i].media_final < NOTA_MINIMA) {
                reprovadosNota++;
                sprintf(alunos[i].situacao, "Reprovado por nota");
            } else if (alunos[i].frequencia < FREQUENCIA_MINIMA) {
                reprovadosFreq++;
                sprintf(alunos[i].situacao, "Reprovado por freq.");
            }
        }
    }
    
    double mediaGeral = somaMedias / TOTAL_ALUNOS;

    printf("\n| Seq |   N1   |   N2   |   Freq   |   MF   |          Situacao          |\n");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        printf("| %3d | %6.2f | %6.2f | %7.2f%% | %6.2f | %-25s |\n", 
               i + 1, alunos[i].n1, alunos[i].n2, alunos[i].frequencia * 100, 
               alunos[i].media_final, alunos[i].situacao);
    }

    printf("\nMedia geral da turma: %.2f\n", mediaGeral);
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados por nota: %d\n", reprovadosNota);
    printf("Alunos reprovados por frequencia: %d\n", reprovadosFreq);
    printf("Alunos reprovados por ambos (nota e frequencia): %d\n", reprovadosAmbos);

    return 0;
}
