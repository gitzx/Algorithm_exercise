/*Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
*/

#include <iostream>
using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        int len_a = a.size();
        int len_b = b.size();
        string sum  = len_a>len_b ? a:b;
        int overflow = 0;
        for(int i=0; i<sum.size();++i){
            char ca = i<len_a ? a[len_a-i-1]:'0';
            char cb = i<len_b ? b[len_b-i-1]:'0';
            int bit = ca-'0'+cb-'0'+overflow;
            overflow = bit/2;
            sum[sum.size()-i-1]=bit%2 + '0';
        }
        if(overflow){
            sum="1" + sum;
        }
        return sum;
    }
};

int main(){
    Solution solution;
    string a="11";
    string b="1";
    cout<< solution.addBinary(a,b)<<endl; //100
    return 0;
}
