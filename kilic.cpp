//============================================================================
// Name        : kilic.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <time.h>
using namespace std;

string* ranks;
string suits[4]={"s","h","d","c"};
int counter=0;

class Card {
	int suit;
	int rank;

public:
	Card() {
		suit=0;
		rank=0;
	}

	Card(Card& c) {
		suit=c.suit;
		rank=c.rank;
	}

	static Card* createRandomCard() {
		Card* c=new Card();
		c->setSuit((rand() % 4));
		c->setRank((rand() % 13));
		return c;
	}

	Card(int s,int r) {
		suit=s;
		rank=r;
	}

	int getSuit() {
		return suit;
	}

	void setSuit(int s) {
		suit=s;
	}

	int getRank() {
		return rank;
	}

	void setRank(int r) {
		rank=r;
	}

	void operator=(Card& c) {
		suit=c.suit;
		rank=c.rank;
	}

	bool operator == (const Card& c) const {
	   return (suit==c.suit && rank==c.rank);
	}
};


ostream& operator<<(ostream& out, Card& c) {
	int suit= c.getSuit();
	int rank= c.getRank();

    cout << suits[suit] << ranks[rank];
    return out;
}

Card* playersCard;
Card* computersCard;

class Deck {
	Card* cards;

public:
	Deck() {
		cards= new Card[52];
		for (int i=0;i<52;i++) {
			cards[i].setSuit(i/13);
			cards[i].setRank(i%13);
		}
	}

	void shuffle() {
		Card temp;
		for (int i=51;i>0;i--) {
			int r=(rand() % i);
			temp= cards[r];
			cards[r]= cards[i];
			cards[i]= temp;
		}
	}
	void deal() {
		string input;
		while (true) {
			if (counter==52) {
				cout << endl << "No cards left" << endl;
				break;
			}
			Card currentCard = cards[counter];

			cout << currentCard << ",";
			if (currentCard==*playersCard) {
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
				if (currentCard==*computersCard) {
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

	void printDeck() {
		for (int i=0;i<52;i++) {
			cout << cards[i] << ",";
		}
	}
};

int findSuit(string s) {
	for (int i=0;i<4;i++) {
		if (suits[i]==s) {
			return i;
		}
	}
}

int findRank(string r) {
	for (int i=0;i<13;i++) {
		if (ranks[i]==r) {
			return i;
		}
	}
}

void initializeRanks() {
	ranks = new string[13];
	for (int i=0;i<10;i++) {
		ranks[i]=to_string(i+1);
	}
	ranks[10]="j";
	ranks[11]="q";
	ranks[12]="k";
}



Deck* initializeDeck() {
	Deck* d = new Deck();
	d->shuffle();
//	d->print();
	return d;
}

int main() {
	srand (time(NULL));

	initializeRanks();
	Deck* deck=initializeDeck();

	cout << "Enter your card (c:clubs, s:spades, h:hearts, d:diamonds, j:jack, q:queen, k:king)" << endl;
	cout << "with space between suit and rank" << endl;
	cout << "eg. s 4 for spades 4 or h j for jack of hearts" << endl;

	string suit, rank;
	cin >> suit >> rank;
	int s=findSuit(suit);
	int r=findRank(rank);
	playersCard = new Card(s, r);

	cout << endl << "You have chosen " << *playersCard << endl;

	computersCard=Card::createRandomCard();
	cout << "I choose " << *computersCard << ", you pick first " << endl << endl;

	deck->deal();

	return 0;
}



