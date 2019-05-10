//cards.h
//Authors: Your Partner's Name and Your Name
//All class declarations go here
#include<string>
#ifndef CARDS_H
#define CARDS_H
class Person
{
public:
    Person(); //constructor, set all parameter to zero
    ~Person(); //destructor, delete all card created
    void append(char n, char s); // add card to the end
    bool search(char n, char s); // search card with given value n and s
    void delete_card(char n,char s); //delete specific card with given value n and s
    void one_term(Person& other,std::string name); // play one term of the game
    void hand(std::string file); //created a hand of cards
    friend void print_card(const Person& p1); //print all the cards
    bool operator!=(const Person& other); //check whether two person's cards are completely different
private:
    struct Card
    {
        char number;
        char shape;
        Card* next;
    };
    Card* first_card;
    Card* last_card;
    Card* curr_position;
};
void game(Person& p1,Person& p2,std::string p1_name,std::string p2_name); // play the whole game
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
