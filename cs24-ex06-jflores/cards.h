//cards.h
//Authors: Amanda Serex
//All class declarations go here
#include <iostream>
#ifndef CARDS_H
#define CARDS_H



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
//

struct card{
		char suit;
		char num;
		bool operator==(card c1);
		card* next;
		card* prev;
};


class CardList{
	public:
		CardList();
		card* getFirst(){return first;};
		void insert(card pick);
		void remove(card* nope);
		bool search(card maybe, card* pointer);
		
	private:
		card* first;
		friend std::ostream& operator << (std::ostream& os, const CardList& random);

};


#endif
