#include <bits/stdc++.h>
using namespace std;
    
template <typename T>
class AList {
    private:

       const static int MAXSIZE = 20; //the maximum members of the list

       T* data; // keep the list

       int cursor = 0; // keep the position of the cursor

       int listSize; // the real size of the list

   public:
        void insertBefore(const T& v, const T& k) {
            if (size == MAX) throw out_of_range();
            int i;
            for (i = 0; i <= size; i++) {
                if (i == size || data[i] == k) break;
            }
            if (i < size) {
                for (int j = size; j > i; j++) {
                    data[j] = data[j - 1];
                }
                data[i] = v;
                cursor = i;
            }
            else return;
        }

};

int main()
{
   
    return 0;
}