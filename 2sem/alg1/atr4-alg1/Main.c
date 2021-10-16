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

    LISTA *lista[operations];
    int k = lista_preencher_resultados(lista, operations);
    printf("%d", k);
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
