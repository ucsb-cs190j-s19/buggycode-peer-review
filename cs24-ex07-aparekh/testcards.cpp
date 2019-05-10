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
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
    CardList c1;
    Card tester('h', '9');
    c1.insertCard(tester);
    vector<char> v1, v2;
    v1 = c1.vectorize();
    v2.push_back('h');
    v2.push_back('9');
    assertEquals(v2, v1, "Append Empty List");

}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)
   CardList c1;
   c1.insertCard(Card('h', '9'));
   c1.insertCard(Card('s', 'a'));
   vector<char> v1, v2;
   v1 = c1.vectorize();
   v2.push_back('h');
   v2.push_back('9');
   v2.push_back('s');
   v2.push_back('a');
   assertEquals(v2, v1, "Append single element list");

}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  CardList l1, l2;
  assertEquals(l1,l2, "Empty List Equal");

}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
  Card test1('h', '9'), test2('h', '9'), test3('s', '9');
  assertEquals(true, (test1 == test2), "Same Cards Equal");
  assertEquals(false, (test1 == test3), "Different Cards Not Equal");
}




