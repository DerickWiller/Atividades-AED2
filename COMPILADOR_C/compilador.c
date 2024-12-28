#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compilador.h"

patricia * node(char * key)
{
    patricia * node = (patricia*)malloc(sizeof(patricia));

    node->key = strdup(key);
    node->direita = NULL;
    node->esquerda = NULL;
    return node;
}

patricia * inserir(patricia * head, char * key)
{
    if(head == NULL)
    {
        return node(key);
    }

    if(strcmp(key, head->key) == 0)
    {
        return head;
    }

    if(strcmp(key, head->key) < 0)
    {
        head->esquerda = inserir(head->esquerda, key);
    } else 
    {
        head->direita = inserir(head->direita, key);
    }

    return head;
}

int busca(patricia * head, char * key)
{
    if(head == NULL)
    {
        return 0;
    }

    if(strcmp(key, head->key) == 0)
    {
        return 1;
    }

    if(strcmp(key, head->key) < 0)
    {
        return busca(head->esquerda, key);
    } else 
    {
        return busca(head->direita, key);
    }
}

int verifica_funcao(char * function)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(function[i] <= 97 || function[i] >= 122)
        {
            break;
        }
    }

    if(i >= 1)
    {
        return 1;
    }

    return 0;
}