#include <iostream>
#include "MyVector.h"

using namespace std;

int main(void){
	
	MyVector<int> v={10,12,12};
	MyVector<int> v1=v;
	cout<<"poszione 1 di v "<<v[1]<<"\nposzione 1 di v1 "<<v1[1]<<" e dimensione uguale a "<<v1.getSize();
	v.push_back(14);
	cout<<"\naggiunto a v "<<v[3]<<" e dimensione uguale a "<<v.getSize();
	cout<<"\nstampo v "<<v;
	int n=10;
	v.at(1)=n;
	cout<<"\nposizione 1 uguale a "<<v[1]<<" ora "<<" e dimensione uguale a "<<v.getSize();

	v.push_back(15);
	v.push_back(16);
	v.push_back(17);
	v.push_back(18);
	cout<<"\nstampo v dopo aver aggiunto 15,16,17,18"<<v;

	v.pop_back();
	v.pop_back();
	cout<<"\nstampo v dopo aver effettuato 2 pop"<<v;



	return 0;
}