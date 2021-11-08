#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Cliente.h"

struct cliente_st
{
    long chave;// CPF em int
    char nome[50];
    int idade;
    int saldo;
};

CLIENTE *cliente_criar_vazio()
{
    CLIENTE *cliente;

    cliente = (CLIENTE *) calloc(sizeof(CLIENTE), 1);
    return cliente;
}

CLIENTE *cliente_criar (long chave, char *nome, int idade, int saldo)
{
    CLIENTE *cliente;

    cliente = (CLIENTE *) malloc(sizeof(CLIENTE));

    if (cliente != NULL)
    {
        cliente->chave = chave;
        strcpy(cliente->nome, nome);
        cliente->idade = idade;
        cliente->saldo = saldo;
        return cliente;
    }
    return NULL;
}

boolean cliente_apagar(CLIENTE **cliente)
{
    if (*cliente != NULL)
    {
        (*cliente)->chave = ERRO; /*apaga o cliente simbolicamente*/
        free (*cliente);
        *cliente = NULL;
        return TRUE;
    }
    return FALSE;
}

int cliente_get_chave(const CLIENTE *cliente)
{
    if (cliente != NULL)
    {
        return cliente->chave;
    }
    return ERRO;
}


boolean cliente_set_chave(CLIENTE *cliente, long chave)
{
    if (cliente != NULL){
        cliente->chave = chave;
        return TRUE;
    }
    return FALSE;
}


void cliente_imprimir(const CLIENTE *cliente)
{
    if (cliente != NULL)
    {
        printf("\nchave: %ld", cliente->chave);
    }
}

int cliente_comparar(const CLIENTE *cliente1, const CLIENTE *cliente2)
{
    if (cliente1 != NULL && cliente2 != NULL)
    {
        if (cliente1->chave == cliente2->chave)
        {
            return 0;
        }
        else if (cliente1->chave > cliente2->chave)
        {
            return -1; // esquerda
        }
        else
        {
            return 1;
        }
    }
    return ERRO;
}
void cliente_imprimir_verboso(const CLIENTE *cliente)
{
    if (cliente != NULL)
    {
        printf("\nchave: %ld", cliente->chave);
        printf("\nnome: %s", cliente->nome);
        printf("\nidade: %d", cliente->idade);
        printf("\nsaldo: %d\n", cliente->saldo);
    }
}