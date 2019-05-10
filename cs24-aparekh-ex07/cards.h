//cards.h
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <vector>
#include <iostream>

class CardList;

class Card{
public:
//constructor
Card();
Card(char ss, char vv);

//accessor functions
char getSuit() const;
char getValue() const;

//modifier functions
void setSuit(char ss);
void setValue(char vv);

bool operator==(const Card& cc);
void operator=(const Card& cc);
friend std::ostream& operator<< (std::ostream& os, const Card& cc);
friend CardList;

private:
char suit;
char value;
Card* next;
};

class CardList{
public:
//constructor and destructor
CardList();
~CardList();

//accessor function
Card* getFirst() const;

//other functions
void insertCard(const Card& cc);
void removeCard(const Card& cc);
bool hasMatch(CardList* otherHand) const;
Card getMatch(CardList* otherHand) const;
void printCards() const;
std::vector<char> vectorize();

bool operator==(const CardList& cc);

private:
Card* first;

};

class Player{
public:
//constructor and destructor
Player(std::string nn = "Anonymous", CardList* hh = nullptr);
~Player();

//accessors
std::string getName() const;
CardList* getHand() const;

//game functions
bool hasMatch(const Player& other) const;
Card getMatch(const Player& other) const;
void removeCard(const Card & cc);
void printHand() const;

//other functions/operators
void setName(std::string nn);
friend std::ostream& operator<< (std::ostream& os, const Player& pp);
void insertCard(const Card& cc);

private:
std::string name;
CardList* hand;
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
