#include <iostream>
using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other); // Copy constructor
    Array<T> & operator=(const Array<T> & other); // Copy assignment operator
    
    void print();

private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

// TODO
template<typename T>
Array<T>::Array(const Array<T> & other) {
    this->size = other.size;
    p = new T[size];
    for (int i = 0; i < size; i++) {
        p[i] = other.p[i];
    }
    cout << "Call copy constructor" << endl;
}

template<typename T>
Array<T> & Array<T>::operator=(const Array<T> & other) {
    if (this != &other) {
        delete[] p;
        this->size = other.size;
        p = new T[size];
        for (int i = 0; i < size; i++) {
            p[i] = other.p[i];
        }
    }
    cout << "Call assignment operator" << endl;
    return *this;
}