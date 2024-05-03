#include <bits/stdc++.h>
using namespace std;


class Eval;
class PrintPrefix;
class PrintPostfix;

class Exp{
    private: 
        string prefix;
        string postfix;
        int res;
    public: 
        void setPrefix(string str) {
            prefix = str;
        }
        void setPostfix(string str) {
            postfix = str;
        }
        void printPrefix() {
            cout << prefix;
        }
        string getPrefix() {
            return prefix;
        }
        string getPostfix() {
            return postfix;
        }
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
            string str1 = "", str2 = "";
            str1 += op; 
            str1 += " " + left->getPrefix() + " " + right->getPrefix();
            this->setPrefix(str1); 

            str2 += left->getPostfix() + " " + right->getPostfix() + " ";
            str2 += op;
            this->setPostfix(str2);

            if (op == '+') this->set(left->eval() + right->eval());
            else if (op == '-') this->set(left->eval() - right->eval());
            else if (op == '*') this->set(left->eval() * right->eval());
            else this->set(left->eval() / right->eval());
        }
        int accept(Eval *v);
        void accept(PrintPrefix *v);
        void accept(PrintPostfix *v);
};

class UnExp: public Exp{
    public:
        UnExp(char op, Exp *exp) {
            string str1 = "", str2 = "";
            str1 += op;
            str1 += ". " + exp->getPrefix();
            
            str2 += exp->getPostfix() + " ";
            str2 += op;
            str2 += ".";
            
            this->setPrefix(str1);
            this->setPostfix(str2);

            if (op == '+') this->set(exp->eval());
            else this->set(exp->eval() * (-1));
        }
        int accept(Eval *v);
        void accept(PrintPrefix *v);
        void accept(PrintPostfix *v);
};

class IntLit: public Exp{
    public:
        IntLit(int v) {
            string str = to_string(v);
            this->setPrefix(str);
            this->setPostfix(str);

            this->set(v);
        }
        int accept(Eval *v);
        void accept(PrintPrefix *v);
        void accept(PrintPostfix *v);
};

class Eval {
    public: 
        Eval() {};
        int visit(Exp *x) {
            return x->eval();
        }
};

class PrintPrefix {
    public:
        PrintPrefix() {};
        void visit(Exp *x) {
            cout << x->getPrefix();
        };
};

class PrintPostfix {
    public: 
        PrintPostfix() {};
        void visit(Exp *x) {
            cout << x->getPostfix();
        };
};

int BinExp::accept(Eval *v) {
    return v->visit(this);
}
void BinExp::accept(PrintPrefix *v) {
    v->visit(this);
}
void BinExp::accept(PrintPostfix *v) {
    v->visit(this);
}

int UnExp::accept(Eval *v) {
    return v->visit(this);
}
void UnExp::accept(PrintPrefix *v) {
    v->visit(this);
}
void UnExp::accept(PrintPostfix *v) {
    v->visit(this);
}

int IntLit::accept(Eval *v) {
    return v->visit(this);
}
void IntLit::accept(PrintPrefix *v) {
    v->visit(this);
}
void IntLit::accept(PrintPostfix *v) {
    v->visit(this);
}

int main()
{
   
    return 0;
}