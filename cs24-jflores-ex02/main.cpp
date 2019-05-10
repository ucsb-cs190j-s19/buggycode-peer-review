#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

int main(int argv, char** argc){
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
  cardFile1.close();
  cardFile2.close();
  
  Person Alice,Bob;
  Alice.hand(argc[1]);
  Bob.hand(argc[2]);
  game(Alice,Bob,"Alice","Bob");
  return 0;
}
