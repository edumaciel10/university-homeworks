#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[50];
    float preco;
    int quantEstoque;
} produto;

typedef struct
{
    int codigoProduto;
    int quantVendas;
    int dia;
    int mes;
    int ano;
} registroVendas;

void menu(produto listaDeProdutos[], registroVendas *listaVendas, int quantProduto, int quantVendas);
void cadastrar(produto listaDeProdutos[], int quantProduto);
void editarProduto(produto listaDeProdutos[], int quantProduto);
void apagarProduto(produto listaDeProdutos[], int quantProduto);

void pesquisarProduto(produto listaDeProdutos[], int quantProduto);
void listarProdutos(produto listaDeProdutos[], int quantProduto);
void verificarCodigo(produto listaDeProdutos[], int quantProduto);
int lugarVazioProduto(produto listaDeProdutos[], int quantProduto);

int main()
{
    FILE *fileProduto;
    FILE *fileVendas;
    int quantProduto = 20;
    int quantVendas = 50;
    produto listaDeProdutos[quantProduto];
    for (int i = 0; i < quantProduto;i++) {
        listaDeProdutos[i].codigo = 0;
        strcpy(listaDeProdutos[i].nome, "");
        listaDeProdutos[i].preco = 0;
        listaDeProdutos[i].quantEstoque = 0;
    }
    registroVendas listaDeVendas[quantVendas];

    // menu(listaDeProdutos, listaDeVendas, quantProduto, quantVendas);
    int op=0;
    do
    {
        printf("\n1 - Cadastrar produto \n2 - Editar produto");
        printf("\n3 - Apagar produto \n4 - Registrar venda");
        printf("\n5 - Pesquisar produto\n6 - Listar Produtos\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                cadastrar(listaDeProdutos, quantProduto);
                break;
            case 2:
                editarProduto(listaDeProdutos, quantProduto);
                break;
            case 3:
                apagarProduto(listaDeProdutos, quantProduto);
                break;
            case 4:
                break;
            case 5:
                pesquisarProduto(listaDeProdutos, quantProduto);
                break;
            case 6:
                listarProdutos(listaDeProdutos, quantProduto);
                break;
        }
    } while (op != 0);

    fileProduto = fopen("produto.txt", "rb+"); //Abre arquivo para leitura
    if (fileProduto == NULL)
    {
        printf("Erro ao ler arquivo. Criando um outro...");
        fileProduto = fopen("produto.txt", "wb+"); //Cria caso não exista
        if (fileProduto == NULL)
        {
            printf("Erro");
            return 0;
        }

        fseek(fileProduto, 0, SEEK_SET);
        apagarProduto(listaDeProdutos, quantProduto);
        
        for (int i = 0; i < quantProduto; i++) {
            printf("\nO codigo e: %d \n", listaDeProdutos[i].codigo);
            printf("O nome e: %s\n", listaDeProdutos[i].nome);
            printf("O preco e: %.2f\n", listaDeProdutos[i].preco);
            printf("A quantidade no estoque e: %d \n", listaDeProdutos[i].quantEstoque);
        }
        return 0;
        fwrite(listaDeProdutos, sizeof(listaDeProdutos[quantProduto]), quantProduto, fileProduto);
        fclose(fileProduto);
    }
    else
    {
        fseek(fileProduto, 0, SEEK_SET);
        fread(listaDeProdutos, sizeof(listaDeProdutos[quantProduto]), quantProduto, fileProduto);
    }
    fclose(fileProduto);

    fileProduto = fopen("produto.txt", "wb+");
    // menu(listaDeProdutos, listaDeVendas, quantProduto, quantVendas);

    fwrite(listaDeProdutos, sizeof(listaDeProdutos[quantProduto]), quantProduto, fileProduto);
    fclose(fileProduto);
}
void menu(produto listaDeProdutos[], registroVendas listaVendas[], int quantProduto, int quantVendas)
{
    system("cls");
    int op;
    do
    {
        printf("\n1 - Cadastrar produto \n2 - Editar produto");
        printf("\n3 - Apagar produto \n4 - Registrar venda");
        printf("\n5 - Pesquisar produto\n6 - Listar Produtos\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
            case 0:
                return;
            case 1:
                cadastrar(listaDeProdutos, quantProduto);
                break;
            case 2:
                editarProduto(listaDeProdutos, quantProduto);
                break;
            case 3:
                apagarProduto(listaDeProdutos, quantProduto);
                break;
            case 4:
                break;
            case 5:
                pesquisarProduto(listaDeProdutos, quantProduto);
                break;
            case 6:
                listarProdutos(listaDeProdutos, quantProduto);
                break;
        }
    } while (op != 0);
}

void cadastrar(produto listaDeProdutos[], int quantProduto)
{
    system("cls");
    int lugarVazio;
    lugarVazio = lugarVazioProduto(listaDeProdutos, quantProduto);

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &listaDeProdutos[lugarVazio].codigo);
    printf("\nDigite o nome do produto: ");
    setbuf(stdin, 0);
    fgets(listaDeProdutos[lugarVazio].nome, 50, stdin);
    printf("\nDigite o preco do produto: ");
    scanf("%f", &listaDeProdutos[lugarVazio].preco);
    printf("\nDigite a quantidade em estoque: ");
    scanf("%d", &listaDeProdutos[lugarVazio].quantEstoque);
    printf("\n\nProduto cadastrado com sucesso!!");
}
void apagarProduto(produto listaDeProdutos[], int quantProduto)
{
    for (int i = 0; i < quantProduto; i++)
    {
        listaDeProdutos[i].codigo = -1;
    }
}
int lugarVazioProduto(produto listaDeProdutos[], int quantProduto)
{
    for (int i = 0; i < quantProduto; i++)
    {
        if (listaDeProdutos[i].codigo == 0)
        {
            return i;
        }
    }
    printf("nao há mais espaços vazios");
    return 0;
}
void listarProdutos(produto listaDeProdutos[], int quantProduto)
{
    for (int i = 0; i < quantProduto; i++)
    {
        if (listaDeProdutos[i].codigo != 0)
        {
            printf("\nO codigo e: %d \n", listaDeProdutos[i].codigo);
            printf("O nome e: %s\n", listaDeProdutos[i].nome);
            printf("O preco e: %.2f\n", listaDeProdutos[i].preco);
            printf("A quantidade no estoque e: %d \n", listaDeProdutos[i].quantEstoque);
        }
    }
}
void editarProduto(produto listaDeProdutos[], int quantProduto)
{
    int codigo = 0;
    printf("Informe o codigo do produto a ser editado: ");
    scanf("%d", &codigo);
    for (int i = 0; i < quantProduto; i++)
    {
        if (codigo == listaDeProdutos[i].codigo)
        {
            printf("Esse código já está cadastrado");
        }
        else
        {
            printf("informe o novo nome do produto selecionado \n");
            setbuf(stdin, 0);
            fgets(listaDeProdutos[i].nome, 50, stdin);
            listaDeProdutos[i].nome[strcspn(listaDeProdutos[i].nome, "\n")] = 0;
            printf("Insira o novo preco:\t");
            scanf("%f", &listaDeProdutos[i].preco);
            printf("Insira a nova quantidade em estoque: ");
            scanf("%d", &listaDeProdutos[i].quantEstoque);
        }
    }
}
void pesquisarProduto(produto listaDeProdutos[], int quantProduto)
{
    int codigo;
    printf("Informe o codigo do produto a ser pesquisado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < quantProduto; i++)
    {
        if (codigo == listaDeProdutos[i].codigo)
        {
            printf("\no codigo do produto e: %d", listaDeProdutos[i].codigo);
            printf("\no nome do produto e: %s", listaDeProdutos[i].nome);
            printf("\no preco do produto e: %f", listaDeProdutos[i].preco);
            printf("\na quantidade no estoque e: %d", listaDeProdutos[i].quantEstoque);
        }
        else
        {
            printf("Esse codigo nao esta cadastrado!!\n");
            // break;
        }
    }
}
void verificarCodigo(produto listaDeProdutos[], int quantProduto)
{
}
