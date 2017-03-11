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

public:
	Deck();
	void shuffle();
	void deal(Card& playersCard, Card& computersCard);
	void print();
	static Deck* createShuffledDeck();
	virtual ~Deck();
};

#endif /* DECK_H_ */
