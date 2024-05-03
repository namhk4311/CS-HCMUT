#ifndef _array_
#define _array_
#include "list.h"

template <typename E> 
class Alist : public List<E> {
    private: 
        int maxSize;
        int listSize;
        int curr;
        E * listArray;
        //int defaultSize;
    public:
        Alist(int size = defaultSize) {
            maxSize = size;
            listSize = curr = 0;
            listArray = new E[maxSize];
        }
        ~Alist() { delete [] listArray;}
        void clear() {
            delete [] listArray;
            listSize = curr = 0;
            listArray = new E[maxSize];
        }
        void insert(const E& it) {
            assert(listSize < maxSize);
            for (int i = listSize; i > curr; i--) {
                listArray[i] = listArray[i - 1];
            }
            listArray[curr] = it;
            listSize++;
        }
};

#endif
