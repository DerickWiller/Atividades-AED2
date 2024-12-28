#include <stdio.h>
#include "lista_encadeada.c"

#define NUM_ALUNOS 30

int main() {
    Aluno* lista_alunos = NULL;
    double nota, soma_notas = 0.0, media_turma;
    int frequencia;
    int aprovados = 0, reprovados = 0;
    int reprovados_frequencia = 0, reprovados_nota = 0, reprovados_ambos = 0;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%lf", &nota);
        printf("Digite a frequencia do aluno %d (em %%): ", i + 1);
        scanf("%d", &frequencia);

        lista_alunos = adicionar_aluno(lista_alunos, nota, frequencia);
    }

    processar_alunos(lista_alunos, &aprovados, &reprovados, &reprovados_frequencia, &reprovados_nota, &reprovados_ambos, &soma_notas);

    media_turma = soma_notas / NUM_ALUNOS;

    printf("\nMédia geral da turma: %.2f\n", media_turma);
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados: %d\n", reprovados);
    printf("Reprovados por frequencia: %d\n", reprovados_frequencia);
    printf("Reprovados por nota: %d\n", reprovados_nota);
    printf("Reprovados por ambos: %d\n", reprovados_ambos);

    liberar_lista(lista_alunos);

    return 0;
}
