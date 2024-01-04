#include <bits/stdc++.h>
using namespace std;

class ClockType
{
public:
    void setTime(int, int, int);
    bool equalTime(const ClockType&) const;
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};

// TODO
bool ClockType::equalTime(const ClockType&yourclock) const{
    if (this->hr == yourclock.hr && this->min == yourclock.min && this->sec == yourclock.sec) return true;
    return false;
}

int main()
{
   
    return 0;
}