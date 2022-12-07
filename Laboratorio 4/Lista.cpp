//Battistin Claudio

#include <iostream>
#include <string.h>
#include "Lista.h"
using namespace std;

Link* Link::insert(Link* p){
    Link* t=this;

    if(!p){
        return t;
    }

    p->succ=t;

    if (t->prev)
    {
        cout<<"cè succ";
        t->prev->succ=p;
        cout<<"t prev "<<t->prev->succ<<" e p "<<p;
        p->prev=t->prev;
    }

     t->prev=p;

    return p;
    
}
Link* Link::add(Link* p){
    Link* t=this;

    if(!p){
        return t;
    }

    
    if (t->succ)
    {
        t->succ->prev=p;
        p->succ=t->succ;
    }
    p->prev=t;
    t->succ=p;

    return t;
}

Link* Link::erase(){
    
    if(!this) return nullptr;

    if(this->prev){
        this->prev->succ=this->succ;
    }
    else if(this->succ){
        this->succ->prev=this->prev;
    }
    return this->succ;
}

void Link::print_all(){

    Link*t=this;

    while(t)
    {
        cout<<"valore: "<<t->value<<"\n";
        t=t->succ;
    }
    
    
}

Link* Link::find(const string& v){
    Link*t=this;

    while(t)
    {
        if(v.compare(t->value)==0) {
            return this;
        }
        t=t->succ;
    }
    return nullptr;
    
}

void Link::push_back(Link*p){

    if(!this)return;

    Link*t=this;

    while(t->succ)
    {
        t=t->succ;
    }
    t->succ=p;
    p->prev=t;
}

Link* Link::push_front(Link*p){
    if(!this)return p;;

    Link*t=this;

    p->succ=t;
    t->prev=p;
}

void Link::pop_back(){
    if(!this)return ;

    Link*t=this;

    while(t->succ)
    {
        t=t->succ;
    }
    t=t->prev;
    t->succ=nullptr;
}

Link* Link::pop_front(){
    if(!this)return nullptr;

    Link* t=this;

    while(t->prev)
    {
        t=t->prev;
    }
    t=t->succ;
    t->prev=nullptr;
    return t;
}

Link* Link::advance(int n){
    Link* t=this;
    if(!t) return nullptr;

    while (n<0)
    {

        t=t->succ;
        if(!t) return nullptr;
        n++;
    }
    while (n>0)
    {
        t=t->succ;
        if(!t) return nullptr;
        n--;
    }
    
    return t;

}