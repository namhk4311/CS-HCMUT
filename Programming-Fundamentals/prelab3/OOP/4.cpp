#include <bits/stdc++.h>
using namespace std;

class ClockType
{
public:
    ClockType(int, int, int);
    ClockType();    
    void printTime() const;
    void setTime(int, int, int);
    
    void getTime(int&, int&, int&) const;
    

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

// TODO
void ClockType::getTime(int& hour, int& min, int& sec) const{
    if (0 <= this->sec && this->sec < 60) sec = this->sec;
    else sec = 0;
    
    if (0 <= this->min && this->min < 60) min = this->min;
    else min = 0;
    
    if (0 <= this->hr && this->hr < 24) hour = this->hr;
    else hour = 0;
}


int main()
{
    ClockType myClock;
    myClock.setTime(5, 4, 30);
    int hours,minutes,seconds;
    myClock.getTime(hours, minutes, seconds);
    cout << "Hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds << endl;
    return 0;
}