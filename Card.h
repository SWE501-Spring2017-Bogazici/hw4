/*
 * Card.h
 *
 *  Created on: Mar 10, 2017
 *      Author: ody
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

class Card {

private:
	int suit;
	int rank;

public:
	static const string suits[];
	Card();
	Card(Card& c);
	Card(int s,int r);
	Card(string s, string r);
	int getRank() const;
	void setRank(int rank);
	int getSuit() const;
	void setSuit(int suit);
	void operator=(Card& c);
	static Card* createRandomCard();
	static int findSuit(string s);
	static int findRank(string s);
	bool operator == (const Card& c) const;

	virtual ~Card();

};

ostream& operator<<(ostream& out, Card& c);

#endif /* CARD_H_ */
