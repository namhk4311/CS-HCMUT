#include <iostream>
#include <sstream>
using namespace std;

string op[4] = {"+", "-", "*", "/"};

int infix_cal(const string& input) {
    string s;
    int a, b, i = 0;
    string res_op;
    stringstream ss(input);
    while (ss >> s) {
        i++;
        if (i == 1) {
            a = stoi(s);
        }
        else if (i == 3) {
            b = stoi(s);
        }
        else {
            if (s == "+") res_op = op[0];
            else if (s == "-") res_op = op[1];
            else if (s == "*") res_op = op[2];
            else res_op = op[3];
        }
    }
    if (res_op == "+") return a + b;
    if (res_op == "-") return a - b;
    if (res_op == "*") return a * b;
    return a / b; 
}

int main() {
    cout << infix_cal("10 + 2");
}