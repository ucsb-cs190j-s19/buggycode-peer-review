//cards.cpp
//Authors: Your Partner's Name and Your Name
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
#include <string>

using namespace std;
//class: card functions
//
//
card::card(char s, char n){
	this->suit = s;
	this->num = n;
}

bool card::operator==(const card& two){
	if(this->suit == two.suit && this->num == two.num){
		return true;
	}
	else {
		return false;
	}
}

char card::getSuit() const{
	return suit;
}

char card::getNum() const{
	return num;
}
ostream& operator<<(ostream& out, const card& source){
	out << source.suit << " " << source.num << " ";
	return out;
}


//class: cardlist functions
//
//
cardList::cardList(){
	// Constructor
	head = nullptr;
	tail = nullptr;
}

cardList::~cardList(){
	// Deconstructor 
	clear();

}

void cardList::clear(){
	Node*temp1=head;
	Node*temp2=nullptr;
	while(temp1){
		temp2=temp1->next;
		delete temp1;
		temp1=temp2;
	}
}


void cardList::append(card c){
	Node* n = new Node;
	n->next = nullptr;
	n->data = c;
	if(!head){
		//empty list 
		head = n;
		tail = n;
	}
	else{
		tail->next = n;
		tail = n;

	}
}

bool cardList::search(card c){
	Node* n = head;
	while(n){
		if(n->data == c){
			return n;
		}
		n = n->next;
	}
	return false;
}


void cardList::remove(card c){
	Node* temp = head;
	Node* temp2 = head->next;
	if(!temp){
		return;
	}


	// Check if head is node want to remove 
	if(temp->data == c){
		head = temp2;
		delete temp;
	}
	//check second node on to tail
	else{
		while(temp2){
			if(temp2->data == c){
				temp->next = temp2->next;
				if(temp2->next == nullptr){
					// if temp2 was tail 
					tail = temp;
				}
				delete temp2;
				// exits loop so duplicate wont be deleted
                return;
			}
			temp = temp2;
			temp2 = temp2->next;	
		}
	}
	
	
}

void cardList::print(){
	Node* temp = head;
	while(temp){
		cout << temp->data << endl;
		temp = temp->next;
	}
}

card* cardList::findMatch(cardList* other){
	Node* temp = this->head;
	while(temp){
		if(other->search(temp->data)){
			card* car = new card(temp->data.getSuit(), temp->data.getNum());
			this->remove(temp->data);
			other->remove(temp->data);
			return car;
		}
		temp = temp->next;
	}
	return nullptr;
}

//class: player functions
//
//

player::player(string N){
	name = N;
	turn = true;
	hand = new cardList;
}
void player::addHand(card c){
	hand->append(c);
}

player::~player(){
	delete hand;
}

string player::getName() const{
	return name;
}

void player::printHand() const{
	hand->print();
}

bool player::isTurn(){
	return this->turn;
}

void player::toggleTurn(){
	if(this->turn == true){
		this->turn = false;
	}
	else if(this->turn == false){
		this->turn = true;
	}
	
}










