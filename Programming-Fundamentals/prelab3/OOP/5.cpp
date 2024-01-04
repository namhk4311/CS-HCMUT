#include <iostream>
using namespace std;

class Room{
    private:
        float length;
        float breadth;
        float height;
    public:
        Room(float length, float breadth, float height) : length(length), breadth(breadth), height(height){};
        float calculateArea(){
            return this->length * this->breadth;
        };
        float calculateVolume(){
            return this->length * this->breadth * this->height;
        };
};    

int main()
{
   
    return 0;
}