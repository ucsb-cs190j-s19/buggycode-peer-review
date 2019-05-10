#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

 
  // print out each hand
  // Start the game
  //first player asks second player for a matching card, iterates through hand to find one
  //find matching card say who picked what card
  //then use remove fuction for both players
  //next players turn
  //continue until no matching cards
  //then use print function for each players' CardList
void turn(CardList thisp, CardList otherp){
  card* golook= thisp.getFirst();
  while(golook){
  if(otherp.search(*golook,otherp.getFirst())){
	cout <<thisp<< "picked matching card"<<" "<<golook->suit<<" "<<golook->num<<endl;
	thisp.remove(golook);
	otherp.remove(golook);
	turn(otherp,thisp);
	}
  else{
  	golook= golook->next;
  	}
  	}
	return;
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
  CardList hand1;
  CardList hand2;

  
  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
  
  card a;
  a.suit=line[0];
  a.num=line[2];
  hand1.insert(a);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
  card b;
  b.suit=line[0];
  b.num=line[2];
  hand2.insert(b);
  }

  cardFile2.close();
  
  
  turn(hand1, hand2); 
	
  cout<<hand1;
  cout<<hand2;
 

  return 0;
}

