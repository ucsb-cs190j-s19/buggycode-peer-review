#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cards.h"
//might have to include cards.cpp too idk

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
	//
	CardList a;
	CardList b;

	// Read each file and store cards
	while (getline (cardFile1, line) && (line.length() > 0)){
		a.append(line);
	}//I think this one will store the contents from cardFile1 into the first class object
	cardFile1.close();

	while (getline (cardFile2, line) && (line.length() > 0)){
		b.append(line);
	}//this will do the same for the second class object
	cardFile2.close();
	// Start the game
	string name1 = "Alice";
	string name2 = "Bob";
	Player p1(name1, a);
	Player p2(name2, b);
	p1.playGame(p2);
	
	return 0;
}
