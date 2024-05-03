#include <iostream>
using namespace std;

class Exp{
    private: 
        char op;
        double res;
    public: 
        int eval() {
            return res;
        }
        void set(int v) {
            res = v;
        }
};

class BinExp: public Exp{
    public:
        BinExp(Exp *left, char op, Exp *right) {
            if (op == '+') this->set(left->eval() + right->eval());
            else if (op == '-') this->set(left->eval() - right->eval());
            else if (op == '*') this->set(left->eval() * right->eval());
            else this->set(left->eval() / right->eval());
        }
};

class UnExp: public Exp{
    public:
        UnExp(char op, Exp *exp) {
            if (op == '+') this->set(exp->eval());
            else this->set(exp->eval() * (-1));
        }
};

class IntLit: public Exp{
    public:
        IntLit(int v) {
            this->set(v);
        }
};

int main()
{
    
    return 0;
}