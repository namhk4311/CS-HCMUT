#include <bits/stdc++.h>
using namespace std;
    
template <typename T>

class AList : public List<T>{

    private:

       const static int MAXSIZE = 20; //the maximum members of the list

      T* data; // keep the list

       int cursor = 0; // keep the position of the cursor

       int listSize; // the real size of the list

   public:
    void remove() {
        if (cursor == listSize) throw out_of_range("Cannot remove element");
        for (int i = cursor; i < listSize - 1; i++) {
            data[i] = data[i + 1];
        }
        listSize--;
    }

};

int main()
{
   
    return 0;
}