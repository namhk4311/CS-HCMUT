#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void print();
    
    Array(const Array<T> & other); // Copy Constructor
    
private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "") << this->p[i];
    }
    cout << endl;
}

// TODO
template<typename T>
Array<T>::Array(const Array<T> &other){
    this->size = other.size;
    this->p = new T[this->size];
    // for (int i = 0; i < this->size; i++){
        
    // }
    this = &other;
}


int main()
{
   
    return 0;
}