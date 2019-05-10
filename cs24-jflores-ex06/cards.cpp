#include "cards.h"
#include <iostream>
CardList::CardList(){
	first=0;
}


void CardList::insert(card pick){
	if(first==0){
		first= new card;
		first->num=pick.num;
		first->suit=pick.suit;
		first->next=NULL;
		first->prev=NULL;
		return;
	}
	else{
		card* c=first;
		while(c->next){
			c=c->next;
		}
		c->next=new card;
		c->next->num= pick.num;
		c->next->suit= pick.suit;
		c->next->prev=c;
		c->next->next=NULL;
		return;
	}
}




void CardList::remove(card* nope){
	if(nope->prev == NULL){
		first=nope->next;
		nope->next->prev=NULL;
		delete nope;
	}
	else if(nope->next==NULL){
	 	nope->prev->next=NULL;
		delete nope;
	}
	else{
		nope->prev->next=nope->next;
		nope->next->prev=nope->prev;
		delete nope;
	}
}

bool card::operator==(card c1){
	if (c1.suit==this->suit && c1.num== this->num){
		return true;
	}
	else{
		return false;
	}
}
	



//uses recursion to go through list for matching card
//unclear how to do this whithout having to enter cardlist as a parameter
bool CardList::search(card maybe, card* pointer){
	if(pointer != NULL){
		if(maybe ==*pointer){//want the info inside pointer can i use the astrick to make it what is inside it?
			return true;
		}
		else{
			return search(maybe, pointer->next);//can I do this if it's private
		}
	}
	return false; //breaks while loop when it ends
		
}





std::ostream& operator<< (std::ostream& os,const CardList& random){
                        card* r=random.first;
                        while(r){
                        os<< r->suit<<" " <<r->num<<std::endl;
                        r=r->next;
                        }
                        return os; 
                }

