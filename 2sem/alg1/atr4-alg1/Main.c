#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista/Lista.h"
#include "Item/Item.h"

void testeEmpilhaStdin();

int main()
{
    int operations = 0;
    scanf("%d", &operations);
    char *operation;    // soma maior menor menos
    char *firstNumber;  // vai pegar os dois numeros
    char *secondNumber; // vai pegar os dois numeros
    // LISTA *firstNumber;
    // LISTA *secondNumber;
    // LISTA *resultList;
    // firstNumber = lista_criar();
    // secondNumber = lista_criar();
    // resultList = lista_criar();
    operation = malloc(6 * sizeof(char));
    firstNumber = malloc(25 * sizeof(char));
    secondNumber = malloc(25 * sizeof(char));
    int length = 0;
    int length1 = 0;
    char aux[4];

    LISTA *lista;
    lista = lista_criar();
    LISTA *lista1;
    lista1 = lista_criar();
    LISTA *lista2;
    lista2 = lista_criar();
    ITEM *item;
    ITEM *item1;
    ITEM *item2;
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
                item = item_criar(j, atoi(aux), strlen(aux)); // averigar slides
                lista_inserir(lista, item);
            }
            else
            {
                strncpy(aux, &firstNumber[0], length);
                item = item_criar(j, atoi(aux), strlen(aux)); // averigar slides
                lista_inserir(lista, item);
            }
            memset(aux, 0, strlen(aux));
        }
        scanf("%s", secondNumber);
        length1 = strlen(secondNumber);
        for (int j = 0; j < (strlen(secondNumber) / 4) + 1; j++)
        {
            if (length1 - 4 >= 0)
            {
                strncpy(aux, &secondNumber[length1 - 4], 4);
                length1 -= 4;
                item = item_criar(j, atoi(aux), strlen(aux)); // averigar slides
                lista_inserir(lista1, item);
            }
            else
            {
                strncpy(aux, &secondNumber[0], length1);
                item = item_criar(j, atoi(aux), strlen(aux)); // averigar slides
                lista_inserir(lista1, item);
            }
            memset(aux, 0, strlen(aux));
        }
    }
    int carry = 0;
    int valorLista2 = 0;
    for (int i = 0; i < 4 /* mocked value*/; i++)
    {
        item = lista_busca_ordenada(lista, i);
        item1 = lista_busca_ordenada(lista1, i);
        valorLista2 = item_somar(item, item1);
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
        item2 = item_criar(i, valorLista2, 4);
        lista_inserir(lista2, item2);
        carry = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        item_imprimir_valor(lista_busca_ordenada(lista2, i));
    }
    // 11123456789
    printf("operation: %s", operation);
    printf("\n number1: %s", firstNumber);
    printf("\n number2:  %s", secondNumber);

    // testeEmpilhaStdin();
    // lista_apagar(&lista);
    // lista_apagar(&lista);
    // lista_apagar(&lista);
}

// void testeEmpilhaStdin()
// {
//     LISTA *lista;
//     lista = lista_criar();
//     ITEM *item = item_ler_std_in();
//     lista_inserir(lista, item);
//     item = item_ler_std_in();
//     lista_inserir(lista, item);
//     item_imprimir(lista_busca_sequencial(lista, 0));
//     item_imprimir(lista_busca_sequencial(lista, 1));
//     boolean_print(lista_vazia(lista));
//     lista_apagar(&lista);
// }
