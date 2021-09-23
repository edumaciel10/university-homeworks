#include <stdio.h>
#include "Deck.h"

void testeEmpilhaEDesempilha();
// void testeEmpilhaMuitos();

int main()
{
  DECK *deck;
  deck = createDeck();

  CARD *card = createCard(0, "Ouro", "10");
  pushDeck(deck, card);
  card = createCard(1, "Ouro", "10");
  pushDeck(deck, card);
  card = createCard(2, "Ouro", "10");
  pushDeck(deck, card);
  card = createCard(3, "Ouro", "10");
  pushDeck(deck, card);
  card = createCard(4, "Ouro", "10");
  pushDeck(deck, card);
  item_imprimir(topDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  item_imprimir(popDeck(deck));
  deleteDeck(&deck);
  return 0;
}

void testeEmpilhaEDesempilha()
{
    DECK *deck;
    deck = createDeck();
    // CARD *card = createCard(0, "Ouro", "10");
    // pushDeck(deck, card);
    // item_imprimir(topDeck(deck));
    // item_imprimir(popDeck(deck));
    // deleteDeck(&deck);
}
