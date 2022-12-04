#include <iostream>
#include "MyVector.h"

using namespace std;

int main(void){
	
	MyVector<int> v={10,12,12};
	MyVector<int> v1=v;
	cout<<"poszione 1 di v "<<v[1]<<"\nposzione 1 di v1 "<<v1[1];
	v.push_back(14);
	cout<<"\naggiunto a v "<<v[3];
	int n=10;
	v.at(1)=n;
	cout<<"\nposizione 1 uguale a "<<v[1]<<" ora";

	return 1;
}