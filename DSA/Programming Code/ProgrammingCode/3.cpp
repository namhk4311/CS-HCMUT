#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string many_infix_cal(const string& input) {
    string s, res = "";
    stringstream ss(input);
    stack<int> st;
    int op_cal;
    while (ss >> s) {
        if (s != "+" && s != "-" && s != "*" && s != "/") st.push(stoi(s));
        else {
            if (s == "+") op_cal = 0;
            else if (s == "-") op_cal = 1;
            else if (s == "*") op_cal = 2;
            else op_cal = 3;
        } 
        if (st.size() == 2) {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            ostringstream os;
            if (op_cal == 0) os << a + b;
            else if (op_cal == 1) os << a - b;
            else if (op_cal == 2) os << a * b;
            else os << a / b;
            if (res != "") res += " ";
            res += os.str();
        }
    } 
    return res;
}

int main() {
    cout << many_infix_cal("10 + 2\n14 * 2\n102 - 10");
}
