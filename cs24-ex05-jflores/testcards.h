// testcards.h
//Authors: Joel Salzman
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitely add more
// You should test all possible corner cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;

void runAll();

// Basic function tests
void test_append(CardList* c) {
	c.append("dummy");
}
void test_equal()
void test_card();
void test_remove();
void test_search();

// Special list tests
void test_append_empty_list(CardList* c) {
	c.append("dummy");
void test_append_single_element_list(CardList* c) {
	c.append("thicc");
}
void test_equal_empty_list(CardList* b, CardList* c) {
	c.remove("dummy");
	Card* bX = b->first;
	Card* cX = c->first;
	assertEquals(bX, cX);
	c.append("dummy");
}
void test_equal_single_element_list(CardList* c, CardList* d) {
	d.remove("thicc");
	Card* bX = b->first;
        Card* cX = c->first;
	while(bX || cX) {
                assertEquals(bX, cX);
                bX = bX->next;
                cX = cX->next;
        }
	d.append("thicc");
}
	
void test_cardlist_operator_double_equal(CardList* d, CardList* e) {
        Card* bX = b->first;
        Card* cX = c->first;
        while(bX || cX) {
                assertEquals(bX, cX);
                bX = bX->next;
                cX = cX->next;
        }
}

// Other
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

// You should add more assertEquals function for your classes. For example, Node/Card class

// Card
void assertEquals(Card *expected, Card *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

// CardList
void assertEquals(CardList *expected, CardList *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

// Person
void assertEquals(Person *expected, Person *actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}


#endif
