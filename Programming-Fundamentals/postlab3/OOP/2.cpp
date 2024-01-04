#include <bits/stdc++.h>
using namespace std;

template <class T> 
class Array2D {
private:
	int r;
	int c;
	T** arr;

public:
    // TODO
    Array2D(int r, int c){
        this->r = r; this->c = c;
        arr = new T*[this->r];
        for (int i = 0; i < this->r; i++){
            arr[i] = new T[this->c];
        }
    };
    Array2D(int r, int c, T init){
        this->r = r; this->c = c;
        arr = new T*[this->r];
        for (int i = 0; i < this->r; i++){
            arr[i] = new T[this->c];
        }
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                arr[i][j] = init;
            }
        }
    };
    ~Array2D(){
        for (int i = 0; i < this->r; i++){
            delete [] arr[i];
        }
        delete [] arr;
    };
    Array2D<T> * operator* (Array2D<T> &other){
        if (this->c != other.r) return nullptr;
        Array2D<T> *newarr = new Array2D<T>(this->r,other.c);
        T sum = 0;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < other.c; j++){
                int cnt = 0;
                while (cnt < this->c){
                    sum += this->arr[i][cnt] * other.arr[cnt][j];
                    //cout << this->arr[i][cnt] << " " << other.arr[cnt][j] << endl;
                    ++cnt;
                }
                (*newarr)[i][j] = sum;
                sum = 0;
            }
        }
        return newarr;
    };
    
    T * operator[](int idx){
        return arr[idx];
    };

    int getR() {return this->r;}
    int getC() {return this->c;}
    
    void disp() {
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < this->c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Array2D<int>* p = new Array2D<int>(1, 2, 3);
    cout << (*p)[0][1] << endl;
    p->disp();
    return 0;
}