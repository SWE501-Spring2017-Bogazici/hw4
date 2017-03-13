//============================================================================
// Name        : card_game.cpp

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
using namespace std;

// suits
string Suit[4] = {"H", "S", "C", "D"};

// ranks
string Rank[13] = {"A", "2", "3", "4", "5", "6", "7", "8",
			"9", "10", "J", "Q", "K"};

class Card
{
public:

	// constructor
	Card() {}

	Card (string s, string r)
	{
		suit = s;
		rank = r;
	}

	// destructor
	~Card()
	{

	}

	// set suit
	void setSuit(string s)
	{
		suit = s;
	}

	// get suit
	string getSuit()
	{
		return suit;
	}

	// set rank
	void setRank(string r)
	{
		rank = r;
	}

	// get rank
	string getRank()
	{
		return rank;
	}

	// overload operator (==)

private:
	// suit
	string suit;

	// rank
	string rank;

};

// overload operator <<
ostream & operator<<(ostream & out, Card & card)
{
	out << card.getRank() << " of " << card.getSuit();
	return out;
}

// class Deck to shuffle and deal the cards
class Deck
{
public:

	// constructor
	Deck()
	{
		// initialize the deck
		int idx=0; // index of the card (0-51)
		for (int i = 0; i < 4; i++)
		{
			for ( int j = 0; j < 13; j++)
			{
				deck[idx].setRank(Rank[j]);
				deck[idx].setSuit(Suit[i]);

				// increment the index
				idx++;
			}
		}

	}

	// shuffle
	void shuffle()
	{
		Card temp; // to hold the temporary card

		// shuffle the card
		for (int i = 0; i < 52; i++)
		{
			// choose cards randomly
			int val = rand() % 52;
			temp = deck[i];
			deck[i] = deck[val];
			deck[val] = temp;
		}

	}

	// deal
	Card deal()
	{
		int rcard = rand() % 52; // choose random card index
		return deck[rcard];
	}

	// destructor
	~Deck()
	{

	}

private:

	// deck of cards
	Card deck[52];

};


int main() {

	// initialize random
	srand((unsigned)time(NULL));

	// initialize the deck
	Deck deck;
	deck.shuffle();

	// enter your card
	cout << "please enter suit: ";
	cout << "H - Hearts, S - Spades, C - Clubs, D - Diamonds" << endl;

	string suit;
	cin >> suit;

	cout << "\nplease enter rank: ";
	cout << "A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K";

	string rank;
	cin >> rank;

	// player card
	cout << " Chosen card is: " << rank << " of " << suit << endl;

	// start the game
	for(int i = 0; i < 10; i++)
	{
		cout << "\nPlayer's turn: " << endl;

		Card player = deck.deal();
		cout << "Dealt card is: " << player << endl;
		if(player.getRank() == rank && player.getSuit() == suit)
		{
			cout << "Player won!" << endl;
			break;
		}

		cout << "Player guessed wrong!"<< endl << "Computer's turn" << endl;

		Card computer = deck.deal();
		cout << "Dealt card is: " << computer << endl;
		if(computer.getRank() == rank && computer.getSuit() == suit)
		{
			cout << "Computer Won!" << endl;
			break;
		}
		cout << "Computer guessed wrong!" << endl;
	}
	// game over
	cout << "Game Over!" << endl;
}
