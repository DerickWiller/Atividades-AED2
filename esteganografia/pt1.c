#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void char_para_binario(char c, char *vector);

int main() {
    char palavra[12];

    printf("Digite a Palavra a ser Inserida (Máximo de 10 Caracteres):\n");
    fgets(palavra, 12, stdin);

    FILE *imagem;
    char local_arquivo[100];

    printf("Digite o Caminho da Imagem:\n");
    scanf("%[^\n]", local_arquivo);
    getchar();

    imagem = fopen(local_arquivo, "rb+");
    if (imagem == NULL) {
        printf("ERRO AO ABRIR A IMAGEM\n");
        return 1;
    }

    printf("Imagem aberta com sucesso\n");

    int i = 0;
    char bin[7], buff[7];
    char j = palavra[i];
    char buffer;

    while (j != '\n') {
        char_para_binario(palavra[i], bin);

        for (int k = 0; k < 7; k++) {
            fread(&buffer, 1, 1, imagem);
            char_para_binario(buffer, buff);
            buff[6] = bin[k];
            fseek(imagem, -1, SEEK_CUR);
            char new = (char)strtol(buff, NULL, 2);
            fwrite(&new, 1, 1, imagem);
            fseek(imagem, -2, SEEK_CUR);
        }
        i++;
        j = palavra[i];
    }

    char_para_binario((char)10, bin);
    for (int k = 0; k < 7; k++) {
        fread(&buffer, 1, 1, imagem);
        char_para_binario(buffer, buff);
        buff[6] = bin[k];
        fseek(imagem, -1, SEEK_CUR);
        char new = (char)strtol(buff, NULL, 2);
        fwrite(&new, 1, 1, imagem);
        fseek(imagem, -2, SEEK_CUR);
    }

    fclose(imagem);
    printf("Inserção concluída!\n");

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
