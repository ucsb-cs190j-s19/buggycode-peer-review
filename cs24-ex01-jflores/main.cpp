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
  CardList L1;
  CardList L2;
  char CardSuite;
  char CardValue;
  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
      CardSuite = line[0];
      CardValue = line[2];
      L1.appendCard(CardSuite,CardValue);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
     CardSuite = line[0];
     CardValue = line[2];
     L2.appendCard(CardSuite,CardValue);
  }
  cardFile2.close();
 
  // Start the game
  string name1 = "Alice";
  string name2 = "Bob";

  Player p1;
  Player p2;

  p1.setHand(L1);
  p1.setName(name1);
  p2.setHand(L2);
  p2.setName(name2);

  p1.printHand();
  p2.printHand();
  
  return 0;
}




