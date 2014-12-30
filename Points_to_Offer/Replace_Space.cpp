/*请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <iostream>
using namespace std;

class Solution{
public:
    void replaceSpace(string strs){
        int count = 0;
        for(int i=0;i<strs.length();i++){
            if(strs[i]==' '){
                ++count;
            }
        }
        int k=strs.length()+count*2;
        for(int j=strs.length();j>=0;--j){
            if(strs[j]!=' '){
                strs[k--]=strs[j];
            }else{
                strs[k--]='0';
                strs[k--]='2';
                strs[k--]='%';
            }
        }
        for(int p=0;p<strs.length()+2*count;p++){
            cout<<strs[p];
        }
        cout<<endl;
   }
};

int main(){
    Solution solution;
    string strs="We are happy";
    solution.replaceSpace(strs);
    return 0;
}
