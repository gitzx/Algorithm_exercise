/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

#include <iostream>
using namespace std;

class Solution{
public:
    string convertToTitle(int n){
        string str;
        while(n){
            int index=n%26;
            n=n/26;
            if(index==0){
                str+='Z';
                n--;
            }else{
                str+=('A'+index-1);
            }
        }
        for(int i=0;i<str.length()/2;++i){
            char c=str[i];
            str[i]=str[str.length()-i-1];
            str[str.length()-i-1]=c;
        }
        return str;
    }
};

int main(){
    Solution solution;
    string str;
    str=solution.convertToTitle(28);
    cout<<str<<endl; //AB
    return 0;
}
