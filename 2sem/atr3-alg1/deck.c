#include <stdlib.h>
#include "Deck.h"

struct deck_st {
    CARD *card[TAM];
    int top;
};

DECK *createDeck()
{
    DECK *deck = (DECK*) malloc(sizeof(DECK));
    if(deck != NULL)
    {
        deck->top = 0;
    }
    return deck;
}

int emptyDeck(const DECK* deck)
{
  return (deck != NULL) ? deck->top == 0 : DECK_ERROR;
}

int fullDeck(const DECK *deck) {
    return (deck != NULL) ? deck->top == TAM : DECK_ERROR;
}

int lengthDeck(const DECK *deck) {
    return ((deck != NULL) ? deck->top : DECK_ERROR);
}

int pushDeck(DECK *deck, CARD* card)
{
    if ((deck!=NULL) && (!fullDeck(deck)))
    {
        deck->card[deck->top] = card;
        deck->top++;
        return 1;
    }
    return 0;
}

CARD* topDeck(const DECK *deck){
    if ((deck != NULL) && (!emptyDeck(deck))) {
        return (deck->card[deck->top-1]);
    }
    return NULL;
}

CARD* popDeck(DECK* deck){
    CARD* card;
    if ((deck != NULL) && (!emptyDeck(deck))) {
        card = topDeck(deck);
        deck->card[deck->top-1] = NULL;
        deck->top--;
        return card;
    }
    return NULL;
}

int deleteDeck(DECK **deck)
{
    if (*deck != NULL)
    {
        (*deck)->top = DECK_ERROR; /*apaga o item simbolicamente*/
        free (*deck);
        *deck = NULL;
        return 1;
    }
    return 0;
}