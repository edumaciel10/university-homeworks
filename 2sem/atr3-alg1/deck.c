#include <stdlib.h>
#include <stdio.h>
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

void getDeckCards(DECK* deck) {
    CARD *card = NULL;
    char *suit;
    char *number;
    for (int i = 0; i < TAM; i++)
    {
        if(!scanf("%s", suit)) {
            break;
        }

        if(!scanf("%s", number)) {
            break;
        }

        card = createCard(i, suit, number);
        item_imprimir(card);
        if (card != NULL)
        {
            pushDeck(deck, card);
        }
    }
}
int getSumCardsOfDeck(DECK * deck) {
    CARD *card = NULL;
    int sumOfCards = 0;
    for (int i = 0; i < TAM; i++)
    {
        card = popDeck(deck);
        sumOfCards += getCardNumber(card);
        if(sumOfCards >= 21) {
            return sumOfCards;
        }
    }
}

void printResult(int sumOfCards) {
    if(sumOfCards == 21) {
        printf("\nGanhou ;)");
    } else {
        printf("\nPerdeu :(");
        printf("\nSoma :: %d", sumOfCards);
    }
}

int deleteDeck(DECK **deck)
{
    if (*deck != NULL)
    {
        (*deck)->top = DECK_ERROR;
        free (*deck);
        *deck = NULL;
        return 1;
    }
    return 0;
}