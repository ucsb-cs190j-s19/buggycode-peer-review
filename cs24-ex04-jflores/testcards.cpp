// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;


void runAll(){
  test_append();
  //test_equal();
  test_search();
  test_card();
  test_remove();
}



void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  //LinkedList l1, l2;
  //assertEquals(l1.head,l2.head,testname);
  return;
}

//TESTING CARD FUNCTIONS
void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  END_TEST("test_card");
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for 
  card c('s','9');
  card b('s','9');
  card a('s','1');
  assertEquals(true, c==b, "case 0: cards are equal");
  assertEquals(false, c==a, "case 1: cards are not equal");
  return;
}


//TESTING CARDLIST APPEND FUNCTION
void test_append(){
  START_TEST("test_cardList_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_cardList_append");

}

void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
  cardList list;
  card c('s','9');
  list.append(card('s','9'));
  assertEquals(true, list.search(c), "test_append_empty_list");
  return;
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)
  cardList list;
  card c('s','9');
  card a('c','3');
  list.append(card('s','8'));
  list.append(card('s','9'));
  assertEquals(true, list.search(c), "case 0: list contains card that is searched for");
  assertEquals(false, list.search(a), "case 1: list does not contains card that is searched for");
  return;
}

//TESTING CARDLIST SEARCH
void test_search(){
  START_TEST("test_cardList_search");
  test_search_empty_list();
  test_search_regular();
  END_TEST("test_cardList_search");
}

void test_search_empty_list(){
  cardList list;
  assertEquals(false, list.search(card('s','8')), "case 0: search empty list");
}
void test_search_regular(){
  cardList list;
  card c('s','9');
  card a('c','3');
  card b('d','a');
  list.append(a);
  list.append(b);
  list.append(c);
  assertEquals(true,list.search(card('d','a')), "case 0: should find card b");
  assertEquals(false,list.search(card('d','j')), "case 1: should fail to find d j");
}

void test_remove(){
  START_TEST("test_cardList_remove");
  test_search_empty_list();
  test_search_regular();
  END_TEST("test_cardList_remove");
}
void test_remove_empty_list(){
  cardList list;
  assertEquals(false,list.search(card('d','j')),"case 0: trying to reemove");
}
void test_remove_regular(){
  cardList list;
  card c('s','9');
  card a('c','3');
  card b('d','a');
  list.append(a);
  list.append(b);
  list.append(c);
  list.remove(b);
  assertEquals(false,list.search(b),"case 0: removing a node in middle");

  cardList list2;
  list2.append(a);
  list2.append(b);
  list2.append(c);
  list2.remove(a);
  assertEquals(false,list2.search(a),"case 1: removing first node");

  cardList list3;
  list3.append(a);
  list3.append(b);
  list3.append(c);
  list3.remove(c);
  assertEquals(false,list3.search(c),"case 2: removing last node");

}

void test_isTurn(){
  START_TEST("test_player_isTurn");
  END_TEST("test_player_isTurn");
}




int main(){
  runAll();
  // for valgrind:
  player player1("koosh");
  player* p1 = &player1;
  p1->addHand(card('d','k'));
  //delete player1;

  cardList* list=new cardList();
  list->append(card('d','k'));
  list->clear();
  //delete list;

  cardList* list2=new cardList();
  list2->append(card('d','k'));
  //delete list2;
  return 0;
}


