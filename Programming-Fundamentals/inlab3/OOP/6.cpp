#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void print();
private:
    int size;
    T * p;
};

// TODO
template <typename T>
Array<T>::Array(int size, T initValue){
    this->size = size;
    this->p = new T[this->size];
    for (int i = 0; i < this->size; i++){
        p[i] = initValue;
    }
}

template <typename T>
Array<T>::~Array(){
    delete [] p;
}


int main()
{
   
    return 0;
}