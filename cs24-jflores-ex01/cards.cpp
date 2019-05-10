//cards.cpp
//Implementation of the classes defined in cards.h

#include <iostream>
#include <string>
#include "cards.h"
using namespace std;

//CardList: CONSTRUCTOR
CardList::CardList() {
    head = nullptr;
}

//CardList: DESTRUCTOR
CardList::~CardList() {
    Card *temp = head;
    while(head) {
	    temp = head->next;
	    delete head;
	    head = temp;
    }
}

//CardList: COPY CONSTRUCTOR 
/*CardList::CardList(const CardList& source) {
    head = 0;
    if(source.head == nullptr)
	head = nullptr;
    else {
	Card* current = source.head;
	Card* temp = new Card;
	head = temp;
	while(current->next) {
		temp->suite = current->suite;
		temp->value = current->value;
		temp->next = new Card;
		temp = temp->next;
		current = current->next;
	}
    }
} */

//CardList: appends Card to end of CardList.
void CardList::appendCard(char CardSuite,char CardValue) {
    if(head == nullptr) {
	head = new Card;
	head->suite = CardSuite;
	head->value = CardValue;
	head->next = 0;
    }
    else {
	Card *temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = new Card;
	temp->next->suite = CardSuite;
	temp->next->value = CardValue;
	temp->next->next = 0;
    }
}

//CardList: prints out CardList.
void CardList::printList() const {
    Card* temp = head;
    while(temp) {
	cout << temp->suite << " " << temp->value << endl;
	temp = temp->next;
    }
    delete temp;
}

//CardList: Assignment Operator Overload
CardList& CardList::operator=(const CardList& source) {
    Card *temp = head;
    while(head) {
	    temp = head->next;
	    delete head;
	    head = temp;
    }
    head = nullptr;
    Card* current = source.head;
    while(current) {
	this->appendCard(current->suite,current->value);
	current = current->next;
    }
    
    return *this;
}

//Player: CONSTRUCTOR
Player::Player() {
    Name = "";
}

//Player: Returns name of Player
string Player::getName()const {
    return Name;
}

CardList Player::getHand()const {
    return Hand;
}

//Player: ostream << overload
ostream& operator<<(ostream&os,const Player& p1) {
    os << p1.getName();
    return os;
}	

void Player::printHand() const {
    cout << this->getName()  << "'s cards:" << endl;
    this->getHand().printList();
}

void Player::setHand(const CardList& hand) {
	Hand = hand;
}

void Player::setName(string name) {
	Name = name;
}
