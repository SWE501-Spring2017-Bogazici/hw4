//
//  Deck.cpp
//  TheGame
//
//  Created by Firat Atalay on 27/03/2017.
//  Copyright © 2017 Firat Atalay. All rights reserved.
//

#include "Deck.hpp"

void Deck::generate(){
    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            deck[(s*13)+r].setCard(s, r);
        }
    }
};

void Deck::shuffle(){
    generate();
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 51; i++) {
        int j = rand() % 52;
        temp.setCard(deck[j].suitLiteral, deck[j].rankLiteral);
        deck[j].setCard(deck[i].suitLiteral, deck[i].rankLiteral);
        deck[i].setCard(temp.suitLiteral, temp.rankLiteral);
    }
};

Card Deck::deal(){
    shuffle();
    dealCounter < 52 ? dealCounter++ : dealCounter = 0;
    temp.setCard(deck[dealCounter].suitLiteral, deck[dealCounter].rankLiteral);
    card = temp;
    return card;
};

