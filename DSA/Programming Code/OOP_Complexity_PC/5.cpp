#include <bits/stdc++.h>
using namespace std;
    
template <typename T>
//O(n * 2^n)
vector<vector<T>> powerSet(vector<T> arr) {
    int sizeArr = arr.size();
    vector<vector<T>> res;
    int sizeNewArr = 1 << sizeArr;
    for (int i = 0; i < sizeNewArr; i++) {
        vector<T> tmp;
        for (int j = 0; j < sizeArr; j++) {
            if (i & (1 << j)) tmp.push_back(arr[j]); 
        }
        res.push_back(tmp);
    }
    return res;
}

int main()
{
    cout << (1 << 0) << endl;
    return 0;
}