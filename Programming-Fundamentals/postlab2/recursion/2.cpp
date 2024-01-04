#include <iostream>
#include <cmath>

int process(int power,int base,int sum){
    int kq=pow(base,power);
    if(sum==kq){
        return 1;
    }
    else if(sum<kq){
        return 0;
    }
    
    int p1=process(power,base+1,sum-kq);
    int p2=process(power,base+1,sum);
    return p1+p2;
}

int countWaySumOfSquare(int x)
{
	/*
	* STUDENT ANSWER
	*/
	return process(2,1,x);
}

void main1(){
    int sum; std::cin >> sum;
    std::cout << countWaySumOfSquare(sum);
}
int main(){
    main1();
}