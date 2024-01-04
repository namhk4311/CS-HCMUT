#include<iostream>
using namespace std;

// TODO
class Integer{
    private:
        int val;
    public:
        Integer(int val) : val(val){};
        Integer(Integer*);
        void print();
        friend Integer operator + (Integer a, Integer b);
};

// Integer Integer::operator + (Integer another){
//     this->val = this->val + another.val;
//     Integer sum(this->val);
//     return sum;
// }

Integer::Integer(Integer *integer){
    this->val = integer->val;
}

Integer operator + (Integer a, Integer b){
    Integer sum(a.val + b.val);
    return sum;
}


void Integer::print() {
    cout << this->val << endl;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;   
    return 0;
}