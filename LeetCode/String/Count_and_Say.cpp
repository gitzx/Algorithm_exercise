#include <iostream>
using namespace std;

class Solution{
public:
    string countAndSay(int n){
        if(n<=0){
            return "";
        }
        string s = "1";
        for(int i=2;i<=n;++i){
            string t;
            for(int j=0;j<s.size();++j){
                char curc=s[j];
                int count = 1;
                for(int k=j+1;k<s.size()&&s[k]==curc;++k,++j){
                    ++count;
                }
                if(count>3){
                    cout<<"error";
                }
                t+=('0'+count);
                t+=curc;
            }
            s=t;
        }
        return s;
    }
};

int main(){
    Solution solution;
    cout<<5<<" Count and Say: "<<solution.countAndSay(5)<<endl; //111221
    return 0;
}
