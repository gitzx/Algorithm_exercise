/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid.The brackets must close in the correct order, 
 "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
    	if(s.length() == 0)
    	{
    		return true;
    	}
    	stack<char> st;
    	st.push(s[0]);
    	for(int i = 1; i < s.length(); ++i)
    	{
    		if(!st.empty() && isMatch(st.top(), s[i]))
    		{
    			st.pop();
    		}
    		else
    		{
    			st.push(s[i]);
    		}
    	}
    	if(st.empty())
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    bool isMatch(char c1, char c2)
    {
    	if((c1 == '(' && c2 == ')')
    	|| (c1 == '{' && c2 == '}')
    	|| (c1 == '[' && c2 == ']'))
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
};

int main(){
    Solution solution;
    string s = "[](){}";
    bool b = solution.isValid(s);
    cout<<s <<" is valid palindrome:"<<b<<endl;
    return 0;
}