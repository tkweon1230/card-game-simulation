//Tae Kweon
//deck implementation file 
#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Default constructor
Deck::Deck()
{
    topCard = 52;
    int count = 0;
    for(int i = 0; i < 13; i++)
    {
        Card myCard(i, clubs);
        theDeck[count] = myCard;
        count++;
    }
    
    for(int i = 0; i < 13; i++)
    {
        Card myCard(i, hearts);
        theDeck[count] = myCard;
        count++;
    }

    for(int i = 0; i < 13; i++)
    {
        Card myCard(i, spades);
        theDeck[count] = myCard;
        count++;
    }

    for(int i = 0; i < 13; i++)
    {
        Card myCard(i, diamonds);
        theDeck[count] = myCard;
        count++;
    }

    
}
//This function returns the top card of the deck
Card Deck::dealCard()
{
    topCard--;
    return theDeck[topCard];
}
//This function shuffles the deck
void Deck::Shuffle()
{
    random_shuffle(begin(theDeck), end(theDeck));

}
//This function returns true if the deck is empty
bool Deck::isEmpty()
{
    if(topCard == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//Overloaded ostream operator
ostream& operator<< (ostream& os, const Deck& myDeck)
{
    for(int i = 51; i >= 39; i--)
    {
        os << myDeck.theDeck[i] << " ";
    }

    os << endl;
        
    for(int i = 38; i >= 26; i--)
    {
        os << myDeck.theDeck[i] << " ";
    }

    os << endl;

    for(int i = 25; i >= 13; i--)
    {
        os << myDeck.theDeck[i] << " ";
    }

    os << endl;

    for(int i = 12; i >= 0; i--)
    {
        os << myDeck.theDeck[i] << " ";
    }

    os << endl;

    return os;
}
