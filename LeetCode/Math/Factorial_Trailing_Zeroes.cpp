//Given an integer n, return the number of trailing zeroes in n!.

#include <iostream>
using namespace std;

/*Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
*/
class Solution{
public:
    int trailingZeroes(int n){
        int count=0;
        for(int i=5;n/i>=1;i*=5){
            count+=n/i;
        }
        return count;
    }
};

int main(){
    Solution solution;
    int n=100;
    cout<<solution.trailingZeroes(n)<<endl; //24
    return 0;
}
