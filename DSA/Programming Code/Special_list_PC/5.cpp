#include "2.h"

//template<typename T> 
int postfix(string *L, int n) {
    AStack<int> st;
    for (int i = 0; i < n; i++) {
        if (L[i] == "+" || L[i] == "-") {
            int s2 = st.pop();
            int s1 = st.pop();
            if (L[i] == "+") st.push(s1 + s2);
            else st.push(s1 - s2);
        }
        else {
            st.push(stoi(L[i]));
        }
    }
    return st.topValue();
}

int main() {
    string x[] = {"10","6","-"};
    cout << postfix(x,3);
}