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

  if (card != NULL)
  {
    card->key = key;
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
    (*card)->key = ERRO;
    free(*card);
    *card = NULL;
    return 1;
  }
  return 0;
}

int isLetter(char *letter) {
  if(strstr(letter,"V") != NULL ||
      strstr(letter,"D") != NULL ||
      strstr(letter,"R") != NULL) {
    return 1;
  }
  return 0;
}

int getCardNumber(const CARD *card)
{
  if (card != NULL)
  {
    if (isLetter(card->number) == 1)
    {
      return 10;
    }
    return atoi(card->number);
  }

  return ERRO;
}
void item_imprimir(const CARD *item)
{
  if (item != NULL)
  {
    printf("\n-->key: %d", item->key);
    printf("\n-->suit: %s", item->suit);
    printf("\n-->number: %s", item->number);
  }
}