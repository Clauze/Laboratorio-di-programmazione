#include <iostream>
#include "MyVector.cpp"

using namespace std;

int main(void){
	
	MyVector<int> v={10,12,12};
	MyVector<int> v1=v;
	cout<<"poszione 1 di v"<<v[1]<<"\nposzione 1 di v1 "<<v1[1];
	v.push_back(14);
	cout<<"poszione 1 di v"<<v[1]<<"\nposzione 1 di v1 "<<v1[1];
	v.push_back(15);
	cout<<"poszione 1 di v"<<v[1]<<"\nposzione 1 di v1 "<<v1[1];
	v.push_back(16);
	cout<<"poszione 1 di v"<<v[1]<<"\nposzione 1 di v1 "<<v1[1];
	v.push_back(17);
	cout<<"poszione 1 di v"<<v[1]<<"\nposzione 1 di v1 "<<v1[1];
	v.push_back(18);

	for (int i = 0; i < v.size(); i++)
	{
		cout<<"\nvalore in posizione "<<i<<" uguale a: "<<v[i];
	}
	
	cout<<"\nrimuovo con pop back "<<v.pop_back();
	return 1;
}