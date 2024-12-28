#include <stdio.h>
#include <stdlib.h>

void char_para_binario(char c, char *vector);
char binario_para_char(char *vector);

int main() {
    FILE *imagem;
    char local_arquivo[100];

    printf("Digite o Caminho da Imagem:\n");
    scanf("%[^\n]", local_arquivo);
    getchar();

    imagem = fopen(local_arquivo, "rb");
    if (imagem == NULL) {
        printf("ERRO AO ABRIR A IMAGEM\n");
        return 1;
    }

    printf("Imagem aberta com sucesso\n");
    printf("A Palavra Extraída:\n");

    char bin[7], buff[7];
    char buffer, c;

    while (1) {
        for (int l = 0; l < 7; l++) {
            fread(&buffer, 1, 1, imagem);
            char_para_binario(buffer, buff);
            bin[l] = buff[6];
            fseek(imagem, -2, SEEK_CUR);
        }

        c = binario_para_char(bin);
        printf("%c", c);

        if (c == '\n') {
            break;
        }
    }

    fclose(imagem);
    printf("Extração concluída!\n");

    return 0;
}

void char_para_binario(char c, char *vector) {
    int num = (int)c;
    int i = 6;

    while (i >= 0) {
        vector[i] = (num % 2 == 1) ? '1' : '0';
        num /= 2;
        i--;
    }
}

char binario_para_char(char *vector) {
    int digito;
    int num = 0;
    int pot = 1;

    for (int i = 6; i >= 0; i--) {
        digito = (vector[i] == '1') ? 1 : 0;
        num += digito * pot;
        pot *= 2;
    }

    return (char)num;
}
