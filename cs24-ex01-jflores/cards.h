//cards.h
//Authors: Alejandro Diera , 23 April 2019.
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <string>
#include <iostream>

using namespace std;

class CardList { 
public:
    //THE BIG FOUR:
    CardList(); //Constructor
    ~CardList(); //Destructor
    //CardList(const CardList& source); //Copy Constructor
    //ACCESSORS:
    void printList() const; //Prints a CardList w/ specific format.
    //MUTATORS:
    void appendCard(char CardSuite ,char CardValue); //Appends Card to end of a List
    //OVERLOADING:
    CardList& operator=(const CardList& source); //Overloading assignment operator
private:
    struct Card {
	char suite;
	char value;
	Card *next;
    };
    Card *head;
};

class Player {
public:
    //THE BIG FOUR:
    Player(); //Constructor
    //ACCESSORS:
    void printHand()const; //Prints out Player's hand w/ specific format
    CardList getHand()const; //Returns Hand.
    string getName()const; //Return Player's name.
    //MUTATORS:
    void setHand(const CardList& hand); //Sets Player's Hand as a deep copy of CardList hand object
    void setName(string name); //Sets Player's Name to name.
    //OVERLOADING:
    friend ostream& operator<<(ostream& out,const Player& p1);
private:
    CardList Hand;
    string Name;
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
