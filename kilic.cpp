//============================================================================
// Name        : kilic.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main() {
	srand (time(NULL));

	Deck* deck=Deck::createShuffledDeck();

	cout << "Enter your card (c:clubs, s:spades, h:hearts, d:diamonds, j:jack, q:queen, k:king)" << endl;
	cout << "with space between suit and rank" << endl;
	cout << "eg. s 4 for spades 4 or h j for jack of hearts" << endl;

	string suit, rank;
	cin >> suit >> rank;

	Card* playersCard = new Card(suit, rank);
	cout << endl << "You have chosen " << *playersCard << endl;

	Card* computersCard=Card::createRandomCard();
	cout << "I choose " << *computersCard << ", you pick first " << endl << endl;

	deck->deal(*playersCard, *computersCard);

	return 0;
}



