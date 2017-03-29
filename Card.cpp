//
//  Card.cpp
//  TheGame
//
//  Created by Firat Atalay on 27/03/2017.
//  Copyright © 2017 Firat Atalay. All rights reserved.
//

#include "Card.hpp"

void Card::getCard(){
    random_device rd;
    default_random_engine rng(rd());
    
    uniform_int_distribution<> dist1(0,3);
    suitLiteral = dist1(rng);
    suitUniChar = getSuitUniChar(suitLiteral);
    
    uniform_int_distribution<> dist2(0,12);
    rankLiteral = dist2(rng);
    
    suitOut = suit[suitLiteral];
    rankOut = rank[rankLiteral];
};

void Card::setCard(int s, int r){
    suitLiteral = s%4;
    rankLiteral = r%13;
    
    suitOut = suit[suitLiteral];
    rankOut = rank[rankLiteral];
};

const char * Card::getSuitUniChar(int s){
    switch (s) {
        case 0:
            return u8"\u2663"; // club - ♣
            break;
        case 1:
            return u8"\u2666"; // diamond - ♦
            break;
        case 2:
            return u8"\u2665"; // heart - ♥
            break;
        case 3:
            return u8"\u2660"; // spade - ♠
            break;
        default:
            return 0;
    }
};

bool Card::operator==(Card &comparison){
    if (suitOut == comparison.suitOut && rankOut == comparison.rankOut){
        return true;
    } else {
        return false;
    }
}

Card &Card::operator=(Card &other){
    suitLiteral = other.suitLiteral;
    rankLiteral = other.rankLiteral;
    
    suitOut = suit[suitLiteral];
    rankOut = rank[rankLiteral];

    return *this;
}

