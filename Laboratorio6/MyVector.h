#ifndef MyVector_h
#define MyVector_h
#include <iostream>
using namespace std;

template <typename T> 
class MyVector{
    private:
        int logicDim;
        int fisDim;
        T* elem;
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
            delete[] elem;
        }
        
        int getSize()const{ return logicDim;}

        T& operator[](int n);
        T operator[](int n) const;
        void reserve(int n);
        T pop_back();
        void push_back(T val);
        T& at (int n);
        template<typename R>
        friend ostream& operator<<(ostream& os, const MyVector<R>& out);

};

#include "MyVector.hpp"

#endif