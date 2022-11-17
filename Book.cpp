/*
@Clauze @gioia @malve
*/

#include <iostream>
using namespace std;


class Date
{
public:
    class InvalidDate{};
    enum Month{ 
        jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };

    Date(int yy, Month mm, int dd);
    
private:

    int day;
    Month month;
    int year;
    bool isValid();

};

Date::Date(int yy, Month mm, int dd)
    :year{yy},month{mm},day{dd}
{
    if(!isValid()) throw InvalidDate();
}

bool Date::isValid(){
    if(month<1 || month>12) return false;
    else if(month==2){
        if( year % 4==0 || (year % 100==0 && year % 400==0)) {
            if(day<1 || day >29) return false;
        }
        else {
            if(day<1 || day>28) return false;
        }
    }
    else if(month<=7){
        if(month%2!=0){
            if(day<1 || day>31) return false;
        }
        else{
            if(day<1 || day>30) return false;
        }
    }
    else{
        if(month%2==0){
            if(day<1 || day>31) return false;
        }
        else{
            if(day<1 || day>30) return false;
        }
    }

    return true;
    

}

//Classe isbn
class Isbn
{
    private:
        class InvalidIsbn{};
        int n1;
        int n2;
        int n3;
        char x;
        bool isValid();
    public:
        Isbn(int v1,int v2,int v3,char val );
        friend ostream& operator<<(ostream& os,const Isbn &isbn);

};

Isbn::Isbn(int v1,int v2,int v3,char val)
    : n1{v1},n2{v2},n3{v3},x{val}
{
    if(!isValid()) throw InvalidIsbn();
}

bool Isbn::isValid(){

    if((n1<0 || n1>999) || (n2<0 || n2>999) || (n3<0 || n3>999))return false;
    
    if(x<48 || (x>57 && x<65) || (x>90 && x<97) || x>122)  return false;

    return true;
}

ostream& operator<<(ostream& os,const Isbn &isbn){

    if(isbn.n1>=0 && isbn.n1<=9) os<< "00" << isbn.n1;
    else if(isbn.n1>=10 && isbn.n1<=99) os << "0" << isbn.n1;
    else os << isbn.n1;

    if(isbn.n2>=0 && isbn.n2<=9) os << "-00" << isbn.n2;
    else if(isbn.n2>=10 && isbn.n2<=99) os << "-0" << isbn.n2;
    else os << "-" << isbn.n2;

    if(isbn.n3>=0 && isbn.n3<=9) os << "-00" << isbn.n3;
    else if(isbn.n3>=10 && isbn.n3<=99) os << "-0" << isbn.n3;
    else os << "-" << isbn.n3;

    return os<< "-" << isbn.x << "\n";

}


//Classe book
class Book
{
private:
    Isbn isbn;
    string titolo;
    string nome;
    string cognome;
    Date dataCopyright;
    bool stato;

public:

    Book(const string& tit,const string& nom,const string& cog,bool sta, Date dataCop,Isbn i);
    string getTitolo();
    string getNome();
    string getCognome();
    bool getStato();
    bool prestito();
    bool restituzione();
    //bool operator==();
    //bool operator!=();
    friend ostream& operator<<(ostream& os,const Book &libro);
};

Book::Book(const string& tit,const string& nom,const string& cog,bool sta, Date dataCop,Isbn i)
    : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{i}
{

}

ostream& operator<<(ostream& os,const Book &libro){

    os << "\n\nTitolo: " << libro.titolo << "\nAutore: " << libro.nome << " " << libro.cognome;

    if(libro.stato) os << "\nStato: disponibile"; 
    else os << "\nStato: in prestito";

    os << "\nData copyright: " /*<< libro.dataCopyright*/ << "\nISBN: " << libro.isbn; //manca operator della data

    return os;
}


int main(void){

    
    cout<<"creo";
    Isbn i{9,99,999,'Z'};
    cout<<"\n"<<i;

    Book b{"c++","marco","rossi",false,Date{2000,Date::Month::apr,22},i};
    cout<<"\nlibro"<<b;
    
    return 0;
}