//cards.cpp
//Implementation of the classes defined in cards.h

#include <iostream>
#include "cards.h"
#include <string>
#include <vector>
using namespace std;

//Card Class Implementation
Card::Card(){
    next = nullptr;
}

Card::Card(char ss, char vv):suit(ss),value(vv),next(nullptr){}

char Card::getSuit() const{
    return suit;
}

char Card::getValue() const{
    return value;
}

void Card::setSuit(char ss){
    suit = ss;
}

void Card::setValue(char vv){
    value = vv;
}

bool Card::operator==(const Card& cc){
    if(suit == cc.getSuit() && value == cc.getValue())
        return true;

        return false;
}

void Card:: operator=(const Card& cc){
    suit = cc.getSuit();
    value = cc.getValue();
}

std::ostream& operator<< (std::ostream& os, const Card& cc) {
      os << cc.suit << " " << cc.value;
      return os;
}


//CardList Class Implementation
CardList::CardList(){
    first = nullptr;
}

CardList::~CardList(){
    Card *p = first;

    while(p){
        p = first->next;
        delete first;
        first = p;
    }
}

Card* CardList::getFirst() const{
    return first;
}

void CardList::insertCard(const Card& cc){
    if(!first){ // empty list

        first = new Card(cc.getSuit(), cc.getValue());
        
    }

    else {

        Card *n = first;

        while (n->next) // not last node yet
            n = n->next;

        n->next = new Card(cc.getSuit(),cc.getValue());
    }
}

void CardList::removeCard(const Card& cc){
     Card* p = first;
     Card* tmp;

    while(p){
        if(*p == cc){
            tmp = p->next;
            delete p;
            p = tmp;
        }
        else    
            p = p->next;
    }
}

bool CardList::hasMatch(CardList* otherHand) const{
    Card* p = first, *n = otherHand->getFirst();

    while(p){
        while(n){
        if(*p == *n)
            return true;
        else
            n = n->next;
        }
        p = p->next;
        n = otherHand->getFirst();
    }

    return false;
}

Card CardList::getMatch(CardList* otherHand) const{
    Card* p = first, *n = otherHand->getFirst();
    if(this->hasMatch(otherHand)){
        while(p){
            while(n){
                if(*p == *n)
                    return *p;
                else
                    n = n->next;
            }
           p = p->next;
           n = otherHand->getFirst();
        }
    }
    
    Card z('z', 'z');
    return z;
}

void CardList::printCards() const{
    Card* p = first;
    
    while(p){
        cout<< p << endl;
        p = p->next;
    }
}

vector<char> CardList::vectorize(){
    vector<char> v;		
    Card* p = first;
			while(p){
				v.push_back(p->suit);
                v.push_back(p->value);
				p = p->next;
			}
    return v;
}

bool CardList::operator==(const CardList& cc){
    Card *p = first, *n = cc.getFirst();
    while(p && n){
        if(*p == *n){
            p = p->next;
            n = n->next;
        }
        else
            return false;
    }
    if(!p && !n) //both are null, meaning same length
        return true;
    
    return false;
}   



//Player Class Implementation
Player::Player(string nn, CardList* hh):name(nn),hand(hh){}

Player::~Player(){
    delete hand;
}

string Player::getName() const{
    return name;
}

CardList* Player::getHand() const{
    return hand;
}

bool Player::hasMatch(const Player& other) const{
    return hand->hasMatch(other.getHand());
}

Card Player::getMatch(const Player& other) const{
    return hand->getMatch(other.getHand());
}

void Player::removeCard(const Card & cc){
    hand->removeCard(cc);
}

std::ostream& operator<< (std::ostream& os, const Player& pp) {
      os << pp.name;
      return os;
}

void Player::insertCard(const Card& cc){
    if(!hand){
        hand = new CardList;
    }
    hand->insertCard(cc);
}

void Player::printHand() const{
   hand->printCards();
}
