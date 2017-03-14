/*
 * Deck.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: ody
 */

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <time.h>
using namespace std;

Deck::Deck() {
	// TODO Auto-generated constructor stub
	cards= new Card[52];
	for (int i=0;i<52;i++) {
		cards[i].setSuit(i/13);
		cards[i].setRank(i%13);
	}
}

void Deck::shuffle() {
	Card temp;
	for (int i=51;i>0;i--) {
		int r=(rand() % i);
		temp= cards[r];
		cards[r]= cards[i];
		cards[i]= temp;
	}
}

Card Deck::deal() {
	if (idxTopCard>=52) {
		throw domain_error("no cards to deal");
	}
	Card topCard= cards[idxTopCard++];
	return topCard;
}

Deck* Deck::createShuffledDeck() {
	Deck* d = new Deck();
	d->shuffle();
	return d;
}


void Deck::print() {
	for (int i=0;i<52;i++) {
		cout << cards[i] << ",";
	}
}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

