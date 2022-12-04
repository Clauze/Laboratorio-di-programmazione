#include <iostream>
#include "MyVector.h"

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

