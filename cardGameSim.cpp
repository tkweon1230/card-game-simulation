//Tae Kweon
//This program simulates a card game between two players. A standard 
//deck is used and the cards are shuffled. After shuffling, each player draws 
//three cards from the top of the deck. Remaining cards are placed
//in a pile face-down between the two players. Players then select
//a card from the three in their hand. The player playing the 
//card with the highest point value wins, and collects both cards
//and adds them to their score. If the cards have the same point value,
//the hand is a draw and no points are given to either player. Each
//player draws the top card from the deck after a card is played.
//The players alternate drawing cards. They have three cards in their
//hands at all times. Play continues until all cards have been played.
//The winner is the player with the most points at the end of the game.
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <fstream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int randSeed;
    int count = 0;
    ifstream myin;

    Card p1Card;
    Card p2Card;

    string p1name, p2name;
    Deck myDeck;

    myin.open("cardgame.txt");

    myin >> p1name;
    myin >> p2name;
    myin >> randSeed;
    
    Player p1(p1name);
    Player p2(p2name);

    srand(randSeed);       

    cout << myDeck << endl;    
    myDeck.Shuffle();
    cout << myDeck << endl;

    for(int i = 0; i < 3; i++)          //drawing three cards to start game
    {
        p1.drawCard(myDeck);
        p2.drawCard(myDeck);
    }
    while(!p1.emptyHand() && !p1.emptyHand())
    {
        cout << count+1 << ")" << p1.getName() << " " << p1 << "(" << p1.getScore() << ") ";
        cout << "- " << p2.getName() << " " << p2 << "(" << p2.getScore() << ")";

        cout << endl;

        p1Card = p1.playCard();
        p2Card = p2.playCard();
        if(p1Card.getPointValue() > p2Card.getPointValue())
        {
            p1.addScore(p1Card);
            p1.addScore(p2Card);
            cout << count+1 << ")" << p1.getName() << "* " << p1 << "(" << p1.getScore() << ") ";
            cout << "- " << p2.getName() << " " << p2 << "(" << p2.getScore() << ")";
        }
        else if(p1Card.getPointValue() < p2Card.getPointValue())
        {
            p2.addScore(p1Card);
            p2.addScore(p2Card);
            cout << count+1 << ")" << p1.getName() << " " << p1 << "(" << p1.getScore() << ") ";
            cout << "- " << p2.getName() << "* " << p2 << "(" << p2.getScore() << ")";
        }
        else if(p1Card.getPointValue() == p2Card.getPointValue())
        {
            cout << count+1 << ")" << p1.getName() << " " << p1 << "(" << p1.getScore() << ") ";
            cout << "- " << p2.getName() << " " << p2 << "(" << p2.getScore() << ")";
        }

        cout << endl;
        cout << endl;
        p1.drawCard(myDeck);
        p2.drawCard(myDeck);
        count++;
    }

    if(p1.getScore() > p2.getScore())
    {
        cout << "Winner " << p1.getName() << " " << p1.getScore();
    }
    else if(p1.getScore() < p2.getScore())
    {
        cout << "Winner " << p2.getName() << " " << p2.getScore();
    }
    else if(p1.getScore() == p2.getScore())
    {
        cout << "Tie " << p1.getScore();
    }
    cout << endl;
    

    return 0;
}

