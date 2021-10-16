#include <stdlib.h>
#include "../Lista/Lista.h"
#include "../Item/Item.h"

#include <malloc.h>
#include "Lista.h"
#include <string.h>

typedef struct node_st NODE;

struct node_st
{
    ITEM *item;
    NODE *proximo;
};

struct lista
{
    NODE *inicio;
    NODE *fim;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}
int lista_preencher_resultados(LISTA *lista[], int operations)
{
    char operation[6];     // soma maior menor menos igual
    char firstNumber[25];  // vai pegar primeiro numero
    char secondNumber[25]; // vai pegar segundo numero
    int length = 0;
    int length1 = 0;
    int lengthBiggestNumber = 0;
    int valorLista2 = 0;
    int carry = 0;
    char aux[4];
    ITEM *item;
    ITEM *item1;
    LISTA *auxLista = lista_criar();
    LISTA *auxLista1 = lista_criar();
    for (int i = 0; i < operations; i++)
    {
        setbuf(stdin, 0);
        scanf("%s", operation);
        scanf("%s", firstNumber);
        // scanf("%s", secondNumber);
        length = strlen(firstNumber);
        for (int j = 0; j < (strlen(firstNumber) / 4) + 1; j++)
        {
            if (length - 4 >= 0)
            {
                strncpy(aux, &firstNumber[length - 4], 4);
                length -= 4;
                item = item_criar(j, atoi(aux), strlen(aux), 0);
                lista_inserir(auxLista, item);
            }
            else
            {
                strncpy(aux, &firstNumber[0], length);
                item = item_criar(j, atoi(aux), strlen(aux), 0);
                lista_inserir(auxLista, item);
            }
            memset(aux, 0, strlen(aux));
        }
        setbuf(stdin, 0);

        scanf("%s", secondNumber);
        break;
        length1 = strlen(secondNumber);
        for (int j = 0; j < (strlen(secondNumber) / 4) + 1; j++)
        {
            if (length1 - 4 >= 0)
            {
                strncpy(aux, &secondNumber[length1 - 4], 4);
                length1 -= 4;
                item = item_criar(j, atoi(aux), strlen(aux), 0); // averigar slides
                lista_inserir(auxLista1, item);
            }
            else
            {
                strncpy(aux, &secondNumber[0], length1);
                item = item_criar(j, atoi(aux), strlen(aux), 0); // averigar slides
                lista_inserir(auxLista1, item);
            }
            memset(aux, 0, strlen(aux));
            item_apagar(&item);
        }
        lengthBiggestNumber = strlen(firstNumber) > strlen(secondNumber) ? strlen(firstNumber) : strlen(secondNumber);
        printf("[Aqui eu cheguei em!");
        for (int i = 0; i < lengthBiggestNumber; i++)
        {
            item = lista_busca_sequencial(auxLista, i);
            item1 = lista_busca_sequencial(auxLista1, i);
            valorLista2 = item_somar(item, item1) + carry;
            // pode ser 0000 -> 0
            // pode ser 0001 -> 1
            // pode ser 0010 -> 10
            // pode ser 0100 -> 1000
            // procurar por strpad
            if (valorLista2 > 10000)
            {
                carry = 1;
                valorLista2 -= 10000;
            }
            else
            {
                carry = 0;
            }
            lista_inserir(lista[i], item_criar(i, valorLista2, 4, 0));
        }
    }
    return 0;
    for (int i = 0; i < operations; i++)
    {
        for (int j = 0; j < lista_tamanho(lista[i]); j++)
        {
            item_imprimir_valor(lista_busca_sequencial(lista[j], i));
            printf("\n");
        }
    }
    return 0;
}
boolean lista_vazia(const LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->inicio == NULL;
    }
    return ERRO;
}

int lista_tamanho(const LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->tamanho;
    }
    return ERRO;
}

int lista_inserir(LISTA *lista, ITEM *item)
{
    if (lista != NULL)
    {
        NODE *novoNode = (NODE *)malloc(sizeof(NODE));
        if (novoNode != NULL)
        {
            novoNode->item = item;
            novoNode->proximo = NULL;
            if (lista_vazia(lista))
            {
                lista->inicio = novoNode;
            }
            else
            {
                lista->fim->proximo = novoNode;
            }
            lista->fim = novoNode;
            lista->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

ITEM *lista_busca_sequencial(const LISTA *lista, int chave)
{
    if (lista != NULL)
    {
        NODE *noAtual;
        noAtual = lista->inicio;
        while (noAtual != NULL)
        {
            if (item_get_chave(noAtual->item) == chave)
            {
                return noAtual->item;
            }
            noAtual = noAtual->proximo;
        }
    }
    return NULL;
}

boolean lista_remover_item(LISTA *lista, int chave)
{
    if (lista != NULL)
    {
        NODE *noAtual;
        NODE *noAnterior = NULL;
        noAtual = lista->inicio;
        while (noAtual != NULL && (item_get_chave(noAtual->item) != chave))
        {
            noAnterior = noAtual;
            noAtual = noAtual->proximo;
        }
        if (noAtual != NULL)
        {
            if (noAtual == lista->inicio)
            {
                lista->inicio = noAtual->proximo;
                noAtual->proximo = NULL;
            }
            else
            {
                noAnterior->proximo = noAtual->proximo;
                noAtual->proximo = NULL;
            }
            if (lista->fim == noAtual)
            {
                lista->fim = noAnterior;
            }
            return TRUE;
        }
    }
    return FALSE;
}