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
    lista_preencher_resultados(lista, operations);
    // lista_mostrar_resultados(lista, operations);
}