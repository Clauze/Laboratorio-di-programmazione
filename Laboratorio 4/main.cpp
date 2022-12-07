//Battistin Claudio

#include <iostream>
#include <string.h>
#include "Lista.h"
using namespace std;


int main(void){
    Link* lista=new Link{"Valore 1"};
    lista=lista->insert(new Link("Valore 2"));
    lista=lista->insert(new Link("Valore 3"));
    lista->print_all();
    lista->add(new Link("Valore 4"));
    cout<<"aggiungo valore 4\n";
    lista->print_all();
     lista->add(new Link("Valore 5"));
    cout<<"aggiungo valore 5\n";
    lista->print_all();
    cout<<"elimino valore in p1\n";
    lista=lista->erase();
    lista->print_all();
    cout<<"elimino valore in p1\n";
    lista=lista->erase();
    lista->print_all();

    cout<<"cerco valore 4\n";
    Link*t=lista->find("Valore 4");

    if(t){
        cout<<"trovato\n";
    }
    else{
        cout<<"non trovato\n";
    }

    cout<<"elimino valore 4\n";
    lista=t->erase();
    lista->print_all();

    cout<<"cerco Valore 7\n";
    t=lista->find("valore 7");

    if(t){
        cout<<"trovato\n";
    }
    else{
        cout<<"non trovato\n";
    }

    cout<<"aggiungo in coda Valore 15\n";
    lista->push_back(new Link("Valore 15"));
    lista->print_all();

    cout<<"aggiungo in testa Valore 19\n";
    lista->push_back(new Link("Valore 19"));
    lista->print_all();

    cout<<"rimuovo in coda\n";
    lista->pop_back();
    lista->print_all();

    cout<<"rimuovo in testa\n";
    lista=lista->pop_front();
    lista->print_all();

    cout<<"aggiungo in testa Valore 20\n";
    lista->push_back(new Link("Valore 20"));
    lista->print_all();

    cout<<"aggiungo in testa Valore 21\n";
    lista->push_back(new Link("Valore 21"));
    lista->print_all();

    cout<<"aggiungo in testa Valore 22\n";
    lista->push_back(new Link("Valore 22"));
    lista->print_all();

    cout<<"aggiungo in testa Valore 23\n";
    lista->push_back(new Link("Valore 23"));
    lista->print_all();

    cout<<"mi muovo fino alla poszione 3 e la rimuovo\n";
    Link* pos=lista->advance(3);
    pos->erase();
    lista->print_all();

    cout<<"mi muovo fino alla poszione 2, torno alla posizione 1 e la rimuovo\n";
    pos=lista->advance(3);
    pos=lista->advance(-1);
    pos->erase();
    lista->print_all();

    return 0;
}