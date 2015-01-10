/*Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

#include <iostream>
using namespace std;

class Solution{
public:
    int titleToNumber(string s){
        int number = 0;
        int temp = 0;
        for(int i=0;i<s.length();++i){
            temp = s[i]-'A' + 1;
            number = number*26 + temp;
        }
        return number;
    }
};

int main(){
    Solution solution;
    string s="AB";
    int number=solution.titleToNumber(s);
    cout<<number<<endl; //28
    return 0;
}
