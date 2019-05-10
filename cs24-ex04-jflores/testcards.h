// testcards.h
//Authors: Your Partner's Name and Your Name
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_constructor();
void test_equal();

// CARD FUNCTIONS TEST
void test_card();
void test_card_operator_double_equal();

//CARDLIST FUNCTIONS TEST
void test_append();
void test_append_empty_list(); // A test case for append
void test_append_single_element_list(); 

void test_search();
void test_search_empty_list();
void test_search_regular();

void test_remove();
void test_remove_empty_list();
void test_remove_regular();

void test_toggleTurn();
void test_addHand();
//PLAYER FUNCTIONS TEST

/*
void test_destructor();
void test_remove();
void test_search();

*/

void test_equal_empty_list();


void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
void assertEquals(bool expected, bool actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(card expected, card actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
/*
void assertEquals(cardList expected, cardList actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
*/

// You should add more assertEquals function for your classes. For example, Node/Card class
/*
void assertEquals(Node *expected, Node *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
*/


#endif
