string minDiffPairs(int* arr, int n){
    // STUDENT ANSWER
    string res = "";
    int MAX = 2e9 + 7;
    if (n == 1) return res;
    sort(arr, arr + n);
    int minVal = MAX;
    int minfinal = MAX;
    for (int i = 0; i < n; i++) {
        
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[j] - arr[i]) <= minVal) {
                minVal = abs(arr[j] - arr[i]);
                minfinal = i; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ok = false;
             if (abs(arr[j] - arr[i]) == minVal) {
                res += "(" + to_string(arr[i]) + ", " + to_string(arr[j]) + ")";            
                ok = true;
             }
             if (i != minfinal && ok) res += ", ";
        }
    }
    return res;
}