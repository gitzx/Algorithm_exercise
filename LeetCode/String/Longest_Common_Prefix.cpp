/*Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        string prefix;
        if(strs.size()==0){
            return prefix;    
        }
        int len=0;
        while(1){
            if(len==strs[0].size()){
                break;
            }
            char c = strs[0][len];
            int i=1;
            for(;i<strs.size();i++){
                if(len==strs[i].size()){
                    break;
                }
                if(c!=strs[i][len]){
                    break;
                }
            }
            if(i!=strs.size()){
                break;
            }
            prefix.append(1,c);
            len++;
        }
        return prefix;
    }
};

int main(){
    Solution solution;
    vector<string> v;
    vector<string>::iterator it;
    v.push_back("hello");
    v.push_back("helloworld");
    v.push_back("helloo");
    string prefix = solution.longestCommonPrefix(v);
    cout<<" longestCommonPrefix: "<< prefix<<endl;
    return 0;
}
