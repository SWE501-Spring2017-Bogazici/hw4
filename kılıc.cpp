#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <iomanip>
using namespace std;

enum suit{ Spade, Club, Heart, Diamond };
const string SUIT_NAMES[4] = { "Spade", "Club", "Heart", "Diamond" };
ostream& operator<<(ostream& out, const suit& s){
    out << SUIT_NAMES[s];
    return out;
}

class Card{
    //data
    public:
        int r; suit s;
    
    //constructors
    public:
        Card(int input){
            if (input > 52 || input < 1) { r=1; s=Spade; }
            else {s = static_cast<suit>((input-1)/13);
            r = ((input-1) % 13) + 1;}
        };
        Card() { r=1; s=Spade; };
        Card(suit in_s, int in_r){ r=in_r; s=in_s; };
        
    //checking if cards match
    public:
        bool isEqual(Card &in_c){ return (r == in_c.r) && (s == in_c.s); }
};
ostream& operator<<(ostream& out, Card& sdm){
    switch(sdm.r){
        case 1: out << "Ace of " << sdm.s <<"s"; break;
        case 11: out << "Jack of " << sdm.s <<"s"; break;
        case 12: out << "Quenn of " << sdm.s <<"s"; break;
        case 13: out << "King of " << sdm.s <<"s"; break;
        default: out << sdm.r << " of " << sdm.s <<"s";
    }
    
    return out;
}

class Deck{
    array<Card, 52> b;
    array<Card*, 52> a;
    
    public:
        Deck(){
            cout << "Deck initialized." << endl; //test line
            for(int i=0; i<52; i++){
                b[i] = Card(i+1);
                a[i] = &b[i];
            }
            cout << "Deck filled." << endl; //test line
        };
        
        void shuffle(){
            Card* temp; int i;
            srand (time(NULL));
            
            for(int k=52; k>1; k--){
                i = rand() % k;
                temp = a[i];
                a[i] = a[k-1];
                a[k-1] = temp;
            }
	    cout << "Deck shuffled." << endl; //test line
        };
        
        bool deal(Card &wanted){
            int i=0;
            bool counter=false, test;
            cout << left << setw(24) << "Player" << setw(24) << "Computer" 
                << "\n------------------------------------------------\n";
            do{
                counter = !counter;
                test = (*a[i]).isEqual(wanted);
                cout << *a[i] << "\t\t";
                if(!counter) cout << "\n";
                i++;
            } while (!test);
            
            return counter;
        };
};

int main()
{
    cout << "Initializing deck." << endl; //test line
    Deck d1;
    cout << "Enter a number, from 1 to 52. Suit ranges are as follows:\n1-13: Spades; 14-26: Clubs; 27-39: Hearts; 40-52: Diamonds; Default: Ace of Spades;" << endl;
    int t; cin >> t;
    Card wanted(t);
    cout << "Wanted card (" << wanted << ") initialized." << endl; //test line
    
    d1.shuffle();
    
    bool result = d1.deal(wanted);    
    
    if(result) cout << endl << "Player wins!" << endl;
    else cout << "Computer wins!" << endl;
    
    return 0;
}
