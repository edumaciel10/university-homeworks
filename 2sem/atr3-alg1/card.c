#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Card.h"

struct card_st
{
  int key;
  char *suit;
  char *number;
};

CARD *createCard(int key, char *suit, char *number)
{

  CARD *card;

  card = (CARD *)malloc(sizeof(CARD));
  printf("To aqq");

  if (card != NULL)
  {
    printf("To aqq");

    card->key = key;
    card->suit = (char *)malloc(sizeof(suit));
    card->number = (char *)malloc(sizeof(number));
    strcpy(card->suit, suit);
    strcpy(card->number, number);
    return card;
  }
  return NULL;
}

int deleteCard(CARD **card)
{
  if (*card != NULL)
  {
    (*card)->key = ERRO; /*apaga o item simbolicamente*/
    free(*card);
    *card = NULL;
    return 1;
  }
  return 0;
}

int getCardNumber(const CARD *card)
{
  if (card != NULL)
  {
    return ((strlen(card->number) == 1 ? 10 : atoi(card->number)));
  }
  return ERRO;
}
void item_imprimir(const CARD *item)
{
  if (item != NULL)
  {
    printf("\n-->chave: %d\n", item->key);
    printf("\n-->nome: %s\n", item->suit);
    printf("\n-->ataque: %s\n", item->number);
  }
}