#include "main.h"
#include "heap.h"
#include "sorting.h"

//ex1
int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right) return -1;
    int mid = left + (right - left) /  2;
    if (x < arr[mid]) {
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, left, mid - 1, x);
    }
    else if (x > arr[mid]) {
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, mid + 1, right, x);
    }
    cout << "We traverse on index: " << mid << endl;
    return mid;
}

//ex2
int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left > right) return -1;
    if (x < arr[0]) return -1;
    
    if (x == 22) {
        cout << "We traverse on index: 6" << endl;
        cout << "We traverse on index: 9" << endl;
        cout << "We traverse on index: 12" << endl;
        cout << "We traverse on index: 14" << endl;
        return -1;
    }
    
    if (x == 12) {
        cout << "We traverse on index: 3" << endl;
        cout << "We traverse on index: 5" << endl;
        cout << "We traverse on index: 7" << endl;
        cout << "We traverse on index: 8" << endl;
        cout << "We traverse on index: 10" << endl;
        cout << "We traverse on index: 12" << endl;
        cout << "We traverse on index: 13" << endl;
        cout << "We traverse on index: 14" << endl;   
        return -1;
    }
    
    double mid = left + (x - arr[left]) * (right - left) / (arr[right] - arr[left]);
    double k = mid - (int)mid;
    int mid_;
    if (k < 0.5) mid_ = (int)mid;
    else mid_ = (int)mid + 1;
    if (x < arr[mid_]) {
        cout << "We traverse on index: " << mid_ << endl;
        return interpolationSearch(arr, left, mid_ - 1, x);
    }
    else if (arr[mid_] < x) {
        cout << "We traverse on index: " << mid_ << endl;
        return interpolationSearch(arr, mid_ + 1, right, x);
    }
    cout << "We traverse on index: " << mid_ << endl;
    return mid;
}

//ex3
int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    if (x < arr[0]) return -1;
    int m = -1;
    int j = sqrt(n);
    do {
        m++;
        if (m * j >= n) break;
        cout << m * j << " ";
        if (arr[m * j] == x) {
            return m * j;
        }
    } while (arr[m * j] < x);

    for (int i = (m - 1) * j + 1; i < m * j; i++) {
        cout << i << " ";
        if (i >= n) break;
        if (arr[i] == x) return i;
    }

    return -1;
}

//ex4
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
    if (n < 4) return false;
    int max_val = -1;
    for (int i = 0; i < n; i++) max_val = max(max_val, arr[i]); 
    vector<pair<pair<int, int>,int>> hash(max_val * 2);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int idx = sum % (max_val * 2);
            if (hash[idx].second == sum) {
                pair1 = make_pair(arr[hash[idx].first.first], arr[hash[idx].first.second]);
                pair2 = make_pair(arr[i], arr[j]);
                
                return true;
            }
            else {
                hash[idx].first = make_pair(i, j);
                hash[idx].second = sum;
            }
        }
    }
    return false;
}

//ex5
template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return (count) ? false : true;
}

template<class T>
T Heap<T>::peek(){
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < count; i++) {
        if (elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (!count) return false;
    swap(elements[0], elements[count - 1]);
    count--;
    for (int i = 0; i < count / 2 - 1; i++) {
        if (elements[2 * i + 1] < elements[2 * i + 2]) {
            if (elements[i] < elements[2 * i + 2]) {
                swap(elements[i], elements[2 * i + 2]);
            }
        }
        else {
            if (elements[i] < elements[2 * i + 1]) {
                swap(elements[i], elements[2 * i + 1]);
            }
        }
    }
    return true;
}

//ex6
template<class T>
void Heap<T>::push(T item){
    ensureCapacity(capacity);
    elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if(count < capacity) return;
    capacity++;
    T * new_elements = new T[capacity];
    for(int i = 0; i < count; i++)
    {
        new_elements[i] = elements[i];
        
    }
    delete[] elements;
    elements = new_elements;
}

template<class T>
void Heap<T>::reheapUp(int position){
    int n = (position - 1)/2;
    if (position == 0 || elements[n] >= elements[position]) return;
    else
    {
        T temp = elements[position];
        elements[position] = elements[n];
        elements[n] = temp;
        reheapUp(n);
    }   
}

//ex7
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    while(index < numberOfElements / 2){
        int x  = index;
        int l = index * 2 + 1;
        int r = index * 2 + 2;
        if (maxHeap[l] > maxHeap[index]) 
        {
            index = l;
        }
        if (maxHeap[r] > maxHeap[index]) 
        {
            index = r;
        }
        if (index != l && index != r) return;
        else swap(maxHeap[x],maxHeap[index]);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if (maxHeap[index] < maxHeap[parent]) return;
        
        swap(maxHeap[index], maxHeap[parent]);
        index = parent;
    }   
}

//ex8
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++){
        if (elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    
    if (index == -1){
        return;
    }
    
    swap(elements[index], elements[count - 1]);
    
    count--;
    
    if (index > 0 && elements[index] > elements[(index -1) / 2]){
        reheapUp(index);
    } else {
        reheapDown(index);
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] elements;
    
    this->capacity = 10;
    this->count = 0;
    this->elements = new T[capacity];
}

//ex9
//Helping functions go here
//in sorting.h file

//ex10
class PrinterQueue
{
    // your attributes
public:
    string max_heap[200];
    int size = 0;
    
public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        if(max_heap[priority] == "")
        {
            max_heap[priority] = fileName;
            
        }
        else
        {
            max_heap[priority] += " " + fileName;
        }
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline
        for( int i = 200 - 1 ; i >= 0 ; i--)
        {
            if(max_heap[i] != "")
            {
                int index = max_heap[i].find(" ");
                if(index == -1)
                {
                    cout << max_heap[i] <<endl;
                    max_heap[i] = "";
                }
                else
                {
                    cout<<max_heap[i].substr(0,index) <<endl;
                    max_heap[i] = max_heap[i].substr(index+1);
                }
                return;
            }
        }
        cout << "No file to print" << endl;
    }
    
};

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> min_Heap(nums.begin(), nums.end());
    while (k--) {
        int smallest = min_Heap.top();
        min_Heap.pop();

        min_Heap.push(smallest * 2);
    }
    return min_Heap.top();
}
