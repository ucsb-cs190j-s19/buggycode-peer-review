#include <stdio.h>


#include <iostream>
#include <fstream>
#include "table.h"
using namespace std;

unsigned int user_get(Table &t);
unsigned int user_remove(Table &t);

int main() {
    
    cout << "Demonstrate very small table\n";
    Table t(5);
    t.put(7, "seven");
    t.put(9, "nine");
    t.put(17, "Seventeen");
    t.put(4, "four");
    t.put(36, "Thirty-six");
    cout << t;

    Table tin(t);
    cout << "new table tin created with copy constructor" << endl;
    cout<< tin << endl;
    cout << "table tin printed!" << endl;


    Table lyuda(5);
    cout << "empty table lyuda created"<< endl;
    lyuda = t; 
    cout << "assignment operator works" << endl;
    cout << lyuda << endl;
    cout << "table lyuda printed!" << endl;



}

