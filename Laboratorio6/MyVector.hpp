#ifndef MyVector_hpp
#define MyVector_hpp
#include <iostream>
#include "MyVector.h"

template <typename T>
T& MyVector<T>::operator[](int n){
	return this->elem[n];
}

template <typename T>
T MyVector<T>::operator[](int n) const{
	return this->elem[n];
}

template <typename T>
void MyVector<T>::push_back(T val){
	if(fisDim==logicDim){
		reserve(fisDim*2);
	}
	elem[logicDim++]=val;
}

template <typename T>
T MyVector<T>::pop_back(){
    if(logicDim==0){
		throw std::out_of_range("out of range");
    }else{
        logicDim= logicDim-1;
        T val = elem[logicDim];
        elem[logicDim] = 0;
        return val;
    }
}

template<typename T>
void MyVector<T>::reserve(int n){
    if(n>fisDim){
        T* v = new T[n];
        copy(elem, elem+logicDim, v);
        delete[] v;
        elem = v;
        fisDim = n;
    }
}

template <typename T>
T& MyVector<T>::at (int n){
	if(n>fisDim){
		throw std::out_of_range("out of range");
	}
	return elem[n];
}

template <typename R>
std::ostream& operator<<(std::ostream& os, const MyVector<R> &out){
	os<<"\ndimensione "<<out.getSize();
	for (int i = 0; i < out.logicDim; i++)
	{
		os<<"\nvalore: "<<out.elem[i];
	}
	
	return  os;
}


#endif