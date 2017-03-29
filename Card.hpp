//
//  Card.hpp
//  TheGame
//
//  Created by Firat Atalay on 27/03/2017.
//  Copyright © 2017 Firat Atalay. All rights reserved.
//

#include <iostream>
#include <random>
#include <string>
using namespace std;

#ifndef Card_h
#define Card_h

class Card {
private:
    const char * getSuitUniChar(int s);
    
public:
    int suitLiteral;
    int rankLiteral;
    
    const string suit[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    const string rank[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    string suitOut;
    string rankOut;
    
    const char * suitUniChar;
    
    void getCard();
    void setCard(int s, int r);
    bool operator==(Card &comparison);
    Card &operator=(Card &other);
};

#endif /* Card_h */
