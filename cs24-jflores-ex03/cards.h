//cards.h
//Authors: David Farias-Llerenas
//all class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;
#include <vector>

class CardList
{
	public:
		CardList(): head(0),tail(0){};
		~CardList();

		//append function can take in a string
		//create a new card item
		//and then append it
		void append(string suit);//DONE

		void remove(string card);//DONE

		vector<string> vectorizeHand() const;//returns a vector of the cards that 
		//the player currently has

		vector<string> returnMatches() const;//returns a vector that
		//includes all the matches found between the deck of cards
		
		vector<int> returnPlayerOrder() const;	

		void removeMatches(CardList& other);


	private:

		//dont necessarily have to make anything in here private
		//since it is already under private
		class Card
		{
			public:
			//making the constructor make next = to null becuase
			//when we create a new card and append it we don't want it
			//to point to anything
			Card(string type): data(type),next(nullptr){}
			string data;
			Card* next;


			//how do you implement this in the .cpp file?
			//Do I do CardList:: or Card::
			//if i make it a nonmember fucntion, can I still access
			//date and next by doing cardobject.data
			//I think so because it is public to CARD objects 
			//but private to CARDLIST object
	
			bool operator == (const Card& other) const;
		};

		//bool thruList;
		Card* head;
		Card* tail;
		vector<string> matches;
		vector<int> players;// use 1 for player 1 and 2 for player 2
};
//to print out each players' cards
ostream& operator<<(ostream& out, CardList& a);
//might be able to use returnMatches function for this


//i am confused as to where the game actually happens
//do we include a seperate function?
//put the play function in your player class
class Player
{
	public:
		Player(string n, CardList& hand):name(n),Hand(hand){}
		//we want this for when we do << overload becuase we want 
		//to have access to the name of the players
		string getName() const;//return the name
		//this essentially uses the functions we have defined to simulate
		//a game and print out the final result
		//i think we assume that argv[1] is the "this" player
		//and argv[2] is the "other" player
		//p1.playGame(p2)
		void playGame(Player& other);//this isn't const because
		//CarList member variable for both player objects will get changed
		//due to removing cards from linked list
		//for this function you can just iterate through the this players
		//list and everytime a match is found just alternate names
		//do until while

	private:
		string name;
		CardList& Hand; 


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
