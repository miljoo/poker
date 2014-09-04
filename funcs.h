#ifndef FUNCS_H
#define FUNCS_H
#include "card.h"

using namespace std;

void initDeck(Card deck[]);
Card deal(Card deck[]);
int checkHand(Card _hand[]);
void resetChanges(bool _array[]);
void handresults(Card *_hand, int &_money);

#endif
