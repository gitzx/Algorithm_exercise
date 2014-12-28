/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
using namespace std;
class Solution1{
    public:
        bool isValid(string s){
            if(s.length()==0){
                return true;
            }
            stack<char> st;
            st.push(s[0]);
            for(int i=1;i<s.length();i++){
                if(!st.empty()&&isMatch(st.top(),s[i])){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
            if(st.empty()){
                return true;
            }else{
                return false;
            }
        }
        bool isMatch(char c1, char c2){
            if((c1=='('&&c2==')')
                    ||(c1=='['&&c2==']')
                    ||(c1=='{'&&c2=='}')){
                return true;
            }else{
                return false;
            }
        }
};

class Solution2{
public:
    bool isValid(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if((c ==')') && (top != '(')){
                    return false;
                }else if((c == ']') && (top != '[')){
                    return false;
                }else if((c == '}') && (top != '{')){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    string s="{[]()}";
    bool b1 = solution1.isValid(s);
    bool b2 = solution2.isValid(s);
    cout<<s<<"is valid palindrome:"<<b1<<endl; //1
    cout<<s<<"is valid palindrome:"<<b2<<endl; //1
    return 0;
}
