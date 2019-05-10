#include <iostream>
using namespace std;
#include <vector>
#include "cards.h"


CardList::~CardList()
{

	Card* p = head;
	while(p != 0)
	{
		Card* temp = p->next;
		delete p;
		p= temp;
	}
	head = 0;
	tail = 0;

}



//adds card objects to the end of a card linked list
void CardList:: append(string suit)
{
	Card* p = new Card(suit);
	//if it's an empty list
	if(head == 0)
	{
		head = p;
		tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}



//this will remove matching element from both linked lists and put the information into an array
//and the corresponding players information in another array
void CardList:: removeMatches(CardList& opp)
{

	if(head != 0)
	{
		Card* placeHolder1 = head;
		Card* placeHolder2 = opp.head;

		//while both player's hands haven't been checked completely
		while(placeHolder1 != 0 && placeHolder2 != 0)
		{
			//player 1's turn
			while( placeHolder1 != 0)
			{
				bool found = false;
				Card* other = opp.head;
				while(other != 0)
				{
					if(*placeHolder1 == *other)//still have to overload this operator
					{
						matches.push_back(placeHolder1->data);
						players.push_back(1);//using 1 to signify player 1
						placeHolder1 = placeHolder1->next;
						remove(other->data);
						//to make sure that we don't leave the placeholder pointing to
						//nothing if it's node happens to get deleted
						if(placeHolder2->data == other->data)
						{
							placeHolder2 = placeHolder2->next;
						}
						opp.remove(other->data);
						found = true;
						break;
					}
					other = other->next;
				}
				if(found == true)
				{
					break;
				}
				placeHolder1 = placeHolder1->next;
			}

			//player 2's turn
			while( placeHolder2 != 0)
			{
				bool found = false;
				Card* other = head;
				while(other != 0)
				{
					if(*placeHolder2 == *other)//still have to overload this operator
					{
						matches.push_back(placeHolder2->data);
						players.push_back(2);//using 1 to signify player 1
						placeHolder2 = placeHolder2->next;
						opp.remove(other->data);
						if(placeHolder1->data == other->data)
						{
							placeHolder1 = placeHolder1->next;
						}
						remove(other->data);
						found = true;
						break;
					}
					other = other->next;
				}
				if(found == true)
				{
					break;
				}
				placeHolder2 = placeHolder2->next;
			}

		}
	}
}



//removes a node with the matching data
//we are assuming that there are no duplicates
//ask about this though
void CardList:: remove(string card)
{
	//if linked list is empty
	if(head == 0)
	{
		return;
	}
	else
	{
		//if the matching card is the first card
		if(head->data == card)
		{
			Card* temp = head->next;
			delete head;
			head = temp;
			return;
		}

		Card* before = head;
		Card* temp = head->next;

		while(temp != 0)
		{	
			//if matching card is the last card
			if((temp->data == card) && (temp->next)==0)
			{
				tail = before;
				delete temp;
				return;
			}
			//if matching card is in the middle
			if (temp->data == card)
			{
				before->next = temp->next;
				delete temp;
				return;//this is assuming there aren't any duplicates 
				//ask if there are any duplicates
			}

			temp= temp->next;
			before = before->next;
		}
	}
}

//returns a pointer to a vector
//QUESTION: do vectors act the same as pointers in terms of 
//they are pointers to the first element?
vector<string> CardList:: returnMatches() const
{
	return matches;
}

vector<int> CardList:: returnPlayerOrder() const
{
	return players;
}


//can I make this a non member function and still have access to the data?
//I'm confused becuase it's under my CardList private 
//but the data is under my Card public
//I think you can
bool CardList::Card:: operator == (const Card& other) const
{
	if(data == other.data)
		return true;
	else
		return false;
}

vector<string> CardList:: vectorizeHand() const
{
	vector<string> *cards = new vector<string>();
	Card* temp = head;
	while(temp != 0)
	{
		cout << temp->data << endl;
		cards->push_back(temp->data);
		temp = temp->next;
	}

	return *cards;
}


ostream& operator<<(ostream& out, CardList& other)
{

	string s = "";
	vector<string> cards; 
	other.vectorizeHand();

	int j = cards.size();
	for(int i = 0; i < j; i++)
	{
		s = s + cards[i] +"\n";
	}

	out<<s;
	return out;

}


string Player:: getName() const
{
	return name;
}

//should the parameter be const?
void Player:: playGame(Player& other)
{
	//this will remove the matches from both players hands
	Hand.removeMatches(other.Hand);
	//
	vector<string> matches = Hand.returnMatches();
	
	vector<int> player = Hand.returnPlayerOrder();

	for(int i = 0; i < matches.size(); i++)
	{

		if(player[i] == 1)
		{
			string s = name + " picked matching card " + matches[i] + "\n";
			cout<<s;
		}
		else
		{
			string s = other.name + " picked matching card " + matches[i] + "\n";
			cout<<s;
		}
	}

	cout<<endl;

	string a = name + "'s cards:";
	cout<< a;
	cout<<Hand;//this is the overloaded operator
	
	string b = other.name + "'s cards:";
	cout<< b;
	cout<<other.Hand;
}
