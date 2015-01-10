/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>
#include <limits.h>
using namespace std;

class Solution{
public:
    int reverse(int x){
       bool isPositive=x>0?true:false;
       if(!isPositive){
           x*=-1;
       }
       int newNumber=0;
       int num=0;
       while(x!=0){
           num=x%10;
           newNumber=newNumber*10+num;
           x=x/10;
       }
       if(newNumber>INT_MAX){
           return isPositive?INT_MAX:INT_MIN;
       }
       if(!isPositive){
           return newNumber*(-1);
       }else{
           return newNumber;
       }
    }
};

int main(){
    Solution solution;
    cout<<solution.reverse(-123)<<endl; //-321
    return 0;
}
