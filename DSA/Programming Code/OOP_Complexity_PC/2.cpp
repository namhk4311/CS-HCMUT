#include <iostream>
#include <string>
using namespace std;

class Exp{
    private: 
        string prefix;
    public: 
        void set(string str) {
            prefix = str;
        }
        void printPrefix() {
            cout << prefix;
        }
        string getPrefix() {
            return prefix;
        }
};

class BinExp: public Exp{
    public:
        BinExp(Exp *left, char op, Exp *right) {
            string str = "";
            str += op; 
            str += " " + left->getPrefix() + " " + right->getPrefix();
            this->set(str); 
        }
};

class UnExp: public Exp{
    public:
        UnExp(char op, Exp *exp) {
            string str = "";
            str += op;
            str += ". " + exp->getPrefix();
            this->set(str);
        }
};

class IntLit: public Exp{
    public:
        IntLit(int v) {
            string str = to_string(v);
            this->set(str);
        }
};

int main()
{
    Exp *x = new BinExp(x, '+', x);
    return 0;
}