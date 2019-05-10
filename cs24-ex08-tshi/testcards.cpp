// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_card();
  test_hand();
  test_player();
}

void test_card() {
  test_c_equals();
  test_c_lessless();
}

void test_hand() {
  test_h_append();
  test_h_getCur();
}XSZ

void test_player() {
  test_p_receiveCard();
  test_p_showCard();
  test_p_search();
  test_p_remove();
}
		 
void test_c_equals(){
  START_TEST("test_c_equals");
  Card a(h, a);
  Card b(d, 2);
  Card c(h, a);
  bool x = a==b;
  bool y = a==c;
  assertEquals(false, x, "equals");
  assertEquals(true, y, "equals");
  END_TEST("test_c_equals");
}

void test_c_lessless(){
  START_TEST("test_c_lessless");
  Card a(h, a);
  cout<<"expected: "<<"h a"<<endl;
  cout<<"actual  : "<<a<<endl;
  END_TEST("test_c_lessless");
}

void test_h_append(){
  START_TEST("test_h_append");
  Hand h;
  Card c(h, a);
  h.append(c);
  
  END_TEST("test_h_append");
}

void test_h_getCur(){
  START_TEST("test_h_getCur");

  END_TEST("test_h_getCur");
}

void test_p_receiveCard(){
  START_TEST("test_p_receiveCard");

  END_TEST("test_p_receiveCard");
}
void test_p_showCard(){
  START_TEST("test_p_showCard");

  END_TEST("test_p_showCard");
}
void test_p_search(){
  START_TEST("test_p_search");

  END_TEST("test_p_search");
}

void test_p_remove(){
  START_TEST("test_p_remove");

  END_TEST("test_p_remove");
}
