/*Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
using namespace std;

class Solution{
public:
    int romanToInt(string s){
        int result=0;
        for(int i=0;i<s.size();++i){
            if(i>0&&c2n(s[i])>c2n(s[i-1])){
                result+=(c2n(s[i])-2*c2n(s[i-1]));
            }else{
                result+=c2n(s[i]);
            }
        }
        return result;
    }
    int c2n(char c){
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
};

int main(){
    Solution solution;
    string s="IV";
    cout<<solution.romanToInt(s)<<endl; //4
    return 0;
}
