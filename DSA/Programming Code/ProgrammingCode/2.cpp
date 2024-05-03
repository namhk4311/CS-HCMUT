#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

struct action {

    string op; // operator

    int (*func)(int, int); // function pointer to corresponding function

};

int myadd(int x, int y) { return x + y;}

int mymin(int x, int y) { return x - y;}

int mymul(int x, int y) { return x * y;}

int mydiv(int x, int y) { return x / y;}

int infix_cal(const string& input) {
    action operation[4];
    operation[0].op = "+";
    operation[0].func = myadd; 
    operation[1].op = "-";
    operation[1].func = mymin;
    operation[2].op = "*";
    operation[2].func = mymul;
    operation[3].op = "/";
    operation[3].func = mydiv;
    stringstream ss(input);
    string s;
    stack<int> st;
    int op_cal;
    while (ss >> s) {
        if (s != operation[0].op && s != operation[1].op && s != operation[2].op && s != operation[3].op) {
            st.push(stoi(s));
        }
        else {
            for (int i = 0; i < 4; i++) {
                if (s == operation[i].op) {
                    op_cal = i;
                    break;
                }
            }
        }
        if (st.size() == 2) {
            int a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(operation[op_cal].func(b, a));
        }
    }
    return st.top();
}

int main() {
    
}