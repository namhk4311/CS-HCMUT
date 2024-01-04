#include <iostream>
using namespace std;

class ClockType
{
public:
    ClockType(){};
      
    void setTime(int, int, int);
    void printTime() const;

private:
    int hr;
    int min;
    int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

void ClockType::setTime(int hr, int min, int sec){
    this->hr = this->min = this->sec = 0;
    if (0 <= sec && sec < 60) this->sec = sec;
    if (0 <= min && min < 60) this->min = min;
    if (0 <= hr && hr < 24) this->hr = hr;
}