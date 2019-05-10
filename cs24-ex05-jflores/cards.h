//cards.h
//Authors: Joel Salzman
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <vector>
using namespace std;

class Card{
public:
	Card(string info);
	~Card();
	Card(const Card& c);
	string getInfo() const;
	Card* next;
        Card* prev;
	bool operator == (const Card& c);
private:
	friend ostream& operator << (ostream& os, const Card& c);
	string info;
};

class CardList{
public:
	CardList();
	~CardList();
	CardList(const CardList& source);
	void append(Card& item);
	void remove(Card& item);
	Card* search(const Card& item);
	Card* getFirst() const;
	Card* current;
private:
	friend ostream& operator << (ostream& os, const Card& list);
	Card* first;
        Card* last;
};

class Person{
public:
	Person(string name);
	~Person();
	string getName() const;
	CardList hand;
private:
	string name;
};

#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP principles using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Card in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
