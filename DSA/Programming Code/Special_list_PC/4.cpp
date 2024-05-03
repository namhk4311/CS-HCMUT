#include "2.h"

bool parentheses(const string &L) {
    AStack<char> ASt;
    for (int i = 0; i < L.length(); i++) {
        if (L[i] == '(') ASt.push('(');
        else if (L[i] == ')') {
            if (ASt.length()) ASt.pop();
            else return false;
        } 
    }
    if (ASt.length()) return false;
    return true;
}

int main() {
    string z = "((())())()";
    cout << parentheses(z) << endl;
}