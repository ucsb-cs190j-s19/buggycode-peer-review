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
  test_c_equals();
  test_c_lessless();
  test_h_receive();
  test_h_show();
  test_h_search();
  test_h_remove();
}
		 
void test_c_equals(){
  START_TEST("test_c_equals");
  Card a('h', 'a');
  Card b('d', '2');
  Card c('h', 'a');
  bool x = a==b;
  bool y = a==c;
  assertEquals(false, x, "equals");
  assertEquals(true, y, "equals");
  END_TEST("test_c_equals");
}

void test_c_lessless(){
  START_TEST("test_c_lessless");
  Card a('h', 'a');
  cout<<"expected: "<<"h a"<<endl;
  cout<<"actual  : "<<a<<endl;
  END_TEST("test_c_lessless");
}

void test_h_receive(){
  START_TEST("test_p_receive");
  Hand h;
  Card c('h', 'a');
  h.receive(c);
  bool a = h.search(c);
  assertEquals(true, a, "receive");
  END_TEST("test_p_receive");
}
void test_h_show(){
  START_TEST("test_p_show");
  Hand h;
  Card a('h', 'a');
  Card b('c', 'j');
  h.receive(a);
  h.receive(b);
  Card c = h.show();
  Card d = h.show();
  bool x = a==c;
  bool y = b==d;
  cout<<"c and d "<<c<<d<<endl;
  assertEquals(true, x, "show");
  assertEquals(true, y, "show");  
  END_TEST("test_p_showCard");
}
void test_h_search(){
  START_TEST("test_p_search");
  Hand h;
  Card a('h', 'a');
  Card b('c', 'j');
  Card c('h', '2');
  h.receive(a);
  h.receive(b);
  bool x = h.search(c);
  assertEquals(false, x, "search");  
  END_TEST("test_p_search");
}

void test_h_remove(){
  START_TEST("test_p_remove");
  Hand h;
  Card a('h', 'a');
  Card b('c', 'j');
  h.receive(a);
  h.receive(b);
  h.remove(a);
  bool x = h.search(a);
  assertEquals(false, x, "remove");
  END_TEST("test_p_remove");
}
