#include "cards.h"
using namespace std;

// Card

	// Constructor, Destructor, Copy Constructor
	Card::Card(string info){
		this->info = info;
		this->next = this->prev = nullptr;
	}
	Card::~Card() {
		this->next = this->prev = nullptr;
	}
	Card::Card(const Card& c) {
		this->info = c.info;
		this->next = c.next;
		this->prev = c.prev;
	}

	// Getter
	string Card::getInfo() const {
		return info;
	}

	// Operators
	bool Card::operator == (const Card& c) {
		if(c.getInfo() == this->getInfo()) {return true;}
		return false;
	}
	ostream& operator << (ostream& os, const Card& c) {
		os << c.info << endl;
		return os;
	}

// CardList

	// Constructor, Destructor, Copy Constructor
	CardList::CardList() {
		first = nullptr;
		last = nullptr;
	}
	CardList::~CardList() {
		Card* p = first;
		Card* q;
		while(p) {
			q = p->next;
			delete p;
			p = q;
		}
	}
	CardList::CardList(const CardList& source) {
	    Card *n = source.first;
	    first = nullptr;
	    while(n) {
		    append(*n);
		    n = n->next;
	    }
	}

	// Functions
	void CardList::append(Card& item) {
		Card* p = new Card(item);
		if(!first) {
			first = last = p;
		} else {
			last->next = p;
			p->prev = last;
			last = p;
		}
	}
	void CardList::remove(Card& item) {
		Card* curr = search(item);
		Card* p = curr->prev;
		Card* n = curr->next;
		if(p) {p->next = n;}
		if(n) {n->prev = p;}
		curr->next = curr->prev = nullptr;
		delete curr;
	}
	Card* CardList::search(const Card& item) {
		Card* n = first;
		while(n) {
			if(*n == item) {return n;}
			n = n->next;
		}
		return nullptr;
	}

	// Getter
	Card* CardList::getFirst() const {
		return first;
	}

	// Operator
        ostream& operator << (ostream& os, const CardList& list) {
        	Card* c = list.getFirst();
		while(c) {
			os << c->getInfo() << endl;
			c = c->next;
        	}
		return os;
	}

// Person

	// Constructor, Destructor
	Person::Person(string name = "Joel") {
		this->name = name;
	}
	Person::~Person() {}

	// Getter
	string Person::getName() const {
		return name;
	}
