#ifndef TADGENERICO_cliente_H
#define TADGENERICO_cliente_H

#define ERRO (-32000)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct cliente_st CLIENTE;

CLIENTE *cliente_criar_vazio();
CLIENTE *cliente_criar (long chave, char *nome, int idade, int saldo);
CLIENTE *cliente_ler_std_in();
boolean cliente_apagar(CLIENTE **cliente);
void cliente_imprimir(const CLIENTE *cliente);
int cliente_get_chave(const CLIENTE *cliente);
boolean cliente_set_chave(CLIENTE *cliente, long chave);
int cliente_comparar(const CLIENTE *cliente1, const CLIENTE *cliente2);

#endif //TADGENERICO_cliente_H
