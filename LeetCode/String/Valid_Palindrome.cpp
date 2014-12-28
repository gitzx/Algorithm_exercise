/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

#include <iostream>
#include <algorithm>
using namespace std;
class Solution1{
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(start<end){
            while(start<end && !isAlpha(s[start])){
                start++;
            }
            while(start<end && !isAlpha(s[end])){
                end--;
            }
            if(s[start]!=s[end]){
                break;
            }
            start++;
            end--;
        }
        if(start>=end){
            return true;
        }else{
            return false;
        }
    }
    bool isAlpha(char c){
        if(c>='a' && c<='z'){
            return true;
        }
        if(c>='0' && c<'9'){
            return true;
        }
        return false;
    }
};

class Solution2{
public:
    bool isPalindrome(string s){
        int len = s.length();
        if(len<=1){
            return true;
        }
        int i=0;
        int j=len-1;
        while(i<=j){
            if(!isAlpha(s[i])){
                i++;
            }else if(!isAlpha(s[j])){
                j--;
            }else{
                if(isSame(s[i],s[j])){
                    i++;
                    j--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    bool isAlpha(char c){
        if(c>='a' && c<='z'){
            return true;
        }
        if(c>='A'&& c<='Z'){
            return true;
        }
        if(c>='0' && c<='9'){
            return true;
        }
        return false;
    }
    bool isSame(char c1, char c2){
        if(c1>='A' && c1<='Z'){
            c1 +=32;
        }
        if(c2>='A' && c2<='Z'){
            c2 +=32;
        }
        return c1==c2;
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    string s = "A man, a plan, a canal: Panama";
    bool b1 = solution1.isPalindrome(s);
    bool b2 = solution2.isPalindrome(s);
    cout<< s <<" is valid palindrome: "<< b1 << endl; //b1=0
    cout<< s <<" is valid palindrome: "<< b2 << endl; //b2=0
    return 0;
}
