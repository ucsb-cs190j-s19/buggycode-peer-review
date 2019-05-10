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
    Player alice("Alice"), bob("Bob");
    Card a, b;
  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
        a.setSuit(line.at(0));
        a.setValue(line.at(2));
        alice.insertCard(a);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
        b.setSuit(line.at(0));
        b.setValue(line.at(2));
        bob.insertCard(b);
  }
  cardFile2.close();

    Card match;
  // Start the game
        while(alice.hasMatch(bob) || bob.hasMatch(alice)){ //while either player has a match
            //Alice first
            if(alice.hasMatch(bob)){//check for match
                match = alice.getMatch(bob);
                cout<< alice << " picked matching card "<< match<<endl;
                if(match.getSuit() == 'z')
                    break;
                alice.removeCard(match);
                bob.removeCard(match);
            }

            //Bob's turn
            if(bob.hasMatch(alice)){
                match = bob.getMatch(alice);
                cout << bob << " picked matching card "<< match<<endl;
                if(match.getSuit() == 'z')
                    break;
                bob.removeCard(match);
                alice.removeCard(match);
                }
            }

         cout<<"The game has ended.\n";

         cout<<alice<< "'s cards:\n";
         alice.printHand();
         
         cout<<bob<< "'s cards:\n";
         bob.printHand();
    
  return 0;
}
