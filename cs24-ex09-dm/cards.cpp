//cards.cpp
//Authors: Huiyu Zhang
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
bool Card::operator==(Card other) {
  return this->suit == other.suit && this->rank == other.rank;
}
ostream& operator<<(ostream& os, Card card) {
  os<<card.suit<<" "<<card.rank;
  return os; 
}
Hand::~Hand() {
  delete head;
}
Hand::Node::~Node() {
  delete next;
}
void Hand::receive(Card card) {
  Node* t = new Node(card);
  if (head == 0){
    head = tail = t;
  } else {
    tail->next = t;
    tail = tail->next;
  }
}

Card Hand::show() {
  Card c;
  if (!cur) {
    return c;
  }
  c = cur->info;
  cur = cur->next;
  return c;
}
bool Hand::search(Card card) {
  for (Node* t = head; t; t = t->next) {
    if (t->info == card) {
      return true;
    }
  }
  return false;
}
void Hand::remove(Card card) {
  for (Node* t = head; t; t = t->next) {
    if (t->info == card) {
      Node* tmp = t;
      t = t->next;
      delete tmp;
    }
  }
}

