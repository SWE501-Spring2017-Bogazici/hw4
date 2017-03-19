// Tugcan Olgun

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
string suits[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};

class Card {
    int suit;
    int rank;
public:
    Card() {}
    Card(int r, int s) {
        suit = s;
        rank = r;
    }
    string getRank() {
        return ranks[rank];
    }
    string getSuit() {
        return suits[suit];
    }
    int getRankNum() {
        return rank;
    }
    int getSuitNum() {
        return suit;
    }
    void setRank(int r) {
        rank = r;
    }
    void setSuit(int s) {
        suit = s;
    }
};

class Deck {
    Card card[52];
public:
    Deck() {
        int count = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                card[count].setSuit(i);
                card[count].setRank(j);
                count++;
            }
        }
    }
    
    void Shuffle() {
        for (int i = 0; i < 52; ++i) {
            int randomNumber = rand() % 52;
            Card temp;
            temp = card[i];
            card[i] = card[randomNumber];
            card[randomNumber] = temp;
        }
    }

    Card getCard(int i) {
        return card[i];
    }
};

ostream &operator<<(ostream &out, Card &card) {
    out << card.getRank() << " of " << card.getSuit();
    return out;
}

int main() {
    srand(time(NULL));
    Deck deck;
    deck.Shuffle();

    cout << "Enter a rank" << endl;
    int usrRank;
    cin >> usrRank;
    cout << "Enter a suit" << endl;
    int usrSuit;
    cin >> usrSuit;
    int comSuit = rand() % 4;
    int comRank = rand() % 13;
    cout << "Your card is " << deck.getCard(usrRank).getRank() << " of " << deck.getCard(usrSuit).getSuit() << endl;
    cout << "Computer card is " << deck.getCard(comRank).getRank() << " of " << deck.getCard(comSuit).getSuit() << endl;
    for (int i = 0; i < 52; (i+=2)) {
        cout << "You picked: " << deck.getCard(i).getRank() << " of " << deck.getCard(i).getSuit() << endl;
        if(usrRank == deck.getCard(i).getRankNum() && usrSuit == deck.getCard(i).getSuitNum()){
            cout << "YOU HAVE WON!";
            break;
        }
        cout << "Computer picked: " << deck.getCard(i+1).getRank() << " of " << deck.getCard(i+1).getSuit() << endl;
        if(comRank == deck.getCard(i+1).getRankNum() && comSuit == deck.getCard(i+1).getSuitNum()){
            cout << "COMPUTER HAS WON";
            break;
        }
    }

    return 0;
}