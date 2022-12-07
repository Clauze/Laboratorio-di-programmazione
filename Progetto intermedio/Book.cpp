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
};

Isbn::Isbn(int v1,int v2,int v3,char val)
    : n1{v1},n2{v2},n3{v3},x{val}
{
    if(!isValid()) throw InvalidIsbn();
}

bool Isbn::isValid(){
    if((n1<0 || n1>999) || (n2<0 || n2>999) || (n3<0 || n3>999))return false;
    if(x<48 || (x>57 && x<65) || x>90)  return false;//lowercase
    return true;
}


//Classe book
/*class Book
{
private:
    //Isbn isbn;
    string titolo;
    string nome;
    string cognome;
    //Date dataCopyright;
    bool stato;

public:

    Book(const string& titolo,const string& nome,const string& cognome,bool stato /*Date dataCopyright,Isbn isbn*/ //);
    /*Isbn */
   /* string getTitolo();
    string getNome();
    string getCognome();
    bool getStato();
    bool prestito();
    bool restituzione();
    bool operator==();
    bool operator!=();
    ostream& operator<<(ostream& os,const Book &libro);
    ~Book();
};

Book::Book()
{
}

Book::~Book()
{
}8
*/

int main(void){

    
    cout<<"creo";
    Isbn i{1,2,3,'W'};

    return 0;
}