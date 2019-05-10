#include "cards.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
Person::Person():first_card(nullptr),last_card(nullptr),curr_position(nullptr){}
Person::~Person()
{
    Card* curr=first_card;
    Card* prev=nullptr;
    while(curr)
    {
        prev=curr->next;
        delete curr;
        curr=prev;
    }
    first_card=nullptr;
    last_card=nullptr;
    curr_position=nullptr;
}
void Person::append(char v,char s)
{
    Card* c=new Card;
    c->number=v;
    c->shape=s;
    c->next=nullptr;
    if(first_card==nullptr && last_card==nullptr)
    {
        first_card=c;
        last_card=c;
        curr_position=c;
    }
    else
    {
        last_card->next=c;
        last_card=c;
    }
}
bool Person::search(char v,char s)
{
    Card* c=first_card;
    while(c)
    {
        if(c->number==v && c->shape==s)
            return true;
        c=c->next;
    }
    return false;
}
void Person::delete_card(char v,char s)
{
    Card* curr=first_card;
    Card* prev=nullptr;
    while(curr)
    {
        if(curr->number==v && curr->shape==s)
        {
            if(curr==first_card)
            {
                first_card=first_card->next;
                delete curr;
            }
            else if(curr==last_card)
            {
                last_card=prev;
                delete curr;
                prev->next=nullptr;
            }
            else
            {
                prev->next=curr->next;
                delete curr;
            }
            return;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
}
void Person::one_term(Person& other,string name)
{

    while(curr_position)
    {
        if(other.search(curr_position->number,curr_position->shape))
        {
            cout<<name<<" picked matching card " <<(curr_position->shape)<< " "<<(curr_position->number)<<endl;
            if(curr_position==last_card)
            {
                delete_card(curr_position->number,curr_position->shape);
                other.delete_card(curr_position->number,curr_position->shape);
                curr_position=nullptr;
            }
            else
            {
                Card* c=curr_position->next;
                delete_card(curr_position->number,curr_position->shape);
                other.delete_card(curr_position->number,curr_position->shape);
                curr_position=c;
            }
            return;
        }
        else
            curr_position=curr_position->next;
    }
    return;
}
bool Person::operator!=(const Person& other)
{
    for(Card* c=first_card;c!=nullptr;c=c->next)
    {
        for(Card* n=other.first_card;n!=nullptr;n=n->next)
        {
            if(c->number==n->number && c->shape==n->shape)
                return true;
        }
    }
    return false;
}
void print_card(const Person& p1)
{
    Person::Card* c=p1.first_card;
    while(c)
    {
        cout<<c->shape<<" "<<c->number<<endl;
        c=c->next;
    }
    return;
}
void Person::hand(string file)
{
    ifstream ifs;
    ifs.open(file);
    string line;
    while(getline(ifs,line))
    {
        append(line[2],line[0]);
    }
    ifs.close();
}
void game(Person& p1,Person& p2,string p1_name,string p2_name)
{
    while(p1!=p2)
    {
        p1.one_term(p2,p1_name);
        p2.one_term(p1,p2_name);
    }
    cout<<endl;
    cout<<p1_name<<"'s cards:"<<endl;
    print_card(p1);
    cout<<endl;
    cout<<p2_name<<"'s cards:"<<endl;
    print_card(p2);
    return;
}
