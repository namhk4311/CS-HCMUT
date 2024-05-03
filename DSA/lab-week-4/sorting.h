#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    //ex9===============================================
    //Helping functions go here
    static void heapSort(T* start, T* end){
        priority_queue<T> q(start, end);
        T* tmp = end - 1;
        while(!q.empty()){
            *tmp = q.top();
            q.pop();
            tmp--;
        }
        Sorting<T>::printArray(start,end);
    }
    
};
#endif /* SORTING_H */
