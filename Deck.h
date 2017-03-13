/*
 * Deck.h
 *
 *  Created on: Mar 10, 2017
 *      Author: ody
 */

#ifndef DECK_H_
#define DECK_H_

#include "Card.h"

class Deck {

private:
	Card* cards;
	int idxTopCard=0;

public:
	Deck();
	void shuffle();
	Card deal();
	void print();
	static Deck* createShuffledDeck();
	virtual ~Deck();
};

#endif /* DECK_H_ */
