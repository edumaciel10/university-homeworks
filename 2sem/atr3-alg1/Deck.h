#ifndef DECK_H
#define DECK_H

#include "Card.h"

#define TAM 52
#define DECK_ERROR (-313131)

typedef struct deck_st DECK;

DECK* createDeck();
int emptyDeck(const DECK* deck); // bool
int fullDeck(const DECK *deck);// bool
int lengthDeck(const DECK *deck);
int pushDeck(DECK *deck, CARD* card);
CARD* topDeck(const DECK *deck);
CARD* popDeck(DECK* deck);
int deleteDeck(DECK **deck);// bool

#endif //DECK_H