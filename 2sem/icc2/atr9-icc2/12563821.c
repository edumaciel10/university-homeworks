/* Faça um programa em C que 
leia um número N de elementos 
de um vetor de inteiros V,
e em seguida leia os N elementos de V.
Após isso, leia um número inteiro K, seguido da leitura de K inteiros.
 O seu programa deverá busca todos os K números no vetor V, e escrever 1 se o elemento foi encontrado em V e 0 caso contrário.
*/
// Ponto extra:

// Caso o grupo escolha utilizar árvores na solução,
// será acrescido um ponto na nota final caso a utilização esteja correta. 
// Isso deve estar indicado na mensagem da submissão do link vídeo no fórum do e-disciplinas, ou seja,
// o grupo deve deixar claro que foi utilizado árvores na solução na mensagem e somente esses serão verificados.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct node_st NODE;

struct node_st
{
    int valor;
    NODE *direita;
    NODE *esquerda;
};

struct arvore_binaria
{
    NODE* raiz;
};

ARVORE_BINARIA *arvore_binaria_criar()
{
    ARVORE_BINARIA *arvore;
    arvore = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

void arvore_binaria_buscar(ARVORE_BINARIA *arvore, int valor)
{
    NODE *atual = arvore->raiz;
    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("1\n");
            return;
        }
        if (atual->valor > valor) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    printf("0\n");
}

NODE * ab_cria_no(int valor)
{
    NODE * novo_no;
    novo_no = (NODE *) malloc(sizeof(NODE));
    if (novo_no != NULL) {
        novo_no->valor = valor;
        novo_no->direita = NULL;
        novo_no->esquerda = NULL;
    }
    return novo_no;
}
int valor_comparar(int valor1, int valor2)
{
    if (valor1 == valor2)
    {
        return 0;
    }
    else if (valor1 < valor2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int no_checa_duplicado(NODE *raiz, int valor)
{
    if (valor_comparar(raiz->valor, valor) == 0) {
        return 1;
    }
    if(raiz->esquerda != NULL) {
        if (valor_comparar(raiz->esquerda->valor, valor) == 0) {
            return 1;
        }
    }
    if(raiz->direita != NULL) {
        if (valor_comparar(raiz->direita->valor, valor) == 0) {
            return 1;
        }
    }
    return 0;
}

NODE * ab_inserir_no(NODE* raiz, int valor)
{
    if (raiz == NULL) {
        raiz = ab_cria_no(valor);
    } else {
        if (valor < raiz->valor ) {
            raiz->esquerda = ab_inserir_no(raiz->esquerda, valor);
        } else if (valor > raiz->valor) {
            raiz->direita = ab_inserir_no(raiz->direita, valor);
        }  
    }
    return raiz;
}


int ab_inserir(ARVORE_BINARIA *T, int valor){
    if (T->raiz == NULL)
        return((T->raiz = ab_cria_no(valor)) != NULL);
    else
        return((T->raiz = ab_inserir_no(T->raiz, valor)) != NULL);
}

int ab_apagar_no(NODE *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    ab_apagar_no(raiz->esquerda);
    ab_apagar_no(raiz->direita);
    free(raiz);
    raiz = NULL;
    return 1;
}
int ab_apagar (ARVORE_BINARIA **T) {
    if (*T == NULL) {
        return 0;
    }
    ab_apagar_no((*T)->raiz);
    free(*T);
    *T = NULL;
    return 1;
}

void heap(int *array, int n) {
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
    
#define N 6

int main() {
    ARVORE_BINARIA *arvoreBinaria;
    arvoreBinaria = arvore_binaria_criar();
    

    int elN, valor, elB;
    scanf("%d", &elN);
    int *vetor = calloc(elN, sizeof(int));

    for(int i = 0; i < elN; i++) {
        scanf("%d", &valor);
        vetor[i]= valor;
    }


  
    for (int j = 0; j < 20; j++) {
        heap(vetor, elN);
    }

    for(int i = 0; i < elN; i++) {
        ab_inserir(arvoreBinaria, vetor[i]);
    }

    scanf("%d",&elB);
    
    for(int i = 0; i < elB; i++) {
        scanf("%d", &valor);
        arvore_binaria_buscar(arvoreBinaria, valor);
    }

    ab_apagar(&arvoreBinaria);

    return 0;
}