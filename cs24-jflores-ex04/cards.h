//cards.h
//Authors: Your Partner's Name and Your Name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <iostream>
using namespace std;

class card {
public:
	card(char s='n', char n = 'n'); //default constructor
	bool operator==(const card& two);
	char getSuit() const;
	char getNum() const;
	friend ostream& operator<<(ostream& out, const card& source);
private:
	char suit; // card suits
	char num; 
};


class cardList {
public:
	cardList(); //constructor
	~cardList(); //de-constructor 

	//functions
	void append(card c);
	bool search(card c);
	void remove(card c);
	card* findMatch(cardList* other);
	void clear();
	void print();


private:
	// Nodes of linked list 
	// Node contains: card data, next ptr
	struct Node {
		Node(){
			next = nullptr;
		}
		card data;
		Node* next;
	};
	Node* head;
	Node* tail;
};


class player {
public:
	player(string N);
	~player();
	string getName() const;
	void addHand(card c);
	void printHand() const;
	bool isTurn();
	void toggleTurn();
	cardList* hand;
private:
	bool turn;
	string name;
};






#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
