#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Cliente.h"

struct cliente_st
{
    long chave;// CPF em int
    char nome[50];
    int idade;
    float saldo;
};

CLIENTE *cliente_criar_vazio()
{
    CLIENTE *cliente;

    cliente = (CLIENTE *) calloc(sizeof(CLIENTE), 1);
    return cliente;
}

CLIENTE *cliente_criar (long chave, char *nome, int idade, float saldo)
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

void cliente_imprimir(const CLIENTE *cliente)
{
    if (cliente != NULL)
    {
        printf("%ld\n", cliente->chave);
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
        else if (cliente1->chave < cliente2->chave)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    return ERRO;
}
long cliente_ler_chave_input(char chave[13]) {
    char chave_concat[13] = "";
    strcpy(chave_concat, " ");
    char *pointer = strtok(chave, ".");
    strcat(chave_concat, pointer);
    pointer = strtok(NULL, ".");
    strcat(chave_concat, pointer);
    pointer = strtok(NULL, "-");
    strcat(chave_concat, pointer);
    pointer = strtok(NULL, "");
    strcat(chave_concat, pointer);
    return atol(chave_concat);
}

CLIENTE *cliente_ler_stdin()
{
    char *chave_char = malloc(sizeof(char));
    char nome[50];
    int idade;
    float saldo;
    char *line = readLine();
    char *pointer = strtok(line, ";");
    sprintf(chave_char, "%s", pointer);
    pointer = strtok(NULL, ";");
    strcpy(nome, pointer);
    pointer = strtok(NULL, ";");
    idade = atoi(pointer);
    pointer = strtok(NULL, "\n");
    saldo = atof(pointer);
    long chave = cliente_ler_chave_input(chave_char);
    CLIENTE *cliente = cliente_criar(chave, nome, idade, saldo);
    free(chave_char);
    free(line);
    return cliente;
}