#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct product {
    int productId;
    char name[100];
    float price;
    int amount;
};

struct sale {
    int productId;
    int amount;
    float total;
    char date[20];
};

struct product getProductData(struct product produto, int id){
    printf("\n [Dados do produto]");
    if(id == 1) {
        printf("\n Digite o id do produto:");
        scanf("%d", &produto.productId);
    }
    printf("\n Digite o nome:");
    setbuf(stdin,0);
    fgets(produto.name, 100, stdin);
    printf("\nDigite o preco:");
    scanf("%f", &produto.price);
    printf("\nDigite a quantidade:");
    scanf("%d", &produto.amount);
    return produto;
}

void insertProduct(struct product produto) {
    FILE *arq;
    struct product lastProduct;

    if ((arq = fopen("products.txt", "ab+")) == NULL)
        printf("\nErro abrindo arquivo.\n");
    // get last product
    fseek(arq,-sizeof(struct product),SEEK_END);

    // add 1 to id of the last product
    if (fread(&lastProduct, sizeof(struct product), 1, arq) == 1)
    {
        produto.productId = lastProduct.productId + 1;
    }
    else
    {
        produto.productId = 1;
    }
    //saving new product
    if(fwrite(&produto, sizeof(produto), 1, arq) != 1) {
        printf("Erro na escrita do arquivo");
    }
    fflush(arq);
    fclose(arq);
}

void readProduct() {
    FILE *arq;
    printf("\n[Todos os produtos disponíveis na base de dados]");
    struct product produto;
    if ((arq = fopen("products.txt", "a+")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    printf("\nId \t Nome \t Preco \t Quantidade");
    while(!feof(arq)) {
        fread(&produto, sizeof(struct product), 1, arq);
        if(feof(arq))
            break;
        printf("\n%d \t %.5s \t %.2f \t %d ", produto.productId, produto.name, produto.price, produto.amount);
    }
    printf("\n");
    fflush(arq);
    fclose(arq);
}


struct product getProductById(int id) {
    FILE *arq;
    struct product produto;
    if ((arq = fopen("products.txt", "r+")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    printf("\nId \t Nome \t Preco \t Quantidade");
    while(!feof(arq)) {
        fread(&produto, sizeof(struct product), 1, arq);
        if(feof(arq))
            break;

        if(produto.productId == id) {
            break;
        }
    }
    printf("\n%d \t %.5s \t %.2f \t %d ", produto.productId, produto.name, produto.price, produto.amount);

    printf("\n");
    fflush(arq);
    fclose(arq);
    return produto;
}

void findAndUpdateProduct(struct product updated) {
    FILE *arq;
    
    struct product produto;
    int currentPositionOfFile;
    if ((arq = fopen("products.txt", "r+b")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    while(!feof(arq)) {
        fread(&produto, sizeof(struct product), 1, arq);
        if(produto.productId == updated.productId) {
            currentPositionOfFile = ftell(arq);
            fseek(arq, currentPositionOfFile - sizeof(produto), SEEK_SET);
            fwrite(&updated, sizeof(updated), 1, arq);
            printf("\nAlteracao Feita com sucesso!");
            // printf("\n %.5s \t %f \t  %d \t", produto.name, produto.price, produto.amount);
            break;
        }
    }
    fflush(arq);
    fclose(arq);
}

void showSalesOfMonth() {

    int month;
    char *arrayOfSplitString, date[100];
    printf("\n[Relatório de vendas por mês]\n");

    printf("\n Digite por qual mês você gostaria de filtrar:");
    scanf("%d", &month);

    FILE *arq;
    
    struct sale venda;

    int totalAmount=0, totalPrice=0;

    if ((arq = fopen("sales.txt", "r+")) == NULL) {
        printf("\nErro abrindo arquivo.\n");
    }

    printf("\n ID \t Quantidade \t Data \t Total");

    while (!feof(arq))
    {
        fread(&venda, sizeof(struct sale), 1, arq);
        if (feof(arq)) {
            break;
        }
        // get month from DD-MM-AAAA
        strcpy(date, venda.date);
        arrayOfSplitString = strtok(venda.date, "-");
        arrayOfSplitString = strtok(NULL, venda.date);
        if(atoi(arrayOfSplitString) == month ) {
            totalAmount += venda.amount;
            totalPrice += venda.total;
            printf("\n %d \t%d \t %s \t %f", venda.productId, venda.amount, date, venda.total);
        }
    }
    setbuf(stdout, 0);
    printf("\n Valor total de produtos vendidos: %d \n Quantidade otal de produtos vendidos: %d", totalPrice, totalAmount);
    fflush(arq);
    fclose(arq);

}

void showSalesOfProduct() {

    int productId;
    printf("\n[Relatório de vendas por produto]\n");

    readProduct();

    printf("\n Digite por qual produto você gostaria de filtrar:");
    scanf("%d", &productId);

    FILE *arq;

    struct sale venda;

    int totalAmount=0, totalPrice=0;

    if ((arq = fopen("sales.txt", "r+")) == NULL) {
        printf("\nErro abrindo arquivo.\n");
    }

    printf("\n ID \t Quantidade \t Data \t Total");

    while (!feof(arq))
    {
        fread(&venda, sizeof(struct sale), 1, arq);
        if (feof(arq)) {
            break;
        }
        // get month from DD-MM-AAAA
        if(venda.productId == productId ) {
            totalAmount += venda.amount;
            totalPrice += venda.total;
            printf("\n %d \t%d \t %s \t %f", venda.productId, venda.amount, venda.date, venda.total);
        }
    }
    setbuf(stdout, 0);
    printf("\n Valor total de produtos vendidos: %d \n Quantidade otal de produtos vendidos: %d", totalPrice, totalAmount);
    fflush(arq);
    fclose(arq);

}

int fsize(FILE* arq) {
    fseek(arq, 0, SEEK_END);
    long size = ftell(arq);
    fseek(arq, 0, SEEK_SET);
    return (int)size;
}
// Deve retornar um array de struct dos produtos.
void getProductsLength(struct product **produtos) {
    FILE *arq;

    int i=0;

    if ((arq = fopen("products.txt", "r+")) == NULL)
    {
        printf("\nErro abrindo arquivo.\n");
    }
    int fsizeProducts = fsize(arq)/sizeof(struct product);
    *produtos= (struct product *) malloc(fsizeProducts*sizeof(struct product));

    struct product produto;

    while (!feof(arq))
    {
        fread(&produto, sizeof(struct product), 1, arq);
        if (feof(arq))
            break;
        (*produtos)[i] = produto;
        i++;
    }
    // int fsizeProducts = 10;

    fflush(arq);
    fclose(arq);
}

void aloca2(int n, int **v) {
    int i;
    *v= (int *) malloc(n*sizeof(int));

    for (i=0; i<5; i++)
        (*v)[i]=i;
}

void showSalesRanking() {
    printf("\n[Relatório de produtos mais vendidos]\n");

    /*
        Pegar todas as structs do arquivo
        produtos[productId].amount, and price
        colocar dentro de um array de struct com a função do cara do zap
        fazer um bubble sort de acordo com o price
        printar por ordem
    */
    // get and organize a struct of products
    FILE *arqSale,*arqProduct;

    int totalAmount = 0;
    float totalPrice = 0;

    struct product *produtos;
    getProductsLength(&produtos);
    if ((arqProduct = fopen("products.txt", "r+")) == NULL)
    {
        printf("\nErro abrindo arquivo.\n");
    }
    int fsizeProducts = fsize(arqProduct) / sizeof(struct product);
    fflush(arqProduct);
    fclose(arqProduct);
    //finish  organize a struct of products
    // get and organize data of sales
    if ((arqSale = fopen("sales.txt", "r+")) == NULL)
    {
        printf("\nErro abrindo arquivo.\n");
    }
    setbuf(stdout, 0);
    setbuf(stdin, 0);

    int fsizeSales = fsize(arqSale) / sizeof(struct sale);
    struct sale vendas[fsizeSales];
    //Clear sales
    for (int i = 0; i < fsizeSales;i++) {
        vendas[i].amount = 0;
        strcpy(vendas[i].date, "");
        vendas[i].total = 0;
        vendas[i].productId = 0;
    }
    struct sale venda;
    int vendaIndex = 0;
    while (!feof(arqSale))
    {
        fread(&venda, sizeof(struct sale), 1, arqSale);
        if (feof(arqSale))
        {
            break;
        }
        vendas[vendaIndex] = venda;
        vendaIndex++;
        totalAmount += venda.amount;
        totalPrice += venda.total;
    }
    // GROUP BY PRODUCTS
    for (int i = 0; i < fsizeSales; i++)
    {
        for (int j = 0; j < fsizeSales; j++)
        {
            if(vendas[i].productId == vendas[j].productId && j>i) {
                vendas[i].amount += vendas[j].amount;
                vendas[i].total += vendas[j].total;
                vendas[j].productId = 0;
            }
        }
    }


    // end get and organize data of sales
    // sort items
    struct sale aux;
    int troca = 1;
    while (troca == 1)
    {
        troca = 0;
        for (int i = 0; i < fsizeProducts; i++)
        {
            if(i+1 == fsizeProducts) continue;

            if (vendas[i].total > vendas[i + 1].total)
            {
                troca = 1;
                aux = vendas[i];
                vendas[i] = vendas[i + 1];
                vendas[i + 1] = aux;
            }
        }
    }
    for (int i = fsizeProducts; i > 0; i--)
    {
        printf("\n%.10s\t%d\t%d\t %.2f", produtos[vendas[i].productId].name, vendas[i].productId, vendas[i].amount, vendas[i].total);
    }
    printf("\n Valor total de produtos vendidos: %.2f \n Quantidade Total de produtos vendidos: %d", totalPrice, totalAmount);
    fflush(arqSale);
    fclose(arqSale);
}
void findAndDeleteProductById(int id) {
    FILE *arq;
    
    struct product produto;
    int currentPositionOfFile;
    if ((arq = fopen("products.txt", "r+b")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    while(!feof(arq)) {
        fread(&produto, sizeof(struct product), 1, arq);
        // check if id of file is equal to id of param
        if(produto.productId == id) {
            //get current position of cursor on file
            currentPositionOfFile = ftell(arq);
            //set cursor position
            fseek(arq, currentPositionOfFile - sizeof(produto), SEEK_SET);
            //write blank struct
            strcpy(produto.name, "");
            produto.amount = 0;
            produto.price = 0;
            fwrite(&produto, sizeof(produto), 1, arq);
            printf("\n %.5s \t %f \t  %d \t", produto.name, produto.price, produto.amount);
            break;
        }
    }

    fclose(arq);
}

// mando uma struct vazia e retorno com ela.
struct sale getSaleData(struct sale venda) {
    printf("\nEscolha o id do produto:");
    scanf("%d", &venda.productId);
    printf("\nDigite a quantidade do produto:");
    scanf("%d", &venda.amount);
    setbuf(stdin, 0);
    printf("\nDigite a data neste formato: DD-MM-AAAA:");
    fgets(venda.date, 100, stdin);
    return venda;
}

void insertSale(struct sale newSale) {
    FILE *arq;

    struct product produto = getProductById(newSale.productId);

    if(newSale.amount > produto.amount) {
        printf("\n A quantidade colocada na venda é superior a que temos em estoque, tente novamente.");
        return;
    }
    produto.amount -= newSale.amount;
    findAndUpdateProduct(produto);
    newSale.total = newSale.amount * produto.price;

    if ((arq = fopen("sales.txt", "ab+")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    // add 1 to id of the last product
    fseek(arq,sizeof(struct sale),SEEK_END);


    //saving new product
    if(fwrite(&newSale, sizeof(newSale), 1, arq) != 1) {
        printf("\nErro na escrita do arquivo");
    } else {
        printf("\nVenda feita com sucesso!");
    }

    fflush(arq);
    fclose(arq);
}

void readSale() {
    FILE *arq;
    
    struct sale venda;

    if ((arq = fopen("sales.txt", "r+")) == NULL)
        printf("\nErro abrindo arquivo.\n");

    while(!feof(arq)) {
        fread(&venda, sizeof(struct sale), 1, arq);
        if(feof(arq))
            break;
        printf("\n %d \t %d \t %s \t %.2f ", venda.productId, venda.amount, venda.date, venda.total);
    }
    fflush(arq);
    fclose(arq);
}

void showPrincipalMenu() {
    printf("\n\n Qual operação deseja realizar?");
    printf("\n 1 - Cadastrar um produto");
    printf("\n 2 - Alterar um produto");
    printf("\n 3 - Deletar um produto");
    printf("\n 4 - Cadastrar uma venda ");
    printf("\n 5 - Extrair relatório de vendas em um mês");
    printf("\n 6 - Extrair relatório de um produto");
    printf("\n 7 - Extrair relatório de produtos mais vendidos");
    printf("\n 0 - Encerrar o programa");
}

int getInput(int input) {
    printf("\n Digite sua escolha:");
    scanf("%d",&input);
    return input;
}

int main()
{
    int stopProgram = 0;
    struct product produto;
    struct sale venda;
    int input = 0;
    printf("\nOla, seja bem vindo.");
    while (stopProgram != 1)
    {
        showPrincipalMenu();
        printf("\n Digite sua escolha:");
        scanf("%d",&input);
        if(input ==0) {
            break;
        }
        if(input == 1) { // create product
            produto = getProductData(produto,0);
            insertProduct(produto);
            readProduct();
        }
        if(input ==2) { // update product
            readProduct();
            produto = getProductData(produto,1);
            findAndUpdateProduct(produto);
        }
        if(input ==3) { // delete product
            readProduct();
            produto = getProductData(produto,0);
            findAndDeleteProductById(produto.productId);
        }
        if(input == 4) {
            printf("\n[Cadastro de vendas]\n");
            readProduct();
            venda = getSaleData(venda);
            insertSale(venda);
        }
        if(input == 5) { //Read all products and separate to a array
            showSalesOfMonth();
        }
        if(input == 6) {
            showSalesOfProduct();
        }
        if(input == 7) {
            readSale();
            showSalesRanking();
        }
        // sleep(10);
        // system("@cls||clear");

    }
    return 0;
}
