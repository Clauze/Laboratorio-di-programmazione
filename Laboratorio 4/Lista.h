//Battistin Claudio

#include <iostream>
using namespace std;


class Link {
   
    public:
        Link(const string& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} {}

        Link* insert(Link* p);//inserisce l'elemento prima di un altro nodo
        Link* add(Link* p);//inserimento dopo un elemento
        Link* erase();//rimozione elemento
        Link* find(const string& v);//trova un elemento con un certo valore
        void print_all();//stampa tutti i valori 
        Link* advance(int n);//trova n-esimo valore 
        void push_back(Link*p);//aggiunge elemento in coda
        Link* push_front(Link*p);//aggiunge elemento in testa
        void pop_back();//rimuove l'elemento in coda
        Link* pop_front();//rimuove l'elemento in testa
    private:
        string value;
        Link* prev;
        Link* succ;
};