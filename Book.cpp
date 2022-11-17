/*
@Clauze @gioia @malve
*/
#include <iostream>
#include <string>
using namespace std;


class Date
{
public:
    class InvalidDate{};
    enum Month{ 
        jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };

    Date(int yy, Month mm, int dd);
    friend ostream& operator<<(ostream& os,const Date &data);
    
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

ostream& operator<<(ostream& os,const Date &data) {

    return os << data.day << "/" << data.month << "/" << data.year;
}

//Classe isbn
class Isbn
{
    private:
        int n1;
        int n2;
        int n3;
        char x;
        bool isValid();
        bool isValidString(const char* isbn);
        
    public:
        class InvalidIsbn{};
        Isbn(int v1,int v2,int v3,char val);
        Isbn(const char* isbn);
        bool operator==(const Isbn &code);
        bool operator!=(const Isbn &code);
        friend ostream& operator<<(ostream& os,const Isbn &isbn);

};

Isbn::Isbn(int v1,int v2,int v3,char val)
    : n1{v1},n2{v2},n3{v3},x{val}
{
    if(!isValid()) throw InvalidIsbn();
}

Isbn::Isbn(const char* isbn)
{
    if(!isValidString(isbn)) throw InvalidIsbn();
}

bool Isbn::isValid(){

    if((n1<0 || n1>999) || (n2<0 || n2>999) || (n3<0 || n3>999))return false;
    
    if(x<48 || (x>57 && x<65) || (x>90 && x<97) || x>122)  return false;

    return true;
}

bool Isbn::isValidString(const char* isbn){
    int size=0;
    string s="";
    
    while(isbn[size]!='\0') {
        size++;
    }
    
    if(size!=13) return false;
    else {
    	try {
    		n1 = (isbn[0]-'0')*100 + (isbn[1]-'0')*10 + (isbn[2]-'0');
    		n2 = (isbn[4]-'0')*100 + (isbn[5]-'0')*10 + (isbn[6]-'0');
    		n3 = (isbn[8]-'0')*100 + (isbn[9]-'0')*10 + (isbn[10]-'0');
		}
		catch(invalid_argument) {
			cout << "isbn non valido";
			return false;
		}
		
		x = isbn[12];
		
		if(x<48 || (x>57 && x<65) || (x>90 && x<97) || x>122)  return false;
		
		return true;
	}
}

bool Isbn::operator==(const Isbn &code){
    if((this->n1 == code.n1) && (this->n2 == code.n2) && (this->n3 == code.n3) && (this->x == code.x))
        return true;
    else return false;
}

bool Isbn::operator!=(const Isbn &code){
    if((this->n1 != code.n1) || (this->n2 != code.n2) || (this->n3 != code.n3) || (this->x != code.x))
        return true;
    else return false;
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

    Book(const string& nom,const string& cog, const string& tit, bool sta, Date dataCop,Isbn i);
    Book(const string& nom,const string& cog, const string& tit,const char* i, bool sta, Date dataCop);
    string getTitolo();
    string getNome();
    string getCognome();
    bool getStato();
    bool prestito();
    bool restituzione();
    bool operator==(const Book &libro);
    bool operator!=(const Book &libro);
    friend ostream& operator<<(ostream& os,const Book &libro);
};

Book::Book(const string& nom,const string& cog,const string& tit,bool sta=true, Date dataCop = Date{1970,Date::Month::jan,1},Isbn i = Isbn{000,000,000,0})
    : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{i}
{}

Book::Book(const string& nom,const string& cog,const string& tit, const char* is = "000-000-000-0", bool sta=true, Date dataCop = Date{1970,Date::Month::jan,1})
    : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{Isbn{is}}
{}

string Book::getTitolo() {
    return this->titolo;
}

string Book::getNome() {
    return this->nome;
}

string Book::getCognome() {
    return this->cognome;
}

bool Book::getStato() {
    return this->stato;
}

bool Book::prestito(){
    if(!this->stato) return false;
    else{
        this->stato = false;
        return true;
    }
}

bool Book::restituzione(){
    if(this->stato) return false;
    else{
        this->stato = true;
        return true;
    }
}

bool Book::operator==(const Book &libro){
    if(isbn == libro.isbn) return true;
    else return false;
}

bool Book::operator!=(const Book &libro){
    if(this->isbn != libro.isbn) return true;
    else return false;
}

ostream& operator<<(ostream& os,const Book &libro){

    os << "\n\nTitolo: " << libro.titolo << "\nAutore: " << libro.nome << " " << libro.cognome;

    if(libro.stato) os << "\nStato: disponibile"; 
    else os << "\nStato: in prestito";

    os << "\nData copyright: " << libro.dataCopyright << "\nISBN: " << libro.isbn; 

    return os;
}


int main(void){
    
    cout<<"creo";
    Isbn i{9,99,999,'Z'};
    Isbn i2{4,229,423,'F'};
    cout<<"\n"<<i;
    
    try{
        Book b{"marco","rossi","c++",true,Date{2000,Date::Month::apr,5}, Isbn{9,99,150,'Z'}};
        cout<<"\nlibro"<<b;
        if(b.prestito()){
            cout<<"\nLibro correttamente preso in prestito\n";
        }
        else cout << "\nLibro non disponibile";

        if(b.restituzione()){
            cout<<"\nLibro correttamente restituito dal prestito";
        }
        else cout << "\nIl libro non era in prestito";
    }
    catch(Date::InvalidDate){
        cerr<<"inserita data non valida";
    }
    catch(Isbn::InvalidIsbn){
        cerr<<"inserito isbn non valido";
    }

    try{
        Book b{"marco","rossi","g++",false,Date{2000,Date::Month::apr,5}, Isbn{9,99,150,'Z'}};
        cout<<"\nlibro"<<b;
        if(b.prestito()){
            cout<<"\nLibro correttamente preso in prestito\n";
        }
        else cout << "\nLibro non disponibile";

        if(b.restituzione()){
            cout<<"\nLibro correttamente restituito dal prestito";
        }
        else cout << "\nIl libro non era in prestito";
    }
    catch(Date::InvalidDate){
        cerr<<"inserita data non valida";
    }
    catch(Isbn::InvalidIsbn){
        cerr<<"inserito isbn non valido";
    }

    


    Book b{"marco","rossi","c++",false,Date{2000,Date::Month::apr,22},i};
    Book b2{"carlo","mariconda","esploratore",true,Date{2000,Date::Month::apr,22},i2};
    if(b==b2) cout << "== libri uguali\n";
    else cout << "== libri diversi\n";
    if(b!=b2) cout << "!= libri diversi\n";
    else cout << "!=libri uguali\n";
    cout<<"\nlibro"<<b;
    cout << "\nlibro"<<b2;
    if(b.restituzione()) cout << "\n\nlibro restituito correttamente\n";
    else cout << "\n\nRestituzione fallita, libro gi� disponibile\n";
    if(b2.prestito()) cout << "libro prestato correttamente\n";
    else cout << "impossibile effettuare il prestito, libro non disponibile\n";
    cout<<"\nlibro"<<b;
    cout << "\nlibro"<<b2;

    //vector<Book> shelf(10);
    try{
        Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "999-999-150-Z");
        cout << "\n" << my_favourite_book;
    }
    catch(Isbn::InvalidIsbn){
        cerr<<"\ninserito isbn non valido\n";
    }
    
    return 0;
}
