// Faça um programa em C que leia um número inteiro M que indica a capacidade da tabela, criando-a em seguida. Após isso, seu programa deverá:

//     Ler um número inteiro N que indica o total de inserções na tabela, seguido da leitura e inserção dos N elementos lidos (inteiros e não negativos), utilizando a estratégia linear para sondagem. Não é permitido a inserção de números repetidos na tabela.

//     Ler um número inteiro D que indica o total de remoções na tabela, seguido da leitura e remoção de cada elemento informado.

//     Ler um número inteiro B que indica o total de buscas na tabela. Após isso, deve-se ler B elementos e buscar cada um na tabela, imprimindo o índice da tabela onde ele se encontra. Se não for encontrado, deve-se imprimir -1

#include <stdio.h>
#include <stdlib.h>

int gerarHash(int num, int tamanho);
void imprimirTabela(int *tabela, int tamanho);
void inserir(int *tabela, int tamanho, int num);
int buscar(int *tabela, int tamanho, int num);
void remover(int *tabela, int tamanho, int num);

int main() {
  int capacidade, n, d, b, i, valor;


  scanf("%d", &capacidade);

  int *tabela = (int*) calloc(capacidade, sizeof(int));
  
  for(int i =0;i<capacidade;i++){
    tabela[i] = -1;
  }

  scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if(i < capacidade) {
          scanf("%d", &valor);
          inserir(tabela, capacidade, valor);
        } else {
          scanf("%d", &valor); // discartando valores fora da capacidade
        }
    }

   scanf("%d", &d);

    for (i = 0; i < d; i++) {
      scanf("%d", &valor);
      remover(tabela, capacidade, valor);
    }

    scanf("%d", &b);

    for (i = 0; i < b; i++) {
        scanf("%d", &valor);
        printf("%d ", buscar(tabela, capacidade, valor));
    }
}

int gerarHash(int num, int tamanho){
    return num % tamanho;
}

void imprimirTabela(int *tabela, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", tabela[i]);
    }
}
void inserir(int *tabela, int tamanho, int num) {
    int pos = gerarHash(num, tamanho);
    while (tabela[pos] != -1) {
        if(tabela[pos] == num){
            break;
        }
        pos = gerarHash(pos+1, tamanho);
    }
    tabela[pos] = num;
}
int buscar(int *tabela, int tamanho, int num) {
    int pos = gerarHash(num, tamanho);
    int i = 0;
    while (i<tamanho) {
        if(tabela[pos] == num){
            return pos;
        }
        pos = gerarHash(pos+1, tamanho);
        i++;
    }
    return -1;
}
void remover(int *tabela, int tamanho, int num) {
    int pos = gerarHash(num, tamanho);
    int i = 0;
    while (i<tamanho) {
        if(tabela[pos] == num){
            tabela[pos] = -1;
            break;
        }
        pos = gerarHash(pos+1, tamanho);
        i++;
    }
}