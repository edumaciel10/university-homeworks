#include <stdio.h>
#include <stdlib.h>
#include "Deck.h"

int main()
{
  DECK *deck;
  int sumOfCards = 0;
  deck = createDeck();
  getDeckCards(deck);
  sumOfCards = getSumCardsOfDeck(deck);
  printResult(sumOfCards);
  return 0;
}
