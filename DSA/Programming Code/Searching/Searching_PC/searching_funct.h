#include "main.h"
/*
1.Write function binarysearch(T arr[],int left, int right, T k) to search key k in the ascending-sorted array arr with lower bound index left and upper bound index right using binary search method. The method return true if the key k is found in the array arr, otherwise it returns false. To make sure the function applying binary search, please print the values (followed by comma) compared to key k during searching process. The prototype of the function is as follows:

template <typename T>

bool binarysearch(T arr[], int left, int right, T k);
*/
template <typename T>

bool binarysearch(T arr[], int left, int right, T k){
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (k < arr[mid]) {
            cout << arr[mid] << ",";
            right = mid - 1;
        }
        else if (arr[mid] < k) {
            cout << arr[mid] << ",";
            left = mid + 1;
        }
        else {
            cout << arr[mid] << ",";
            return true;
        }
    }
    return false;
};

/*
2.Write function binarysearch(T arr[],int n, T k) to search key k in the ascending-sorted array arr with n elements using binary search method. The method return the index of key k if the key is found in the array arr, or the index of the greatest value less than k if the key k is not found in the array arr, or ERROR if the key k is less than the least value in the array arr. To make sure that you are using binary search, please print the index of elements (followed by the comma) comparing during the searching before the result of the function.

The prototype of the function is as follows:

template <typename T>

int binarysearch(T arr[], int n, T k);
*/

template <typename T>

int binarysearch(T arr[], int n, T k) {
    
    int lo = 0;
    int hi = n - 1;
    int mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (k < arr[mid]) {
            hi = mid - 1;
            cout << mid << ",";
        }
        else if (arr[mid] < k) {
            lo = mid + 1;
            cout << mid << ",";
        }
        else {
            cout << mid << ",";
            return mid;
        }
    }
    if (k < arr[0]) return -1;
    return (k < arr[mid]) ? mid - 1 : mid;
};

/*
3.
Write function dictionarySearch(T arr[],int left, int right, T k) to search key k in the ascending-sorted array arr with lower bound index left and upper bound index right using dictionary search method. The method return true if the key k is found in the array arr, otherwise it returns false. To make sure the function applying dictionary search, please print the values (followed by comma) compared to key k during searching process. The prototype of the function is as follows:

template <typename T>

bool dictionarySearch(T arr[], int left, int right, T k);
*/

template <typename T>

bool dictionarySearch(T arr[], int left, int right, T k) {
    if (k < arr[0]) return false;
    if (arr[right] < k) return false;
    int n = right;
    int p_pre = -1;
    int p_idx = -2;
    while (left < right) {
        double p = (k - arr[left]) / (double)(arr[right] - arr[left]) * (double)(right - left) + left;
        if (p > n) break;
        if (p - (int)p < 0.5) {
            p_idx = (int)p;
        }
        else {
            p_idx = (int)p + 1;
        }
        if (p_idx == p_pre) break;
        
        if (k < arr[p_idx]) {
            cout << arr[p_idx] << ",";
            right = p_idx - 1;
            if (arr[right] < k) break;
        }
        else if (arr[p_idx] < k) {
            cout << arr[p_idx] << ",";
            left = p_idx + 1;
            if (arr[left] > k) break;
        }
        else {
            cout << arr[p_idx] << ",";
            return true;
        }
        p_pre = p_idx;
    }
    return false;
}

/*
4. Write function jumpsearch(T arr[],int n, T k,int j) to search key k in the ascending-sorted array arr with size n using jump search method with j. The method return true if the key k is found in the array arr. To make sure the function applying jump search, please print the values compared to key k during searching process. These printed values are followed by commas. The prototype of the function is as follows:

template <typename T>

bool jumpsearch(T arr[], int n, T k, int j);
*/

template <typename T>

bool jumpsearch(T arr[], int n, T k, int j) {
   int m = 0;
    do {
        if (m * j >= n) break;
        cout << arr[m * j] << ",";
        if (arr[m * j] == k) return true;
   } while (arr[m * j] <= k && (m++) * j < n);
   if (m * j >= n) {
       for (int i = (m - 1) * j + 1; i < n; i++) {
           cout << arr[i] << ",";
           if (arr[i] == k) return true;
       }
   }
   else if (m > 0) {
       for (int i = (m - 1) * j + 1; i < (m * j); i++) {
           
           cout << arr[i] << ",";
           if (arr[i] > k) break;
           if (arr[i] == k) return true;
       }
   }
   return false;
}



/*5. 
Implement an integer hash (with separate chaining) in class ChainingHash with three following elementary methods:

- insert: to Insert an integer key into a hash

- remove: to remove an integer key from a hash if found, otherwise throw exception "Not found!"

- search: to search a key in hash, return true if found, otherwise return false.

Assume that there is no duplicate key.

Initial code:
*/

class ChainingHash {
private:
    int (*hash)(int);
    list<int> *data;
    int size;
    
public:
    ChainingHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    ChainingHash(int size, int (*hash)(int)) {
        this->hash = hash;
        this->size = size;
        this->data = new list<int>[size];
    }
    
    void insert(int key) {
        int idx = hash(key);
        data[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hash(key);
        int pre_size = data[idx].size();
        data[idx].remove(key); 
        int pos_size = data[idx].size();
        if (pre_size == pos_size) throw std::runtime_error("Not found!");
    }

    bool search(int key) {
        int idx = hash(key);
        list<int>::iterator it;
        for (it = data[idx].begin(); it != data[idx].end(); it++) {
            if (*it == key) return true;
        }
        return false;
    }
    
    int count() {
        int total = 0;
        for (int i = 0; i < this->size; i++) {
            total += this->data[i].size();
        }
        return total;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
        }
    }
};

int hashWith11(int key) {
    return key % 11;
}
int hashWith15(int key) {
    return key % 15;
}
int hashWith17(int key) {
    return key % 17;
}

