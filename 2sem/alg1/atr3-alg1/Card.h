#ifndef CARD_H
#define CARD_H

#define TAM 52
#define ERRO (-32000)

typedef struct card_st CARD;

CARD *createCard (int key, char *suit, char *number);
int deleteCard(CARD **card);
void printCard(const CARD *card);
int getCardNumber(const CARD *card);
void item_imprimir(const CARD *item);
int isLetter(char *letter);
#endif //CARD_H