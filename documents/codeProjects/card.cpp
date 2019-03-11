//Tae Kweon
//CSCI 3110-001
//Project #4
//Due: 02/28/19
//card implementation file for project #4

#include "card.h"
#include <iostream>
#include <string>

//default constructor
Card::Card()
{
    cardFace = 0;
    pointValue = 0;

}

//constructor that takes a card's face value(an int) and
//its suit
Card::Card(int face, suit st) //is face going to be in face value or regular card value
{
    cardFace = face;
    cardSuit = st;

    if(face == 0)
    {
        pointValue = 15;
    }
    else
    {
        if(face == 10 || face == 11 || face == 12)
        {
            pointValue = 10;
        }
        else
        {
            pointValue = face + 1;
        }
    }
    
}

//overloaded << operator to display card
ostream& operator<< (ostream& os, const Card& cd)
{

    switch(cd.cardFace)
    {
        case 0: os << "A";
                break;
        case 1: os << "2"; //will it ever give me a 1?
                break;
        case 2: os << "3";
                break;
        case 3: os << "4";
                break;
        case 4: os << "5";
                break;
        case 5: os << "6";
                break;
        case 6: os << "7";
                break;
        case 7: os << "8";
                break;
        case 8: os << "9";
                break;
        case 9: os << "10";
                break;
        case 10: os << "J";
                break;
        case 11: os << "Q";
                break;
        case 12: os << "K";
                break;
    }
    switch(cd.cardSuit)
    {
        case 0: os << "C";
                break;
        case 1: os << "H";
                break;
        case 2: os << "S";
                break;
        case 3: os << "D";
                break;
    }
    os << "[" << cd.pointValue << "]";

    return os;

}

//overloaded < operator to compare and return true if
//*this has a lesser point value than cd, false otherwise
bool Card::operator< (const Card& cd) const
{
    if(pointValue < cd.pointValue)
    {
      return true;
    }
    else
    {
        return false;
    }

}

//overloaded > operator to compare and return true if
//*this has a larger point value than cd, false otherwise
bool Card::operator> (const Card& cd) const
{
    if(pointValue > cd.pointValue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//overloaded == operator to compare and return true if
//*this has the same point value as cd, false otherwise
bool Card::operator== (const Card& cd) const
{
    if(pointValue == cd.pointValue)
    {
        return true;
    }
    else
    {
        return false;
    }

}

//return the point value of the card: Ace: 15, Faces: 10,
//Number: the number
int Card::getPointValue() const
{
    return pointValue;
}

//return the face value of the card: Ace: 0, 2: 1,
//3:2, ..... Queen:11, King:12
int Card::getFaceValue() const
{
    return cardFace;
}

//return the card's suit: clubs, hearts, spades, diamonds
suit Card::getSuit() const
{
    return cardSuit;
}
