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

void Deck::deal(Card& playersCard, Card& computersCard) {
	string input;
	int counter=0;
	while (true) {
		if (counter==52) {
			cout << endl << "No cards left" << endl;
			break;
		}
		Card currentCard = cards[counter];

		cout << currentCard << ",";
		if (currentCard==playersCard) {
			cout << " You win !!!" << endl;
			break;
		} else {
			counter=counter+1;
			if (counter==52) {
				cout << endl << "No cards left" << endl;
				break;
			}
			currentCard = cards[counter];
			cout << currentCard << ",";
			if (currentCard==computersCard) {
				cout << " I win !!!" << endl;
				break;
			} else {
				cout << endl;
				counter=counter+1;
				continue;
			}
		}
	}
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

