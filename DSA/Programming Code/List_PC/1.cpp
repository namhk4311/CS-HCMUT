#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AList :public List<T> {
    private:

       const static int MAX = 20; //the maximum members of the list

       T* data; // keep the list

       int cursor = 0; // keep the position of the cursor

       int size; // the real size of the list

   public:

       AList() { data = new T[MAX];}
        void insert(const T& v){
            if (size == MAX) return;
            for (int i = size; i > cursor; i--) {
                data[i] = data[i - 1];
            }
            data[cursor] = v;
            size++;
        }

};    

int main()
{
   
    return 0;
}