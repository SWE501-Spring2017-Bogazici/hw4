#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

// Arrays to I/O rank & suits, as we cannot get enum name from enum value
const string SUIT_BY_INDEX[] = {"Hearts", "Spades", "Diamonds", "Clubs"};
const string RANK_BY_INDEX[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
                                "Queen", "King"};

const int CARD_COUNT = 52;

enum Suit {
    Hearts,
    Spades,
    Diamonds,
    Clubs
};

enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};


class Card {
private:
    Suit suit;
    Rank rank;

public:
    Card(){}

    Card(Suit s, Rank r) {
        suit = s;
        rank = r;
    }

    Rank GetRank() {
        return rank;
    }

    Suit GetSuit() {
        return suit;
    }
};

ostream &operator<<(ostream &out, Card &c) {
    out << RANK_BY_INDEX[c.GetRank()] << " of " << SUIT_BY_INDEX[c.GetSuit()] << endl;
    return out;
}

class Deck {
private:
    Card *cards;

    void Shuffle() {
        // Do the Knuth shuffle
        for (int i = CARD_COUNT-1; i > 0; --i) {
            int r = rand() % CARD_COUNT;
            Card temp = cards[i];
            cards[i] = cards[r];
            cards[r] = temp;
        }
    }

public:
    Deck() {
        cards = new Card[CARD_COUNT];

        // Generate deck here
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < CARD_COUNT / 4; ++i) {
                Suit s = static_cast<Suit>(j); // Cast int value to enum
                Rank r = static_cast<Rank>(i);

                cards[13 * j + i] = Card(s, r);
            }
        }

        // Then shuffle them
        this->Shuffle();
    }


    Card *GetCards() {
        return cards;
    }

    Card *Deal() {
        int r = rand() % CARD_COUNT;
        return &(cards[r]);
    }

};

ostream &operator<<(ostream &out, Deck &d) {
    Card *cards = d.GetCards();
    for (int i = 0; i < CARD_COUNT; ++i) {
        cout << cards[i];
    }
    return out;
}

// Getting the index from the char representation of suits and ranks, for prettier input
int GetIndexFromChar(char sr)
{
    switch (sr)
    {
        case 'A':
        case 'H':
            return 0;
        case 'S':
            return 1;
        case 'D':
            return 2;
        case 'C':
            return 3;
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12;
        default:
            return sr - '0';
    }
}

int main() {
    srand(time(NULL));

    Deck deck;

    cout << "Pick a suit and rank! (Suit-> H S D C and rank-> A 2 3 4 5 6 7 8 9 10 J Q K, separated by a space)." << endl;
    char s;
    char r;

    cin >> s >> r;
    Rank rank = (Rank)(GetIndexFromChar(r));
    Suit suit = (Suit)(GetIndexFromChar(s));

    cout << "You picked: " << RANK_BY_INDEX[GetIndexFromChar(r)] << " of " << SUIT_BY_INDEX[GetIndexFromChar(s)] << endl;
    int inc = 0;

    // Main game loop
    while (inc < 100) {
        cout << "Your turn:\nDealing a random card from the deck.." << endl;

        Card *c = deck.Deal();
        cout << "The card is " << *c;
        if (c->GetRank() == rank && c->GetSuit() == suit) {
            cout << "You've won!" << endl;
            break;
        }

        cout << "Wrong guess!\nComputers turn:" << endl;

        cout << "Dealing a random card from the deck.." << endl;

        Card *cc = deck.Deal();
        cout << "The card is " << *cc;

        if (cc->GetRank() == rank && cc->GetSuit() == suit) {
            cout << "The computer has won!" << endl;
            break;
        } else {
            cout << "Both of you guessed incorrectly. Lets try again." << endl;
        }

        inc++;

        if(inc == 100)
        {
            cout << "Terminating the game as it took more than a 100 steps." << endl;
        }
    }

    cout << "This game took " << inc << " rounds to end." << endl;
    return 0;
}