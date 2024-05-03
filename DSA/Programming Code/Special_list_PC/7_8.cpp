#include "7_1.h"
using namespace std;
    
int prefix(const string *L, int n) {
    LQueue<string> q;
    for (int i = 0; i < n; i++) {
        q.enqueue(L[i]);
    }
    while (q.length() > 1) {
        string first = q.dequeue();
        if (first == "+" || first == "-") {
            int num1 = 0, num2 = 0; 
            if (q.frontValue() != "+" && q.frontValue() != "-") num1 = stoi(q.dequeue());
            else {
                q.enqueue(first);
                continue;
            }

            if (q.frontValue() != "+" && q.frontValue() != "-") num2 = stoi(q.dequeue());
            else {
                q.enqueue(first);
                q.enqueue(to_string(num1));
                continue;
            }

            if (first == "+") q.enqueue(to_string(num1 + num2));
            else q.enqueue(to_string(num1 - num2));
        }
        else {
            q.enqueue(first);
        }
    }
    return stoi(q.dequeue());
}

int main()
{    	
    string t[] = {"-","+","2","-","9","6","4"};
    cout << prefix(t,7);
    return 0;
}