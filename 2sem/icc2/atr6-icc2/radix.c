#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RADICANDO 2
#define DIGITO_SIGNIFICATIVO 1
#define MENOR_QUE_10_DIGITOS_FLAG -1

void print(long *, int);
int pegar_maior_elemento(long *, int);
void radix(long *, int, const int);
void preenche_vetor(int, long *);
void pega_dados(int *, int *);
void preenche_vet_meio_ordenado(long *, int, const int *);
int *alocar_vet_meio_ordenado(int tam);

int main()
{
  int expoente, tam, base;
  long *vetor;

  pega_dados(&expoente, &tam);
  base = (int) pow(RADICANDO, expoente);
  vetor = (long *) calloc(tam, sizeof (long));
  preenche_vetor(tam, vetor);
  radix(vetor, tam, base);
}

void pega_dados(int *expoente, int *tam) 
{
  scanf("%d", expoente);
  scanf("%d", tam);
}

void preenche_vetor(int tam, long *vetor) 
{
  for(int i = 0; i < tam; i++)
  {
    scanf("%ld", &vetor[i]);
  }
}

void print(long * vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("%ld ", vetor[i]);
  }
  printf("\n");
}

int pegar_maior_elemento(long * vetor, int tam)
{
  int maior = vetor[0];

  for(int i = 0; i < tam; i++)
  {
    if( maior < vetor[i])
    {
      maior = vetor[i];
    }
  }
  return maior;
}

void radix(long * vetor, int tam, const int BASE)
{
  int *meio_ordenado = NULL, i, digito_na_base, digito_signif = DIGITO_SIGNIFICATIVO;
  long maior_elemento = pegar_maior_elemento(vetor, tam);

  meio_ordenado = alocar_vet_meio_ordenado(tam);

  // loop até alcançarmos o maior dígito significativo
  while (maior_elemento / digito_signif > 0)
  {
    long *auxiliar = (long *) calloc(BASE, sizeof(long));

    //Conta o número de chaves q vão p cada vetor auxiliar
    for (i = 0; i < tam; i++)
    {
      digito_na_base = (vetor[i] / digito_signif) % BASE;
      auxiliar[digito_na_base]++;
    }
    //soma os elementos de index de todos os numeros significativos
    for (i = 1; i < BASE; i++)
    {
      auxiliar[i] = auxiliar[i] + auxiliar[i - 1];
    }
    //preenche o meio ordenado com os que foram ordenados pelo digito.
    for (i = tam - 1; i >= 0; i--)
    {
      digito_na_base = (vetor[i] / digito_signif) % BASE;
      auxiliar[digito_na_base]--;
      int j = auxiliar[digito_na_base];
      meio_ordenado[j] = vetor[i];
    }
    preenche_vet_meio_ordenado(vetor, tam, meio_ordenado);
    digito_signif *= BASE;
    print(vetor, tam);
  }
}

int *alocar_vet_meio_ordenado(int tam) {
  int *meio_ordenado;

  meio_ordenado = (int *) calloc(tam, sizeof (int));
  return meio_ordenado;
}

void preenche_vet_meio_ordenado(long *vetor, int tam, const int *meio_ordenado)
{
  for (int i = 0; i < tam; i++)
  {
    vetor[i] = meio_ordenado[i];
  }
}