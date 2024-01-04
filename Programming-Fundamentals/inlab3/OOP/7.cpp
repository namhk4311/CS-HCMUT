#include <bits/stdc++.h>
using namespace std;

class ClockType
{
   public:
      void setTime(int, int, int);
      void printTime() const;
      void incrementSeconds();
      void incrementMinutes();
      void incrementHours();
      ClockType(int, int, int);
      ClockType();

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
void ClockType::incrementSeconds(){
    this->sec++;
    if (this->sec >= 60){
        this->sec = 0;
        this->incrementMinutes();
    }
}

void ClockType::incrementMinutes(){
    this->min++;
    if (this->min >= 60){
        this->min = 0;
        this->incrementHours();
    }
}

void ClockType::incrementHours(){
    this->hr++;
    if (this->hr >= 24) this->hr = 0;
}


int main()
{
   
    return 0;
}