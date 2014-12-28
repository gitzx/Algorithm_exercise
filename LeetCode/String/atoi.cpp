/*Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;
class Solution{
public:
    int atoi(const char *str){
        int len = strlen(str);
        int sign=1;
        int num=0;
        int i=0;
        while(str[i]==' ' && i<len){
            i++;
        }
        if(str[i]=='+'){
            i++;
        }
        if(str[i]=='-'){
            sign=-1;
            i++;
        }
        for(;i<len;i++){
            if(str[i]==' '){
                break;
            }   
            if(str[i]<'0'||str[i]>'9'){
                break;
            }
            if(INT_MAX/10<num || INT_MAX/10==num && INT_MAX%10<(str[i]-'0')){
                return sign==-1?INT_MIN:INT_MAX;
                break;
            }
            num = num*10 + str[i]-'0';
        }
        return num*sign;
    }
};
int main(){
    Solution solution;
    char str[]="  22 ";
    int str_num = solution.atoi(str);
    cout<<str<<" atoi:"<<str_num<<endl;
    return 0;
}
