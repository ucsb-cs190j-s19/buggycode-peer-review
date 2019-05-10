//cards.h
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>

using namespace std;

class Card{
 public:
  Card(char s,char r){
    suit = s;
    rank = r;
  }
  bool operator==(Card other);
  friend ostream& operator<< (ostream& os, Card card);
 private:
  char suit;
  char rank;
};
class Hand{
 public:
  ~Hand();
  void append(char suit, char rank);
  Card getCur();
 private:
  class Node{
  public:
    Node(Card card) {
      info = card;
      next = 0;
    }
    ~Node();
  private:
    Card info;
    Node* next;
  };
  Node* head;
  Node* cur = head;
};
class Player{
 public:
  void receiveCard(Card card);
  Card showCard();
  bool search(Card card);
  void remove(Card card);
 private:
  Hand hand;
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
