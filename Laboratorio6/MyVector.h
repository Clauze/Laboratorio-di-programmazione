#include <iostream>
using namespace std;

template <typename T> class MyVector{
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
            delete elem;
        }
        
        T& operator[](int n);
        void push_back(T val);
        T& at (int n);
};