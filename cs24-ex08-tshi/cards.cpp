//cards.cpp
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
bool Card::operator==(Card other) {
  return this->suit == other.suit && this->rank == other.rank;
}
ostream& Card::operator<< (ostream& os, Card card) {
  os<<card.rank<<" "<<card.suit;
  return os; 
}
Hand::~Hand() {
  delete head;
}
Node::~Node() {
  delete next;
}
void Hand::append(char suit, char rank) {
  Card temp(suit, rank);
  Node* tmp(temp);
  if (head == 0) {
    head = tmp;
  } else {
    Node* t = head;
    while (t->next) {
      t = t->next;
    }
    t->next = tmp;
  }
}
Card Hand::getCur() {
  if (cur) {
    Node* t = cur;
    cur = cur->next;
    return t->info;
  } else {
    return 0;
  }
}
void Player::receiveCard(Card card) {
  hand.append(card);
}
Card Player::showCard() {
  return hand.getCur();
}
bool Player::search(Card card) {
  for (Node* t = hand.head; t; t = t->next) {
    if (t->info == card) {
      return true;
    }
  }
  return false;
}
void Player::remove(Card card) {
  for (Node* t = hand.head; t; t = t->next) {
    if (t->info == card) {
      Node* tmp = t;
      t = t->next;
      delete tmp;
    }
  }
}

