//
//  TheGame.cpp
//  TheGame
//
//  Created by Firat Atalay on 27/03/2017.
//  Copyright © 2017 Firat Atalay. All rights reserved.
//

#include "TheGame.hpp"

int main()
{
    while (true) {
        cout << "************************************************************************************************************************" << endl;
        int s;
        string pickSuit = "Pick a suit // [0]:Clubs, [1]:Diamonds, [2]:Hearts, [3]:Spades";
        cout << pickSuit << endl;
        cin >> s;
        s = s%4;
        
        int r;
        string pickRank = "Pick a rank // [0]:Ace, [1]:2, [2]:3, [3]:4, [4]:5, [5]:6, [6]:7, [7]:8, [8]:9, [9]:10 [10]:Jack, [11]:Queen, [12]:King";
        cout << pickRank << endl;
        cin >> r;
        r = r%13;
        
        Card player;
        player.setCard(s, r);
        
        cout << "You picked " << player.rankOut << " of " << player.suitOut << endl;
        
        Deck d;
        d.shuffle();
        
        Card game;
        d.deal();
        game = d.card;
        
        Card computer;
        d.deal();
        computer = d.card;
        
        cout << "Game got " << game.rankOut << " of " << game.suitOut << endl;
        
        cout << "Computer got " << computer.rankOut << " of " << computer.suitOut << endl;
        
        
        if (player == game){
            cout << player.suitUniChar << player.suitUniChar << player.suitUniChar << " You won! " << player.suitUniChar << player.suitUniChar << player.suitUniChar << endl;
            break;
        }
        
        if (computer == game){
            cout << computer.suitUniChar << computer.suitUniChar << computer.suitUniChar << " Computer won! " << computer.suitUniChar << computer.suitUniChar << computer.suitUniChar << endl;
            break;
        }
    }
    return 0;
}
