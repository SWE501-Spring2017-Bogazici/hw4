/*
 * Card.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: ody
 */

#include "Card.h"
#include <iostream>
#include <time.h>
using namespace std;

const string Card::suits[]={"s","h","d","c"};

int Card::findSuit(string x) {
	for (int i=0;i<4;i++) {
		if (x == Card::suits[i]) {
			return i;
		}
	}
}

int Card::findRank(string r) {
	if (r=="j") return 10;
	if (r=="q") return 11;
	if (r=="k") return 12;
	return stoi(r)-1;
}

Card::Card() {
	// TODO Auto-generated constructor stub
	suit=0;
	rank=0;
}

Card::Card(Card& c) {
	suit=c.suit;
	rank=c.rank;
}

Card::Card(int s, int r) {
	suit=s;
	rank=r;
}

Card::Card(string s, string r) {
	int si=findSuit(s);
	int ri=findRank(r);
	suit=si;
	rank=ri;
}

void Card::operator =(Card& c) {
	suit=c.suit;
	rank=c.rank;
}

Card* Card::createRandomCard() {
	Card* c=new Card();
	c->setSuit((rand() % 4));
	c->setRank((rand() % 13));
	return c;
}

bool Card::operator ==(const Card& c) const {
	return (suit==c.suit && rank==c.rank);
}

int Card::getRank() const {
	return rank;
}

void Card::setRank(int rank) {
	this->rank = rank;
}

int Card::getSuit() const {
	return suit;
}

void Card::setSuit(int suit) {
	this->suit = suit;
}

ostream& operator<<(ostream& out, Card& c) {
	int suit= c.getSuit();
	int rank= c.getRank();

	string rankstr;
	if (rank==10) {
		rankstr="j";
	} else if (rank==11) {
		rankstr="q";
	} else if (rank==12) {
		rankstr="k";
	} else {
		rankstr= to_string(rank+1);
	}


    cout << c.suits[suit] << rankstr;
    return out;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

