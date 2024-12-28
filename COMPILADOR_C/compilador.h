#ifndef __COMPILADOR_H__
#define __COMPILADOr_H__

typedef struct patricia
{
    char * key;
    struct patricia * esquerda;
    struct patricia * direita;
} patricia;

patricia * node(char * key);

patricia * inserir(patricia * head, char * key);

int busca(patricia * head, char * key);

int verifica_funcao(char * function);

#endif