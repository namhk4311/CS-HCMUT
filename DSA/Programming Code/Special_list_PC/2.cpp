#include "2.h"

string dec2bin(const unsigned int& x) {
    AStack<unsigned int> LSt;
    unsigned int temp = x;
    while (temp) {
        LSt.push(temp % 2);
        temp /= 2;
    }
    string str = "";
    while (LSt.length()) {
        str += to_string(LSt.topValue());
        LSt.pop();
    }
    return str;
}

int main() {
    cout << dec2bin(18);
}