#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

// Card class that holds suit and rank of card
class Card {
    string suit;
    string rank;

public:
    Card() {

    }

    Card(string s, string r) {
        suit = s;
        rank = r;
    }

    ~Card() {

    }

    void setSuit(string s) {
        suit = s;
    }

    string getSuit() {
        return suit;
    }

    void setRank(string r) {
        rank = r;
    }

    string getRank() {
        return rank;
    }

    // == operator overloading for Card
    bool operator==(Card &card) {
        if (getSuit().compare(card.getSuit()) == 0
                && getRank().compare(card.getRank()) == 0) {
            return true;
        }
        return false;
    }

};

// left shift operator overloading for Card
ostream &operator<<(ostream &out, Card &card) {
    out << "(" << card.getSuit() << ", " << card.getRank() << ")";
    return out;
}

istream &operator>>(istream &in, Card &card) {
    string suit, rank;
    int ranksSize = sizeof(ranks) / sizeof(ranks[0]);
    int suitsSize = sizeof(suits) / sizeof(suits[0]);
    bool isSuitValid = false;
    bool isRankValid = false;

    cout << "Enter the suit of game card (Spades, Hearts, Diamonds, Clubs): ";
    getline(cin, suit);
    for (int i = 0; i < suitsSize; i++) {
        if (suit.compare(suits[i]) == 0) {
            isSuitValid = true;
        }
    }
    if (!isSuitValid) {
        // set default suit for invalid inputs..
        suit = "Spades";
    }
    card.setSuit(suit);

    cout << "Enter the rank of game card (A, 1, 2, 3, 4, 5, .., 10, J, Q, K): ";
    getline(cin, rank);
    for (int i = 0; i < ranksSize; i++) {
        if (rank.compare(ranks[i]) == 0) {
            isRankValid = true;
        }
    }
    if (!isRankValid) {
        // set default rank for invalid inputs..
        rank = "A";
    }
    card.setRank(rank);
    return in;
}

// Deck class to hold cards and indexes to deal cards randomly
class Deck {

private:
    Card cards[52];
    int indexes[52];

    void swap(Card &c1, Card &c2) {
        Card temp = c1;
        c1 = c2;
        c2 = temp;
    }

public:
    Deck() {
        int count = 0;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                cards[count].setRank(ranks[i]);
                cards[count].setSuit(suits[j]);
                count++;
            }
        }
    }

    void shuffle() {
        // Knut shuffle
        for (int i = 0; i < 52; i++) {
            int rCard = rand() % 52;
            swap(cards[i], cards[rCard]);
        }
    }

    Card deal() {
        int random = rand() % 52;
        while(indexes[random] != 0) {
            random = rand() % 52;
        }
        indexes[random] = 1;
        return getCard(random);
    }

    Card getCard(int index) {
        if (index < 1 || index > 52) {
            // return default card for invalid inputs
            return cards[0];
        }
        return cards[index - 1];
    }

    int size() {
        return sizeof(cards) / sizeof(cards[0]);
    }

};

// left shift operator overloading for Deck
ostream &operator<<(ostream &out, Deck &deck) {
    for (int i = 0; i < 52; i++) {
        out << deck.getCard(i).getSuit() << "," << deck.getCard(i).getRank();
    }
    return out;
}

Card chooseGameCard() {
    srand(time(NULL));

    Card gameCard;
    cin >> gameCard;
    cout << "Game card is: " << gameCard << endl << endl;
    return gameCard;
}

int main() {
    int turn = 0;
    string player;

    Card gameCard = chooseGameCard();

    Deck deck;
    deck.shuffle();

    while (true) {
        if (turn % 2 == 0) {
            player = "user";
        } else {
            player = "computer";
        }
        Card dealedCard = deck.deal();
        cout << player << " gets: " << dealedCard << endl;
        if (dealedCard == gameCard) {
            cout << endl << player << " wins the game! " << endl;
            break;
        }
        turn++;
    }

    return 0;
}
