#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compilador.h"

#define MAX_LENGTH 10

int main()
{

    patricia * dicionario = NULL;

    FILE * funcao = fopen("funcao.txt", "r");

    if(funcao == NULL)
    {
        printf("ERRO NA LEITURA DO ARQUIVO funcao.txt\n");
        return 1;
    }

    char key[10];

    while (fgets(key, MAX_LENGTH, funcao) != NULL) 
    {
        key[strcspn(key, "\n")] = '\0';

        dicionario = inserir(dicionario, key);
    }
    
    fclose(funcao);

    FILE * arquivo = fopen("test.txt", "r");

    char c;
    char prev;
    char function[MAX_LENGTH];
    int i = 0, linha = 1;
    int resultado;
    int parentese = 0, chave = 0, colchete = 0;
    int comentario = 0, definition = 0; 

    while(!feof(arquivo))
    {
        c = fgetc(arquivo);
        if(c >= 97 && c <= 122)
        {
            function[i] = c;
            i++;
        } else if(c == '(' || c == '{' || c == '<')
        {
            if(comentario == 0)
            {
                function[i] = '\0';

                resultado = verifica_funcao(function);

                if(resultado == 1)
                {
                    resultado = busca(dicionario, function);
                    if(resultado == 0)
                    {
                        printf("ERRO NA LINHA %d: DECLARACAO %s DESCONHECIDA OU INCORRETA\n", linha, function);
                    }
                }
            }

            function[0] = '\0';
            i = 0;

            if(comentario == 0)
            {
                if(c == '(')
                {
                    parentese++;
                } else if(c == '[')
                {
                    colchete++;
                } else if(c == '{')
                {
                    chave++;
                }
            }

        } else if(c == '\n')
        {
            function[0] = '\0';
            i = 0;

            if(comentario == 0)
            {
                if(prev != '\n')
                {
                    if(prev != ';' && prev != '{' && prev != '>' && prev != '}')
                    {
                        printf("ERRO NA LINHA %d: ESPERADO ';' APOS A ULTIMA EXPRESSAO\n", linha);
                    }
                }
            }

            comentario = 0;

            linha++;
        } else{

            if(c == '/' && prev == '/')
            {
                if(comentario == 0)
                {
                    comentario = 1;
                } else
                {
                    comentario = 0;
                }
            }

            if(c == '#' && comentario != 1)
            {
                definition = 1;
            }

            if(c == ' ' && definition == 1)
            {
                function[i] = '\0';

                resultado = verifica_funcao(function);

                if(resultado == 1)
                {
                    resultado = busca(dicionario, function);
                    if(resultado == 0)
                    {
                        printf("ERRO NA LINHA %d: DECLARACAO %s DESCONHECIDA OU INCORRETA\n", linha, function);
                    }
                }

                definition = 0;
            }

            function[0] = '\0';
            i = 0;

            if(comentario == 0)
            {
                if(c == ')')
                {
                    parentese--;
                } else if(c == ']')
                {
                    colchete--;
                } else if(c == '}')
                {
                    chave--;
                }
            }
        }

        prev = c;
    }

    if(parentese > 0)
    {
        printf("ERRO: EXCESSO DE '(' NO CODIGO");
    } else if(parentese < 0)
    {
        printf("ERRO: EXCESSO DE ')' NO CODIGO");
    }
    if(colchete > 0)
    {
        printf("ERRO: EXCESSO DE '[' NO CODIGO");
    } else if(colchete < 0)
    {
        printf("ERRO: EXCESSO DE ']' NO CODIGO");
    }
    if(chave > 0)
    {
        printf("ERRO: EXCESSO DE '{' NO CODIGO");
    } else if(chave < 0)
    {
        printf("ERRO: EXCESSO DE '}' NO CODIGO");
    }

    return 0;
}