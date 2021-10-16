#include <malloc.h>
#include <stdlib.h>
#include "Lista.h"
#include <string.h>

struct lista
{
    ITEM *valores[TAM_MAX];
    int inicio;
    int fim;
};

static boolean posicao_valida(const LISTA *l, int pos);

static void move_itens_a_direita(LISTA *l, int pos);

static void lista_remove_tudo(LISTA *lista);

LISTA *lista_criar()
{
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if (lista != NULL)
    {
        lista->inicio = INICIO;
        lista->fim = lista->inicio;
    }
    return lista;
}

int lista_preencher_resultados(LISTA *lista[], int operations)
{
    char *operation = malloc(6 * sizeof(char));     // soma maior menor menos igual
    char *firstNumber = malloc(25 * sizeof(char));  // vai pegar primeiro numero
    char *secondNumber = malloc(25 * sizeof(char)); // vai pegar segundo numero
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
        scanf("%s", operation);
        scanf("%s", firstNumber);
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
            item_apagar(&item);
        }
        scanf("%s", secondNumber);
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
        for (int i = 0; i < lengthBiggestNumber; i++)
        {
            item = lista_busca_ordenada(auxLista, i);
            item1 = lista_busca_ordenada(auxLista1, i);
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
            lista_inserir(lista[operations], item_criar(i, valorLista2, 4, 0));
        }
    }
    for (int i = 0; i < operations; i++)
    {
        for (int j = 0; j < lista_tamanho(lista[i]); j++)
        {
            item_imprimir_valor(lista_busca_ordenada(lista[j], i));
            printf("\n");
        }
    }
    return 0;
}

boolean lista_inserir(LISTA *lista, ITEM *item)
{

    if ((lista != NULL) && !lista_cheia(lista))
    {
        (lista->valores[lista->fim]) = item;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

boolean lista_cheia(const LISTA *lista)
{
    return lista->fim >= TAM_MAX;
}
boolean lista_vazia(const LISTA *lista)
{
    return lista->fim == INICIO;
}

boolean lista_inserir_posicao(LISTA *lista, int posicao, ITEM *item)
{
    if (!lista_cheia(lista) && posicao_valida(lista, posicao))
    {
        move_itens_a_direita(lista, posicao);
        lista->valores[posicao] = item;
        lista->fim++;
        return TRUE;
    }
    return FALSE;
}

ITEM *lista_busca_sequencial(const LISTA *lista, int chave)
{
    for (int i = 0; i < lista->fim; i++)
    {
        if (item_get_chave(lista->valores[i]) == chave)
        {
            return lista->valores[i];
        }
    }
    return NULL;
}

ITEM *lista_busca_ordenada(const LISTA *lista, int chave)
{
    for (int i = 0; i < lista->fim; i++)
    {
        if (item_get_chave(lista->valores[i]) == chave)
        {
            return (lista->valores[i]);
        }
        else if (item_get_chave(lista->valores[i]) > chave)
        {
            return NULL; //retorna erro – não está na valores – elemento > chave
        }
    }
    return NULL; //retorna erro – não está na valores - percorreu toda a valores
}

static boolean posicao_valida(const LISTA *l, int pos)
{
    return pos < l->fim;
}

static void move_itens_a_direita(LISTA *l, int pos)
{
    for (int i = (l->fim - 1); i >= pos; i--)
    {
        l->valores[i + 1] = l->valores[i];
    }
}

boolean lista_apagar(LISTA **lista)
{
    if ((*lista != NULL) && (!lista_vazia(*lista)))
    {
        lista_remove_tudo(*lista);
        free(*lista);
        *lista = NULL;
        return TRUE;
    }
    return FALSE;
}

static void lista_remove_tudo(LISTA *lista)
{
    for (int i = 0; i < lista->fim; ++i)
    {
        item_apagar(&lista->valores[i]);
        lista->valores[i] = NULL;
    }
    lista->fim = INICIO;
}
