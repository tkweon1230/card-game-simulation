//Tae Kweon
//player implementation file 
#include "player.h"
#include "deck.h"
#include "card.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor
Player::Player(string nme)
{
   name = nme;
   score = 0;
   for(int i = 0; i < Max_Cards; i++)
   {
       hasPlayed[i] = true;            
   }
}

//This function picks a card to play from the hand array by comparing 
//the point value of the cards. It plays the card with the greater point value.
//If the point values are the same, then it plays the card with the greater face value.
//If the face values are the same then it plays the card with the greater suit value.
//Once the card is played, the 'hasPlayed' of that card will be made 'true'.  
Card Player::playCard()
{   
    int count = 0;
    Card highestVal = hand[0];
    if(hasPlayed[0])       //if 0th element has been played then use the next element to compare
    {
        highestVal = hand[1];
    }
    

    for(int i = 0; i < Max_Cards; i++)
    {
        if(!hasPlayed[i] && highestVal < hand[i])  //if point value is less than
        {                                                     
            highestVal = hand[i];
            count = i;
        }
        else if(!hasPlayed[i] && highestVal == hand[i]) //if same
        {
            if(highestVal.getFaceValue() < hand[i].getFaceValue())
            {
                highestVal = hand[i];
                count = i;
            }

            else if(highestVal.getFaceValue() == hand[i].getFaceValue())   //if the face values are the same then
            {
                if(highestVal.getSuit() > hand[i].getSuit()) //greater than is used here because the suits are
                {                                            //ranked in decreasing order (0 is highest, 3 is lowest)
                    highestVal = hand[i];
                    count = i;
                }
                else if(highestVal.getSuit() ==  hand[i].getSuit())
                {
                    highestVal = hand[i];
                    count = i;
                }
                
            }
        }
       
    }                                       
    hasPlayed[count] = true;
    
    return highestVal;

}
//This function draws a card from the deck only if the card has been played in 
//that hand and if the deck is not empty.
void Player::drawCard(Deck& dk)        
{
    bool drawn = false;
    for(int i = 0; i < Max_Cards; i++)
    {
        if(!drawn)                      //if drawn is false
        {
            if(hasPlayed[i] && !dk.isEmpty())           //if hasPlayed is true and if deck is not empty
            {
                hand[i] = dk.dealCard();        //draw card
                hasPlayed[i] = false;               //have card to play again
                drawn = true;                       //drew card
            }
            else if(hasPlayed[i] && dk.isEmpty())    //if the deck is empty and have played a card already
            {
                hasPlayed[i] = true;                 //make hasplayed true so it cant play again
            }
        }

    }
    
}
//This function keeps track of the score the players
void Player::addScore(Card acard)
{
    score += acard.getPointValue();
}
//This function returns the score
int Player::getScore() const
{
    return score;
}
//This function returns the name
string Player::getName() const
{
    return name;
}
//This function checks if the player has played all
//the cards in the hand
bool Player::emptyHand() const
{
  if(hasPlayed[0] && hasPlayed[1] && hasPlayed[2])
  {
        return true;
  }
  else
  {
      return false;
  }
                    
}
//Overloaded ostream operator
ostream& operator<< (ostream& os, const Player& myPlayer)
{
    for(int i = 0; i < myPlayer.Max_Cards; i++)
    {
        if(!myPlayer.hasPlayed[i])
        {
            os << myPlayer.hand[i] << " ";
        }
        else if(myPlayer.hasPlayed[i])
        { 
            os << "____" << " ";
        }
    }
    return os;
}
