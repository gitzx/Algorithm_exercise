//Determine whether an integer is a palindrome. Do this without extra space.

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        if(x<0){
            return false;
        }
        int div=1;
        while(x/10>=div){
            div*=10;
        }
        while(x>0){
            int high=x/div;
            int low=x%10;
            if(high!=low){
                return false;
            }
            x=(x%div)/10;
            div/=100;
        }
        return true;
    }
};

int main(){
    Solution solution;
    bool isPalindrome=solution.isPalindrome(112211);
    cout<<isPalindrome<<endl; //1
    return 0;
}
