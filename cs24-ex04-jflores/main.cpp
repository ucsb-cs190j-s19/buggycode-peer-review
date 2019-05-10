#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

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
  player player1("Alice");
  player player2("Bob");

  player* p1 = &player1;
  player* p2 = &player2;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    card c(line[0],line[2]);
    p1->addHand(c);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    card c(line[0],line[2]);
    p2->addHand(c);
  }
  cardFile2.close();

  //cout << "p1 turn " << p1->isTurn() <<endl;
  //p2->toggleTurn();
  //cout << "p2 turn" << p2->isTurn() << endl;
  
  // Start the game
  
  p2->toggleTurn();
  while(p1->isTurn() || p2->isTurn()){
    if(p1->isTurn()){
      card* find = p1->hand->findMatch(p2->hand);
      p1->toggleTurn();
      if(find){
        cout<< p1->getName() << " picked matching card " << *find << endl;
        p2->toggleTurn();
	delete find;
        
      }
    }
    else if(p2->isTurn()){
      card* find2 = p2->hand->findMatch(p1->hand);
      p2->toggleTurn();
      if(find2){
        cout<< p2->getName() << " picked matching card " << *find2 << endl;
        p1->toggleTurn();
	delete find2;
      }
    }
  }
  cout << endl;

  cout<< p1->getName() << "'s cards:" << endl;
  p1->printHand();

  cout << endl;
  cout << p2->getName() << "'s cards:" << endl;
  p2->printHand();

/*  
  cardList* test = new cardList;

  card car('s', 'j');
  card car2('d', '1');
  card car3('c', 'k');
  card car4('s', '1');
  
  test->append(car);
  test->append(car2);
  test->append(car3);
  test->print();

  player p1("player1");
  p1.getName();
  p1.addHand(car);
  */

  //player player2('test2', argc[2]);
  return 0;
  
}
