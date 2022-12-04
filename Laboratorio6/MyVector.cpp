#include <iostream>
using namespace std;

template <typename T>
class MyVector{
public:
	
	MyVector(int size=0)
	: fisDim{size}, elem{new T[size]}, logicDim{0}
	{
			if(size==0) elem=nullptr;
	};
	
	MyVector(initializer_list<T> lst)
	:fisDim{lst.size()}, elem{new T[lst.size()]}, logicDim{lst.size()}
	{
		copy(lst.begin(),lst.end(),elem);
	};
	
	MyVector(const MyVector& arg)
	:fisDim{arg.fisDim}, elem{new T[arg.fisDim]}
	{
		copy(arg.elem, arg.elem+fisDim,elem);	
	};
	
	~MyVector()
	{
		delete elem;
	}
	
	T& operator[](int n);
	void push_back(T val);
	T& at (int n);
	
private:
	int logicDim;
	int fisDim;
	T* elem;
};

template <typename T>
T& MyVector<T>::operator[](int n){
		return this->elem[n];
}

template <typename T>
void MyVector<T>::push_back(T val){
	if(fisDim==logicDim){
			T* c=new T[fisDim*2];
			copy(elem, elem+logicDim,c);	
			delete elem;
			elem=c;
	}
	elem[logicDim++]=val;
}

template <typename T>
T& MyVector<T>::at (int n){
	if(n>fisDim){
		throw std::out_of_range("out of range");
	}
	return elem[n];
}

