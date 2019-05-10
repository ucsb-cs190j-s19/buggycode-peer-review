#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

Card* game(Person* p1, Person* p2) {
  // writing p1->hand.current can get tiresome
  Card* p1Card = p1->hand.current;

  // set p1Card to the matching card if there is one, nullptr otherwise
  while(p1Card && !p2->hand.search(*p1Card)) {
    p1Card = p1Card->next;
    if(!p1Card) {return nullptr;}
  }

  // if there's a matching card, store next, print message and delete cards from both hands
  if(p1Card) {
    // properly set both players' next cards
    Card* nextCard = p1Card->next;
    if(p1Card->getInfo() == p2->hand.current->getInfo()) {p2->hand.current = p2->hand.current->next;}
    // announce victory
    cout << p1->getName() << " picked matching card " << *p1Card;
    // remove the cards and returns p1's new current card
    p2->hand.remove(*p2->hand.search(*p1Card));
    p1->hand.remove(*p1Card);
    return nextCard;
  }

  // if p1's hand has no more matching cards, return nullptr
  return nullptr;
}

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files

  Person* alice = new Person("Alice");
  Person* bob = new Person("Bob");

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
	Card* c = new Card(line);
	alice->hand.append(*c);
	delete c;
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
	Card* c = new Card(line);
	bob->hand.append(*c);
	delete c;
  }
  cardFile2.close();

  // Start the game
  alice->hand.current = alice->hand.getFirst();
  bob->hand.current = bob->hand.getFirst();
  while(alice->hand.current || bob->hand.current) {
	  alice->hand.current = game(alice, bob);
	  bob->hand.current = game(bob, alice);
  }
  cout << "\nAlice's cards:\n" << alice->hand << endl;
  cout << "Bob's cards:\n" << bob->hand << endl;
}
