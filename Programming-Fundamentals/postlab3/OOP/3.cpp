#include <iostream>

using namespace std;
class Coordinate{
    private:
        float x;
        float y;
    public:
        Coordinate(float x, float y);
        void setX(float);
        void setY(float);
        float getX();
        float getY();
        float distanceTo(Coordinate&);
};

Coordinate::Coordinate(float x, float y){
    this->x = x;
    this->y = y;
}

void Coordinate::setX(float x){
    this->x = x;
}
void Coordinate::setY(float y){
    this->y = y;
}
float Coordinate::getX(){
    return this->x;
}
float Coordinate::getY(){
    return this->y;
}
float Coordinate::distanceTo(Coordinate &other){
    return abs(this->x - other.x) + abs(this->y - other.y);
}


int main () {
    float Xa, Xb, Ya, Yb;
    cin >> Xa >> Xb >> Ya >> Yb;
    Coordinate a(1,2);
    Coordinate b(0,1);
    cout << a.distanceTo(b) << endl;
    a.setX(Xa); a.setY(Ya);
    b.setX(Xb); b.setY(Yb);
    cout << abs(a.getX() - b.getX()) + abs(a.getY() - b.getY()) << endl;
    cout << a.distanceTo(b) << endl;
    cout << abs(Xa - Xb) + abs(Ya - Yb);
    return 0;
}